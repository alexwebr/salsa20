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

On the BSDs you will need `gmake` and `bash`.

`make tests` will generate an executable called `tests` containing
all unit tests and test vectors. This may need several minutes and
upwards of 1GB of memory. Once compiled, they are fast to execute.

`make clean` will remove the `tests` executable and all object files.

`make cli` will compile the sample program.

`make perf` will compile a simple performance test. It will encrypt
and then decrypt 100 MB (literally 100,000,000 bytes) on the heap and
then exit (200 MB total).

All commits from October 18th onwards should be signed under my GPG
public key. This can be seen with `git log --show-signature`.


Performance
-----------

While not originally designed for speed, this implementation performs
reasonably well with compiler optimizations enabled. This
implementation does not make use of CPU-specific performance features,
so it most likely does not compete with optimized implementations.

**NOTE**: These numbers were obtained with the performance test
included with this implementation. I'm not sure if this is an
appropriate way to benchmark a stream cipher. If it is not, please
let me know!

**Core i7**: 1.123 seconds, or 178 MB/s

**Pentium T4400**: 1.558 seconds, or 128 MB/s

**ARM Cortex-A8 at 1GHz (BeagleBone Black Rev. A5A)**: 6.912 seconds, or 28 MB/s
