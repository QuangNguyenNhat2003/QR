all: qr

update:
	git submodule update --remote --merge

qr: qr.c Image/image.o Reedsol/reedsol.o iec18004.o
	cc -O -o $@ $< Image/image.o Reedsol/reedsol.o iec18004.o -lpopt -lz -IImage -IReedsol -g --std=gnu99

iec18004.o: iec18004.c
	cc -O -c -o $@ $< -IReedsol -IAXL -DLIB -g --std=gnu99

Image/image.o: Image/image.c
	make -C Image

Reedsol/reedsol.o: Reedsol/reedsol.c
	make -C Reedsol

AXL/axl.o: AXL/axl.c
	make -C AXL
