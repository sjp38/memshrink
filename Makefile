.PHONY: clean help

APPS	+= domlock domfaults

DOML	:= domlock
DOMF	:= domfaults

IDIR	:= include
CC	:= gcc
CFLAGS	:= -g -I$(IDIR) -O3 -Wall -Werror -std=gnu99
LIBS	:=
ODIR	:= ./

_OBJ_ML	:= domlock.o
OBJ_ML	:= $(patsubst %,$(ODIR)/%,$(_OBJ_ML))

_OBJ_MF	:= domfaults.o
OBJ_MF	:= $(patsubst %,$(ODIR)/%,$(_OBJ_MF))

all: $(APPS)

$(DOML): $(OBJ_ML)
	$(CC) -o $@ $^ $(LIBS)

$(DOMF): $(OBJ_MF)
	$(CC) -o $@ $^ $(LIBS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.s: %.c $(DEPS)
	$(CC) -S -o $@ $< $(CFLAGS)


clean:
	rm -f $(ODIR)/*.o $(ODIR)/*.s $(APPS)


help:
	@echo "usage: make <target>"
	@echo ""
	@echo "targets: $(APPS)"
	@echo ""
