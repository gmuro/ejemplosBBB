#==========================================================================
# Autores:
# Gustavo Muro gustmuro@gmail.com
# Luciano Diamand lucianodiamand@yahoo.com
#==========================================================================
 
CFLAGS = -Wall -g
CROSS_COMPILE ?= arm-linux-
CC = ${CROSS_COMPILE}gcc
EXECUTABLE = adc
OBJECTS = main.o
OBIN = bin
ODIR = obj

OBJ = $(patsubst %,$(ODIR)/%,$(OBJECTS))

all: folders $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OBIN)/$(EXECUTABLE)

$(ODIR)/%.o : %.c
	$(CC) -g -c -o $@ $< $(CFLAGS)

clean:
	$(RM) -f $(OBIN)/$(EXECUTABLE) $(ODIR)/*.o

folders:
	mkdir -p $(OBIN) $(ODIR)
