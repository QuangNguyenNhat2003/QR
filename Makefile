all: git qr

qr: qr.c Image/image.o Reedsol/reedsol.o iec18004.o
	cc -O -o $@ $< Image/image.o Reedsol/reedsol.o iec18004.o -lpopt -lz -IImage -IReedsol

iec18004.o: iec18004.c AXL/axl.o SQLlib/sqllib.o
	cc -O -c -o $@ $< -IReedsol -IAXL -ISQLlib AXL/axl.o SQLlib/sqllib.o -DLIB

Image/image.o: Image/image.c
	make -C Image

Reedsol/reedsol.o: Reedsol/reedsol.c
	make -C Reedsol

AXL/axl.o: AXL/axl.c
	make -C AXL

SQLlib/sqllib.o: SQLlib/sqllib.c
	make -C SQLlib

git:
	git submodule update --init
