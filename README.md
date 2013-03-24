Salsa20
=======

This is an implementation of the Salsa20 stream cipher, designed by
Daniel J Bernstein and a part of the eSTREAM stream cipher portfolio.
This implementation is a naive translation from specification to
source with a focus on terseness and readability.

It requires a minimal set of headers (`stdint.h` and `stddef.h` only)
and no special libraries.


Disclaimer
----------

1. I am not a cryptographer, and this is my first time implementing
   any sort of cryptographic algorithm.
2. This library has not been thoroughly tested or vetted by anybody
   yet.
3. This library does not provide key expansion, message
   authentication, or digest functionality.


Pseudo-code example
--------------------

For a compile-and-run example of byte-by-byte encryption/decryption of
stdin to stdout (warning: slow!), please see `cli.c`.

To encrypt a 5000-byte stream in 500-byte pieces sequentially:

    uint8_t *key = 128_bit_key_generation();
    uint8_t *nonce = unique_message_number();
    unsigned len = 500;
    uint8_t buf[len];

    // Position (in bytes) in the stream
    uint32_t sindex = 0;

    for (sindex = 0; sindex < 5000; sindex += len) {
        // recv 'len' bytes into 'buf'
        s20_crypt(key, S20_KEYLEN_128, nonce, sindex, buf, len);
        // copy 'len' bytes from 'buf' elsewhere
    }

Encryption and decryption is identical in Salsa20, therefore there is
a single function provided by this library: `s20_crypt`.


Usage
-----

`make tests` will generate an executable called `tests` containing
all unit tests and test vectors.

`make clean` will remove the `tests` executable and all object files.

`make cli` will compile the sample program.
