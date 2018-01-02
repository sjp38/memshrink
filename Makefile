.PHONY: clean help

APP	+= domlock

IDIR	:= include
CC	:= gcc
CFLAGS	:= -g -I$(IDIR) -O3 -Wall -Werror -std=gnu99
LIBS	:=
ODIR	:= ./

_OBJ	:= domlock.o
OBJ	:= $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.s: %.c $(DEPS)
	$(CC) -S -o $@ $< $(CFLAGS)


$(APP): $(OBJ)
	$(CC) -o $@ $^ $(LIBS)


all: $(APP)

clean:
	rm -f $(ODIR)/*.o $(ODIR)/*.s $(APP)


help:
	@echo "usage: make <target>"
	@echo ""
	@echo "targets: $(APP)"
	@echo ""
