#ifdef __linux__

#include <string.h>

void *__memcpy_old(void *, const void *, size_t);

asm(".symver __memcpy_old, memcpy@GLIBC_2.2.5");
void *__wrap_memcpy(void *dest, const void *src, size_t n)
{
    return __memcpy_old(dest, src, n);
}

#endif