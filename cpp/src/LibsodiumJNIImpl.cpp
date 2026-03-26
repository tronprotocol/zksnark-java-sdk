//
// Created by ruipeng on 6/5/19.
//

#include "org_tron_common_zksnark_Libsodium_LibsodiumJNI.h"
#include "sodium.h"
#include <cstring>
#include <new>

JNIEXPORT jlong JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1generichash_1blake2b_1state_1init
    (JNIEnv *, jobject) {
    crypto_generichash_blake2b_state* state_p = new (std::nothrow) crypto_generichash_blake2b_state();
    if (!state_p) {
        return 0;
    }

    return reinterpret_cast<jlong>(state_p);
}

JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1generichash_1blake2b_1state_1free
(JNIEnv *, jobject, jlong state) {
    auto* state_p = reinterpret_cast<crypto_generichash_blake2b_state*>(state);
    if (state_p) {
        delete state_p;
    }
}

JNIEXPORT jint JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1generichash_1blake2b_1init_1salt_1personal
    (JNIEnv *env, jobject, jlong state, jbyteArray key, jint keylen, jint outlen, jbyteArray salt, jbyteArray personal) {
    auto* state_p = reinterpret_cast<crypto_generichash_blake2b_state*>(state);
    if (state_p == nullptr) {
        return -1;
    }
    const jbyte* key_p = key ? env->GetByteArrayElements(key, nullptr) : nullptr;
    const jbyte* salt_p = salt ? env->GetByteArrayElements(salt, nullptr) : nullptr;
    const jbyte* personal_p = personal ? env->GetByteArrayElements(personal, nullptr) : nullptr;

    if (key && key_p == nullptr) {
        return -1;
    }
    if (salt && salt_p == nullptr) {
        if (key) env->ReleaseByteArrayElements(key, const_cast<jbyte*>(key_p), JNI_ABORT);
        return -1;
    }
    if (personal && personal_p == nullptr) {
        if (key) env->ReleaseByteArrayElements(key, const_cast<jbyte*>(key_p), JNI_ABORT);
        if (salt) env->ReleaseByteArrayElements(salt, const_cast<jbyte*>(salt_p), JNI_ABORT);
        return -1;
    }

    auto ret = static_cast<jint>(crypto_generichash_blake2b_init_salt_personal(
        state_p,
        reinterpret_cast<const unsigned char*>(key_p),
        static_cast<size_t>(keylen),
        static_cast<size_t>(outlen),
        reinterpret_cast<const unsigned char*>(salt_p),
        reinterpret_cast<const unsigned char*>(personal_p)
    ));

    if (key) env->ReleaseByteArrayElements(key, const_cast<jbyte*>(key_p), JNI_ABORT);
    if (salt) env->ReleaseByteArrayElements(salt, const_cast<jbyte*>(salt_p), JNI_ABORT);
    if (personal) env->ReleaseByteArrayElements(personal, const_cast<jbyte*>(personal_p), JNI_ABORT);

    return ret;
}

JNIEXPORT jint JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1generichash_1blake2b_1update
    (JNIEnv *env, jobject, jlong state, jbyteArray in, jlong inlen) {
    auto* state_p = reinterpret_cast<crypto_generichash_blake2b_state*>(state);
    if (state_p == nullptr) {
        return -1;
    }
    const jbyte* in_p = in ? env->GetByteArrayElements(in, nullptr) : nullptr;

    if (in && in_p == nullptr) {
        return -1;
    }

    auto ret = static_cast<jint>(crypto_generichash_blake2b_update(
        state_p,
        reinterpret_cast<const unsigned char*>(in_p),
        static_cast<unsigned long long>(inlen)
    ));

    if (in) env->ReleaseByteArrayElements(in, const_cast<jbyte*>(in_p), JNI_ABORT);

    return ret;
}

JNIEXPORT jint JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1generichash_1blake2b_1final
    (JNIEnv *env, jobject, jlong state, jbyteArray out, jint outlen) {
    auto* state_p = reinterpret_cast<crypto_generichash_blake2b_state*>(state);
    if (state_p == nullptr) {
        return -1;
    }
    jbyte* out_p = out ? env->GetByteArrayElements(out, nullptr) : nullptr;

    if (out && out_p == nullptr) {
        return -1;
    }

    auto ret = static_cast<jint>(crypto_generichash_blake2b_final(
        state_p,
        reinterpret_cast<unsigned char*>(out_p),
        static_cast<size_t>(outlen)
    ));

    if (out) env->ReleaseByteArrayElements(out, out_p, 0);

    return ret;
}

JNIEXPORT jint JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1generichash_1blake2b_1salt_1personal
    (JNIEnv *env, jobject, jbyteArray out, jint outlen, jbyteArray in, jlong inlen, jbyteArray key, jint keylen, jbyteArray salt, jbyteArray personal) {
    jbyte* out_p = out ? env->GetByteArrayElements(out, nullptr) : nullptr;
    const jbyte* in_p = in ? env->GetByteArrayElements(in, nullptr) : nullptr;
    const jbyte* key_p = key ? env->GetByteArrayElements(key, nullptr) : nullptr;
    const jbyte* salt_p = salt ? env->GetByteArrayElements(salt, nullptr) : nullptr;
    const jbyte* personal_p = personal ? env->GetByteArrayElements(personal, nullptr) : nullptr;

    if (out && out_p == nullptr) {
        return -1;
    }
    if (in && in_p == nullptr) {
        if (out) env->ReleaseByteArrayElements(out, out_p, JNI_ABORT);
        return -1;
    }
    if (key && key_p == nullptr) {
        if (out) env->ReleaseByteArrayElements(out, out_p, JNI_ABORT);
        if (in) env->ReleaseByteArrayElements(in, const_cast<jbyte*>(in_p), JNI_ABORT);
        return -1;
    }
    if (salt && salt_p == nullptr) {
        if (out) env->ReleaseByteArrayElements(out, out_p, JNI_ABORT);
        if (in) env->ReleaseByteArrayElements(in, const_cast<jbyte*>(in_p), JNI_ABORT);
        if (key) env->ReleaseByteArrayElements(key, const_cast<jbyte*>(key_p), JNI_ABORT);
        return -1;
    }
    if (personal && personal_p == nullptr) {
        if (out) env->ReleaseByteArrayElements(out, out_p, JNI_ABORT);
        if (in) env->ReleaseByteArrayElements(in, const_cast<jbyte*>(in_p), JNI_ABORT);
        if (key) env->ReleaseByteArrayElements(key, const_cast<jbyte*>(key_p), JNI_ABORT);
        if (salt) env->ReleaseByteArrayElements(salt, const_cast<jbyte*>(salt_p), JNI_ABORT);
        return -1;
    }

    auto ret = static_cast<jint>(crypto_generichash_blake2b_salt_personal(
        reinterpret_cast<unsigned char*>(out_p),
        static_cast<size_t>(outlen),
        reinterpret_cast<const unsigned char*>(in_p),
        static_cast<unsigned long long>(inlen),
        reinterpret_cast<const unsigned char*>(key_p),
        static_cast<size_t>(keylen),
        reinterpret_cast<const unsigned char*>(salt_p),
        reinterpret_cast<const unsigned char*>(personal_p)
    ));

    if (out) env->ReleaseByteArrayElements(out, out_p, 0);
    if (in) env->ReleaseByteArrayElements(in, const_cast<jbyte*>(in_p), JNI_ABORT);
    if (key) env->ReleaseByteArrayElements(key, const_cast<jbyte*>(key_p), JNI_ABORT);
    if (salt) env->ReleaseByteArrayElements(salt, const_cast<jbyte*>(salt_p), JNI_ABORT);
    if (personal) env->ReleaseByteArrayElements(personal, const_cast<jbyte*>(personal_p), JNI_ABORT);

    return ret;
}

JNIEXPORT jint JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1aead_1chacha20poly1305_1ietf_1decrypt
    (JNIEnv *env, jobject, jbyteArray m, jlongArray mlen_p, jbyteArray nsec, jbyteArray c, jlong clen, jbyteArray ad, jlong adlen, jbyteArray npub, jbyteArray k) {
    jbyte* m_p = m ? env->GetByteArrayElements(m, nullptr) : nullptr;
    jlong* mlen_p_p = mlen_p ? env->GetLongArrayElements(mlen_p, nullptr) : nullptr;
    jbyte* nsec_p = nsec ? env->GetByteArrayElements(nsec, nullptr) : nullptr;
    const jbyte* c_p = c ? env->GetByteArrayElements(c, nullptr) : nullptr;
    const jbyte* ad_p = ad ? env->GetByteArrayElements(ad, nullptr) : nullptr;
    const jbyte* npub_p = npub ? env->GetByteArrayElements(npub, nullptr) : nullptr;
    const jbyte* k_p = k ? env->GetByteArrayElements(k, nullptr) : nullptr;

    if (m && m_p == nullptr) {
        return -1;
    }
    if (mlen_p && mlen_p_p == nullptr) {
        if (m) env->ReleaseByteArrayElements(m, m_p, JNI_ABORT);
        return -1;
    }
    if (nsec && nsec_p == nullptr) {
        if (m) env->ReleaseByteArrayElements(m, m_p, JNI_ABORT);
        if (mlen_p) env->ReleaseLongArrayElements(mlen_p, mlen_p_p, JNI_ABORT);
        return -1;
    }
    if (c && c_p == nullptr) {
        if (m) env->ReleaseByteArrayElements(m, m_p, JNI_ABORT);
        if (mlen_p) env->ReleaseLongArrayElements(mlen_p, mlen_p_p, JNI_ABORT);
        if (nsec) env->ReleaseByteArrayElements(nsec, nsec_p, JNI_ABORT);
        return -1;
    }
    if (ad && ad_p == nullptr) {
        if (m) env->ReleaseByteArrayElements(m, m_p, JNI_ABORT);
        if (mlen_p) env->ReleaseLongArrayElements(mlen_p, mlen_p_p, JNI_ABORT);
        if (nsec) env->ReleaseByteArrayElements(nsec, nsec_p, JNI_ABORT);
        if (c) env->ReleaseByteArrayElements(c, const_cast<jbyte*>(c_p), JNI_ABORT);
        return -1;
    }
    if (npub && npub_p == nullptr) {
        if (m) env->ReleaseByteArrayElements(m, m_p, JNI_ABORT);
        if (mlen_p) env->ReleaseLongArrayElements(mlen_p, mlen_p_p, JNI_ABORT);
        if (nsec) env->ReleaseByteArrayElements(nsec, nsec_p, JNI_ABORT);
        if (c) env->ReleaseByteArrayElements(c, const_cast<jbyte*>(c_p), JNI_ABORT);
        if (ad) env->ReleaseByteArrayElements(ad, const_cast<jbyte*>(ad_p), JNI_ABORT);
        return -1;
    }
    if (k && k_p == nullptr) {
        if (m) env->ReleaseByteArrayElements(m, m_p, JNI_ABORT);
        if (mlen_p) env->ReleaseLongArrayElements(mlen_p, mlen_p_p, JNI_ABORT);
        if (nsec) env->ReleaseByteArrayElements(nsec, nsec_p, JNI_ABORT);
        if (c) env->ReleaseByteArrayElements(c, const_cast<jbyte*>(c_p), JNI_ABORT);
        if (ad) env->ReleaseByteArrayElements(ad, const_cast<jbyte*>(ad_p), JNI_ABORT);
        if (npub) env->ReleaseByteArrayElements(npub, const_cast<jbyte*>(npub_p), JNI_ABORT);
        return -1;
    }

    auto ret = static_cast<jint>(crypto_aead_chacha20poly1305_ietf_decrypt(
        reinterpret_cast<unsigned char*>(m_p),
        reinterpret_cast<unsigned long long*>(mlen_p_p),
        reinterpret_cast<unsigned char*>(nsec_p),
        reinterpret_cast<const unsigned char*>(c_p),
        static_cast<unsigned long long>(clen),
        reinterpret_cast<const unsigned char*>(ad_p),
        static_cast<unsigned long long>(adlen),
        reinterpret_cast<const unsigned char*>(npub_p),
        reinterpret_cast<const unsigned char*>(k_p)
    ));

    if (m) env->ReleaseByteArrayElements(m, m_p, 0);
    if (mlen_p) env->ReleaseLongArrayElements(mlen_p, mlen_p_p, 0);
    if (nsec) env->ReleaseByteArrayElements(nsec, nsec_p, 0);
    if (c) env->ReleaseByteArrayElements(c, const_cast<jbyte*>(c_p), JNI_ABORT);
    if (ad) env->ReleaseByteArrayElements(ad, const_cast<jbyte*>(ad_p), JNI_ABORT);
    if (npub) env->ReleaseByteArrayElements(npub, const_cast<jbyte*>(npub_p), JNI_ABORT);
    if (k) env->ReleaseByteArrayElements(k, const_cast<jbyte*>(k_p), JNI_ABORT);

    return ret;
}

JNIEXPORT jint JNICALL Java_org_tron_common_zksnark_Libsodium_00024LibsodiumJNI_crypto_1aead_1chacha20poly1305_1ietf_1encrypt
    (JNIEnv *env, jobject, jbyteArray c, jlongArray clen_p, jbyteArray m, jlong mlen, jbyteArray ad, jlong adlen, jbyteArray nsec, jbyteArray npub, jbyteArray k) {
    jbyte* c_p = c ? env->GetByteArrayElements(c, nullptr) : nullptr;
    jlong* clen_p_p = clen_p ? env->GetLongArrayElements(clen_p, nullptr) : nullptr;
    const jbyte* m_p = m ? env->GetByteArrayElements(m, nullptr) : nullptr;
    const jbyte* ad_p = ad ? env->GetByteArrayElements(ad, nullptr) : nullptr;
    const jbyte* nsec_p = nsec ? env->GetByteArrayElements(nsec, nullptr) : nullptr;
    const jbyte* npub_p = npub ? env->GetByteArrayElements(npub, nullptr) : nullptr;
    const jbyte* k_p = k ? env->GetByteArrayElements(k, nullptr) : nullptr;

    if (c && c_p == nullptr) {
        return -1;
    }
    if (clen_p && clen_p_p == nullptr) {
        if (c) env->ReleaseByteArrayElements(c, c_p, JNI_ABORT);
        return -1;
    }
    if (m && m_p == nullptr) {
        if (c) env->ReleaseByteArrayElements(c, c_p, JNI_ABORT);
        if (clen_p) env->ReleaseLongArrayElements(clen_p, clen_p_p, JNI_ABORT);
        return -1;
    }
    if (ad && ad_p == nullptr) {
        if (c) env->ReleaseByteArrayElements(c, c_p, JNI_ABORT);
        if (clen_p) env->ReleaseLongArrayElements(clen_p, clen_p_p, JNI_ABORT);
        if (m) env->ReleaseByteArrayElements(m, const_cast<jbyte*>(m_p), JNI_ABORT);
        return -1;
    }
    if (nsec && nsec_p == nullptr) {
        if (c) env->ReleaseByteArrayElements(c, c_p, JNI_ABORT);
        if (clen_p) env->ReleaseLongArrayElements(clen_p, clen_p_p, JNI_ABORT);
        if (m) env->ReleaseByteArrayElements(m, const_cast<jbyte*>(m_p), JNI_ABORT);
        if (ad) env->ReleaseByteArrayElements(ad, const_cast<jbyte*>(ad_p), JNI_ABORT);
        return -1;
    }
    if (npub && npub_p == nullptr) {
        if (c) env->ReleaseByteArrayElements(c, c_p, JNI_ABORT);
        if (clen_p) env->ReleaseLongArrayElements(clen_p, clen_p_p, JNI_ABORT);
        if (m) env->ReleaseByteArrayElements(m, const_cast<jbyte*>(m_p), JNI_ABORT);
        if (ad) env->ReleaseByteArrayElements(ad, const_cast<jbyte*>(ad_p), JNI_ABORT);
        if (nsec) env->ReleaseByteArrayElements(nsec, const_cast<jbyte*>(nsec_p), JNI_ABORT);
        return -1;
    }
    if (k && k_p == nullptr) {
        if (c) env->ReleaseByteArrayElements(c, c_p, JNI_ABORT);
        if (clen_p) env->ReleaseLongArrayElements(clen_p, clen_p_p, JNI_ABORT);
        if (m) env->ReleaseByteArrayElements(m, const_cast<jbyte*>(m_p), JNI_ABORT);
        if (ad) env->ReleaseByteArrayElements(ad, const_cast<jbyte*>(ad_p), JNI_ABORT);
        if (nsec) env->ReleaseByteArrayElements(nsec, const_cast<jbyte*>(nsec_p), JNI_ABORT);
        if (npub) env->ReleaseByteArrayElements(npub, const_cast<jbyte*>(npub_p), JNI_ABORT);
        return -1;
    }

    auto ret = static_cast<jint>(crypto_aead_chacha20poly1305_ietf_encrypt(
        reinterpret_cast<unsigned char*>(c_p),
        reinterpret_cast<unsigned long long*>(clen_p_p),
        reinterpret_cast<const unsigned char*>(m_p),
        static_cast<unsigned long long>(mlen),
        reinterpret_cast<const unsigned char*>(ad_p),
        static_cast<unsigned long long>(adlen),
        reinterpret_cast<const unsigned char*>(nsec_p),
        reinterpret_cast<const unsigned char*>(npub_p),
        reinterpret_cast<const unsigned char*>(k_p)
    ));

    if (c) env->ReleaseByteArrayElements(c, c_p, 0);
    if (clen_p) env->ReleaseLongArrayElements(clen_p, clen_p_p, 0);
    if (m) env->ReleaseByteArrayElements(m, const_cast<jbyte*>(m_p), JNI_ABORT);
    if (ad) env->ReleaseByteArrayElements(ad, const_cast<jbyte*>(ad_p), JNI_ABORT);
    if (nsec) env->ReleaseByteArrayElements(nsec, const_cast<jbyte*>(nsec_p), JNI_ABORT);
    if (npub) env->ReleaseByteArrayElements(npub, const_cast<jbyte*>(npub_p), JNI_ABORT);
    if (k) env->ReleaseByteArrayElements(k, const_cast<jbyte*>(k_p), JNI_ABORT);

    return ret;
}


