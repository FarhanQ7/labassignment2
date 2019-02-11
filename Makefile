##########################################
   
   #   Makefile for CS402 Lab 2
   #      
   #      ##########################################

## Compiler, tools and options
CC         = gcc
LINKER     = gfortran
CCFLAGS    = -g
LDFLAGS    = 

## Notice: Change below to your own LAPACK installation from Lab 1.
LAPACKHOME = /home/ffquresh/lapack-3.8.0


INCPATH    = -I$(LAPACKHOME)/CBLAS/include
LIBS       = -L$(LAPACKHOME) -lcblas -lrefblas 


## Files (Assuming your source code is named lab2.c)
OBJECTS    = lab2.o 
TARGET     = lab2


## Implicit rules
.SUFFIXES: .c
	.c.o:
		$(CC) -c $(CCFLAGS) $(INCPATH) $<


## Build rules
all: $(TARGET)

$(TARGET): $(OBJECTS)
		$(LINKER) -o $@  $(OBJECTS)  $(CCFLAGS) $(LDFLAGS) $(LIBS)

## Clean all .o and executable files
clean:
		rm -f $(OBJECTS) $(TARGET)
			rm -f *~ core

