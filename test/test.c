
#include <stdio.h>
#include <dirent.h>
#include "sim_avr.h"
#include "sim_elf.h"
#include "sim_gdb.h"
#include "ac_input.h"
#include "avr_ioport.h"

avr_t * avr;
ac_input_t ac_input;

void watcher(struct avr_irq_t* irq, uint32_t value, void* closure) {
    printf("PIN%s%d = %d\n", (char*)closure, irq->irq, value);
}

int main() {

  elf_firmware_t f;
  elf_read_firmware ( "atmega328p_memorymodule.axf", &f );

  avr = avr_make_mcu_by_name ( f.mmcu );
  avr_init ( avr );
  avr_load_firmware ( avr, &f );

  ////////////////////////////////
  // GDB setup
  avr->gdb_port = 1234;
  avr->state = cpu_Stopped;
  avr_gdb_init(avr);

  ////////////////////////////////
  // VCD Setup

  ////////////////////////////////
  // Setup periferals
  
  // Watch output
  avr_irq_register_notify(
        avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('B'), 0),
        watcher, "B");

  // Clock
  ac_input_init(avr, &ac_input);
  avr_connect_irq(
        ac_input.irq + IRQ_AC_OUT,
        avr_io_getirq(
                   avr,
                   AVR_IOCTL_IOPORT_GETIRQ('B'), 
                   1)
        );

  int enabled = 0;
  int previous = 0;

  int state = cpu_Running;
  while ( ( state != cpu_Done ) && ( state != cpu_Crashed ) ) {
      state = avr_run ( avr );

      DIR* dir = opendir("mydir");
      if ( dir ) {
        enabled = 1;
      }
      else {
        enabled = 0;
      }

      if( enabled != previous ) {
        previous = enabled;
        printf("Changed\n");
        avr_raise_irq(
                avr_io_getirq(
                        avr, 
                        AVR_IOCTL_IOPORT_GETIRQ('B'), 
                        2 ),
                enabled);
      }
            
    }
  
  }

