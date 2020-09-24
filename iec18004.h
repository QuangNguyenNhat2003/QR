// IEC 18004 (QR) encoding
//

enum
{                               // Error Correction Level
   QR_ECL_L,                    // 01
   QR_ECL_M,                    // 00
   QR_ECL_Q,                    // 11
   QR_ECL_H,                    // 10
};


// Encode to QR code, output is malloc'd, width*width bytes where bit 0 means black
// widthp is for writing back the width
// mode is string of A (alphanumeric), N (numeric), 8 (8 bit), or K (Kanji) for each input character, last code repeats so can be one letter, NULL means auto
// fnc1 can be 1 or 2 for 1st or 2nd FNC code
// eci is character coding, 0 is auto which sets 26 (UTF-8) if any high bit set bytes are in the data
// mask is 1-8 for masks 1-7 and 0. Use 0 for auto mask
// ecl is as above, 0 is medium
// data is len bytes and assumed to be UTF-8. Any high byte characters cause an ECI for UTF-8 to be included
// ver is 1-40 for barcode size, or 0 for auto
// NULL return on error
// sam and san are structured append, 1-16 for code m of n
unsigned char *qr_encode (int len, const char *data, int ver, int ecl, int mask, const char *mode, int *widthp, int eci, int fnc1,int sam,int san);

// Used internally, but this allows you to see what the automatic mode calculation comes up with
void qr_mode (char *mode, int ver, int len, const char *input); // Work out a mode for input
