#include <stdio.h>
#include <string.h>
#include "salsa20.h"

int main(int argc, char *argv[])
{
  if (!(argc == 3 && strlen(argv[1]) == 16 && strlen(argv[2]) == 8)) {
    puts("salsa20 demo program");
    puts("");
    puts("Will encrypt or decrypt from standard input (the operation");
    puts("is reversible for salsa20) until EOF, using a 128-bit key.");
    puts("WARNING: Do not use this program for serious security. No");
    puts("         appropriate key expansion function is used for");
    puts("         converting a password to a cryptographic key.");
    puts("         Use this program as a demo ONLY.");
    puts("");
    puts("Usage:");
    puts("salsa20 <16-character key> <8-character nonce>");
    return 1;
  }

  int in;
  // Stream index
  uint32_t si = 0;
  while ((in = getchar()) != EOF) {
    uint8_t c = in;
    // Encrypt a single character at a time
    //                          key     128-bit key                 nonce  encrypt one byte
    if (s20_crypt((uint8_t *) argv[1], S20_KEYLEN_128, (uint8_t *) argv[2], si++, &c, 1))
      puts("Error: encryption failed");
    putchar(c);
  }

  return 0;
}
