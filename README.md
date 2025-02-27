# QR 

## Forked Repository

This projet is forked from [revk/QR](https://github.com/revk/QR.git), an IEC18004 (QR) 2D barcode geneartion library and command-line tool

## Reason for Forking

The purpose of this fork is to remove all image-processing functionalities and retain only text-based QR code output. This ensures a lightweight implementation that focuses solely on generating Qr codes in text format, without dependencies on image formats such as PNG, SVG, GIF, EPS, or PS.

## Changes Implemented

- Removed the Image submodule and all related code.

- Updated the Makefile to exclude any image-processing libraries.

- Ensured that text-based output functionality remains intact and works as expected.

## Description

QR code generation C libraty and command-line tool

This library efficiently generates QR codes in multiple formats, including text, binary, hex, and KiCad module. See --help for more details.

The command-line tool is designed for Linux, but the library has been successfully used under ESP-IDF and other platforms.

The libraty allows custom padding in the QR code, for "hidden" data, but also provides mapping to the actual pixels so you can adjust padding to make patterns in the final bar code which are still correct ECC. E.g.

![space-invaders](https://WWW.ME.UK/spaceinvader.png)