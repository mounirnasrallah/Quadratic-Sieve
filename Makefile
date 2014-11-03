
#FLAGS FOR COMPILATOR AND LIBRARY
CC=gcc
DEBUGFLAG=-g
CFLAGS=-I/usr/local/include -Wall
LDFLAGS=-lgmp
EXECLDFLAGS=-lmpfr
EXEC=simple-quadratic-sieve

#DIRECTORIES
SRCDIR=src
OBJDIR=obj
BINDIR=bin

#FILES
SOURCES=$(wildcard $(SRCDIR)/*.c)
INCLUDES=$(wildcard $(SRCDIR)/*.h)
OBJECTS:=$(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


.PHONY:all clean

all: $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC): $(OBJECTS)
	$(CC) $(DEBUGFLAG) -o $@ $^ $(CFLAGS) $(EXECLDFLAGS) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES)
	$(CC) $(DEBUGFLAG) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJDIR)/* $(BINDIR)/*
