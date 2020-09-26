// IEC 18004 (QR) encoding
//

enum {                          // Error Correction Level
   QR_ECL_L = 'L',              // 01
   QR_ECL_M = 'M',              // 00
   QR_ECL_Q = 'Q',              // 11
   QR_ECL_H = 'H',              // 10
};

typedef struct {
   int len;                     // Data length
   const char *data;            // Data (can include nulls if required)
   unsigned char ver;           // Size of QR code (units) 1-40, or 0 for auto
   char ecl;                    // Error correction level L/M/Q/H, 0 is L (or better if same size code)
   unsigned char mask;          // Masking code 1-8 for modes 0-7, 0 for auto
   const char *mode;            // Character mode string
   unsigned int *widthp;        // Return width
   unsigned int eci;            // Coding indicator (0=auto)
   unsigned char fnc1;          // Function code 0-2
   unsigned char sam;           // Structured append 1-16 index
   unsigned char san;           // Structured append 1-16 total
   unsigned char noquiet:1;     // No quiet space included
   unsigned int padlen;         // Length of raw padding data to use
   const unsigned char *pad;    // Raw padding data to use
} qr_encode_t;
#define	qr_encode(...)	qr_encode_opts((qr_encode_t){__VA_ARGS__})
unsigned char *qr_encode_opts(qr_encode_t);

// Used internally, but this allows you to see what the automatic mode calculation comes up with
void qr_mode(char *mode, int ver, int len, const char *input);  // Work out a mode for input
