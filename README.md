# QR
QR code generation C library and command line.

Efficient output, and wide variety of output formats including text, binary, hex, KiCad module. See --help for more info.

Command line is aimed at linux, but the library has been used sucessfully under ESP IDF and other platforms.

The library allows custom padding in the QR code, for "hidden" data, but also provides mapping to the actual pixels so you can adjust padding to make patterns in the final bar code which are still correct ECC. E.g.

![space-invaders](https://WWW.ME.UK/spaceinvader.png)