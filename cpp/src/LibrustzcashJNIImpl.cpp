//
// Created by ruipeng on 6/5/19.
//

#include "org_tron_common_zksnark_Librustzcash_LibrustzcashJNI.h"
#include "librustzcash.h"

/*
 * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
 * Method:    librustzcashInitZksnarkParams
 * Signature: ([BILjava/lang/String;[BILjava/lang/String;)V
 */

void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashInitZksnarkParams
  (JNIEnv * env, jobject object, jbyteArray spend_path, jint spend_length, jstring spend_hash, jbyteArray output_path, jint output_length, jstring output_hash) {
    librustzcash_init_zksnark_params(
        (const codeunit*) env->GetByteArrayElements(spend_path, nullptr),
        (size_t) spend_length,
        (const char*) env->GetStringChars(spend_hash, nullptr),
        (const codeunit*)  env->GetByteArrayElements(output_path, nullptr),
        (size_t) output_length,
        (const char*) env->GetStringChars(output_hash, nullptr)
    );
}

///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashZip32XskMaster
// * Signature: ([BI[B)V
// */
//JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashZip32XskMaster
//  (JNIEnv *, jobject, jbyteArray, jint, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashZip32XskDerive
// * Signature: ([BI[B)V
// */
//JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashZip32XskDerive
//  (JNIEnv *, jobject, jbyteArray, jint, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashZip32XfvkAddress
// * Signature: ([B[B[B[B)Z
// */
//JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashZip32XfvkAddress
//  (JNIEnv *, jobject, jbyteArray, jbyteArray, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashAskToAk
// * Signature: ([B[B)V
// */
//JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashAskToAk
//  (JNIEnv *, jobject, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingComputeNf
// * Signature: ([B[BJ[B[B[BJ[B)V
// */
//JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingComputeNf
//  (JNIEnv *, jobject, jbyteArray, jbyteArray, jlong, jbyteArray, jbyteArray, jbyteArray, jlong, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashNskToNk
// * Signature: ([B[B)V
// */
//JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashNskToNk
//  (JNIEnv *, jobject, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingGenerateR
// * Signature: ([B)V
// */
//JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingGenerateR
//  (JNIEnv *, jobject, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingKaDerivepublic
// * Signature: ([B[B[B)Z
// */
//JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingKaDerivepublic
//  (JNIEnv *, jobject, jbyteArray, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashCrhIvk
// * Signature: ([B[B[B)V
// */
//JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashCrhIvk
//  (JNIEnv *, jobject, jbyteArray, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingKaAgree
// * Signature: ([B[B[B)Z
// */
//JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingKaAgree
//  (JNIEnv *, jobject, jbyteArray, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashCheckDiversifier
// * Signature: ([B)Z
// */
//JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashCheckDiversifier
//  (JNIEnv *, jobject, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashIvkToPkd
// * Signature: ([B[B[B)Z
// */
//JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashIvkToPkd
//  (JNIEnv *, jobject, jbyteArray, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingComputeCm
// * Signature: ([B[BJ[B[B)Z
// */
//JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingComputeCm
//  (JNIEnv *, jobject, jbyteArray, jbyteArray, jlong, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingProvingCtxInit
// * Signature: ()J
// */
//JNIEXPORT jlong JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingProvingCtxInit
//  (JNIEnv *, jobject);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingSpendProof
// * Signature: (J[B[B[B[B[BJ[B[B[B[B[B)Z
// */
//JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingSpendProof
//  (JNIEnv *, jobject, jlong, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jlong, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingOutputProof
// * Signature: (J[B[B[B[BJ[B[B)Z
// */
//JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingOutputProof
//  (JNIEnv *, jobject, jlong, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jlong, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingSpendSig
// * Signature: ([B[B[B[B)Z
// */
//JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingSpendSig
//  (JNIEnv *, jobject, jbyteArray, jbyteArray, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingBindingSig
// * Signature: (JJ[B[B)Z
// */
//JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingBindingSig
//  (JNIEnv *, jobject, jlong, jlong, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingProvingCtxFree
// * Signature: (J)V
// */
//JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingProvingCtxFree
//  (JNIEnv *, jobject, jlong);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingVerificationCtxInit
// * Signature: ()J
// */
//JNIEXPORT jlong JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingVerificationCtxInit
//  (JNIEnv *, jobject);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingCheckSpend
// * Signature: (J[B[B[B[B[B[B[B)Z
// */
//JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingCheckSpend
//  (JNIEnv *, jobject, jlong, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingCheckOutput
// * Signature: (J[B[B[B[B)Z
// */
//JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingCheckOutput
//  (JNIEnv *, jobject, jlong, jbyteArray, jbyteArray, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingFinalCheck
// * Signature: (JJ[B[B)Z
// */
//JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingFinalCheck
//  (JNIEnv *, jobject, jlong, jlong, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashSaplingVerificationCtxFree
// * Signature: (J)V
// */
//JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashSaplingVerificationCtxFree
//  (JNIEnv *, jobject, jlong);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashMerkleHash
// * Signature: (I[B[B[B)V
// */
//JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashMerkleHash
//  (JNIEnv *, jobject, jint, jbyteArray, jbyteArray, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashTreeUncommitted
// * Signature: ([B)V
// */
//JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashTreeUncommitted
//  (JNIEnv *, jobject, jbyteArray);
//
///*
// * Class:     org_tron_common_zksnark_Librustzcash_LibrustzcashJNI
// * Method:    librustzcashToScalar
// * Signature: ([B[B)V
// */
//JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Librustzcash_00024LibrustzcashJNI_librustzcashToScalar
//  (JNIEnv *, jobject, jbyteArray, jbyteArray);
