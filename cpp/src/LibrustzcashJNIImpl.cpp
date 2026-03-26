//
// Created by ruipeng on 6/5/19.
//

#include "org_tron_common_zksnark_Librustzcash_LibrustzcashJNI.h"
#include "librustzcash.h"
#include <cstring>

jboolean bool2jboolean(bool b) {
    return b ? JNI_TRUE : JNI_FALSE;
}

/*
 * Matt
 */

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashInitZksnarkParams
 * Signature: ([BILjava/lang/String;[BILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashInitZksnarkParams
    (JNIEnv * env, jobject, jstring spend_path, jstring spend_hash, jstring output_path, jstring output_hash) {
    const char* sp = env->GetStringUTFChars(spend_path, nullptr);
    const char* sh = env->GetStringUTFChars(spend_hash, nullptr);
    const char* op = env->GetStringUTFChars(output_path, nullptr);
    const char* oh = env->GetStringUTFChars(output_hash, nullptr);
    if (sp == nullptr || sh == nullptr || op == nullptr || oh == nullptr)
    {
      if (sp != nullptr) env->ReleaseStringUTFChars(spend_path, sp);
      if (sh != nullptr) env->ReleaseStringUTFChars(spend_hash, sh);
      if (op != nullptr) env->ReleaseStringUTFChars(output_path, op);
      if (oh != nullptr) env->ReleaseStringUTFChars(output_hash, oh);
      return;
    }
    librustzcash_init_zksnark_params(
        reinterpret_cast<const unsigned char*>(sp), std::strlen(sp), sh,
        reinterpret_cast<const unsigned char*>(op), std::strlen(op), oh);
    env->ReleaseStringUTFChars(spend_path, sp);
    env->ReleaseStringUTFChars(spend_hash, sh);
    env->ReleaseStringUTFChars(output_path, op);
    env->ReleaseStringUTFChars(output_hash, oh);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashZip32XskMaster
 * Signature: ([BI[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashZip32XskMaster
  (JNIEnv * env, jobject, jbyteArray seed, jint seedlen, jbyteArray xsk_master) {
    const jbyte* s = env->GetByteArrayElements(seed, nullptr);
    jbyte* x = env->GetByteArrayElements(xsk_master, nullptr);
    if (s == nullptr || x == nullptr)
    {
      if (s != nullptr) env->ReleaseByteArrayElements(seed, const_cast<jbyte*>(s), JNI_ABORT);
      if (x != nullptr) env->ReleaseByteArrayElements(xsk_master, x, JNI_ABORT);
      return;
    }
    librustzcash_zip32_xsk_master(reinterpret_cast<const unsigned char*>(s), static_cast<size_t>(seedlen), reinterpret_cast<unsigned char*>(x));
    env->ReleaseByteArrayElements(seed, const_cast<jbyte*>(s), JNI_ABORT);
    env->ReleaseByteArrayElements(xsk_master, x, 0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashZip32XskDerive
 * Signature: ([BI[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashZip32XskDerive
  (JNIEnv * env, jobject, jbyteArray xsk_parent, jint i, jbyteArray xsk_i) {
    const jbyte* xp = env->GetByteArrayElements(xsk_parent, nullptr);
    jbyte* xi = env->GetByteArrayElements(xsk_i, nullptr);
    if (xp == nullptr || xi == nullptr)
    {
      if (xp != nullptr) env->ReleaseByteArrayElements(xsk_parent, const_cast<jbyte*>(xp), JNI_ABORT);
      if (xi != nullptr) env->ReleaseByteArrayElements(xsk_i, xi, JNI_ABORT);
      return;
    }
    librustzcash_zip32_xsk_derive(reinterpret_cast<const unsigned char*>(xp), static_cast<uint32_t>(i), reinterpret_cast<unsigned char*>(xi));
    env->ReleaseByteArrayElements(xsk_parent, const_cast<jbyte*>(xp), JNI_ABORT);
    env->ReleaseByteArrayElements(xsk_i, xi, 0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashZip32XfvkAddress
 * Signature: ([B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashZip32XfvkAddress
  (JNIEnv * env, jobject, jbyteArray xfvk, jbyteArray j, jbyteArray j_ret, jbyteArray addr_ret) {
    const jbyte* x = env->GetByteArrayElements(xfvk, nullptr);
    const jbyte* jPoint = env->GetByteArrayElements(j, nullptr);
    jbyte* jr = env->GetByteArrayElements(j_ret, nullptr);
    jbyte* a = env->GetByteArrayElements(addr_ret, nullptr);
    if (x == nullptr || jPoint == nullptr || jr == nullptr || a == nullptr)
    {
      if (x != nullptr) env->ReleaseByteArrayElements(xfvk, const_cast<jbyte*>(x), JNI_ABORT);
      if (jPoint != nullptr) env->ReleaseByteArrayElements(j, const_cast<jbyte*>(jPoint), JNI_ABORT);
      if (jr != nullptr) env->ReleaseByteArrayElements(j_ret, jr, JNI_ABORT);
      if (a != nullptr) env->ReleaseByteArrayElements(addr_ret, a, JNI_ABORT);
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_zip32_xfvk_address(
        reinterpret_cast<const unsigned char*>(x),
        reinterpret_cast<const unsigned char*>(jPoint),
        reinterpret_cast<unsigned char*>(jr),
        reinterpret_cast<unsigned char*>(a)));
    env->ReleaseByteArrayElements(xfvk, const_cast<jbyte*>(x), JNI_ABORT);
    env->ReleaseByteArrayElements(j, const_cast<jbyte*>(jPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(j_ret, jr, 0);
    env->ReleaseByteArrayElements(addr_ret, a, 0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashAskToAk
 * Signature: ([B[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashAskToAk
  (JNIEnv * env, jobject, jbyteArray ask, jbyteArray result) {
    const jbyte* a = env->GetByteArrayElements(ask, nullptr);
    jbyte* r = env->GetByteArrayElements(result, nullptr);
    if (a == nullptr || r == nullptr)
    {
      if (a != nullptr) env->ReleaseByteArrayElements(ask, const_cast<jbyte*>(a), JNI_ABORT);
      if (r != nullptr) env->ReleaseByteArrayElements(result, r, JNI_ABORT);
      return;
    }
    librustzcash_ask_to_ak(reinterpret_cast<const unsigned char*>(a), reinterpret_cast<unsigned char*>(r));
    env->ReleaseByteArrayElements(ask, const_cast<jbyte*>(a), JNI_ABORT);
    env->ReleaseByteArrayElements(result, r, 0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingComputeNf
 * Signature: ([B[BJ[B[B[BJ[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingComputeNf
  (JNIEnv * env, jobject, jbyteArray diversifier, jbyteArray pk_d, jlong value, jbyteArray r, jbyteArray ak, jbyteArray nk, jlong position, jbyteArray result) {
    const jbyte* d = env->GetByteArrayElements(diversifier, nullptr);
    const jbyte* p = env->GetByteArrayElements(pk_d, nullptr);
    const jbyte* rPoint = env->GetByteArrayElements(r, nullptr);
    const jbyte* a = env->GetByteArrayElements(ak, nullptr);
    const jbyte* n = env->GetByteArrayElements(nk, nullptr);
    jbyte* rs = env->GetByteArrayElements(result, nullptr);
    if (d == nullptr || p == nullptr || rPoint == nullptr || a == nullptr || n == nullptr || rs == nullptr)
    {
      if (d != nullptr) env->ReleaseByteArrayElements(diversifier, const_cast<jbyte*>(d), JNI_ABORT);
      if (p != nullptr) env->ReleaseByteArrayElements(pk_d, const_cast<jbyte*>(p), JNI_ABORT);
      if (rPoint != nullptr) env->ReleaseByteArrayElements(r, const_cast<jbyte*>(rPoint), JNI_ABORT);
      if (a != nullptr) env->ReleaseByteArrayElements(ak, const_cast<jbyte*>(a), JNI_ABORT);
      if (n != nullptr) env->ReleaseByteArrayElements(nk, const_cast<jbyte*>(n), JNI_ABORT);
      if (rs != nullptr) env->ReleaseByteArrayElements(result, rs, JNI_ABORT);
      return;
    }
    librustzcash_sapling_compute_nf(
        reinterpret_cast<const unsigned char*>(d),
        reinterpret_cast<const unsigned char*>(p),
        static_cast<uint64_t>(value),
        reinterpret_cast<const unsigned char*>(rPoint),
        reinterpret_cast<const unsigned char*>(a),
        reinterpret_cast<const unsigned char*>(n),
        static_cast<uint64_t>(position),
        reinterpret_cast<unsigned char*>(rs));
    env->ReleaseByteArrayElements(diversifier, const_cast<jbyte*>(d), JNI_ABORT);
    env->ReleaseByteArrayElements(pk_d, const_cast<jbyte*>(p), JNI_ABORT);
    env->ReleaseByteArrayElements(r, const_cast<jbyte*>(rPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(ak, const_cast<jbyte*>(a), JNI_ABORT);
    env->ReleaseByteArrayElements(nk, const_cast<jbyte*>(n), JNI_ABORT);
    env->ReleaseByteArrayElements(result, rs, 0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashNskToNk
 * Signature: ([B[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashNskToNk
  (JNIEnv * env, jobject, jbyteArray nsk, jbyteArray result) {
    const jbyte* n = env->GetByteArrayElements(nsk, nullptr);
    jbyte* r = env->GetByteArrayElements(result, nullptr);
    if (r == nullptr || n == nullptr)
    {
      if (n != nullptr) env->ReleaseByteArrayElements(nsk, const_cast<jbyte*>(n), JNI_ABORT);
      if (r != nullptr) env->ReleaseByteArrayElements(result, r, JNI_ABORT);
      return;
    }
    librustzcash_nsk_to_nk(reinterpret_cast<const unsigned char*>(n), reinterpret_cast<unsigned char*>(r));
    env->ReleaseByteArrayElements(nsk, const_cast<jbyte*>(n), JNI_ABORT);
    env->ReleaseByteArrayElements(result, r, 0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingGenerateR
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingGenerateR
  (JNIEnv * env, jobject, jbyteArray result) {
    jbyte* r = env->GetByteArrayElements(result, nullptr);
    if (r == nullptr)
    {
      return;
    }
    librustzcash_sapling_generate_r(reinterpret_cast<unsigned char*>(r));
    env->ReleaseByteArrayElements(result, r, 0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingKaDerivepublic
 * Signature: ([B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingKaDerivepublic
  (JNIEnv * env, jobject, jbyteArray diversifier, jbyteArray esk, jbyteArray result) {
    const jbyte* d = env->GetByteArrayElements(diversifier, nullptr);
    const jbyte* e = env->GetByteArrayElements(esk, nullptr);
    jbyte* r = env->GetByteArrayElements(result, nullptr);
    if (d == nullptr || e == nullptr || r == nullptr)
    {
      if (d != nullptr) env->ReleaseByteArrayElements(diversifier, const_cast<jbyte*>(d), JNI_ABORT);
      if (e != nullptr) env->ReleaseByteArrayElements(esk, const_cast<jbyte*>(e), JNI_ABORT);
      if (r != nullptr) env->ReleaseByteArrayElements(result, r, JNI_ABORT);
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_ka_derivepublic(
        reinterpret_cast<const unsigned char*>(d),
        reinterpret_cast<const unsigned char*>(e),
        reinterpret_cast<unsigned char*>(r)));
    env->ReleaseByteArrayElements(diversifier, const_cast<jbyte*>(d), JNI_ABORT);
    env->ReleaseByteArrayElements(esk, const_cast<jbyte*>(e), JNI_ABORT);
    env->ReleaseByteArrayElements(result, r, 0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashCrhIvk
 * Signature: ([B[B[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashCrhIvk
  (JNIEnv *env, jobject, jbyteArray ak, jbyteArray nk, jbyteArray result) {
    const jbyte* a = env->GetByteArrayElements(ak, nullptr);
    const jbyte* n = env->GetByteArrayElements(nk, nullptr);
    jbyte* r = env->GetByteArrayElements(result, nullptr);
    if (r == nullptr || a == nullptr || n == nullptr)
    {
      if (a != nullptr) env->ReleaseByteArrayElements(ak, const_cast<jbyte*>(a), JNI_ABORT);
      if (n != nullptr) env->ReleaseByteArrayElements(nk, const_cast<jbyte*>(n), JNI_ABORT);
      if (r != nullptr) env->ReleaseByteArrayElements(result, r, JNI_ABORT);
      return;
    }
    librustzcash_crh_ivk(
        reinterpret_cast<const unsigned char*>(a),
        reinterpret_cast<const unsigned char*>(n),
        reinterpret_cast<unsigned char*>(r));
    env->ReleaseByteArrayElements(ak, const_cast<jbyte*>(a), JNI_ABORT);
    env->ReleaseByteArrayElements(nk, const_cast<jbyte*>(n), JNI_ABORT);
    env->ReleaseByteArrayElements(result, r, 0);
}

/*
 * Kiven
 */

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingKaAgree
 * Signature: ([B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingKaAgree
  (JNIEnv * env, jobject, jbyteArray p, jbyteArray sk, jbyteArray result) {
    const jbyte* pPoint = env->GetByteArrayElements(p, nullptr);
    const jbyte* skPoint = env->GetByteArrayElements(sk, nullptr);
    jbyte* r = env->GetByteArrayElements(result, nullptr);
    if (r == nullptr || pPoint == nullptr || skPoint == nullptr)
    {
      if (pPoint != nullptr) env->ReleaseByteArrayElements(p, const_cast<jbyte*>(pPoint), JNI_ABORT);
      if (skPoint != nullptr) env->ReleaseByteArrayElements(sk, const_cast<jbyte*>(skPoint), JNI_ABORT);
      if (r != nullptr) env->ReleaseByteArrayElements(result, r, JNI_ABORT);
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_ka_agree(
        reinterpret_cast<const unsigned char*>(pPoint),
        reinterpret_cast<const unsigned char*>(skPoint),
        reinterpret_cast<unsigned char*>(r)));
    env->ReleaseByteArrayElements(p, const_cast<jbyte*>(pPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(sk, const_cast<jbyte*>(skPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(result, r, 0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashCheckDiversifier
 * Signature: ([B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashCheckDiversifier
  (JNIEnv * env, jobject, jbyteArray diversifier) {
    const jbyte* d = env->GetByteArrayElements(diversifier, nullptr);
    if (d == nullptr)
    {
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_check_diversifier(reinterpret_cast<const unsigned char*>(d)));
    env->ReleaseByteArrayElements(diversifier, const_cast<jbyte*>(d), JNI_ABORT);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashIvkToPkd
 * Signature: ([B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashIvkToPkd
  (JNIEnv * env, jobject, jbyteArray ivk, jbyteArray diversifier, jbyteArray result) {
    const jbyte* i = env->GetByteArrayElements(ivk, nullptr);
    const jbyte* d = env->GetByteArrayElements(diversifier, nullptr);
    jbyte* r = env->GetByteArrayElements(result, nullptr);
    if (r == nullptr || i == nullptr || d == nullptr)
    {
      if (i != nullptr) env->ReleaseByteArrayElements(ivk, const_cast<jbyte*>(i), JNI_ABORT);
      if (d != nullptr) env->ReleaseByteArrayElements(diversifier, const_cast<jbyte*>(d), JNI_ABORT);
      if (r != nullptr) env->ReleaseByteArrayElements(result, r, JNI_ABORT);
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_ivk_to_pkd(
        reinterpret_cast<const unsigned char*>(i),
        reinterpret_cast<const unsigned char*>(d),
        reinterpret_cast<unsigned char*>(r)));
    env->ReleaseByteArrayElements(ivk, const_cast<jbyte*>(i), JNI_ABORT);
    env->ReleaseByteArrayElements(diversifier, const_cast<jbyte*>(d), JNI_ABORT);
    env->ReleaseByteArrayElements(result, r, 0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingComputeCm
 * Signature: ([B[BJ[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingComputeCm
  (JNIEnv * env, jobject, jbyteArray diversifier, jbyteArray pk_d, jlong value, jbyteArray r, jbyteArray result) {
    const jbyte* d = env->GetByteArrayElements(diversifier, nullptr);
    const jbyte* p = env->GetByteArrayElements(pk_d, nullptr);
    const jbyte* rPoint = env->GetByteArrayElements(r, nullptr);
    jbyte* rs = env->GetByteArrayElements(result, nullptr);
    if (rs == nullptr || d == nullptr || p == nullptr || rPoint == nullptr)
    {
      if (d != nullptr) env->ReleaseByteArrayElements(diversifier, const_cast<jbyte*>(d), JNI_ABORT);
      if (p != nullptr) env->ReleaseByteArrayElements(pk_d, const_cast<jbyte*>(p), JNI_ABORT);
      if (rPoint != nullptr) env->ReleaseByteArrayElements(r, const_cast<jbyte*>(rPoint), JNI_ABORT);
      if (rs != nullptr) env->ReleaseByteArrayElements(result, rs, JNI_ABORT);
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_compute_cm(
        reinterpret_cast<const unsigned char*>(d),
        reinterpret_cast<const unsigned char*>(p),
        static_cast<uint64_t>(value),
        reinterpret_cast<const unsigned char*>(rPoint),
        reinterpret_cast<unsigned char*>(rs)));
    env->ReleaseByteArrayElements(diversifier, const_cast<jbyte*>(d), JNI_ABORT);
    env->ReleaseByteArrayElements(pk_d, const_cast<jbyte*>(p), JNI_ABORT);
    env->ReleaseByteArrayElements(r, const_cast<jbyte*>(rPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(result, rs, 0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingProvingCtxInit
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingProvingCtxInit
  (JNIEnv *, jobject) {
  return reinterpret_cast<jlong>(librustzcash_sapling_proving_ctx_init());
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingSpendProof
 * Signature: (J[B[B[B[B[BJ[B[B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingSpendProof
  (JNIEnv * env, jobject, jlong ctx, jbyteArray ak, jbyteArray nsk, jbyteArray diversifier, jbyteArray rcm, jbyteArray ar,
  jlong value, jbyteArray anchor, jbyteArray witness, jbyteArray cv, jbyteArray rk, jbyteArray zkproof) {
    // Validate ctx handle
    if (ctx == 0) {
      return JNI_FALSE;
    }

    // Validate array lengths before accessing elements
    jsize witness_len = env->GetArrayLength(witness);
    if (witness_len < 1065) {
      return JNI_FALSE;
    }
    jsize cv_len = env->GetArrayLength(cv);
    if (cv_len < 32) {
      return JNI_FALSE;
    }
    jsize rk_len = env->GetArrayLength(rk);
    if (rk_len < 32) {
      return JNI_FALSE;
    }
    jsize zkproof_len = env->GetArrayLength(zkproof);
    if (zkproof_len < 192) {
      return JNI_FALSE;
    }

    const jbyte* akPoint = env->GetByteArrayElements(ak, nullptr);
    const jbyte* nskPoint = env->GetByteArrayElements(nsk, nullptr);
    const jbyte* dPoint = env->GetByteArrayElements(diversifier, nullptr);
    const jbyte* rcmPoint = env->GetByteArrayElements(rcm, nullptr);
    const jbyte* arPoint = env->GetByteArrayElements(ar, nullptr);
    const jbyte* anchorPoint = env->GetByteArrayElements(anchor, nullptr);
    const jbyte* wPoint = env->GetByteArrayElements(witness, nullptr);
    jbyte* cvPoint = env->GetByteArrayElements(cv, nullptr);
    jbyte* rkPoint = env->GetByteArrayElements(rk, nullptr);
    jbyte* zPoint = env->GetByteArrayElements(zkproof, nullptr);
    if (akPoint == nullptr || nskPoint == nullptr || dPoint == nullptr || rcmPoint == nullptr ||
        arPoint == nullptr || anchorPoint == nullptr || wPoint == nullptr ||
        cvPoint == nullptr || rkPoint == nullptr || zPoint == nullptr)
    {
      if (akPoint != nullptr) env->ReleaseByteArrayElements(ak, const_cast<jbyte*>(akPoint), JNI_ABORT);
      if (nskPoint != nullptr) env->ReleaseByteArrayElements(nsk, const_cast<jbyte*>(nskPoint), JNI_ABORT);
      if (dPoint != nullptr) env->ReleaseByteArrayElements(diversifier, const_cast<jbyte*>(dPoint), JNI_ABORT);
      if (rcmPoint != nullptr) env->ReleaseByteArrayElements(rcm, const_cast<jbyte*>(rcmPoint), JNI_ABORT);
      if (arPoint != nullptr) env->ReleaseByteArrayElements(ar, const_cast<jbyte*>(arPoint), JNI_ABORT);
      if (anchorPoint != nullptr) env->ReleaseByteArrayElements(anchor, const_cast<jbyte*>(anchorPoint), JNI_ABORT);
      if (wPoint != nullptr) env->ReleaseByteArrayElements(witness, const_cast<jbyte*>(wPoint), JNI_ABORT);
      if (cvPoint != nullptr) env->ReleaseByteArrayElements(cv, cvPoint, JNI_ABORT);
      if (rkPoint != nullptr) env->ReleaseByteArrayElements(rk, rkPoint, JNI_ABORT);
      if (zPoint != nullptr) env->ReleaseByteArrayElements(zkproof, zPoint, JNI_ABORT);
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_spend_proof(
        reinterpret_cast<void*>(ctx),
        reinterpret_cast<const unsigned char*>(akPoint),
        reinterpret_cast<const unsigned char*>(nskPoint),
        reinterpret_cast<const unsigned char*>(dPoint),
        reinterpret_cast<const unsigned char*>(rcmPoint),
        reinterpret_cast<const unsigned char*>(arPoint),
        static_cast<uint64_t>(value),
        reinterpret_cast<const unsigned char*>(anchorPoint),
        reinterpret_cast<const unsigned char*>(wPoint),
        reinterpret_cast<unsigned char*>(cvPoint),
        reinterpret_cast<unsigned char*>(rkPoint),
        reinterpret_cast<unsigned char*>(zPoint)));
    env->ReleaseByteArrayElements(ak, const_cast<jbyte*>(akPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(nsk, const_cast<jbyte*>(nskPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(diversifier, const_cast<jbyte*>(dPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(rcm, const_cast<jbyte*>(rcmPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(ar, const_cast<jbyte*>(arPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(anchor, const_cast<jbyte*>(anchorPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(witness, const_cast<jbyte*>(wPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(cv, cvPoint, 0);
    env->ReleaseByteArrayElements(rk, rkPoint, 0);
    env->ReleaseByteArrayElements(zkproof, zPoint, 0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingOutputProof
 * Signature: (J[B[B[B[BJ[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingOutputProof
  (JNIEnv * env, jobject, jlong ctx, jbyteArray esk, jbyteArray diversifier, jbyteArray pk_d, jbyteArray rcm, jlong value, jbyteArray cv, jbyteArray zkproof) {
    // Validate ctx handle
    if (ctx == 0) {
      return JNI_FALSE;
    }

    // Validate array lengths before accessing elements
    jsize cv_len = env->GetArrayLength(cv);
    if (cv_len < 32) {
      return JNI_FALSE;
    }
    jsize zkproof_len = env->GetArrayLength(zkproof);
    if (zkproof_len < 192) {
      return JNI_FALSE;
    }

    const jbyte* e = env->GetByteArrayElements(esk, nullptr);
    const jbyte* d = env->GetByteArrayElements(diversifier, nullptr);
    const jbyte* p = env->GetByteArrayElements(pk_d, nullptr);
    const jbyte* r = env->GetByteArrayElements(rcm, nullptr);
    jbyte* c = env->GetByteArrayElements(cv, nullptr);
    jbyte* z = env->GetByteArrayElements(zkproof, nullptr);
    if (e == nullptr || d == nullptr || p == nullptr || r == nullptr || c == nullptr || z == nullptr)
    {
      if (e != nullptr) env->ReleaseByteArrayElements(esk, const_cast<jbyte*>(e), JNI_ABORT);
      if (d != nullptr) env->ReleaseByteArrayElements(diversifier, const_cast<jbyte*>(d), JNI_ABORT);
      if (p != nullptr) env->ReleaseByteArrayElements(pk_d, const_cast<jbyte*>(p), JNI_ABORT);
      if (r != nullptr) env->ReleaseByteArrayElements(rcm, const_cast<jbyte*>(r), JNI_ABORT);
      if (c != nullptr) env->ReleaseByteArrayElements(cv, c, JNI_ABORT);
      if (z != nullptr) env->ReleaseByteArrayElements(zkproof, z, JNI_ABORT);
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_output_proof(
        reinterpret_cast<void*>(ctx),
        reinterpret_cast<const unsigned char*>(e),
        reinterpret_cast<const unsigned char*>(d),
        reinterpret_cast<const unsigned char*>(p),
        reinterpret_cast<const unsigned char*>(r),
        static_cast<uint64_t>(value),
        reinterpret_cast<unsigned char*>(c),
        reinterpret_cast<unsigned char*>(z)));
    env->ReleaseByteArrayElements(esk, const_cast<jbyte*>(e), JNI_ABORT);
    env->ReleaseByteArrayElements(diversifier, const_cast<jbyte*>(d), JNI_ABORT);
    env->ReleaseByteArrayElements(pk_d, const_cast<jbyte*>(p), JNI_ABORT);
    env->ReleaseByteArrayElements(rcm, const_cast<jbyte*>(r), JNI_ABORT);
    env->ReleaseByteArrayElements(cv, c, 0);
    env->ReleaseByteArrayElements(zkproof, z, 0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingSpendSig
 * Signature: ([B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingSpendSig
  (JNIEnv * env, jobject, jbyteArray ask, jbyteArray ar, jbyteArray sighash, jbyteArray result) {
    const jbyte* askPoint = env->GetByteArrayElements(ask, nullptr);
    const jbyte* arPoint = env->GetByteArrayElements(ar, nullptr);
    const jbyte* s = env->GetByteArrayElements(sighash, nullptr);
    jbyte* r = env->GetByteArrayElements(result, nullptr);
    if (askPoint == nullptr || arPoint == nullptr || s == nullptr || r == nullptr)
    {
      if (askPoint != nullptr) env->ReleaseByteArrayElements(ask, const_cast<jbyte*>(askPoint), JNI_ABORT);
      if (arPoint != nullptr) env->ReleaseByteArrayElements(ar, const_cast<jbyte*>(arPoint), JNI_ABORT);
      if (s != nullptr) env->ReleaseByteArrayElements(sighash, const_cast<jbyte*>(s), JNI_ABORT);
      if (r != nullptr) env->ReleaseByteArrayElements(result, r, JNI_ABORT);
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_spend_sig(
        reinterpret_cast<const unsigned char*>(askPoint),
        reinterpret_cast<const unsigned char*>(arPoint),
        reinterpret_cast<const unsigned char*>(s),
        reinterpret_cast<unsigned char*>(r)));
    env->ReleaseByteArrayElements(ask, const_cast<jbyte*>(askPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(ar, const_cast<jbyte*>(arPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(sighash, const_cast<jbyte*>(s), JNI_ABORT);
    env->ReleaseByteArrayElements(result, r, 0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingBindingSig
 * Signature: (JJ[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingBindingSig
  (JNIEnv * env, jobject, jlong ctx, jlong valueBalance, jbyteArray sighash, jbyteArray result) {
    // Validate ctx handle
    if (ctx == 0) {
      return JNI_FALSE;
    }

    const jbyte* s = env->GetByteArrayElements(sighash, nullptr);
    jbyte* r = env->GetByteArrayElements(result, nullptr);
    if (s == nullptr || r == nullptr)
    {
      if (s != nullptr) env->ReleaseByteArrayElements(sighash, const_cast<jbyte*>(s), JNI_ABORT);
      if (r != nullptr) env->ReleaseByteArrayElements(result, r, JNI_ABORT);
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_binding_sig(
        reinterpret_cast<void*>(ctx),
        static_cast<int64_t>(valueBalance),
        reinterpret_cast<const unsigned char*>(s),
        reinterpret_cast<unsigned char*>(r)));
    env->ReleaseByteArrayElements(sighash, const_cast<jbyte*>(s), JNI_ABORT);
    env->ReleaseByteArrayElements(result, r, 0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingProvingCtxFree
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingProvingCtxFree
  (JNIEnv *, jobject, jlong ctx) {
  if (ctx == 0) {
    return;
  }
  librustzcash_sapling_proving_ctx_free(reinterpret_cast<void*>(ctx));
}

/*
 * Olenheim
 */

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingVerificationCtxInit
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingVerificationCtxInit
  (JNIEnv *, jobject) {
    return reinterpret_cast<jlong>(librustzcash_sapling_verification_ctx_init());
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingCheckSpend
 * Signature: (J[B[B[B[B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingCheckSpend
  (JNIEnv * env, jobject, jlong ctx, jbyteArray cv, jbyteArray anchor, jbyteArray nullifier, jbyteArray rk, jbyteArray zkproof, jbyteArray spendAuthSig, jbyteArray sighashValue) {
    // Validate ctx handle
    if (ctx == 0) {
      return JNI_FALSE;
    }

    const jbyte* c = env->GetByteArrayElements(cv, nullptr);
    const jbyte* a = env->GetByteArrayElements(anchor, nullptr);
    const jbyte* n = env->GetByteArrayElements(nullifier, nullptr);
    const jbyte* r = env->GetByteArrayElements(rk, nullptr);
    const jbyte* z = env->GetByteArrayElements(zkproof, nullptr);
    const jbyte* sp = env->GetByteArrayElements(spendAuthSig, nullptr);
    const jbyte* si = env->GetByteArrayElements(sighashValue, nullptr);
    if (c == nullptr || a == nullptr || n == nullptr || r == nullptr || z == nullptr || sp == nullptr || si == nullptr)
    {
      if (c != nullptr) env->ReleaseByteArrayElements(cv, const_cast<jbyte*>(c), JNI_ABORT);
      if (a != nullptr) env->ReleaseByteArrayElements(anchor, const_cast<jbyte*>(a), JNI_ABORT);
      if (n != nullptr) env->ReleaseByteArrayElements(nullifier, const_cast<jbyte*>(n), JNI_ABORT);
      if (r != nullptr) env->ReleaseByteArrayElements(rk, const_cast<jbyte*>(r), JNI_ABORT);
      if (z != nullptr) env->ReleaseByteArrayElements(zkproof, const_cast<jbyte*>(z), JNI_ABORT);
      if (sp != nullptr) env->ReleaseByteArrayElements(spendAuthSig, const_cast<jbyte*>(sp), JNI_ABORT);
      if (si != nullptr) env->ReleaseByteArrayElements(sighashValue, const_cast<jbyte*>(si), JNI_ABORT);
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_check_spend(
        reinterpret_cast<void*>(ctx),
        reinterpret_cast<const unsigned char*>(c),
        reinterpret_cast<const unsigned char*>(a),
        reinterpret_cast<const unsigned char*>(n),
        reinterpret_cast<const unsigned char*>(r),
        reinterpret_cast<const unsigned char*>(z),
        reinterpret_cast<const unsigned char*>(sp),
        reinterpret_cast<const unsigned char*>(si)));
    env->ReleaseByteArrayElements(cv, const_cast<jbyte*>(c), JNI_ABORT);
    env->ReleaseByteArrayElements(anchor, const_cast<jbyte*>(a), JNI_ABORT);
    env->ReleaseByteArrayElements(nullifier, const_cast<jbyte*>(n), JNI_ABORT);
    env->ReleaseByteArrayElements(rk, const_cast<jbyte*>(r), JNI_ABORT);
    env->ReleaseByteArrayElements(zkproof, const_cast<jbyte*>(z), JNI_ABORT);
    env->ReleaseByteArrayElements(spendAuthSig, const_cast<jbyte*>(sp), JNI_ABORT);
    env->ReleaseByteArrayElements(sighashValue, const_cast<jbyte*>(si), JNI_ABORT);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingCheckOutput
 * Signature: (J[B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingCheckOutput
  (JNIEnv *env, jobject, jlong ctx, jbyteArray cv, jbyteArray cm, jbyteArray ephemeralKey, jbyteArray zkproof) {
    // Validate ctx handle
    if (ctx == 0) {
      return JNI_FALSE;
    }

    const jbyte* cvPoint = env->GetByteArrayElements(cv, nullptr);
    const jbyte* cmPoint = env->GetByteArrayElements(cm, nullptr);
    const jbyte* e = env->GetByteArrayElements(ephemeralKey, nullptr);
    const jbyte* z = env->GetByteArrayElements(zkproof, nullptr);
    if (cvPoint == nullptr || cmPoint == nullptr || e == nullptr || z == nullptr)
    {
      if (cvPoint != nullptr) env->ReleaseByteArrayElements(cv, const_cast<jbyte*>(cvPoint), JNI_ABORT);
      if (cmPoint != nullptr) env->ReleaseByteArrayElements(cm, const_cast<jbyte*>(cmPoint), JNI_ABORT);
      if (e != nullptr) env->ReleaseByteArrayElements(ephemeralKey, const_cast<jbyte*>(e), JNI_ABORT);
      if (z != nullptr) env->ReleaseByteArrayElements(zkproof, const_cast<jbyte*>(z), JNI_ABORT);
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_check_output(
        reinterpret_cast<void*>(ctx),
        reinterpret_cast<const unsigned char*>(cvPoint),
        reinterpret_cast<const unsigned char*>(cmPoint),
        reinterpret_cast<const unsigned char*>(e),
        reinterpret_cast<const unsigned char*>(z)));
    env->ReleaseByteArrayElements(cv, const_cast<jbyte*>(cvPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(cm, const_cast<jbyte*>(cmPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(ephemeralKey, const_cast<jbyte*>(e), JNI_ABORT);
    env->ReleaseByteArrayElements(zkproof, const_cast<jbyte*>(z), JNI_ABORT);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingFinalCheck
 * Signature: (JJ[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingFinalCheck
  (JNIEnv * env, jobject, jlong ctx, jlong valueBalance, jbyteArray bindingSig, jbyteArray sighashValue) {
    // Validate ctx handle
    if (ctx == 0) {
      return JNI_FALSE;
    }

    const jbyte* b = env->GetByteArrayElements(bindingSig, nullptr);
    const jbyte* s = env->GetByteArrayElements(sighashValue, nullptr);
    if (b == nullptr || s == nullptr)
    {
      if (b != nullptr) env->ReleaseByteArrayElements(bindingSig, const_cast<jbyte*>(b), JNI_ABORT);
      if (s != nullptr) env->ReleaseByteArrayElements(sighashValue, const_cast<jbyte*>(s), JNI_ABORT);
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_final_check(
        reinterpret_cast<void*>(ctx),
        static_cast<int64_t>(valueBalance),
        reinterpret_cast<const unsigned char*>(b),
        reinterpret_cast<const unsigned char*>(s)));
    env->ReleaseByteArrayElements(bindingSig, const_cast<jbyte*>(b), JNI_ABORT);
    env->ReleaseByteArrayElements(sighashValue, const_cast<jbyte*>(s), JNI_ABORT);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingCheckSpendNew
 * Signature: ([B[B[B[B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingCheckSpendNew
  (JNIEnv * env, jobject, jbyteArray cv, jbyteArray anchor, jbyteArray nullifier, jbyteArray rk, jbyteArray zkproof, jbyteArray spendAuthSig, jbyteArray sighashValue) {
    const jbyte* c = env->GetByteArrayElements(cv, nullptr);
    const jbyte* a = env->GetByteArrayElements(anchor, nullptr);
    const jbyte* n = env->GetByteArrayElements(nullifier, nullptr);
    const jbyte* r = env->GetByteArrayElements(rk, nullptr);
    const jbyte* z = env->GetByteArrayElements(zkproof, nullptr);
    const jbyte* sp = env->GetByteArrayElements(spendAuthSig, nullptr);
    const jbyte* si = env->GetByteArrayElements(sighashValue, nullptr);
    if (c == nullptr || a == nullptr || n == nullptr || r == nullptr || z == nullptr || sp == nullptr || si == nullptr)
    {
      if (c != nullptr) env->ReleaseByteArrayElements(cv, const_cast<jbyte*>(c), JNI_ABORT);
      if (a != nullptr) env->ReleaseByteArrayElements(anchor, const_cast<jbyte*>(a), JNI_ABORT);
      if (n != nullptr) env->ReleaseByteArrayElements(nullifier, const_cast<jbyte*>(n), JNI_ABORT);
      if (r != nullptr) env->ReleaseByteArrayElements(rk, const_cast<jbyte*>(r), JNI_ABORT);
      if (z != nullptr) env->ReleaseByteArrayElements(zkproof, const_cast<jbyte*>(z), JNI_ABORT);
      if (sp != nullptr) env->ReleaseByteArrayElements(spendAuthSig, const_cast<jbyte*>(sp), JNI_ABORT);
      if (si != nullptr) env->ReleaseByteArrayElements(sighashValue, const_cast<jbyte*>(si), JNI_ABORT);
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_check_spend_new(
        reinterpret_cast<const unsigned char*>(c),
        reinterpret_cast<const unsigned char*>(a),
        reinterpret_cast<const unsigned char*>(n),
        reinterpret_cast<const unsigned char*>(r),
        reinterpret_cast<const unsigned char*>(z),
        reinterpret_cast<const unsigned char*>(sp),
        reinterpret_cast<const unsigned char*>(si)));
    env->ReleaseByteArrayElements(cv, const_cast<jbyte*>(c), JNI_ABORT);
    env->ReleaseByteArrayElements(anchor, const_cast<jbyte*>(a), JNI_ABORT);
    env->ReleaseByteArrayElements(nullifier, const_cast<jbyte*>(n), JNI_ABORT);
    env->ReleaseByteArrayElements(rk, const_cast<jbyte*>(r), JNI_ABORT);
    env->ReleaseByteArrayElements(zkproof, const_cast<jbyte*>(z), JNI_ABORT);
    env->ReleaseByteArrayElements(spendAuthSig, const_cast<jbyte*>(sp), JNI_ABORT);
    env->ReleaseByteArrayElements(sighashValue, const_cast<jbyte*>(si), JNI_ABORT);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingCheckOutputNew
 * Signature: ([B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingCheckOutputNew
  (JNIEnv *env, jobject, jbyteArray cv, jbyteArray cm, jbyteArray ephemeralKey, jbyteArray zkproof) {
    const jbyte* cvPoint = env->GetByteArrayElements(cv, nullptr);
    const jbyte* cmPoint = env->GetByteArrayElements(cm, nullptr);
    const jbyte* e = env->GetByteArrayElements(ephemeralKey, nullptr);
    const jbyte* z = env->GetByteArrayElements(zkproof, nullptr);
    if (cvPoint == nullptr || cmPoint == nullptr || e == nullptr || z == nullptr)
    {
      if (cvPoint != nullptr) env->ReleaseByteArrayElements(cv, const_cast<jbyte*>(cvPoint), JNI_ABORT);
      if (cmPoint != nullptr) env->ReleaseByteArrayElements(cm, const_cast<jbyte*>(cmPoint), JNI_ABORT);
      if (e != nullptr) env->ReleaseByteArrayElements(ephemeralKey, const_cast<jbyte*>(e), JNI_ABORT);
      if (z != nullptr) env->ReleaseByteArrayElements(zkproof, const_cast<jbyte*>(z), JNI_ABORT);
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_check_output_new(
        reinterpret_cast<const unsigned char*>(cvPoint),
        reinterpret_cast<const unsigned char*>(cmPoint),
        reinterpret_cast<const unsigned char*>(e),
        reinterpret_cast<const unsigned char*>(z)));
    env->ReleaseByteArrayElements(cv, const_cast<jbyte*>(cvPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(cm, const_cast<jbyte*>(cmPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(ephemeralKey, const_cast<jbyte*>(e), JNI_ABORT);
    env->ReleaseByteArrayElements(zkproof, const_cast<jbyte*>(z), JNI_ABORT);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingFinalCheckNew
 * Signature: (J[B[B[BI[BI)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingFinalCheckNew
  (JNIEnv * env, jobject, jlong valueBalance, jbyteArray bindingSig, jbyteArray sighashValue, jbyteArray spendCv, jint spendCvLen, jbyteArray outputCv, jint outputCvLen) {
    const jbyte* b = env->GetByteArrayElements(bindingSig, nullptr);
    const jbyte* s = env->GetByteArrayElements(sighashValue, nullptr);
    const jbyte* scv = env->GetByteArrayElements(spendCv, nullptr);
    const jbyte* ocv = env->GetByteArrayElements(outputCv, nullptr);

    if (b == nullptr || s == nullptr || scv == nullptr || ocv == nullptr)
    {
      if (b != nullptr) env->ReleaseByteArrayElements(bindingSig, const_cast<jbyte*>(b), JNI_ABORT);
      if (s != nullptr) env->ReleaseByteArrayElements(sighashValue, const_cast<jbyte*>(s), JNI_ABORT);
      if (scv != nullptr) env->ReleaseByteArrayElements(spendCv, const_cast<jbyte*>(scv), JNI_ABORT);
      if (ocv != nullptr) env->ReleaseByteArrayElements(outputCv, const_cast<jbyte*>(ocv), JNI_ABORT);
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_final_check_new(
        static_cast<int64_t>(valueBalance),
        reinterpret_cast<const unsigned char*>(b),
        reinterpret_cast<const unsigned char*>(s),
        reinterpret_cast<const unsigned char*>(scv),
        static_cast<size_t>(spendCvLen),
        reinterpret_cast<const unsigned char*>(ocv),
        static_cast<size_t>(outputCvLen)));
    env->ReleaseByteArrayElements(bindingSig, const_cast<jbyte*>(b), JNI_ABORT);
    env->ReleaseByteArrayElements(sighashValue, const_cast<jbyte*>(s), JNI_ABORT);
    env->ReleaseByteArrayElements(spendCv, const_cast<jbyte*>(scv), JNI_ABORT);
    env->ReleaseByteArrayElements(outputCv, const_cast<jbyte*>(ocv), JNI_ABORT);
    return jb;
}


/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingVerificationCtxFree
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingVerificationCtxFree
  (JNIEnv *, jobject, jlong ctx) {
//    void librustzcash_sapling_verification_ctx_free(void *);
    if (ctx == 0) {
      return;
    }
    librustzcash_sapling_verification_ctx_free(reinterpret_cast<void*>(ctx));
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashMerkleHash
 * Signature: (I[B[B[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashMerkleHash
  (JNIEnv *env, jobject, jint depth, jbyteArray a, jbyteArray b, jbyteArray result) {
    const jbyte* aPoint = env->GetByteArrayElements(a, nullptr);
    const jbyte* bPoint = env->GetByteArrayElements(b, nullptr);
    jbyte* r = env->GetByteArrayElements(result, nullptr);
    if (aPoint == nullptr || bPoint == nullptr || r == nullptr)
    {
      if (aPoint != nullptr) env->ReleaseByteArrayElements(a, const_cast<jbyte*>(aPoint), JNI_ABORT);
      if (bPoint != nullptr) env->ReleaseByteArrayElements(b, const_cast<jbyte*>(bPoint), JNI_ABORT);
      if (r != nullptr) env->ReleaseByteArrayElements(result, r, JNI_ABORT);
      return;
    }
    librustzcash_merkle_hash(
        static_cast<size_t>(depth),
        reinterpret_cast<const unsigned char*>(aPoint),
        reinterpret_cast<const unsigned char*>(bPoint),
        reinterpret_cast<unsigned char*>(r));
    env->ReleaseByteArrayElements(a, const_cast<jbyte*>(aPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(b, const_cast<jbyte*>(bPoint), JNI_ABORT);
    env->ReleaseByteArrayElements(result, r, 0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashTreeUncommitted
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashTreeUncommitted
  (JNIEnv *env, jobject, jbyteArray result) {
    jbyte* r = env->GetByteArrayElements(result, nullptr);
    if (r == nullptr)
    {
      return;
    }
    librustzcash_tree_uncommitted(reinterpret_cast<unsigned char*>(r));
    env->ReleaseByteArrayElements(result, r, 0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashToScalar
 * Signature: ([B[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashToScalar
  (JNIEnv *env, jobject, jbyteArray input, jbyteArray result) {
    const jbyte* i = env->GetByteArrayElements(input, nullptr);
    jbyte* r = env->GetByteArrayElements(result, nullptr);
    if (i == nullptr || r == nullptr)
    {
      if (i != nullptr) env->ReleaseByteArrayElements(input, const_cast<jbyte*>(i), JNI_ABORT);
      if (r != nullptr) env->ReleaseByteArrayElements(result, r, JNI_ABORT);
      return;
    }
    librustzcash_to_scalar(
        reinterpret_cast<const unsigned char*>(i),
        reinterpret_cast<unsigned char*>(r));
    env->ReleaseByteArrayElements(input, const_cast<jbyte*>(i), JNI_ABORT);
    env->ReleaseByteArrayElements(result, r, 0);
}
