#
# Sample Makefile for C programming examples
#
CC = gcc
CFLAGS = -Wall -Werror
RM = /bin/rm
RMFLAGS = -f
SRCS =  zero.c \
	zero_soln.c \
	one.c \
	two.c \
	three.c

OBJS = $(SRCS:.c=.o)
PROGS = $(SRCS:.c=)

# This is the multi-executable target...
# If you type 'make' at the command line it will build
# all programs
.PHONY: all

all: $(PROGS)

$(PROGS): %: %.o Makefile
	$(CC) $< -o $@

# Type 'make zero' just to build program one
#zero: zero.o
#	$(CC) zero.o -o zero

# Type 'make zero_soln' just to build program one
#zero_soln: zero_soln.o
#	$(CC) zero_soln.o -o zero_soln

# Type 'make one' just to build program one
#one: one.o
#	$(CC) one.o -o one

# Type 'make two' just to build program two
#two: two.o
#	$(CC) two.o -o two

# Type 'make two' just to build program three
#three: three.o
#	$(CC) three.o -o three

# This line will convert any .c file to a .o file.
%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $<

# Type 'make clean' up the subdirectory...
# Be Very Careful Not To Haphazzardly Make Changes!!!!!!!
clean:
	$(RM) $(RMFLAGS) $(PROGS) $(OBJS) 


