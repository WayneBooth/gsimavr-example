#ifndef __MODEL_H__
#define __MODEL_H__

#include "sim_avr.h"

avr_t * avr;

int reg_pin_to_location ( char *, int );
void set_ddr( int , int );
void set_ioState( int , int );
//void set_outputState( int, int );
//void set_inputState( int, int ); 
uint32_t get_positive_power();
uint32_t get_negative_power();
uint32_t get_positive_outputs();
uint32_t get_negative_outputs();
uint32_t get_positive_inputs();
uint32_t get_negative_inputs();
void setupSimulator(void);

#endif
