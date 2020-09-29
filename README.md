# QR
QR code generation C library and command line.

Efficient output, and wide variety of output formats including png, svg, eps, ps, text, binary, hex, and even a data URL format for png. See --help for more info.

The library allows custom padding in the QR code, for "hidden" data, but also provides mapping to the actual pixels so you can adjust padding to make patterns in the final bar code which are still correct ECC. E.g.

![space-invaders](https://WWW.ME.UK/spaceinvader.png)

There is even a coloured PNG format to allow you to see what parts are data, ecc, padding, control, etc.

![colour-qr-code](https://WWW.ME.UK/exampleqr.png)
