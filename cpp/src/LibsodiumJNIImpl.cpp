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

    auto key_p = (const unsigned char *) env->GetByteArrayElements(key, nullptr);
    auto salt_p = (const unsigned char *) env->GetByteArrayElements(salt, nullptr);
    auto personal_p = (const unsigned char *) env->GetByteArrayElements(personal, nullptr);

    auto ret = (jint) crypto_generichash_blake2b_init_salt_personal(
        (crypto_generichash_blake2b_state *) state,
        key_p,
        (const size_t) keylen,
        (const size_t) outlen,
        salt_p,
        personal_p
    );

    env->ReleaseByteArrayElements(key, (jbyte *)key_p, 0);
    env->ReleaseByteArrayElements(salt, (jbyte *)salt_p, 0);
    env->ReleaseByteArrayElements(personal, (jbyte *)personal_p, 0);

    return ret;
}

JNIEXPORT jint JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1generichash_1blake2b_1update
    (JNIEnv *env, jobject, jlong state, jbyteArray in, jlong inlen) {
//    int crypto_generichash_blake2b_update(crypto_generichash_blake2b_state *state,
//                                          const unsigned char *in,
//                                          unsigned long long inlen);
    auto in_p = (const unsigned char *) env->GetByteArrayElements(in, nullptr);
    auto ret = (jint) crypto_generichash_blake2b_update(
        (crypto_generichash_blake2b_state *) state,
        in_p,
        (unsigned long long) inlen
    );

    env->ReleaseByteArrayElements(in, (jbyte *)in_p, 0);

    return ret;
}

JNIEXPORT jint JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1generichash_1blake2b_1final
    (JNIEnv *env, jobject, jlong state, jbyteArray out, jint outlen) {
//    int crypto_generichash_blake2b_final(crypto_generichash_blake2b_state *state,
//                                         unsigned char *out,
//                                         const size_t outlen);

    auto out_p = (unsigned char *) env->GetByteArrayElements(out, nullptr);

    auto ret = (jint) crypto_generichash_blake2b_final(
        (crypto_generichash_blake2b_state *) state,
        out_p,
        (const size_t) outlen
    );

    env->ReleaseByteArrayElements(out, (jbyte *)out_p, 0);

    return ret;
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

    auto out_p = (unsigned char *) env->GetByteArrayElements(out, nullptr);
    auto in_p = (const unsigned char *) env->GetByteArrayElements(in, nullptr);
    auto key_p = (const unsigned char *) env->GetByteArrayElements(key, nullptr);
    auto salt_p = (const unsigned char *) env->GetByteArrayElements(salt, nullptr);
    auto personal_p = (const unsigned char *) env->GetByteArrayElements(personal, nullptr);

    auto ret = (jint) crypto_generichash_blake2b_salt_personal(
        out_p,
        (size_t) outlen,
        in_p,
        (unsigned long long) inlen,
        key_p,
        (size_t) keylen,
        salt_p,
        personal_p
    );

    env->ReleaseByteArrayElements(out, (jbyte *)out_p, 0);
    env->ReleaseByteArrayElements(in, (jbyte *)in_p, 0);
    env->ReleaseByteArrayElements(key, (jbyte *)key_p, 0);
    env->ReleaseByteArrayElements(salt, (jbyte *)salt_p, 0);
    env->ReleaseByteArrayElements(personal, (jbyte *)personal_p, 0);

    return ret;
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
    auto m_p = (unsigned char *) env->GetByteArrayElements(m, nullptr);
    auto mlen_p_p = (unsigned long long*) env->GetLongArrayElements(mlen_p, nullptr);
    auto nsec_p = (unsigned char *) env->GetByteArrayElements(nsec, nullptr);
    auto c_p = (const unsigned char *) env->GetByteArrayElements(c, nullptr);
    auto ad_p = (const unsigned char *) env->GetByteArrayElements(ad, nullptr);
    auto npub_p = (const unsigned char *) env->GetByteArrayElements(npub, nullptr);
    auto k_p = (const unsigned char *) env->GetByteArrayElements(k, nullptr);


    auto ret = (jint) crypto_aead_chacha20poly1305_ietf_decrypt(
        m_p,
        mlen_p_p,
        nsec_p,
        c_p,
        (unsigned long long) clen,
        ad_p,
        (unsigned long long) adlen,
        npub_p,
        k_p
    );

    env->ReleaseByteArrayElements(m, (jbyte *)m_p, 0);
    env->ReleaseLongArrayElements(mlen_p, (jlong *)mlen_p_p, 0);
    env->ReleaseByteArrayElements(nsec, (jbyte *)nsec_p, 0);
    env->ReleaseByteArrayElements(c, (jbyte *)c_p, 0);
    env->ReleaseByteArrayElements(ad, (jbyte *)ad_p, 0);
    env->ReleaseByteArrayElements(npub, (jbyte *)npub_p, 0);
    env->ReleaseByteArrayElements(k, (jbyte *)k_p, 0);

    return ret;
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

    auto c_p = (unsigned char *) env->GetByteArrayElements(c, nullptr);
    auto clen_p_p = (unsigned long long*) env->GetLongArrayElements(clen_p, nullptr);
    auto m_p = (const unsigned char *) env->GetByteArrayElements(m, nullptr);
    auto ad_p = (const unsigned char *) env->GetByteArrayElements(ad, nullptr);
    auto nsec_p = (const unsigned char *) env->GetByteArrayElements(nsec, nullptr);
    auto npub_p = (const unsigned char *) env->GetByteArrayElements(npub, nullptr);
    auto k_p = (const unsigned char *) env->GetByteArrayElements(k, nullptr);


    auto ret =  (jint) crypto_aead_chacha20poly1305_ietf_encrypt(
        c_p,
        clen_p_p,
        m_p,
        (unsigned long long) mlen,
        ad_p,
        (unsigned long long) adlen,
        nsec_p,
        npub_p,
        k_p
    );

    env->ReleaseByteArrayElements(c, (jbyte *)c_p, 0);
    env->ReleaseLongArrayElements(clen_p, (jlong *)clen_p_p, 0);
    env->ReleaseByteArrayElements(m, (jbyte *) m_p, 0);
    env->ReleaseByteArrayElements(ad, (jbyte *) ad_p, 0);
    env->ReleaseByteArrayElements(nsec, (jbyte *) nsec_p, 0);
    env->ReleaseByteArrayElements(npub, (jbyte *) npub_p, 0);
    env->ReleaseByteArrayElements(k, (jbyte *) k_p, 0);

    return ret;
}


