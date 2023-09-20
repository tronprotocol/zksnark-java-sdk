#ifndef LIBARKWORKS_INCLUDE_H_
#define LIBARKWORKS_INCLUDE_H_

#include <stdint.h>

extern "C" {
#ifdef WIN32
    typedef uint16_t codeunit;
#else
    typedef uint8_t codeunit;
#endif

    bool libarkworks_g1_is_valid(
        const unsigned char *x, 
        const unsigned char *y
    );
    
    bool libarkworks_g2_is_valid(
        const unsigned char *a, 
        const unsigned char *b,
        const unsigned char *c,
        const unsigned char *d
    );

    bool libarkworks_add_g1(
        const unsigned char *a, 
        const unsigned char *b,
        unsigned char *result
    );

    bool libarkworks_mul_g1(
        const unsigned char *p, 
        const unsigned char *s,
        unsigned char *result
    );

    bool libarkworks_pairing_check(
        const unsigned char *g1s, 
        const unsigned char *g2s,
        const uint32_t pairs
    );

    void libarkworks_random_g1(
        unsigned char *g1
    );

    void libarkworks_random_g2(
        unsigned char *g2
    );
}

#endif // LIBARKWORKS_INCLUDE_H_
