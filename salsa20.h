#ifndef _SALSA20_H_
#define _SALSA20_H_

#include <stdint.h>
#include <stddef.h>

/**
 * Key size
 * Salsa20 only permits a 128-bit key or a 256-bit key, so these are
 * the only two options made available by this library.
 */
enum s20_keylen_t
{
  S20_KEYLEN_256,
  S20_KEYLEN_128
};

/**
 * Performs up to 2^32-1 bytes of encryption or decryption under a
 * 128- or 256-bit key in blocks of arbitrary size. Permits seeking
 * to any point within a stream.
 *
 * key    Pointer to either a 128-bit or 256-bit key.
 *        No key-derivation function is applied to this key, and no
 *        entropy is gathered. It is expected that this key is already
 *        appropriate for direct use by the Salsa20 algorithm.
 *
 * keylen Length of the key.
 *        Must be S20_KEYLEN_256 or S20_KEYLEN_128.
 *
 * nonce  Pointer to an 8-byte nonce.
 *        Does not have to be random, but must be unique for every
 *        message under a single key. Nonce reuse destroys message
 *        confidentiality.
 *
 * si     Stream index.
 *        The position within the stream. When encrypting/decrypting
 *        a message sequentially from beginning to end in fixed-size
 *        chunks of length L, this value is increased by L on every
 *        call. Care must be taken not to select values that cause
 *        overlap. Example: encrypting 1000 bytes at index 100, and
 *        then encrypting 1000 bytes at index 500. Doing so will
 *        result in keystream reuse, which destroys message
 *        confidentiality.
 *
 * buf    The data to encrypt or decrypt.
 *
 * len    Length of the data in buf.
 *
 * This function returns either 0 or 1.
 * A return of 0 indicates that basic sanity checking on parameters
 * succeeded and encryption/decryption was performed.
 * A return of 1 indicates that basic sanity checking on parameters
 * failed and encryption/decryption was not performed.
 */
int s20_crypt(uint8_t *key,
              enum s20_keylen_t keylen,
              uint8_t nonce[static 8],
              uint32_t si,
              uint8_t *buf,
              uint32_t len);

#endif
