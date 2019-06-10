//
// Created by ruipeng on 6/5/19.
//

#include "org_tron_common_zksnark_Libsodium_LibsodiumJNI.h"
#include "sodium.h"

JNIEXPORT jlong JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1generichash_1blake2b_1state_1init
    (JNIEnv *, jobject) {
    crypto_generichash_blake2b_state* state_p = new crypto_generichash_blake2b_state();
    if (!state_p) {
        return 0;
    }

    return (jlong) state_p;
}

JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1generichash_1blake2b_1state_1free
(JNIEnv *, jobject, jlong state) {
    crypto_generichash_blake2b_state* state_p = (crypto_generichash_blake2b_state*) state;
    if (state_p) {
        delete state_p;
    }
}

JNIEXPORT jint JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1generichash_1blake2b_1init_1salt_1personal
    (JNIEnv *env, jobject, jlong state, jbyteArray key, jint keylen, jint outlen, jbyteArray salt, jbyteArray personal) {
//    int crypto_generichash_blake2b_init_salt_personal(crypto_generichash_blake2b_state *state,
//                                                      const unsigned char *key,
//                                                      const size_t keylen, const size_t outlen,
//                                                      const unsigned char *salt,
//                                                      const unsigned char *personal);
    return (jint) crypto_generichash_blake2b_init_salt_personal(
        (crypto_generichash_blake2b_state *) state,
        (const unsigned char *) env->GetByteArrayElements(key, nullptr),
        (const size_t) keylen,
        (const size_t) outlen,
        (const unsigned char *) env->GetByteArrayElements(salt, nullptr),
        (const unsigned char *) env->GetByteArrayElements(personal, nullptr)
    );
}

JNIEXPORT jint JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1generichash_1blake2b_1update
    (JNIEnv *env, jobject, jlong state, jbyteArray in, jlong inlen) {
//    int crypto_generichash_blake2b_update(crypto_generichash_blake2b_state *state,
//                                          const unsigned char *in,
//                                          unsigned long long inlen);
    return (jint) crypto_generichash_blake2b_update(
        (crypto_generichash_blake2b_state *) state,
        (const unsigned char *) env->GetByteArrayElements(in, nullptr),
        (unsigned long long) inlen
    );
}

JNIEXPORT jint JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1generichash_1blake2b_1final
    (JNIEnv *env, jobject, jlong state, jbyteArray out, jint outlen) {
//    int crypto_generichash_blake2b_final(crypto_generichash_blake2b_state *state,
//                                         unsigned char *out,
//                                         const size_t outlen);
    jboolean isCopy = JNI_TRUE;
    return (jint) crypto_generichash_blake2b_final(
        (crypto_generichash_blake2b_state *) state,
        (unsigned char *) env->GetByteArrayElements(out, &isCopy),
        (const size_t) outlen
    );
}

JNIEXPORT jint JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1generichash_1blake2b_1salt_1personal
    (JNIEnv *env, jobject, jbyteArray out, jint outlen, jbyteArray in, jlong inlen, jbyteArray key, jint keylen, jbyteArray salt, jbyteArray personal) {
//    int crypto_generichash_blake2b_salt_personal(unsigned char *out, size_t outlen,
//                                                 const unsigned char *in,
//                                                 unsigned long long inlen,
//                                                 const unsigned char *key,
//                                                 size_t keylen,
//                                                 const unsigned char *salt,
//                                                 const unsigned char *personal);
    jboolean isCopy = JNI_TRUE;
    return (jint) crypto_generichash_blake2b_salt_personal(
        (unsigned char *) env->GetByteArrayElements(out, &isCopy),
        (size_t) outlen,
        (const unsigned char *) env->GetByteArrayElements(in, nullptr),
        (unsigned long long) inlen,
        (const unsigned char *) env->GetByteArrayElements(key, nullptr),
        (size_t) keylen,
        (const unsigned char *) env->GetByteArrayElements(salt, nullptr),
        (const unsigned char *) env->GetByteArrayElements(personal, nullptr)
    );
}

JNIEXPORT jint JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1aead_1chacha20poly1305_1ietf_1decrypt
    (JNIEnv *env, jobject, jbyteArray m, jlongArray mlen_p, jbyteArray nsec, jbyteArray c, jlong clen, jbyteArray ad, jlong adlen, jbyteArray npub, jbyteArray k) {
//    int crypto_aead_chacha20poly1305_ietf_decrypt(unsigned char *m,
//                                                  unsigned long long *mlen_p,
//                                                  unsigned char *nsec,
//                                                  const unsigned char *c,
//                                                  unsigned long long clen,
//                                                  const unsigned char *ad,
//                                                  unsigned long long adlen,
//                                                  const unsigned char *npub,
//                                                  const unsigned char *k)
    jboolean isCopy = JNI_TRUE;
    return (jint) crypto_aead_chacha20poly1305_ietf_decrypt(
        (unsigned char *) env->GetByteArrayElements(m, &isCopy),
        (unsigned long long*) env->GetLongArrayElements(mlen_p, &isCopy),
        (unsigned char *) env->GetByteArrayElements(nsec, &isCopy),
        (const unsigned char *) env->GetByteArrayElements(c, nullptr),
        (unsigned long long) clen,
        (const unsigned char *) env->GetByteArrayElements(ad, nullptr),
        (unsigned long long) adlen,
        (const unsigned char *) env->GetByteArrayElements(npub, nullptr),
        (const unsigned char *) env->GetByteArrayElements(k, nullptr)
    );
}

JNIEXPORT jint JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1aead_1chacha20poly1305_1ietf_1encrypt
    (JNIEnv *env, jobject, jbyteArray c, jlongArray clen_p, jbyteArray m, jlong mlen, jbyteArray ad, jlong adlen, jbyteArray nsec, jbyteArray npub, jbyteArray k) {
//    int crypto_aead_chacha20poly1305_ietf_encrypt(unsigned char *c,
//                                                  unsigned long long *clen_p,
//                                                  const unsigned char *m,
//                                                  unsigned long long mlen,
//                                                  const unsigned char *ad,
//                                                  unsigned long long adlen,
//                                                  const unsigned char *nsec,
//                                                  const unsigned char *npub,
//                                                  const unsigned char *k);

    jboolean isCopy = JNI_TRUE;
    return (jint) crypto_aead_chacha20poly1305_ietf_encrypt(
        (unsigned char *) env->GetByteArrayElements(c, &isCopy),
        (unsigned long long*) env->GetLongArrayElements(clen_p, &isCopy),
        (const unsigned char *) env->GetByteArrayElements(m, nullptr),
        (unsigned long long) mlen,
        (const unsigned char *) env->GetByteArrayElements(ad, nullptr),
        (unsigned long long) adlen,
        (const unsigned char *) env->GetByteArrayElements(nsec, nullptr),
        (const unsigned char *) env->GetByteArrayElements(npub, nullptr),
        (const unsigned char *) env->GetByteArrayElements(k, nullptr)
    );
}


