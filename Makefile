all: qr

update:
	git submodule update --remote --merge

qr: qr.c Reedsol/reedsol.o iec18004.o
	gcc -O -o $@ $< Reedsol/reedsol.o iec18004.o -lpopt -IReedsol -g --std=gnu99 -I/usr/local/include -L/usr/local/lib

iec18004.o: iec18004.c
	gcc -O -c -o $@ $< -IReedsol -DLIB -g --std=gnu99 -I/usr/local/include

Reedsol/reedsol.o: Reedsol/reedsol.c
	make -C Reedsol

