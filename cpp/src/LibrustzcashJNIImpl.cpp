//
// Created by ruipeng on 6/5/19.
//

#include "org_tron_common_zksnark_Librustzcash_LibrustzcashJNI.h"
#include "librustzcash.h"
#include <iostream>

jboolean bool2jboolean(bool b) {
    if (b) {
        return JNI_TRUE;
    } else {
        return JNI_FALSE;
    }
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
    const codeunit* sp = (const codeunit*) env->GetStringUTFChars(spend_path, nullptr);
    const char* sh = (const char*) env->GetStringUTFChars(spend_hash, nullptr);
    const codeunit* op = (const codeunit*)  env->GetStringUTFChars(output_path, nullptr);
    const char* oh = (const char*) env->GetStringUTFChars(output_hash, nullptr);
    if (sp == NULL || sh == NULL || op == NULL || oh == NULL)
    {
      return;
    }
    librustzcash_init_zksnark_params(sp, (size_t) env->GetStringLength(spend_path), sh, op,
    (size_t) env->GetStringLength(output_path), oh);
    env->ReleaseStringUTFChars(spend_path, (const char*)sp);
    env->ReleaseStringUTFChars(spend_hash, sh);
    env->ReleaseStringUTFChars(output_path, (const char* )op);
    env->ReleaseStringUTFChars(output_hash, oh);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashZip32XskMaster
 * Signature: ([BI[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashZip32XskMaster
  (JNIEnv * env, jobject, jbyteArray seed, jint seedlen, jbyteArray xsk_master) {
//    void librustzcash_zip32_xsk_master(
//        const unsigned char *seed,
//        size_t seedlen,
//        unsigned char *xsk_master
//    );
    const unsigned char * s = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(seed, nullptr));
    unsigned char * x = reinterpret_cast<unsigned char *>(env->GetByteArrayElements(xsk_master, nullptr));
    if (s == NULL || x == NULL)
    {
      return;
    }
    librustzcash_zip32_xsk_master(s, (size_t) seedlen, x);
    env->ReleaseByteArrayElements(seed, (jbyte*)s, 0);
    env->ReleaseByteArrayElements(xsk_master, (jbyte*)x, 0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashZip32XskDerive
 * Signature: ([BI[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashZip32XskDerive
  (JNIEnv * env, jobject, jbyteArray xsk_parent, jint i, jbyteArray xsk_i) {
//    void librustzcash_zip32_xsk_derive(
//        const unsigned char *xsk_parent,
//        uint32_t i,
//        unsigned char *xsk_i
//    );
    const unsigned char * xp = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(xsk_parent, nullptr));
    unsigned char * xi = reinterpret_cast<unsigned char *>(env->GetByteArrayElements(xsk_i, nullptr));
    if (xp == NULL || xi == NULL)
    {
      return;
    }
    librustzcash_zip32_xsk_derive(xp, (uint32_t) i, xi);
    env->ReleaseByteArrayElements(xsk_parent, (jbyte*)xp, 0);
    env->ReleaseByteArrayElements(xsk_i, (jbyte*)xi, 0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashZip32XfvkAddress
 * Signature: ([B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashZip32XfvkAddress
  (JNIEnv * env, jobject, jbyteArray xfvk, jbyteArray j, jbyteArray j_ret, jbyteArray addr_ret) {
//    bool librustzcash_zip32_xfvk_address(
//        const unsigned char *xfvk,
//        const unsigned char *j,
//        unsigned char *j_ret,
//        unsigned char *addr_ret
//    );
    const unsigned char * x = (const unsigned char *) env->GetByteArrayElements(xfvk, nullptr);
    const unsigned char * jPoint = (const unsigned char *) env->GetByteArrayElements(j, nullptr);
    unsigned char * jr = (unsigned char *) env->GetByteArrayElements(j_ret, nullptr);
    unsigned char * a = (unsigned char *) env->GetByteArrayElements(addr_ret, nullptr);
    if (x == NULL || jPoint == NULL || jr == NULL || a == NULL)
    {
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_zip32_xfvk_address(x, jPoint, jr, a));
    env->ReleaseByteArrayElements(xfvk, (jbyte*)x, 0);
    env->ReleaseByteArrayElements(j, (jbyte*)jPoint, 0);
    env->ReleaseByteArrayElements(j_ret, (jbyte*)jr, 0);
    env->ReleaseByteArrayElements(addr_ret, (jbyte*)a, 0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashAskToAk
 * Signature: ([B[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashAskToAk
  (JNIEnv * env, jobject, jbyteArray ask, jbyteArray result) {
//    void librustzcash_ask_to_ak(const unsigned char *ask, unsigned char *result);

    const unsigned char * a = (const unsigned char *) env->GetByteArrayElements(ask, nullptr);
    unsigned char * r = (unsigned char *) env-> GetByteArrayElements(result, nullptr);
    if (a == NULL || r == NULL)
    {
      return;
    }
    librustzcash_ask_to_ak(a,r);
    env->ReleaseByteArrayElements(result,(jbyte*)r,0);
    env->ReleaseByteArrayElements(ask,(jbyte*)a, 0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingComputeNf
 * Signature: ([B[BJ[B[B[BJ[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingComputeNf
  (JNIEnv * env, jobject, jbyteArray diversifier, jbyteArray pk_d, jlong value, jbyteArray r, jbyteArray ak, jbyteArray nk, jlong position, jbyteArray result) {
//    bool librustzcash_sapling_compute_nf(
//        const unsigned char *diversifier,
//        const unsigned char *pk_d,
//        const uint64_t value,
//        const unsigned char *r,
//        const unsigned char *ak,
//        const unsigned char *nk,
//        const uint64_t position,
//        unsigned char *result
//    );

    const unsigned char * d = (const unsigned char *) env->GetByteArrayElements(diversifier, nullptr);
    const unsigned char * p = (const unsigned char *) env->GetByteArrayElements(pk_d, nullptr);
    const unsigned char * rPoint = (const unsigned char *) env->GetByteArrayElements(r, nullptr);
    const unsigned char * a = (const unsigned char *) env->GetByteArrayElements(ak, nullptr);
    const unsigned char * n = (const unsigned char *) env->GetByteArrayElements(nk, nullptr);
    unsigned char * rs = (unsigned char *) env->GetByteArrayElements(result, nullptr);
    if (d == NULL || p == NULL || rPoint == NULL || a == NULL || n == NULL || rs == NULL)
    {
      return;
    }
    librustzcash_sapling_compute_nf(d,p,static_cast<const uint64_t>((int64_t) value),
        rPoint,a,n,static_cast<const uint64_t>((int64_t) position),rs);
    env->ReleaseByteArrayElements(result,(jbyte*)rs,0);
    env->ReleaseByteArrayElements(diversifier,(jbyte*)d,0);
    env->ReleaseByteArrayElements(pk_d,(jbyte*)p,0);
    env->ReleaseByteArrayElements(r,(jbyte*)rPoint,0);
    env->ReleaseByteArrayElements(ak,(jbyte*)a,0);
    env->ReleaseByteArrayElements(nk,(jbyte*)n,0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashNskToNk
 * Signature: ([B[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashNskToNk
  (JNIEnv * env, jobject, jbyteArray nsk, jbyteArray result) {
//    void librustzcash_nsk_to_nk(const unsigned char *nsk, unsigned char *result);

    const unsigned char * n = (const unsigned char *) env->GetByteArrayElements(nsk, nullptr);
    unsigned char * r = (unsigned char *) env->GetByteArrayElements(result, nullptr);
    if (r == NULL || n == NULL)
    {
      return;
    }
    librustzcash_nsk_to_nk(n,r);
    env->ReleaseByteArrayElements(result,(jbyte*)r,0);
    env->ReleaseByteArrayElements(nsk,(jbyte*)n,0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingGenerateR
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingGenerateR
  (JNIEnv * env, jobject, jbyteArray result) {
//    void librustzcash_sapling_generate_r(
//        unsigned char *result
//    );

    unsigned char * r = (unsigned char *) env->GetByteArrayElements(result, nullptr);
    if (r == NULL)
    {
      return;
    }
    librustzcash_sapling_generate_r(r);
    env->ReleaseByteArrayElements(result,(jbyte*)r,0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingKaDerivepublic
 * Signature: ([B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingKaDerivepublic
  (JNIEnv * env, jobject, jbyteArray diversifier, jbyteArray esk, jbyteArray result) {
//    bool librustzcash_sapling_ka_derivepublic(
//        const unsigned char *diversifier,
//        const unsigned char *esk,
//        unsigned char *result
//    );

    const unsigned char * d = (const unsigned char *) env->GetByteArrayElements(diversifier, nullptr);
    const unsigned char * e = (const unsigned char *) env->GetByteArrayElements(esk, nullptr);
    unsigned char * r = (unsigned char *) env->GetByteArrayElements(result, nullptr);
    if (d == NULL || e == NULL || r == NULL)
    {
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_ka_derivepublic(d,e,r));
    env->ReleaseByteArrayElements(result,(jbyte*)r,0);
    env->ReleaseByteArrayElements(diversifier,(jbyte*)d,0);
    env->ReleaseByteArrayElements(esk,(jbyte*)e,0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashCrhIvk
 * Signature: ([B[B[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashCrhIvk
  (JNIEnv *env, jobject, jbyteArray ak, jbyteArray nk, jbyteArray result) {
//    void librustzcash_crh_ivk(const unsigned char *ak, const unsigned char *nk, unsigned char *result);

    const unsigned char * a = (const unsigned char *) env->GetByteArrayElements(ak, nullptr);
    const unsigned char * n = (const unsigned char *) env->GetByteArrayElements(nk, nullptr);
    unsigned char * r = (unsigned char *) env->GetByteArrayElements(result, nullptr);
    if (r == NULL || a == NULL || n == NULL)
    {
      return;
    }
    librustzcash_crh_ivk(a,n,r);
    env->ReleaseByteArrayElements(result,(jbyte*)r,0);
    env->ReleaseByteArrayElements(ak,(jbyte*)a,0);
    env->ReleaseByteArrayElements(nk,(jbyte*)n,0);
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

  const unsigned char * pPoint = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(p, nullptr));
  const unsigned char * skPoint = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(sk, nullptr));
  unsigned char * r = reinterpret_cast<unsigned char *>(env->GetByteArrayElements(result, nullptr));
  if (r == NULL || pPoint == NULL || skPoint == NULL)
  {
    return JNI_FALSE;
  }
  jboolean jb = bool2jboolean(librustzcash_sapling_ka_agree(pPoint,skPoint,r));
  env->ReleaseByteArrayElements(result,(jbyte*)r,0);
  env->ReleaseByteArrayElements(p,(jbyte*)pPoint,0);
  env->ReleaseByteArrayElements(sk,(jbyte*)skPoint,0);
  return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashCheckDiversifier
 * Signature: ([B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashCheckDiversifier
  (JNIEnv * env, jobject, jbyteArray diversifier) {
  const unsigned char * d = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(diversifier, nullptr));
  if (d == NULL)
  {
    return JNI_FALSE;
  }
  jboolean jb = bool2jboolean(librustzcash_check_diversifier(d));
  env->ReleaseByteArrayElements(diversifier,(jbyte*)d,0);
  return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashIvkToPkd
 * Signature: ([B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashIvkToPkd
  (JNIEnv * env, jobject, jbyteArray ivk, jbyteArray diversifier, jbyteArray result) {

  const unsigned char * i = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(ivk, nullptr));
  const unsigned char * d = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(diversifier, nullptr));
  unsigned char * r = reinterpret_cast<unsigned char *>(env->GetByteArrayElements(result, nullptr));
  if (r == NULL || i == NULL || d == NULL)
  {
    return JNI_FALSE;
  }
  jboolean jb = bool2jboolean(librustzcash_ivk_to_pkd(i,d,r));
  env->ReleaseByteArrayElements(result,(jbyte*)r,0);
  env->ReleaseByteArrayElements(ivk,(jbyte*)i,0);
  env->ReleaseByteArrayElements(diversifier,(jbyte*)d,0);
  return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingComputeCm
 * Signature: ([B[BJ[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingComputeCm
  (JNIEnv * env, jobject, jbyteArray diversifier, jbyteArray pk_d, jlong value, jbyteArray r, jbyteArray result) {

  const unsigned char * d = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(diversifier, nullptr));
  const unsigned char * p = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(pk_d, nullptr));
  const unsigned char * rPonit = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(r, nullptr));
  unsigned char * rs = reinterpret_cast<unsigned char *>(env->GetByteArrayElements(result, nullptr));
  if (rs == NULL || d == NULL || p == NULL || rPonit == NULL)
  {
    return JNI_FALSE;
  }
  jboolean jb = bool2jboolean(librustzcash_sapling_compute_cm(d,p,(const uint64_t) value,rPonit,rs));
  env->ReleaseByteArrayElements(result,(jbyte*)rs,0);
  env->ReleaseByteArrayElements(diversifier,(jbyte*)d,0);
  env->ReleaseByteArrayElements(pk_d,(jbyte*)p,0);
  env->ReleaseByteArrayElements(r,(jbyte*)rPonit,0);
  return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingProvingCtxInit
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingProvingCtxInit
  (JNIEnv *, jobject) {
  return (jlong) librustzcash_sapling_proving_ctx_init();
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingSpendProof
 * Signature: (J[B[B[B[B[BJ[B[B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingSpendProof
  (JNIEnv * env, jobject, jlong ctx, jbyteArray ak, jbyteArray nsk, jbyteArray diversifier, jbyteArray rcm,jbyteArray ar,
  jlong value, jbyteArray anchor, jbyteArray witness, jbyteArray cv, jbyteArray rk, jbyteArray zkproof) {

  const unsigned char * akPoint = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(ak, nullptr));
  const unsigned char * nskPoint = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(nsk, nullptr));
  const unsigned char * dPoint = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(diversifier, nullptr));
  const unsigned char * rcmPoint = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(rcm, nullptr));
  const unsigned char * arPoint = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(ar, nullptr));
  const unsigned char * anchorPoint = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(anchor, nullptr));
  const unsigned char * wPoint = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(witness, nullptr));
  unsigned char * cvPoint = reinterpret_cast<unsigned char *>(env->GetByteArrayElements(cv, nullptr));
  unsigned char * rkPoint = reinterpret_cast<unsigned char *>(env->GetByteArrayElements(rk, nullptr));
  unsigned char * zPoint = reinterpret_cast<unsigned char *>(env->GetByteArrayElements(zkproof, nullptr));
  if (akPoint == NULL || nskPoint == NULL || dPoint == NULL || rcmPoint == NULL || arPoint == NULL || anchorPoint == NULL
    || wPoint == NULL || cvPoint == NULL || rkPoint == NULL || zPoint == NULL)
  {
    return JNI_FALSE;
  }
  jboolean jb = bool2jboolean(librustzcash_sapling_spend_proof((void *)ctx,akPoint,nskPoint,dPoint,rcmPoint,arPoint,
      (const uint64_t) value,anchorPoint,wPoint,cvPoint,rkPoint,zPoint));
  env->ReleaseByteArrayElements(ak,(jbyte*)akPoint,0);
  env->ReleaseByteArrayElements(nsk,(jbyte*)nskPoint,0);
  env->ReleaseByteArrayElements(diversifier,(jbyte*)dPoint,0);
  env->ReleaseByteArrayElements(rcm,(jbyte*)rcmPoint,0);
  env->ReleaseByteArrayElements(ar,(jbyte*)arPoint,0);
  env->ReleaseByteArrayElements(anchor,(jbyte*)anchorPoint,0);
  env->ReleaseByteArrayElements(witness,(jbyte*)wPoint,0);
  env->ReleaseByteArrayElements(cv,(jbyte*)cvPoint,0);
  env->ReleaseByteArrayElements(rk,(jbyte*)rkPoint,0);
  env->ReleaseByteArrayElements(zkproof,(jbyte*)zPoint,0);
  return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingOutputProof
 * Signature: (J[B[B[B[BJ[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingOutputProof
  (JNIEnv * env, jobject, jlong ctx, jbyteArray esk, jbyteArray diversifier, jbyteArray pk_d, jbyteArray rcm, jlong value, jbyteArray cv, jbyteArray zkproof) {
  const unsigned char * e = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(esk, nullptr));
  const unsigned char * d = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(diversifier, nullptr));
  const unsigned char * p = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(pk_d, nullptr));
  const unsigned char * r = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(rcm, nullptr));
  unsigned char * c = reinterpret_cast<unsigned char *>(env->GetByteArrayElements(cv, nullptr));
  unsigned char * z = reinterpret_cast<unsigned char *>(env->GetByteArrayElements(zkproof, nullptr));
  if (e == NULL || d == NULL || p == NULL || r == NULL || c == NULL || z == NULL)
  {
    return JNI_FALSE;
  }
  jboolean jb = bool2jboolean(librustzcash_sapling_output_proof((void *)ctx,e,d,p,r,(const uint64_t) value,c,z));
  env->ReleaseByteArrayElements(esk,(jbyte*)e,0);
  env->ReleaseByteArrayElements(diversifier,(jbyte*)d,0);
  env->ReleaseByteArrayElements(pk_d,(jbyte*)p,0);
  env->ReleaseByteArrayElements(rcm,(jbyte*)r,0);
  env->ReleaseByteArrayElements(cv,(jbyte*)c,0);
  env->ReleaseByteArrayElements(zkproof,(jbyte*)z,0);
  return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingSpendSig
 * Signature: ([B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingSpendSig
  (JNIEnv * env, jobject, jbyteArray ask, jbyteArray ar, jbyteArray sighash, jbyteArray result) {

  const unsigned char * askPoint = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(ask, nullptr));
  const unsigned char * arPoint = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(ar, nullptr));
  const unsigned char * s = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(sighash, nullptr));
  unsigned char * r = reinterpret_cast<unsigned char *>(env->GetByteArrayElements(result, nullptr));
  if (askPoint == NULL || arPoint == NULL || s == NULL || r == NULL)
  {
    return JNI_FALSE;
  }
  jboolean jb = bool2jboolean(librustzcash_sapling_spend_sig(askPoint,arPoint,s,r));
  env->ReleaseByteArrayElements(result,(jbyte*)r,0);
  env->ReleaseByteArrayElements(ask,(jbyte*)askPoint,0);
  env->ReleaseByteArrayElements(ar,(jbyte*)arPoint,0);
  env->ReleaseByteArrayElements(sighash,(jbyte*)s,0);
  return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingBindingSig
 * Signature: (JJ[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingBindingSig
  (JNIEnv * env, jobject, jlong ctx, jlong valueBalance, jbyteArray sighash, jbyteArray result) {

  const unsigned char * s = reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(sighash, nullptr));
  unsigned char * r = reinterpret_cast<unsigned char *>(env->GetByteArrayElements(result, nullptr));
  if (s == NULL || r == NULL)
  {
    return JNI_FALSE;
  }
  jboolean jb = bool2jboolean(librustzcash_sapling_binding_sig((void *)ctx,(int64_t) valueBalance,s,r));
  env->ReleaseByteArrayElements(result,(jbyte*)r,0);
  env->ReleaseByteArrayElements(sighash,(jbyte*)s,0);
  return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingProvingCtxFree
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingProvingCtxFree
  (JNIEnv *, jobject, jlong ctx) {
  librustzcash_sapling_proving_ctx_free((void *)ctx);
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
//    void * librustzcash_sapling_verification_ctx_init();
    return (jlong) librustzcash_sapling_verification_ctx_init();
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingCheckSpend
 * Signature: (J[B[B[B[B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingCheckSpend
  (JNIEnv * env, jobject, jlong ctx, jbyteArray cv, jbyteArray anchor, jbyteArray nullifier, jbyteArray rk, jbyteArray zkproof, jbyteArray spendAuthSig, jbyteArray sighashValue) {
//    bool librustzcash_sapling_check_spend(
//        void *ctx,
//        const unsigned char *cv,
//        const unsigned char *anchor,
//        const unsigned char *nullifier,
//        const unsigned char *rk,
//        const unsigned char *zkproof,
//        const unsigned char *spendAuthSig,
//        const unsigned char *sighashValue
//    );
    const unsigned char * c = (const unsigned char *) env->GetByteArrayElements(cv, nullptr);
    const unsigned char * a = (const unsigned char *) env->GetByteArrayElements(anchor, nullptr);
    const unsigned char * n = (const unsigned char *) env->GetByteArrayElements(nullifier, nullptr);
    const unsigned char * r = (const unsigned char *) env->GetByteArrayElements(rk, nullptr);
    const unsigned char * z = (const unsigned char *) env->GetByteArrayElements(zkproof, nullptr);
    const unsigned char * sp = (const unsigned char *) env->GetByteArrayElements(spendAuthSig, nullptr);
    const unsigned char * si = (const unsigned char *) env->GetByteArrayElements(sighashValue, nullptr);
    if (c == NULL || a == NULL || n == NULL || r == NULL || z == NULL || sp == NULL || si == NULL)
    {
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_check_spend((void *) ctx,c,a,n,r,z,sp,si));
    env->ReleaseByteArrayElements(cv,(jbyte*)c,0);
    env->ReleaseByteArrayElements(anchor,(jbyte*)a,0);
    env->ReleaseByteArrayElements(nullifier,(jbyte*)n,0);
    env->ReleaseByteArrayElements(rk,(jbyte*)r,0);
    env->ReleaseByteArrayElements(zkproof,(jbyte*)z,0);
    env->ReleaseByteArrayElements(spendAuthSig,(jbyte*)sp,0);
    env->ReleaseByteArrayElements(sighashValue,(jbyte*)si,0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingCheckOutput
 * Signature: (J[B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingCheckOutput
  (JNIEnv *env, jobject, jlong ctx, jbyteArray cv, jbyteArray cm, jbyteArray ephemeralKey, jbyteArray zkproof) {
//    bool librustzcash_sapling_check_output(
//        void *ctx,
//        const unsigned char *cv,
//        const unsigned char *cm,
//        const unsigned char *ephemeralKey,
//        const unsigned char *zkproof
//    );
    const unsigned char * cvPoint = (const unsigned char *) env->GetByteArrayElements(cv, nullptr);
    const unsigned char * cmPoint = (const unsigned char *) env->GetByteArrayElements(cm, nullptr);
    const unsigned char * e = (const unsigned char *) env->GetByteArrayElements(ephemeralKey, nullptr);
    const unsigned char * z = (const unsigned char *) env->GetByteArrayElements(zkproof, nullptr);
    if (cvPoint == NULL || cmPoint == NULL || e == NULL || z == NULL)
    {
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_check_output((void *) ctx,cvPoint,cmPoint,e,z));
    env->ReleaseByteArrayElements(cv,(jbyte*)cvPoint,0);
    env->ReleaseByteArrayElements(cm,(jbyte*)cmPoint,0);
    env->ReleaseByteArrayElements(ephemeralKey,(jbyte*)e,0);
    env->ReleaseByteArrayElements(zkproof,(jbyte*)z,0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingFinalCheck
 * Signature: (JJ[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingFinalCheck
  (JNIEnv * env, jobject, jlong ctx, jlong valueBalance, jbyteArray bindingSig, jbyteArray sighashValue) {
//    bool librustzcash_sapling_final_check(
//        void *ctx,
//        int64_t valueBalance,
//        const unsigned char *bindingSig,
//        const unsigned char *sighashValue
//    );
    const unsigned char * b = (const unsigned char *) env->GetByteArrayElements(bindingSig, nullptr);
    const unsigned char * s = (const unsigned char *) env->GetByteArrayElements(sighashValue, nullptr);
    if (b == NULL || s == NULL)
    {
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_final_check((void *) ctx,(int64_t) valueBalance,b,s));
    env->ReleaseByteArrayElements(bindingSig,(jbyte*)b,0);
    env->ReleaseByteArrayElements(sighashValue,(jbyte*)s,0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingCheckSpendNew
 * Signature: ([B[B[B[B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingCheckSpendNew
  (JNIEnv * env, jobject, jbyteArray cv, jbyteArray anchor, jbyteArray nullifier, jbyteArray rk, jbyteArray zkproof, jbyteArray spendAuthSig, jbyteArray sighashValue) {
//    bool librustzcash_sapling_check_spend_new(
//        const unsigned char *cv,
//        const unsigned char *anchor,
//        const unsigned char *nullifier,
//        const unsigned char *rk,
//        const unsigned char *zkproof,
//        const unsigned char *spendAuthSig,
//        const unsigned char *sighashValue
//    );
    const unsigned char * c = (const unsigned char *) env->GetByteArrayElements(cv, nullptr);
    const unsigned char * a = (const unsigned char *) env->GetByteArrayElements(anchor, nullptr);
    const unsigned char * n = (const unsigned char *) env->GetByteArrayElements(nullifier, nullptr);
    const unsigned char * r = (const unsigned char *) env->GetByteArrayElements(rk, nullptr);
    const unsigned char * z = (const unsigned char *) env->GetByteArrayElements(zkproof, nullptr);
    const unsigned char * sp = (const unsigned char *) env->GetByteArrayElements(spendAuthSig, nullptr);
    const unsigned char * si = (const unsigned char *) env->GetByteArrayElements(sighashValue, nullptr);
    if (c == NULL || a == NULL || n == NULL || r == NULL || z == NULL || sp == NULL || si == NULL)
    {
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_check_spend_new(c,a,n,r,z,sp,si));
    env->ReleaseByteArrayElements(cv,(jbyte*)c,0);
    env->ReleaseByteArrayElements(anchor,(jbyte*)a,0);
    env->ReleaseByteArrayElements(nullifier,(jbyte*)n,0);
    env->ReleaseByteArrayElements(rk,(jbyte*)r,0);
    env->ReleaseByteArrayElements(zkproof,(jbyte*)z,0);
    env->ReleaseByteArrayElements(spendAuthSig,(jbyte*)sp,0);
    env->ReleaseByteArrayElements(sighashValue,(jbyte*)si,0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingCheckOutputNew
 * Signature: ([B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingCheckOutputNew
  (JNIEnv *env, jobject, jbyteArray cv, jbyteArray cm, jbyteArray ephemeralKey, jbyteArray zkproof) {
//    bool librustzcash_sapling_check_output_new(
//        const unsigned char *cv,
//        const unsigned char *cm,
//        const unsigned char *ephemeralKey,
//        const unsigned char *zkproof
//    );
    const unsigned char * cvPoint = (const unsigned char *) env->GetByteArrayElements(cv, nullptr);
    const unsigned char * cmPoint = (const unsigned char *) env->GetByteArrayElements(cm, nullptr);
    const unsigned char * e = (const unsigned char *) env->GetByteArrayElements(ephemeralKey, nullptr);
    const unsigned char * z = (const unsigned char *) env->GetByteArrayElements(zkproof, nullptr);
    if (cvPoint == NULL || cmPoint == NULL || e == NULL || z == NULL)
    {
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_check_output_new(cvPoint,cmPoint,e,z));
    env->ReleaseByteArrayElements(cv,(jbyte*)cvPoint,0);
    env->ReleaseByteArrayElements(cm,(jbyte*)cmPoint,0);
    env->ReleaseByteArrayElements(ephemeralKey,(jbyte*)e,0);
    env->ReleaseByteArrayElements(zkproof,(jbyte*)z,0);
    return jb;
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingFinalCheckNew
 * Signature: (J[B[B[BI[BI)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingFinalCheckNew
  (JNIEnv * env, jobject, jlong valueBalance, jbyteArray bindingSig, jbyteArray sighashValue, jbyteArray spendCv, jint spendCvLen, jbyteArray outputCv, jint outputCvLen) {
//    bool librustzcash_sapling_final_check_new(
//        int64_t valueBalance,
//        const unsigned char *bindingSig,
//        const unsigned char *sighashValue,
//        const unsigned char *spendCv,
//        size_t spendCvLen,
//        const unsigned char *outputCv,
//        size_t outputCvLen,

//    );
    const unsigned char * b = (const unsigned char *) env->GetByteArrayElements(bindingSig, nullptr);
    const unsigned char * s = (const unsigned char *) env->GetByteArrayElements(sighashValue, nullptr);
    const unsigned char * scv = (const unsigned char *) env->GetByteArrayElements(spendCv, nullptr);
    const unsigned char * ocv = (const unsigned char *) env->GetByteArrayElements(outputCv, nullptr);

    if (b == NULL || s == NULL || scv == NULL || ocv == NULL)
    {
      return JNI_FALSE;
    }
    jboolean jb = bool2jboolean(librustzcash_sapling_final_check_new((int64_t) valueBalance,b,s,scv,(size_t) spendCvLen,ocv,(size_t) outputCvLen));
    env->ReleaseByteArrayElements(bindingSig,(jbyte*)b,0);
    env->ReleaseByteArrayElements(sighashValue,(jbyte*)s,0);
    env->ReleaseByteArrayElements(spendCv,(jbyte*)scv,0);
    env->ReleaseByteArrayElements(outputCv,(jbyte*)ocv,0);
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
    librustzcash_sapling_verification_ctx_free((void *) ctx);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashMerkleHash
 * Signature: (I[B[B[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashMerkleHash
  (JNIEnv *env, jobject, jint depth, jbyteArray a, jbyteArray b, jbyteArray result) {
//    void librustzcash_merkle_hash(
//        size_t depth,
//        const unsigned char *a,
//        const unsigned char *b,
//        unsigned char *result
//    );
    const unsigned char * aPoint = (const unsigned char *) env->GetByteArrayElements(a, nullptr);
    const unsigned char * bPoint = (const unsigned char *) env->GetByteArrayElements(b, nullptr);
    unsigned char * r = (unsigned char *) env->GetByteArrayElements(result, nullptr);
    if (aPoint == NULL || bPoint == NULL || r == NULL)
    {
      return;
    }
    librustzcash_merkle_hash((size_t) depth,aPoint,bPoint,r);
    env->ReleaseByteArrayElements(result,(jbyte*)r,0);
    env->ReleaseByteArrayElements(a,(jbyte*)aPoint,0);
    env->ReleaseByteArrayElements(b,(jbyte*)bPoint,0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashTreeUncommitted
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashTreeUncommitted
  (JNIEnv *env, jobject, jbyteArray result) {
//    void librustzcash_tree_uncommitted(
//        unsigned char *result
//    );

    unsigned char * r = (unsigned char *) env->GetByteArrayElements(result, nullptr);
    if (r == NULL)
    {
      return;
    }
    librustzcash_tree_uncommitted(r);
    env->ReleaseByteArrayElements(result,(jbyte*)r,0);
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashToScalar
 * Signature: ([B[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashToScalar
  (JNIEnv *env, jobject, jbyteArray input, jbyteArray result) {
//    void librustzcash_to_scalar(const unsigned char *input, unsigned char *result);

    const unsigned char * i = (const unsigned char *) env->GetByteArrayElements(input, nullptr);
    unsigned char * r = (unsigned char *) env->GetByteArrayElements(result, nullptr);
    librustzcash_to_scalar(i,r);
    if (r == NULL || i == NULL)
    {
      return;
    }
    env->ReleaseByteArrayElements(result,(jbyte*)r,0);
    env->ReleaseByteArrayElements(input,(jbyte*)i,0);
}
