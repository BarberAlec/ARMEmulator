#all: ARMEulator
#
#ARMEulator: ARM-file.o instruction.o register.o emulator.o
#	g++ ARM-file.o instruction.o register.o emulator.o -o ARMEulator
#
#ARM-file.o: ARM-file.cc
#    g++ -c ARM-file.cc
#
#instruction.o: instruction.cc
#    g++ -c instruction.cc
#
#register.o: register.cc
#    g++ -c register.cc
#
#emulator.o: emulator.cc
#    g++ -c emulator.cc
#
#clean:
#    rm *o ARMEulator

#all:
#	g++ ARM-file.cc instruction.cc register.cc emulator.cc

# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-c -Wall

all: emulator

emulator: ARM-file.o instruction.o register.o emulator.o
	$(CC) ARM-file.o instruction.o register.o emulator.o -o armulate

ARM-file.o: ARM-file.cc
	$(CC) $(CFLAGS) ARM-file.cc

instruction.o: instruction.cc
	$(CC) $(CFLAGS) instruction.cc

register.o: register.cc
	$(CC) $(CFLAGS) register.cc

emulator.o: emulator.cc
	$(CC) $(CFLAGS) emulator.cc

clean:
	rm *o emulator