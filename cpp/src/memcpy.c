#include <string.h>

#ifdef __linux__
#if defined(__x86_64__) && defined(__GNU_LIBRARY__)
void *__memcpy_old(void *, const void *, size_t);

asm(".symver __memcpy_old, memcpy@GLIBC_2.2.5");
void *__wrap_memcpy(void *dest, const void *src, size_t n) {
    return __memcpy_old(dest, src, n);
}
#else
// https://chromium.googlesource.com/external/github.com/google/protobuf/+/HEAD/ruby/ext/google/protobuf_c/wrap_memcpy.c
void *__wrap_memcpy(void *dest, const void *src, size_t n) {
    return memmove(dest, src, n);
}
#endif
#endif
