//
// Created by ruipeng on 6/5/19.
//

#include "org_tron_common_zksnark_Librustzcash_LibrustzcashJNI.h"
#include "librustzcash.h"

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
    librustzcash_init_zksnark_params(
        (const codeunit*) env->GetStringUTFChars(spend_path, nullptr),
        (size_t) env->GetStringLength(spend_path),
        (const char*) env->GetStringUTFChars(spend_hash, nullptr),
        (const codeunit*)  env->GetStringUTFChars(output_path, nullptr),
        (size_t) env->GetStringLength(output_path),
        (const char*) env->GetStringUTFChars(output_hash, nullptr)
    );
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
    librustzcash_zip32_xsk_master(
        reinterpret_cast<const unsigned char *>(seed),
        (size_t) seedlen,
        reinterpret_cast<unsigned char *>(env->GetByteArrayElements(xsk_master, nullptr))
        );
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

    librustzcash_zip32_xsk_derive(reinterpret_cast<const unsigned char *>(
        env->GetByteArrayElements(xsk_parent, nullptr)),
        (uint32_t) i,
        reinterpret_cast<unsigned char *>(env->GetByteArrayElements(xsk_i, nullptr))
        );
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

    return bool2jboolean(librustzcash_zip32_xfvk_address(
        (const unsigned char *) env->GetByteArrayElements(xfvk, nullptr),
        (const unsigned char *) env->GetByteArrayElements(j, nullptr),
        (unsigned char *) env->GetByteArrayElements(j_ret, nullptr),
        (unsigned char *) env->GetByteArrayElements(addr_ret, nullptr))
        );
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashAskToAk
 * Signature: ([B[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashAskToAk
  (JNIEnv * env, jobject, jbyteArray ask, jbyteArray result) {
//    void librustzcash_ask_to_ak(const unsigned char *ask, unsigned char *result);
    jboolean isCopy = JNI_TRUE;
    librustzcash_ask_to_ak(
        (const unsigned char *) env->GetByteArrayElements(ask, nullptr),
        (unsigned char *) env-> GetByteArrayElements(result, &isCopy)
        );
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
    jboolean isCopy = JNI_TRUE;
    librustzcash_sapling_compute_nf(
        (const unsigned char *) env->GetByteArrayElements(diversifier, nullptr),
        (const unsigned char *) env->GetByteArrayElements(pk_d, nullptr),
        static_cast<const uint64_t>((int64_t) value),
        (const unsigned char *) env->GetByteArrayElements(r, nullptr),
        (const unsigned char *) env->GetByteArrayElements(ak, nullptr),
        (const unsigned char *) env->GetByteArrayElements(nk, nullptr),
        static_cast<const uint64_t>((int64_t) position),
        (unsigned char *) env->GetByteArrayElements(result, &isCopy)
    );
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashNskToNk
 * Signature: ([B[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashNskToNk
  (JNIEnv * env, jobject, jbyteArray nsk, jbyteArray result) {
//    void librustzcash_nsk_to_nk(const unsigned char *nsk, unsigned char *result);
    jboolean isCopy = JNI_TRUE;
    librustzcash_nsk_to_nk(
        (const unsigned char *) env->GetByteArrayElements(nsk, nullptr),
        (unsigned char *) env->GetByteArrayElements(result, &isCopy)
    );
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
    jboolean isCopy = JNI_TRUE;
    librustzcash_sapling_generate_r(
        (unsigned char *) env->GetByteArrayElements(result, &isCopy)
    );
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
    jboolean isCopy = JNI_TRUE;
    return bool2jboolean(librustzcash_sapling_ka_derivepublic(
        (const unsigned char *) env->GetByteArrayElements(diversifier, nullptr),
        (const unsigned char *) env->GetByteArrayElements(esk, nullptr),
        (unsigned char *) env->GetByteArrayElements(result, &isCopy)
    ));
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashCrhIvk
 * Signature: ([B[B[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashCrhIvk
  (JNIEnv *env, jobject, jbyteArray ak, jbyteArray nk, jbyteArray result) {
//    void librustzcash_crh_ivk(const unsigned char *ak, const unsigned char *nk, unsigned char *result);
    jboolean isCopy = JNI_TRUE;
    librustzcash_crh_ivk(
        (const unsigned char *) env->GetByteArrayElements(ak, nullptr),
        (const unsigned char *) env->GetByteArrayElements(nk, nullptr),
        (unsigned char *) env->GetByteArrayElements(result, &isCopy)
    );
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
  (JNIEnv *, jobject, jbyteArray p, jbyteArray sk, jbyteArray result) {
  return bool2jboolean(librustzcash_sapling_ka_agree(
    reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(p, nullptr)),
    reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(sk, nullptr)),
    reinterpret_cast<unsigned char *>(env->GetByteArrayElements(result, nullptr))
  ));
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashCheckDiversifier
 * Signature: ([B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashCheckDiversifier
  (JNIEnv * env, jobject, jbyteArray diversifier) {
    return bool2jboolean(
        librustzcash_check_diversifier(
            reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(diversifier, nullptr))));
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashIvkToPkd
 * Signature: ([B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashIvkToPkd
  (JNIEnv *, jobject, jbyteArray ivk, jbyteArray diversifier, jbyteArray result) {
  return bool2jboolean(
    librustzcash_ivk_to_pkd(
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(ivk, nullptr)),
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(diversifier, nullptr)),
      reinterpret_cast<unsigned char *>(env->GetByteArrayElements(result, nullptr))
    )
  );
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingComputeCm
 * Signature: ([B[BJ[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingComputeCm
  (JNIEnv *, jobject, jbyteArray diversifier, jbyteArray pk_d, jlong value, jbyteArray r, jbyteArray result) {
  return bool2jboolean(
    librustzcash_sapling_compute_cm(
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(diversifier, nullptr)),
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(pk_d, nullptr)),
      reinterpret_cast<const uint64_t>(value),
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(r, nullptr)),
      reinterpret_cast<unsigned char *>(env->GetByteArrayElements(result, nullptr))
    )
  );
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingProvingCtxInit
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingProvingCtxInit
  (JNIEnv *, jobject) {
  return librustzcash_sapling_proving_ctx_init();
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingSpendProof
 * Signature: (J[B[B[B[B[BJ[B[B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingSpendProof
  (JNIEnv *, jobject, jlong ctx, jbyteArray ak, jbyteArray nsk, jbyteArray diversifier, jbyteArray rcm,jbyteArray ar,
  jlong value, jbyteArray anchor, jbyteArray witness, jbyteArray cv, jbyteArray rk, jbyteArray zkproof) {
  return bool2jboolean(
    librustzcash_sapling_spend_proof(
      &ctx,
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(ak, nullptr)),
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(nsk, nullptr)),
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(diversifier, nullptr)),
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(rcm, nullptr)),
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(ar, nullptr)),
      reinterpret_cast<const uint64_t>(value),
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(anchor, nullptr)),
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(witness, nullptr)),
      reinterpret_cast<unsigned char *>(env->GetByteArrayElements(cv, nullptr)),
      reinterpret_cast<unsigned char *>(env->GetByteArrayElements(rk, nullptr)),
      reinterpret_cast<unsigned char *>(env->GetByteArrayElements(zkproof, nullptr)),
    )
  );
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingOutputProof
 * Signature: (J[B[B[B[BJ[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingOutputProof
  (JNIEnv *, jobject, jlong ctx, jbyteArray esk, jbyteArray diversifier, jbyteArray pk_d, jbyteArray rcm, jlong value, jbyteArray cv, jbyteArray zkproof) {
  return bool2jboolean(
    librustzcash_sapling_output_proof(
      &ctx,
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(esk, nullptr)),
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(diversifier, nullptr)),
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(pk_d, nullptr)),
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(rcm, nullptr)),
      reinterpret_cast<const uint64_t>(value),
      reinterpret_cast<unsigned char *>(env->GetByteArrayElements(cv, nullptr)),
      reinterpret_cast<unsigned char *>(env->GetByteArrayElements(zkproof, nullptr)),
    )
  );
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingSpendSig
 * Signature: ([B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingSpendSig
  (JNIEnv *, jobject, jbyteArray ask, jbyteArray ar, jbyteArray sighash, jbyteArray result) {
  return bool2jboolean(
    librustzcash_sapling_spend_sig(
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(ask, nullptr)),
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(ar, nullptr)),
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(sighash, nullptr)),
      reinterpret_cast<unsigned char *>(env->GetByteArrayElements(result, nullptr)),
    )
  );
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingBindingSig
 * Signature: (JJ[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingBindingSig
  (JNIEnv *, jobject, jlong ctx, jlong valueBalance, jbyteArray sighash, jbyteArray result) {
  return bool2jboolean(
    librustzcash_sapling_binding_sig(
      &ctx,
      reinterpret_cast<int64_t>(value),
      reinterpret_cast<const unsigned char *>(env->GetByteArrayElements(sighash, nullptr)),
      reinterpret_cast<unsigned char *>(env->GetByteArrayElements(result, nullptr)),
    )
  );
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashSaplingProvingCtxFree
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingProvingCtxFree
  (JNIEnv *, jobject, jlong ctx) {
  librustzcash_sapling_proving_ctx_free(&ctx);
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
    return bool2jboolean(librustzcash_sapling_check_spend(
        (void *) ctx,
        (const unsigned char *) env->GetByteArrayElements(cv, nullptr),
        (const unsigned char *) env->GetByteArrayElements(anchor, nullptr),
        (const unsigned char *) env->GetByteArrayElements(nullifier, nullptr),
        (const unsigned char *) env->GetByteArrayElements(rk, nullptr),
        (const unsigned char *) env->GetByteArrayElements(zkproof, nullptr),
        (const unsigned char *) env->GetByteArrayElements(spendAuthSig, nullptr),
        (const unsigned char *) env->GetByteArrayElements(sighashValue, nullptr)
    ));
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
    return bool2jboolean(librustzcash_sapling_check_output(
        (void *) ctx,
        (const unsigned char *) env->GetByteArrayElements(cv, nullptr),
        (const unsigned char *) env->GetByteArrayElements(cm, nullptr),
        (const unsigned char *) env->GetByteArrayElements(ephemeralKey, nullptr),
        (const unsigned char *) env->GetByteArrayElements(zkproof, nullptr)
    ));
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
    return bool2jboolean(librustzcash_sapling_final_check(
        (void *) ctx,
        (int64_t) valueBalance,
        (const unsigned char *) env->GetByteArrayElements(bindingSig, nullptr),
        (const unsigned char *) env->GetByteArrayElements(sighashValue, nullptr)
    ));
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
    jboolean isCopy = JNI_TRUE;
    librustzcash_merkle_hash(
        (size_t) depth,
        (const unsigned char *) env->GetByteArrayElements(a, nullptr),
        (const unsigned char *) env->GetByteArrayElements(b, nullptr),
        (unsigned char *) env->GetByteArrayElements(result, &isCopy)
    );
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
    jboolean isCopy = JNI_TRUE;
    librustzcash_tree_uncommitted(
        (unsigned char *) env->GetByteArrayElements(result, &isCopy)
        );
}

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashToScalar
 * Signature: ([B[B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashToScalar
  (JNIEnv *env, jobject, jbyteArray input, jbyteArray result) {
//    void librustzcash_to_scalar(const unsigned char *input, unsigned char *result);
    jboolean isCopy = JNI_TRUE;
    librustzcash_to_scalar(
        (const unsigned char *) env->GetByteArrayElements(input, nullptr),
        (unsigned char *) env->GetByteArrayElements(result, &isCopy)
    );
}
