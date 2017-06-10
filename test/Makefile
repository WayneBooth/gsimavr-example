# 
#   Copyright 2008-2011 Michel Pollet <buserror@gmail.com>
#
# This file is part of simavr.
#
# simavr is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# simavr is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with simavr.  If not, see <http://www.gnu.org/licenses/>.

target= test
firm_src = ${wildcard at*${board}.c}
firmware = ${firm_src:.c=.axf}
#simavr = ../../simavr
simavr = /home/wbooth/Working/git/simavr_test/simavr/simavr/

IPATH = .
#IPATH += ${simavr}/examples/parts
#IPATH += ${simavr}/include
#IPATH += ${simavr}/simavr/sim
IPATH += /usr/local/include/
IPATH += /usr/local/include/simavr/


#VPATH = .
#VPATH += ${simavr}/examples/parts
#VPATH += /usr/local/include/

LDFLAGS += -lpthread

all: clean build
 
build: obj atmega328p_memorymodule.axf ${target} 

atmega328p_memorymodule.axf: atmega328p_memorymodule.c

include Makefile.common

board = ${OBJ}/${target}.elf

${board} : ${OBJ}/ac_input.o
${board} : ${OBJ}/${target}.o

${target}: ${board}
	@echo $@ done

clean: clean-${OBJ}
	rm -rf *.hex *.a *.axf ${target} *.vcd .*.swo .*.swp .*.swm .*.swn

debugger: all
	ddd --debugger /usr/bin/avr-gdb -x gdb.conf

