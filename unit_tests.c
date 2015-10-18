#include "aunit.h"
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

// Include the C file directly, so we can access the otherwise static
// functions
#include "salsa20.h"
#include "salsa20.c"

au_main

{ // test of rotl function, implementing DJB's definition of '<<<'
  au_eq("left rotation (<<<) test", rotl(0xc0a8787e, 5), 0x150f0fd8);
}


// quarterround function tests

{ // First quarterround example provided in Salsa20 specification
  uint32_t s[4] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
  s20_quarterround(&s[0], &s[1], &s[2], &s[3]);
  au_eq("quarterround example 1 word 1", s[0], 0x00000000);
  au_eq("quarterround example 1 word 2", s[1], 0x00000000);
  au_eq("quarterround example 1 word 3", s[2], 0x00000000);
  au_eq("quarterround example 1 word 4", s[3], 0x00000000);
}

{ // Second quarterround example provided in Salsa20 specification
  uint32_t s[4] = { 0x00000001, 0x00000000, 0x00000000, 0x00000000 };
  s20_quarterround(&s[0], &s[1], &s[2], &s[3]);
  au_eq("quarterround example 2 word 1", s[0], 0x08008145);
  au_eq("quarterround example 2 word 2", s[1], 0x00000080);
  au_eq("quarterround example 2 word 3", s[2], 0x00010200);
  au_eq("quarterround example 2 word 4", s[3], 0x20500000);
}

{ // Third quarterround example provided in Salsa20 specification
  uint32_t s[4] = { 0x00000000, 0x00000001, 0x00000000, 0x00000000 };
  s20_quarterround(&s[0], &s[1], &s[2], &s[3]);
  au_eq("quarterround example 3 word 1", s[0], 0x88000100);
  au_eq("quarterround example 3 word 2", s[1], 0x00000001);
  au_eq("quarterround example 3 word 3", s[2], 0x00000200);
  au_eq("quarterround example 3 word 4", s[3], 0x00402000);
}

{ // Fourth quarterround example provided in Salsa20 specification
  uint32_t s[4] = { 0x00000000, 0x00000000, 0x00000001, 0x00000000 };
  s20_quarterround(&s[0], &s[1], &s[2], &s[3]);
  au_eq("quarterround example 4 word 1", s[0], 0x80040000);
  au_eq("quarterround example 4 word 2", s[1], 0x00000000);
  au_eq("quarterround example 4 word 3", s[2], 0x00000001);
  au_eq("quarterround example 4 word 4", s[3], 0x00002000);
}

{ // Fifth quarterround example provided in Salsa20 specification
  uint32_t s[4] = { 0x00000000, 0x00000000, 0x00000000, 0x00000001 };
  s20_quarterround(&s[0], &s[1], &s[2], &s[3]);
  au_eq("quarterround example 5 word 1", s[0], 0x00048044);
  au_eq("quarterround example 5 word 2", s[1], 0x00000080);
  au_eq("quarterround example 5 word 3", s[2], 0x00010000);
  au_eq("quarterround example 5 word 4", s[3], 0x20100001);
}

{ // Sixth quarterround example provided in Salsa20 specification
  uint32_t s[4] = { 0xe7e8c006, 0xc4f9417d, 0x6479b4b2, 0x68c67137 };
  s20_quarterround(&s[0], &s[1], &s[2], &s[3]);
  au_eq("quarterround example 6 word 1", s[0], 0xe876d72b);
  au_eq("quarterround example 6 word 2", s[1], 0x9361dfd5);
  au_eq("quarterround example 6 word 3", s[2], 0xf1460244);
  au_eq("quarterround example 6 word 4", s[3], 0x948541a3);
}

{ // Seventh quarterround example provided in Salsa20 specification
  uint32_t s[4] = { 0xd3917c5b, 0x55f1c407, 0x52a58a7a, 0x8f887a3b };
  s20_quarterround(&s[0], &s[1], &s[2], &s[3]);
  au_eq("quarterround example 7 word 1", s[0], 0x3e2f308c);
  au_eq("quarterround example 7 word 2", s[1], 0xd90a8f36);
  au_eq("quarterround example 7 word 3", s[2], 0x6ab2a923);
  au_eq("quarterround example 7 word 4", s[3], 0x2883524c);
}


// rowround function tests

{ // First rowround example provided in Salsa20 specification
  uint32_t s[16] = { 0x00000001, 0x00000000, 0x00000000, 0x00000000,
                     0x00000001, 0x00000000, 0x00000000, 0x00000000,
                     0x00000001, 0x00000000, 0x00000000, 0x00000000,
                     0x00000001, 0x00000000, 0x00000000, 0x00000000 };
  s20_rowround(s);
  au_eq("rowround example 1 word 01", s[0], 0x08008145);
  au_eq("rowround example 1 word 02", s[1], 0x00000080);
  au_eq("rowround example 1 word 03", s[2], 0x00010200);
  au_eq("rowround example 1 word 04", s[3], 0x20500000);
  au_eq("rowround example 1 word 05", s[4], 0x20100001);
  au_eq("rowround example 1 word 06", s[5], 0x00048044);
  au_eq("rowround example 1 word 07", s[6], 0x00000080);
  au_eq("rowround example 1 word 08", s[7], 0x00010000);
  au_eq("rowround example 1 word 09", s[8], 0x00000001);
  au_eq("rowround example 1 word 10", s[9], 0x00002000);
  au_eq("rowround example 1 word 11", s[10], 0x80040000);
  au_eq("rowround example 1 word 12", s[11], 0x00000000);
  au_eq("rowround example 1 word 13", s[12], 0x00000001);
  au_eq("rowround example 1 word 14", s[13], 0x00000200);
  au_eq("rowround example 1 word 15", s[14], 0x00402000);
  au_eq("rowround example 1 word 16", s[15], 0x88000100);
}

{ // Second rowround example provided in Salsa20 specification
  uint32_t s[16] = { 0x08521bd6, 0x1fe88837, 0xbb2aa576, 0x3aa26365,
                     0xc54c6a5b, 0x2fc74c2f, 0x6dd39cc3, 0xda0a64f6,
                     0x90a2f23d, 0x067f95a6, 0x06b35f61, 0x41e4732e,
                     0xe859c100, 0xea4d84b7, 0x0f619bff, 0xbc6e965a };
  s20_rowround(s);
  au_eq("rowround example 2 word 01", s[0], 0xa890d39d);
  au_eq("rowround example 2 word 02", s[1], 0x65d71596);
  au_eq("rowround example 2 word 03", s[2], 0xe9487daa);
  au_eq("rowround example 2 word 04", s[3], 0xc8ca6a86);
  au_eq("rowround example 2 word 05", s[4], 0x949d2192);
  au_eq("rowround example 2 word 06", s[5], 0x764b7754);
  au_eq("rowround example 2 word 07", s[6], 0xe408d9b9);
  au_eq("rowround example 2 word 08", s[7], 0x7a41b4d1);
  au_eq("rowround example 2 word 09", s[8], 0x3402e183);
  au_eq("rowround example 2 word 10", s[9], 0x3c3af432);
  au_eq("rowround example 2 word 11", s[10], 0x50669f96);
  au_eq("rowround example 2 word 12", s[11], 0xd89ef0a8);
  au_eq("rowround example 2 word 13", s[12], 0x0040ede5);
  au_eq("rowround example 2 word 14", s[13], 0xb545fbce);
  au_eq("rowround example 2 word 15", s[14], 0xd257ed4f);
  au_eq("rowround example 2 word 16", s[15], 0x1818882d);
}


// columnround function tests

{ // First columnround example provided in the Salsa20 specification
  uint32_t s[16] = { 0x00000001, 0x00000000, 0x00000000, 0x00000000,
                     0x00000001, 0x00000000, 0x00000000, 0x00000000,
                     0x00000001, 0x00000000, 0x00000000, 0x00000000,
                     0x00000001, 0x00000000, 0x00000000, 0x00000000 };
  s20_columnround(s);
  au_eq("columnround example 1 word 01", s[0], 0x10090288);
  au_eq("columnround example 1 word 02", s[1], 0x00000000);
  au_eq("columnround example 1 word 03", s[2], 0x00000000);
  au_eq("columnround example 1 word 04", s[3], 0x00000000);
  au_eq("columnround example 1 word 05", s[4], 0x00000101);
  au_eq("columnround example 1 word 06", s[5], 0x00000000);
  au_eq("columnround example 1 word 07", s[6], 0x00000000);
  au_eq("columnround example 1 word 08", s[7], 0x00000000);
  au_eq("columnround example 1 word 09", s[8], 0x00020401);
  au_eq("columnround example 1 word 10", s[9], 0x00000000);
  au_eq("columnround example 1 word 11", s[10], 0x00000000);
  au_eq("columnround example 1 word 12", s[11], 0x00000000);
  au_eq("columnround example 1 word 13", s[12], 0x40a04001);
  au_eq("columnround example 1 word 14", s[13], 0x00000000);
  au_eq("columnround example 1 word 15", s[14], 0x00000000);
  au_eq("columnround example 1 word 16", s[15], 0x00000000);
}

{ // Second columnround example provided in the Salsa20 specification
  uint32_t s[16] = { 0x08521bd6, 0x1fe88837, 0xbb2aa576, 0x3aa26365,
                     0xc54c6a5b, 0x2fc74c2f, 0x6dd39cc3, 0xda0a64f6,
                     0x90a2f23d, 0x067f95a6, 0x06b35f61, 0x41e4732e,
                     0xe859c100, 0xea4d84b7, 0x0f619bff, 0xbc6e965a };
  s20_columnround(s);
  au_eq("columnround example 2 word 01", s[0], 0x8c9d190a);
  au_eq("columnround example 2 word 02", s[1], 0xce8e4c90);
  au_eq("columnround example 2 word 03", s[2], 0x1ef8e9d3);
  au_eq("columnround example 2 word 04", s[3], 0x1326a71a);
  au_eq("columnround example 2 word 05", s[4], 0x90a20123);
  au_eq("columnround example 2 word 06", s[5], 0xead3c4f3);
  au_eq("columnround example 2 word 07", s[6], 0x63a091a0);
  au_eq("columnround example 2 word 08", s[7], 0xf0708d69);
  au_eq("columnround example 2 word 09", s[8], 0x789b010c);
  au_eq("columnround example 2 word 10", s[9], 0xd195a681);
  au_eq("columnround example 2 word 11", s[10], 0xeb7d5504);
  au_eq("columnround example 2 word 12", s[11], 0xa774135c);
  au_eq("columnround example 2 word 13", s[12], 0x481c2027);
  au_eq("columnround example 2 word 14", s[13], 0x53a8e4b5);
  au_eq("columnround example 2 word 15", s[14], 0x4c1f89c5);
  au_eq("columnround example 2 word 16", s[15], 0x3f78c9c8);
}


// doubleround function tests

{ // First doubleround example provided by Salsa20 specification
  uint32_t s[16] = { 0x00000001, 0x00000000, 0x00000000, 0x00000000,
                     0x00000000, 0x00000000, 0x00000000, 0x00000000,
                     0x00000000, 0x00000000, 0x00000000, 0x00000000,
                     0x00000000, 0x00000000, 0x00000000, 0x00000000 };
  s20_doubleround(s);
  au_eq("doubleround example 1 word 01", s[0], 0x8186a22d);
  au_eq("doubleround example 1 word 02", s[1], 0x0040a284);
  au_eq("doubleround example 1 word 03", s[2], 0x82479210);
  au_eq("doubleround example 1 word 04", s[3], 0x06929051);
  au_eq("doubleround example 1 word 05", s[4], 0x08000090);
  au_eq("doubleround example 1 word 06", s[5], 0x02402200);
  au_eq("doubleround example 1 word 07", s[6], 0x00004000);
  au_eq("doubleround example 1 word 08", s[7], 0x00800000);
  au_eq("doubleround example 1 word 09", s[8], 0x00010200);
  au_eq("doubleround example 1 word 10", s[9], 0x20400000);
  au_eq("doubleround example 1 word 11", s[10], 0x08008104);
  au_eq("doubleround example 1 word 12", s[11], 0x00000000);
  au_eq("doubleround example 1 word 13", s[12], 0x20500000);
  au_eq("doubleround example 1 word 14", s[13], 0xa0000040);
  au_eq("doubleround example 1 word 15", s[14], 0x0008180a);
  au_eq("doubleround example 1 word 16", s[15], 0x612a8020);
}

{ // Second doubleround example provided by Salsa20 specification
  uint32_t s[16] = { 0xde501066, 0x6f9eb8f7, 0xe4fbbd9b, 0x454e3f57,
                     0xb75540d3, 0x43e93a4c, 0x3a6f2aa0, 0x726d6b36,
                     0x9243f484, 0x9145d1e8, 0x4fa9d247, 0xdc8dee11,
                     0x054bf545, 0x254dd653, 0xd9421b6d, 0x67b276c1 };
  s20_doubleround(s);
  au_eq("doubleround example 2 word 01", s[0], 0xccaaf672);
  au_eq("doubleround example 2 word 02", s[1], 0x23d960f7);
  au_eq("doubleround example 2 word 03", s[2], 0x9153e63a);
  au_eq("doubleround example 2 word 04", s[3], 0xcd9a60d0);
  au_eq("doubleround example 2 word 05", s[4], 0x50440492);
  au_eq("doubleround example 2 word 06", s[5], 0xf07cad19);
  au_eq("doubleround example 2 word 07", s[6], 0xae344aa0);
  au_eq("doubleround example 2 word 08", s[7], 0xdf4cfdfc);
  au_eq("doubleround example 2 word 09", s[8], 0xca531c29);
  au_eq("doubleround example 2 word 10", s[9], 0x8e7943db);
  au_eq("doubleround example 2 word 11", s[10], 0xac1680cd);
  au_eq("doubleround example 2 word 12", s[11], 0xd503ca00);
  au_eq("doubleround example 2 word 13", s[12], 0xa74b2ad6);
  au_eq("doubleround example 2 word 14", s[13], 0xbc331c5c);
  au_eq("doubleround example 2 word 15", s[14], 0x1dda24c7);
  au_eq("doubleround example 2 word 16", s[15], 0xee928277);
}


// littleendian function tests

{ // First littleendian example provided by Salsa20 specification
  uint8_t arr[] = {0, 0, 0, 0};
  uint32_t result = s20_littleendian(arr);
  au_eq("littleendian example 1", result, 0x00000000);
}

{ // Second littleendian example provided by Salsa20 specification
  uint8_t arr[] = {86, 75, 30, 9};
  uint32_t result = s20_littleendian(arr);
  au_eq("littleendian example 2", result, 0x091e4b56);
}

{ // Third littleendian example provided by Salsa20 specification
  uint8_t arr[] = {255, 255, 255, 250};
  uint32_t result = s20_littleendian(arr);
  au_eq("littleendian example 3", result, 0xfaffffff);
}


// Not part of spec, but part of implementation: little-endian reversal

{ // First rev_littleedian test
  uint8_t arr[] = { 0xFF, 0xFF, 0xFF, 0xFF};
  s20_rev_littleendian(arr, 0x00000000);
  au_eq("rev_littleendian test 1 byte 1", arr[0], 0);
  au_eq("rev_littleendian test 1 byte 2", arr[1], 0);
  au_eq("rev_littleendian test 1 byte 3", arr[2], 0);
  au_eq("rev_littleendian test 1 byte 4", arr[3], 0);
}

{ // Second rev_littleedian test
  uint8_t arr[] = { 0, 0, 0, 0};
  s20_rev_littleendian(arr, 0xfaffffff);
  au_eq("rev_littleendian test 2 byte 1", arr[0], 255);
  au_eq("rev_littleendian test 2 byte 2", arr[1], 255);
  au_eq("rev_littleendian test 2 byte 3", arr[2], 255);
  au_eq("rev_littleendian test 2 byte 4", arr[3], 250);
}

{ // Third rev_littleedian test
  uint8_t arr[] = { 0, 0, 0, 0};
  s20_rev_littleendian(arr, 0x091e4b56);
  au_eq("rev_littleendian test 3 byte 1", arr[0], 86);
  au_eq("rev_littleendian test 3 byte 2", arr[1], 75);
  au_eq("rev_littleendian test 3 byte 3", arr[2], 30);
  au_eq("rev_littleendian test 3 byte 4", arr[3], 9);
}


// the Salsa20 'core' hash function

{ // First hash example provided by the Salsa20 specification
  uint8_t input[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  uint8_t expected[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  s20_hash(input);
  au_eq("core hash example 1", memcmp(input, expected, 64), 0);
}

{ // Second hash example provided by the Salsa20 specification
  uint8_t input[] = {
    211, 159, 13, 115, 76, 55, 82, 183, 3, 117, 222, 37, 191, 187, 234, 136,
    49, 237, 179, 48, 1, 106, 178, 219, 175, 199, 166, 48, 86, 16, 179, 207,
    31, 240, 32, 63, 15, 83, 93, 161, 116, 147, 48, 113, 238, 55, 204, 36,
    79, 201, 235, 79, 3, 81, 156, 47, 203, 26, 244, 243, 88, 118, 104, 54 };
  uint8_t expected[] = {
    109, 42, 178, 168, 156, 240, 248, 238, 168, 196, 190, 203, 26, 110, 170, 154,
    29, 29, 150, 26, 150, 30, 235, 249, 190, 163, 251, 48, 69, 144, 51, 57,
    118, 40, 152, 157, 180, 57, 27, 94, 107, 42, 236, 35, 27, 111, 114, 114,
    219, 236, 232, 135, 111, 155, 110, 18, 24, 232, 95, 158, 179, 19, 48, 202 };
  s20_hash(input);
  au_eq("core hash example 2", memcmp(input, expected, 64), 0);
}

{ // Third hash example provided by the Salsa20 specification
  uint8_t input[] = {
    88, 118, 104, 54, 79, 201, 235, 79, 3, 81, 156, 47, 203, 26, 244, 243,
    191, 187, 234, 136, 211, 159, 13, 115, 76, 55, 82, 183, 3, 117, 222, 37,
    86, 16, 179, 207, 49, 237, 179, 48, 1, 106, 178, 219, 175, 199, 166, 48,
    238, 55, 204, 36, 31, 240, 32, 63, 15, 83, 93, 161, 116, 147, 48, 113 };
  uint8_t expected[] = {
    179, 19, 48, 202, 219, 236, 232, 135, 111, 155, 110, 18, 24, 232, 95, 158,
    26, 110, 170, 154, 109, 42, 178, 168, 156, 240, 248, 238, 168, 196, 190, 203,
    69, 144, 51, 57, 29, 29, 150, 26, 150, 30, 235, 249, 190, 163, 251, 48,
    27, 111, 114, 114, 118, 40, 152, 157, 180, 57, 27, 94, 107, 42, 236, 35 };
  s20_hash(input);
  au_eq("core hash example 2", memcmp(input, expected, 64), 0);
}


// the 128- and 256-bit key expansion functions

{ // Only 16-byte example provided by the Salsa20 specification
  uint8_t keystream[64];
  uint8_t k[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
  uint8_t n[16] = {
    101, 102, 103, 104, 105, 106, 107, 108,
    109, 110, 111, 112, 113, 114, 115, 116 };
  uint8_t expected[64] = {
    39,173, 46,248, 30,200, 82, 17, 48, 67,254,239, 37, 18, 13,247,
    241,200, 61,144, 10, 55, 50,185, 6, 47,246,253,143, 86,187,225,
    134, 85,110,246,161,163, 43,235,231, 94,171, 51,145,214,112, 29,
    14,232, 5, 16,151,140,183,141,171, 9,122,181,104,182,177,193 };
  s20_expand16(k, n, keystream);
  au_eq("16-byte expansion example", memcmp(keystream, expected, 64), 0);
}

{ // Only 32-byte example provided by the Salsa20 specification
  uint8_t keystream[64];
  uint8_t k[32] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 201, 202, 203,
    204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216 };
  uint8_t n[16] = {
    101, 102, 103, 104, 105, 106, 107, 108,
    109, 110, 111, 112, 113, 114, 115, 116 };
  uint8_t expected[64] = {
    69, 37, 68, 39, 41, 15,107,193,255,139,122, 6,170,233,217, 98,
    89,144,182,106, 21, 51,200, 65,239, 49,222, 34,215,114, 40,126,
    104,197, 7,225,197,153, 31, 2,102, 78, 76,176, 84,245,246,184,
    177,160,133,130, 6, 72,149,119,192,195,132,236,234,103,246, 74 };
  s20_expand32(k, n, keystream);
  au_eq("32-byte expansion example", memcmp(keystream, expected, 64), 0);
}


// 128-bit encryption test

{ // Round-trip test
  uint8_t to_encrypt[64] = { 0 };
  uint8_t expected[64] = { 0 };
  uint8_t k[32] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
  // Encrypt, verify that string is different
  s20_crypt(k, S20_KEYLEN_128, n, 0, to_encrypt, 64);
  au_neq("128-bit encryption round-trip single neq", memcmp(to_encrypt, expected, 64), 0);
  // Decrypt, verify that string is once again the same
  s20_crypt(k, S20_KEYLEN_128, n, 0, to_encrypt, 64);
  au_eq("128-bit encryption round-trip single eq", memcmp(to_encrypt, expected, 64), 0);
}

{ // Multi-block test
  uint8_t to_encrypt[256] = { 0 };
  uint8_t expected[256] = { 0 };
  uint8_t k[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, };
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
  // Encrypt, verify that string is different
  s20_crypt(k, S20_KEYLEN_128, n, 0, to_encrypt, 256);
  au_neq("128-bit encryption round-trip multi neq", memcmp(to_encrypt, expected, 256), 0);
  // Decrypt, verify that string is once again the same
  s20_crypt(k, S20_KEYLEN_128, n, 0, to_encrypt, 256);
  au_eq("128-bit encryption round-trip multi eq", memcmp(to_encrypt, expected, 256), 0);
}

{ // Single-block offset test
  uint8_t to_encrypt[64] = { 0 };
  uint8_t expected[64] = { 0 };
  uint8_t k[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, };
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
  // Encrypt, verify that string is different
  s20_crypt(k, S20_KEYLEN_128, n, 2, to_encrypt, 64);
  au_neq("128-bit encryption single-block offset neq", memcmp(to_encrypt, expected, 64), 0);
  // Decrypt, verify that string is once again the same
  s20_crypt(k, S20_KEYLEN_128, n, 2, to_encrypt, 64);
  au_eq("128-bit encryption single-block offset eq", memcmp(to_encrypt, expected, 64), 0);
}

{ // Multi-block offset test
  uint8_t to_encrypt[256] = { 0 };
  uint8_t expected[256] = { 0 };
  uint8_t k[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, };
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
  // Encrypt, verify that string is different
  s20_crypt(k, S20_KEYLEN_128, n, 5, to_encrypt, 256);
  au_neq("128-bit encryption multi-block offset neq", memcmp(to_encrypt, expected, 256), 0);
  // Decrypt, verify that string is once again the same
  s20_crypt(k, S20_KEYLEN_128, n, 5, to_encrypt, 256);
  au_eq("128-bit encryption multi-block offset eq", memcmp(to_encrypt, expected, 256), 0);
}

{ // Multi-block stream seeking test, block boundary
  uint8_t to_encrypt[256] = { 0 };
  uint8_t expected[256] = { 0 };
  uint8_t k[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, };
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
  // Encrypt, verify that string is different
  s20_crypt(k, S20_KEYLEN_128, n, 128, to_encrypt+128, 128);
  s20_crypt(k, S20_KEYLEN_128, n, 0, to_encrypt, 128);
  au_neq("128-bit encryption seeking boundary neq", memcmp(to_encrypt, expected, 256), 0);
  // Decrypt, verify that string is once again the same
  s20_crypt(k, S20_KEYLEN_128, n, 0, to_encrypt, 256);
  au_eq("128-bit encryption seeking boundary eq", memcmp(to_encrypt, expected, 256), 0);
}

{ // Multi-block stream seeking test, not on block boundary
  uint8_t to_encrypt[256] = { 0 };
  uint8_t expected[256] = { 0 };
  uint8_t k[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, };
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
  // Encrypt, verify that string is different
  s20_crypt(k, S20_KEYLEN_128, n, 246, to_encrypt+246, 10);
  s20_crypt(k, S20_KEYLEN_128, n, 0, to_encrypt, 246);
  au_neq("128-bit encryption seeking non-boundary neq", memcmp(to_encrypt, expected, 256), 0);
  // Decrypt, verify that string is once again the same
  s20_crypt(k, S20_KEYLEN_128, n, 0, to_encrypt, 256);
  au_eq("128-bit encryption seeking non-boundary eq", memcmp(to_encrypt, expected, 256), 0);
}


// 256-bit encryption tests

{ // Round-trip test
  uint8_t to_encrypt[64] = { 0 };
  uint8_t expected[64] = { 0 };
  uint8_t k[32] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
  // Encrypt, verify that string is different
  s20_crypt(k, S20_KEYLEN_256, n, 0, to_encrypt, 64);
  au_neq("256-bit encryption round-trip single neq", memcmp(to_encrypt, expected, 64), 0);
  // Decrypt, verify that string is once again the same
  s20_crypt(k, S20_KEYLEN_256, n, 0, to_encrypt, 64);
  au_eq("256-bit encryption round-trip single eq", memcmp(to_encrypt, expected, 64), 0);
}

{ // Multi-block test
  uint8_t to_encrypt[256] = { 0 };
  uint8_t expected[256] = { 0 };
  uint8_t k[32] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
                    18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 30, 31, 32 };
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
  // Encrypt, verify that string is different
  s20_crypt(k, S20_KEYLEN_256, n, 0, to_encrypt, 256);
  s20_crypt(k, S20_KEYLEN_256, n, 0, to_encrypt, 256);
  s20_crypt(k, S20_KEYLEN_256, n, 0, to_encrypt, 256);
  au_neq("256-bit encryption round-trip multi neq", memcmp(to_encrypt, expected, 256), 0);
  // Decrypt, verify that string is once again the same
  s20_crypt(k, S20_KEYLEN_256, n, 0, to_encrypt, 256);
  au_eq("256-bit encryption round-trip multi eq", memcmp(to_encrypt, expected, 256), 0);
}

{ // Single-block offset test
  uint8_t to_encrypt[64] = { 0 };
  uint8_t expected[64] = { 0 };
  uint8_t k[32] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
                    18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 30, 31, 32 };
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
  // Encrypt, verify that string is different
  s20_crypt(k, S20_KEYLEN_256, n, 2, to_encrypt, 64);
  au_neq("256-bit encryption single-block offset neq", memcmp(to_encrypt, expected, 64), 0);
  // Decrypt, verify that string is once again the same
  s20_crypt(k, S20_KEYLEN_256, n, 2, to_encrypt, 64);
  au_eq("256-bit encryption single-block offset eq", memcmp(to_encrypt, expected, 64), 0);
}

{ // Multi-block offset test
  uint8_t to_encrypt[256] = { 0 };
  uint8_t expected[256] = { 0 };
  uint8_t k[32] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
                    18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 30, 31, 32 };
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
  // Encrypt, verify that string is different
  s20_crypt(k, S20_KEYLEN_256, n, 5, to_encrypt, 256);
  au_neq("256-bit encryption multi-block offset neq", memcmp(to_encrypt, expected, 256), 0);
  // Decrypt, verify that string is once again the same
  s20_crypt(k, S20_KEYLEN_256, n, 5, to_encrypt, 256);
  au_eq("256-bit encryption multi-block offset eq", memcmp(to_encrypt, expected, 256), 0);
}

{ // Multi-block stream seeking test, block boundary
  uint8_t to_encrypt[256] = { 0 };
  uint8_t expected[256] = { 0 };
  uint8_t k[32] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
                    18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 30, 31, 32 };
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
  // Encrypt, verify that string is different
  s20_crypt(k, S20_KEYLEN_256, n, 128, to_encrypt+128, 128);
  s20_crypt(k, S20_KEYLEN_256, n, 0, to_encrypt, 128);
  au_neq("256-bit encryption seeking boundary neq", memcmp(to_encrypt, expected, 256), 0);
  // Decrypt, verify that string is once again the same
  s20_crypt(k, S20_KEYLEN_256, n, 0, to_encrypt, 256);
  au_eq("256-bit encryption seeking boundary eq", memcmp(to_encrypt, expected, 256), 0);
}

{ // Multi-block stream seeking test, not on block boundary
  uint8_t to_encrypt[256] = { 0 };
  uint8_t expected[256] = { 0 };
  uint8_t k[32] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
                    18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 30, 31, 32 };
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
  // Encrypt, verify that string is different
  s20_crypt(k, S20_KEYLEN_256, n, 246, to_encrypt+246, 10);
  s20_crypt(k, S20_KEYLEN_256, n, 0, to_encrypt, 246);
  au_neq("256-bit encryption seeking non-boundary neq", memcmp(to_encrypt, expected, 256), 0);
  // Decrypt, verify that string is once again the same
  s20_crypt(k, S20_KEYLEN_256, n, 0, to_encrypt, 256);
  au_eq("256-bit encryption seeking non-boundary eq", memcmp(to_encrypt, expected, 256), 0);
}


// Tests for argument sanity checking

{ // All pointer values are null
  int status = s20_crypt(NULL, S20_KEYLEN_128, NULL, 0, NULL, 0);
  au_eq("sanity: All pointer values are NULL", status, S20_FAILURE);
}

{ // All pointer values are !null
  uint8_t k[32] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
                    18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 30, 31, 32 };
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
  uint8_t buf[] = "";

  int status = s20_crypt(k, S20_KEYLEN_256, n, 0, buf, 0);
  au_eq("sanity: All pointer values are !NULL", status, S20_SUCCESS);
}

{ // Only key is null
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
  uint8_t buf[] = "";

  int status = s20_crypt(NULL, S20_KEYLEN_256, n, 0, buf, 0);
  au_eq("sanity: key is NULL", status, S20_FAILURE);
}

{ // Key length is invalid
  uint8_t k[32] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
                    18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 30, 31, 32 };
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
  uint8_t buf[] = "";

  int status = s20_crypt(k, S20_KEYLEN_256 + 10, n, 0, buf, 0);
  au_eq("sanity: key length is invalid", status, S20_FAILURE);
}

{ // Only nonce is null
  uint8_t k[32] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
                    18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 30, 31, 32 };
  uint8_t buf[] = "";

  int status = s20_crypt(k, S20_KEYLEN_256, NULL, 0, buf, 0);
  au_eq("sanity: nonce is NULL", status, S20_FAILURE);
}

{ // Only buf is null
  uint8_t k[32] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
                    18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 30, 31, 32 };
  uint8_t n[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };

  int status = s20_crypt(k, S20_KEYLEN_256, n, 0, NULL, 0);
  au_eq("sanity: buf is NULL", status, S20_FAILURE);
}


// Official test vectors from
// http://www.ecrypt.eu.org/stream/svn/viewcvs.cgi/ecrypt/trunk/submissions/salsa20/full/verified.test-vectors?logsort=rev&rev=210&view=markup
// These two C files are generated by the vectors_to_tests_{128,256}.sh scripts, from the official test vectors.

#include "test_vectors_128.c"

#include "test_vectors_256.c"

au_endmain
