#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "salsa20.h"

/**
 * This file is a really simple test that can be used to gauge
 * performance of this implementation on your system.
 * 100 MB (literally 100,000,000 bytes) is allocated, encrypted, and
 * then decrypted (200 MB total)
 */

int main()
{
  uint32_t len = 100000000;

  // We will encrypt 100 MB of memory
  uint8_t *data = (uint8_t *) malloc(len);
  if (data == NULL) {
    puts("100 MB malloc failed");
    exit(1);
  }

  uint8_t key[16] = { 0 };
  uint8_t nonce[8] = { 0 };
  if (s20_crypt(key, S20_KEYLEN_128, nonce, 0, data, len))
      puts("Error: encryption failed");

  if (s20_crypt(key, S20_KEYLEN_128, nonce, 0, data, len))
      puts("Error: decryption failed");

  return 0;
}
