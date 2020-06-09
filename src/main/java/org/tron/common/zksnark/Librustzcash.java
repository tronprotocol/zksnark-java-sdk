package org.tron.common.zksnark;

class Librustzcash {
  private static final LibrustzcashJNI INSTANCE = new LibrustzcashJNI();

  public void librustzcashInitZksnarkParams(String spend_path, String spend_hash,
      String output_path, String output_hash) {
    INSTANCE.librustzcashInitZksnarkParams(spend_path, spend_hash, output_path, output_hash);
  }

  public void librustzcashZip32XskMaster(byte[] data, int size, byte[] m_bytes) {
    INSTANCE.librustzcashZip32XskMaster(data, size, m_bytes);
  }

  public void librustzcashZip32XskDerive(byte[] xsk_parent, int i, byte[] xsk_i) {
    INSTANCE.librustzcashZip32XskDerive(xsk_parent, i, xsk_i);
  }

  public boolean librustzcashZip32XfvkAddress(byte[] xfvk, byte[] j, byte[] j_ret, byte[] addr_ret) {
    return INSTANCE.librustzcashZip32XfvkAddress(xfvk, j, j_ret, addr_ret);
  }

  public void librustzcashAskToAk(byte[] ask, byte[] result) {
    INSTANCE.librustzcashAskToAk(ask, result);
  }

  public void librustzcashSaplingComputeNf(byte[] d, byte[] pk_d, long value_, byte[] r, byte[] ak,
      byte[] nk, long position, byte[] result) {
    INSTANCE.librustzcashSaplingComputeNf(d, pk_d, value_, r, ak, nk, position, result);
  }

  public void librustzcashNskToNk(byte[] nsk, byte[] result) {
    INSTANCE.librustzcashNskToNk(nsk, result);
  }

  public void librustzcashSaplingGenerateR(byte[] r) {
    INSTANCE.librustzcashSaplingGenerateR(r);
  }

  public boolean librustzcashSaplingKaDerivepublic(byte[] diversifier, byte[] esk, byte[] result) {
    return INSTANCE.librustzcashSaplingKaDerivepublic(diversifier, esk, result);
  }

  public void librustzcashCrhIvk(byte[] ak, byte[] nk, byte[] result) {
    INSTANCE.librustzcashCrhIvk(ak, nk, result);
  }

  public boolean librustzcashSaplingKaAgree(byte[] p, byte[] sk, byte[] result) {
    return INSTANCE.librustzcashSaplingKaAgree(p, sk, result);
  }

  public boolean librustzcashCheckDiversifier(byte[] diversifier) {
    return INSTANCE.librustzcashCheckDiversifier(diversifier);
  }

  public boolean librustzcashIvkToPkd(byte[] ivk, byte[] diversifier, byte[] result) {
    return INSTANCE.librustzcashIvkToPkd(ivk, diversifier, result);
  }

  public boolean librustzcashSaplingComputeCm(byte[] diversifier, byte[] pk_d, long value, byte[] r,
      byte[] result) {
    return INSTANCE.librustzcashSaplingComputeCm(diversifier, pk_d, value, r, result);
  }

  public long librustzcashSaplingProvingCtxInit() {
    return INSTANCE.librustzcashSaplingProvingCtxInit();
  }

  public boolean librustzcashSaplingSpendProof(long ctx, byte[] ak, byte[] nsk, byte[] diversifier,
      byte[] rcm, byte[] ar, long value, byte[] anchor, byte[] witness, byte[] cv, byte[] rk,
      byte[] zkproof) {
    return INSTANCE.librustzcashSaplingSpendProof(
        ctx, ak, nsk, diversifier, rcm, ar, value, anchor, witness, cv, rk, zkproof);
  }

  public boolean librustzcashSaplingOutputProof(long ctx, byte[] esk, byte[] diversifier,
      byte[] pk_d, byte[] rcm, long value, byte[] cv, byte[] zkproof) {
    return INSTANCE.librustzcashSaplingOutputProof(
        ctx, esk, diversifier, pk_d, rcm, value, cv, zkproof);
  }

  public boolean librustzcashSaplingSpendSig(byte[] ask, byte[] ar, byte[] sighash, byte[] result) {
    return INSTANCE.librustzcashSaplingSpendSig(ask, ar, sighash, result);
  }

  public boolean librustzcashSaplingBindingSig(long ctx, long valueBalance, byte[] sighash,
      byte[] result) {
    return INSTANCE.librustzcashSaplingBindingSig(ctx, valueBalance, sighash, result);
  }

  public void librustzcashSaplingProvingCtxFree(long ctx) {
    INSTANCE.librustzcashSaplingProvingCtxFree(ctx);
  }

  public long librustzcashSaplingVerificationCtxInit() {
    return INSTANCE.librustzcashSaplingVerificationCtxInit();
  }

  public boolean librustzcashSaplingCheckSpend(long ctx, byte[] cv, byte[] anchor,
      byte[] nullifier, byte[] rk, byte[] zkproof, byte[] spendAuthSig, byte[] sighashValue) {
    return INSTANCE
        .librustzcashSaplingCheckSpend(ctx, cv, anchor, nullifier, rk, zkproof, spendAuthSig, sighashValue);
  }

  public boolean librustzcashSaplingCheckOutput(long ctx, byte[] cv, byte[] cm,
      byte[] ephemeralKey, byte[] zkproof) {
    return INSTANCE.librustzcashSaplingCheckOutput(ctx, cv, cm, ephemeralKey, zkproof);
  }

  public boolean librustzcashSaplingFinalCheck(long ctx, long valueBalance, byte[] bindingSig,
      byte[] sighashValue) {
    return INSTANCE.librustzcashSaplingFinalCheck(ctx, valueBalance, bindingSig, sighashValue);
  }

  public void librustzcashSaplingVerificationCtxFree(long ctx) {
    INSTANCE.librustzcashSaplingVerificationCtxFree(ctx);
  }

  public void librustzcashMerkleHash(int depth, byte[] a, byte[] b, byte[] result
  ) {
    INSTANCE.librustzcashMerkleHash(depth, a, b, result);
  }

  public void librustzcashTreeUncommitted(byte[] result) {
    INSTANCE.librustzcashTreeUncommitted(result);
  }

  public void librustzcashToScalar(byte[] input, byte[] result) {
    INSTANCE.librustzcashToScalar(input, result);
  }

  public boolean librustzcashSaplingCheckSpendNew(byte[] cv, byte[] anchor, byte[] nullifier,
      byte[] rk, byte[] zkproof, byte[] spendAuthSig, byte[] sighashValue) {
    return INSTANCE.librustzcashSaplingCheckSpendNew(cv, anchor, nullifier, rk, zkproof,
        spendAuthSig, sighashValue);
  }

  public boolean librustzcashSaplingCheckOutputNew(byte[] cv, byte[] cm, byte[] ephemeralKey,
      byte[] zkproof) {
    return INSTANCE.librustzcashSaplingCheckOutputNew(cv, cm, ephemeralKey, zkproof);
  }

  public boolean librustzcashSaplingFinalCheckNew(long valueBalance, byte[] bindingSig, byte[] sighashValue,
                                                  byte[] spendCv, int spendCvLen, byte[] outputCv, int outputCvLen) {
    return INSTANCE.librustzcashSaplingFinalCheckNew(valueBalance, bindingSig, sighashValue, spendCv, spendCvLen, outputCv, outputCvLen);
  }

  private static class LibrustzcashJNI {

//    static {
//      try {
//        System.load(Utils.getLibraryByName("libzksnark-java-sdk"));
//      } catch (IOException e) {
//        e.printStackTrace();
//        System.exit(-1);
//      }
//    }

    private native void librustzcashInitZksnarkParams(String spend_path, String spend_hash,
        String output_path, String output_hash);

    private native void librustzcashZip32XskMaster(byte[] data, int size, byte[] m_bytes);

    private native void librustzcashZip32XskDerive(byte[] xsk_parent, int i, byte[] xsk_i);

    private native  boolean librustzcashZip32XfvkAddress(byte[] xfvk, byte[] j, byte[] j_ret, byte[] addr_ret);

    private native void librustzcashAskToAk(byte[] ask, byte[] result);

    private native void librustzcashSaplingComputeNf(byte[] d, byte[] pk_d, long value_, byte[] r, byte[] ak,
        byte[] nk, long position, byte[] result);

    private native void librustzcashNskToNk(byte[] nsk, byte[] result);

    private native void librustzcashSaplingGenerateR(byte[] r);

    private native boolean librustzcashSaplingKaDerivepublic(byte[] diversifier, byte[] esk, byte[] result);

    private native void librustzcashCrhIvk(byte[] ak, byte[] nk, byte[] result);

    private native boolean librustzcashSaplingKaAgree(byte[] p, byte[] sk, byte[] result);

    private native boolean librustzcashCheckDiversifier(byte[] diversifier);

    private native boolean librustzcashIvkToPkd(byte[] ivk, byte[] diversifier, byte[] result);

    private native boolean librustzcashSaplingComputeCm(byte[] diversifier, byte[] pk_d, long value, byte[] r,
        byte[] result);

    private native long librustzcashSaplingProvingCtxInit();

    private native boolean librustzcashSaplingSpendProof(long ctx, byte[] ak, byte[] nsk, byte[] diversifier,
        byte[] rcm, byte[] ar, long value, byte[] anchor, byte[] witness, byte[] cv, byte[] rk,
        byte[] zkproof);

    private native boolean librustzcashSaplingOutputProof(long ctx, byte[] esk, byte[] diversifier,
        byte[] pk_d, byte[] rcm, long value, byte[] cv, byte[] zkproof);

    private native boolean librustzcashSaplingSpendSig(byte[] ask, byte[] ar, byte[] sighash, byte[] result);

    private native boolean librustzcashSaplingBindingSig(long ctx, long valueBalance, byte[] sighash,
        byte[] result);

    private native void librustzcashSaplingProvingCtxFree(long ctx);

    private native long librustzcashSaplingVerificationCtxInit();

    private native boolean librustzcashSaplingCheckSpend(long ctx, byte[] cv, byte[] anchor,
        byte[] nullifier, byte[] rk, byte[] zkproof, byte[] spendAuthSig, byte[] sighashValue);

    private native boolean librustzcashSaplingCheckOutput(long ctx, byte[] cv, byte[] cm,
        byte[] ephemeralKey, byte[] zkproof);

    private native boolean librustzcashSaplingFinalCheck(long ctx, long valueBalance, byte[] bindingSig,
        byte[] sighashValue);

    private native void librustzcashSaplingVerificationCtxFree(long ctx);

    /// Computes a merkle tree hash for a given depth.
    /// The `depth` parameter should not be larger than
    /// 62.
    ///
    /// `a` and `b` each must be of length 32, and must each
    /// be scalars of BLS12-381.
    ///
    /// The result of the merkle tree hash is placed in
    /// `result`, which must also be of length 32.
    private native void librustzcashMerkleHash(int depth, byte[] a, byte[] b, byte[] result
    );

    /// Writes the "uncommitted" note value for empty leaves
    /// of the merkle tree. `result` must be a valid pointer
    /// to 32 bytes which will be written.
    private native void librustzcashTreeUncommitted(byte[] result);

    private native void librustzcashToScalar(byte[] input, byte[] result);

    private native boolean librustzcashSaplingCheckSpendNew(byte[] cv, byte[] anchor,
        byte[] nullifier, byte[] rk, byte[] zkproof, byte[] spendAuthSig, byte[] sighashValue);

    private native boolean librustzcashSaplingCheckOutputNew(byte[] cv, byte[] cm,
        byte[] ephemeralKey, byte[] zkproof);

    private native boolean librustzcashSaplingFinalCheckNew(long valueBalance, byte[] bindingSig, byte[] sighashValue,
                                                            byte[] spendCv, int spendCvLen, byte[] outputCv, int outputCvLen);

  }
}

