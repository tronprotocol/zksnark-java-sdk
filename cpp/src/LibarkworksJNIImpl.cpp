#include "org_tron_common_zksnark_Libarkworks_LibarkworksJNI.h"
#include "libarkworks.h"
#include <iostream>

jboolean bool2jbool(bool b) {
    if (b) {
        return JNI_TRUE;
    } else {
        return JNI_FALSE;
    }
}

/*
 * Class:     org_tron_common_zksnark_Libarkworks_LibarkworksJNI
 * Method:    libarkworksG1IsValid
 * Signature: ([B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Libarkworks_00024LibarkworksJNI_libarkworksG1IsValid
  (JNIEnv * env, jobject, jbyteArray x, jbyteArray y) {
    unsigned char * x_p = (unsigned char *) env->GetByteArrayElements(x, nullptr);
    unsigned char * y_p = (unsigned char *) env->GetByteArrayElements(y, nullptr);
    if (x_p == NULL || y_p == NULL) {
      return JNI_FALSE;
    }

    bool result = libarkworks_g1_is_valid(x_p, y_p);
    env->ReleaseByteArrayElements(x, (jbyte*) x_p, 0);
    env->ReleaseByteArrayElements(y, (jbyte*) y_p, 0);
    return bool2jbool(result);
}

/*
 * Class:     org_tron_common_zksnark_Libarkworks_LibarkworksJNI
 * Method:    libarkworksG2IsValid
 * Signature: ([B[B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Libarkworks_00024LibarkworksJNI_libarkworksG2IsValid
  (JNIEnv * env, jobject, jbyteArray a, jbyteArray b, jbyteArray c, jbyteArray d) {
    unsigned char * a_p = (unsigned char *) env->GetByteArrayElements(a, nullptr);
    unsigned char * b_p = (unsigned char *) env->GetByteArrayElements(b, nullptr);
    unsigned char * c_p = (unsigned char *) env->GetByteArrayElements(c, nullptr);
    unsigned char * d_p = (unsigned char *) env->GetByteArrayElements(d, nullptr);
    if (a_p == NULL || b_p == NULL || c_p == NULL || d_p == NULL) {
      return JNI_FALSE;
    }

    bool result = libarkworks_g2_is_valid(a_p, b_p, c_p, d_p);
    env->ReleaseByteArrayElements(a, (jbyte*) a_p, 0);
    env->ReleaseByteArrayElements(b, (jbyte*) b_p, 0);
    env->ReleaseByteArrayElements(c, (jbyte*) c_p, 0);
    env->ReleaseByteArrayElements(d, (jbyte*) d_p, 0);
    return bool2jbool(result);
}

/*
 * Class:     org_tron_common_zksnark_Libarkworks_LibarkworksJNI
 * Method:    libarkworksAddG1
 * Signature: ([B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Libarkworks_00024LibarkworksJNI_libarkworksAddG1
  (JNIEnv * env, jobject, jbyteArray a, jbyteArray b, jbyteArray result) {
    unsigned char * a_p = (unsigned char *) env->GetByteArrayElements(a, nullptr);
    unsigned char * b_p = (unsigned char *) env->GetByteArrayElements(b, nullptr);
    unsigned char * result_p = (unsigned char *) env->GetByteArrayElements(result, nullptr);
    if (a_p == NULL || b_p == NULL || result_p == NULL) {
      return JNI_FALSE;
    }

    bool success = libarkworks_add_g1(a_p, b_p, result_p);
    env->ReleaseByteArrayElements(a, (jbyte*) a_p, 0);
    env->ReleaseByteArrayElements(b, (jbyte*) b_p, 0);
    env->ReleaseByteArrayElements(result, (jbyte*) result_p, 0);
    return bool2jbool(success);
}

/*
 * Class:     org_tron_common_zksnark_Libarkworks_LibarkworksJNI
 * Method:    libarkworksMulG1
 * Signature: ([B[B[B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Libarkworks_00024LibarkworksJNI_libarkworksMulG1
  (JNIEnv * env, jobject, jbyteArray p, jbyteArray s, jbyteArray result) {
    unsigned char * p_p = (unsigned char *) env->GetByteArrayElements(p, nullptr);
    unsigned char * s_p = (unsigned char *) env->GetByteArrayElements(s, nullptr);
    unsigned char * result_p = (unsigned char *) env->GetByteArrayElements(result, nullptr);
    if (p_p == NULL || s_p == NULL || result_p == NULL) {
      return JNI_FALSE;
    }

    bool success = libarkworks_mul_g1(p_p, s_p, result_p);
    env->ReleaseByteArrayElements(p, (jbyte*) p_p, 0);
    env->ReleaseByteArrayElements(s, (jbyte*) s_p, 0);
    env->ReleaseByteArrayElements(result, (jbyte*) result_p, 0);
    return bool2jbool(success);
}

/*
 * Class:     org_tron_common_zksnark_Libarkworks_LibarkworksJNI
 * Method:    libarkworksPairingCheck
 * Signature: ([B[BI)Z
 */
JNIEXPORT jboolean JNICALL Java_org_tron_common_zksnark_Libarkworks_00024LibarkworksJNI_libarkworksPairingCheck
  (JNIEnv * env, jobject, jbyteArray g1s, jbyteArray g2s, jint pairs) {
    unsigned char * g1s_p = (unsigned char *) env->GetByteArrayElements(g1s, nullptr);
    unsigned char * g2s_p = (unsigned char *) env->GetByteArrayElements(g2s, nullptr);
    if (g1s_p == NULL || g2s_p == NULL) {
      return JNI_FALSE;
    }

    bool success = libarkworks_pairing_check(g1s_p, g2s_p, pairs);
    env->ReleaseByteArrayElements(g1s, (jbyte*) g1s_p, 0);
    env->ReleaseByteArrayElements(g2s, (jbyte*) g2s_p, 0);
    return bool2jbool(success);
}

/*
 * Class:     org_tron_common_zksnark_Libarkworks_LibarkworksJNI
 * Method:    libarkworksRandomG1
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Libarkworks_00024LibarkworksJNI_libarkworksRandomG1
    (JNIEnv * env, jobject, jbyteArray g1) {
    unsigned char * g1_p = (unsigned char *) env->GetByteArrayElements(g1, nullptr);
    if (g1_p == NULL) {
      return;
    }

    libarkworks_random_g1(g1_p);
    env->ReleaseByteArrayElements(g1, (jbyte*) g1_p, 0);
}

/*
 * Class:     org_tron_common_zksnark_Libarkworks_LibarkworksJNI
 * Method:    libarkworksRandomG2
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_org_tron_common_zksnark_Libarkworks_00024LibarkworksJNI_libarkworksRandomG2
  (JNIEnv * env, jobject, jbyteArray g2) {
    unsigned char * g2_p = (unsigned char *) env->GetByteArrayElements(g2, nullptr);
    if (g2_p == NULL) {
      return;
    }
    
    libarkworks_random_g2(g2_p);
    env->ReleaseByteArrayElements(g2, (jbyte*)g2_p, 0);
}