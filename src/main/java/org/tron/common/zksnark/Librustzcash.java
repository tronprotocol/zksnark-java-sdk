/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.tron.common.zksnark;

class Librustzcash
{
    private static final LibrustzcashJNI INSTANCE = new LibrustzcashJNI();

    public void librustzcashInitZksnarkParams(String spendPath, String spendHash, String outputPath, String outputHash)
    {
        INSTANCE.librustzcashInitZksnarkParams(spendPath, spendHash, outputPath, outputHash);
    }

    public void librustzcashZip32XskMaster(byte[] data, int size, byte[] mBytes)
    {
        INSTANCE.librustzcashZip32XskMaster(data, size, mBytes);
    }

    public void librustzcashZip32XskDerive(byte[] xskParent, int i, byte[] xskI)
    {
        INSTANCE.librustzcashZip32XskDerive(xskParent, i, xskI);
    }

    public boolean librustzcashZip32XfvkAddress(byte[] xfvk, byte[] j, byte[] jRet, byte[] addrRet)
    {
        return INSTANCE.librustzcashZip32XfvkAddress(xfvk, j, jRet, addrRet);
    }

    public void librustzcashAskToAk(byte[] ask, byte[] result)
    {
        INSTANCE.librustzcashAskToAk(ask, result);
    }

    public void librustzcashSaplingComputeNf(byte[] d, byte[] pkd, long value, byte[] r, byte[] ak, byte[] nk, long position, byte[] result)
    {
        INSTANCE.librustzcashSaplingComputeNf(d, pkd, value, r, ak, nk, position, result);
    }

    public void librustzcashNskToNk(byte[] nsk, byte[] result)
    {
        INSTANCE.librustzcashNskToNk(nsk, result);
    }

    public void librustzcashSaplingGenerateR(byte[] r)
    {
        INSTANCE.librustzcashSaplingGenerateR(r);
    }

    public boolean librustzcashSaplingKaDerivepublic(byte[] diversifier, byte[] esk, byte[] result)
    {
        return INSTANCE.librustzcashSaplingKaDerivepublic(diversifier, esk, result);
    }

    public void librustzcashCrhIvk(byte[] ak, byte[] nk, byte[] result)
    {
        INSTANCE.librustzcashCrhIvk(ak, nk, result);
    }

    public boolean librustzcashSaplingKaAgree(byte[] p, byte[] sk, byte[] result)
    {
        return INSTANCE.librustzcashSaplingKaAgree(p, sk, result);
    }

    public boolean librustzcashCheckDiversifier(byte[] diversifier)
    {
        return INSTANCE.librustzcashCheckDiversifier(diversifier);
    }

    public boolean librustzcashIvkToPkd(byte[] ivk, byte[] diversifier, byte[] result)
    {
        return INSTANCE.librustzcashIvkToPkd(ivk, diversifier, result);
    }

    public boolean librustzcashSaplingComputeCm(byte[] diversifier, byte[] pkd, long value, byte[] r, byte[] result)
    {
        return INSTANCE.librustzcashSaplingComputeCm(diversifier, pkd, value, r, result);
    }

    public long librustzcashSaplingProvingCtxInit()
    {
        return INSTANCE.librustzcashSaplingProvingCtxInit();
    }

    public boolean librustzcashSaplingSpendProof(long ctx, byte[] ak, byte[] nsk, byte[] diversifier, byte[] rcm, byte[] ar, long value, byte[] anchor, byte[] witness, byte[] cv, byte[] rk, byte[] zkproof)
    {
        return INSTANCE.librustzcashSaplingSpendProof(ctx, ak, nsk, diversifier, rcm, ar, value, anchor, witness, cv, rk, zkproof);
    }

    public boolean librustzcashSaplingOutputProof(long ctx, byte[] esk, byte[] diversifier, byte[] pkd, byte[] rcm, long value, byte[] cv, byte[] zkproof)
    {
        return INSTANCE.librustzcashSaplingOutputProof(ctx, esk, diversifier, pkd, rcm, value, cv, zkproof);
    }

    public boolean librustzcashSaplingSpendSig(byte[] ask, byte[] ar, byte[] sighash, byte[] result)
    {
        return INSTANCE.librustzcashSaplingSpendSig(ask, ar, sighash, result);
    }

    public boolean librustzcashSaplingBindingSig(long ctx, long valueBalance, byte[] sighash, byte[] result)
    {
        return INSTANCE.librustzcashSaplingBindingSig(ctx, valueBalance, sighash, result);
    }

    public void librustzcashSaplingProvingCtxFree(long ctx)
    {
        INSTANCE.librustzcashSaplingProvingCtxFree(ctx);
    }

    public long librustzcashSaplingVerificationCtxInit()
    {
        return INSTANCE.librustzcashSaplingVerificationCtxInit();
    }

    public boolean librustzcashSaplingCheckSpend(long ctx, byte[] cv, byte[] anchor, byte[] nullifier, byte[] rk, byte[] zkproof, byte[] spendAuthSig, byte[] sighashValue)
    {
        return INSTANCE.librustzcashSaplingCheckSpend(ctx, cv, anchor, nullifier, rk, zkproof, spendAuthSig, sighashValue);
    }

    public boolean librustzcashSaplingCheckOutput(long ctx, byte[] cv, byte[] cm, byte[] ephemeralKey, byte[] zkproof)
    {
        return INSTANCE.librustzcashSaplingCheckOutput(ctx, cv, cm, ephemeralKey, zkproof);
    }

    public boolean librustzcashSaplingFinalCheck(long ctx, long valueBalance, byte[] bindingSig, byte[] sighashValue)
    {
        return INSTANCE.librustzcashSaplingFinalCheck(ctx, valueBalance, bindingSig, sighashValue);
    }

    public void librustzcashSaplingVerificationCtxFree(long ctx)
    {
        INSTANCE.librustzcashSaplingVerificationCtxFree(ctx);
    }

    public void librustzcashMerkleHash(int depth, byte[] a, byte[] b, byte[] result)
    {
        INSTANCE.librustzcashMerkleHash(depth, a, b, result);
    }

    public void librustzcashTreeUncommitted(byte[] result)
    {
        INSTANCE.librustzcashTreeUncommitted(result);
    }

    public void librustzcashToScalar(byte[] input, byte[] result)
    {
        INSTANCE.librustzcashToScalar(input, result);
    }

    public boolean librustzcashSaplingCheckSpendNew(byte[] cv, byte[] anchor, byte[] nullifier, byte[] rk, byte[] zkproof, byte[] spendAuthSig, byte[] sighashValue)
    {
        return INSTANCE.librustzcashSaplingCheckSpendNew(cv, anchor, nullifier, rk, zkproof, spendAuthSig, sighashValue);
    }

    public boolean librustzcashSaplingCheckOutputNew(byte[] cv, byte[] cm, byte[] ephemeralKey, byte[] zkproof)
    {
        return INSTANCE.librustzcashSaplingCheckOutputNew(cv, cm, ephemeralKey, zkproof);
    }

    public boolean librustzcashSaplingFinalCheckNew(long valueBalance, byte[] bindingSig, byte[] sighashValue, byte[] spendCv, int spendCvLen, byte[] outputCv, int outputCvLen)
    {
        return INSTANCE.librustzcashSaplingFinalCheckNew(valueBalance, bindingSig, sighashValue, spendCv, spendCvLen, outputCv, outputCvLen);
    }

    private static class LibrustzcashJNI
    {
        private native void librustzcashInitZksnarkParams(String spendPath, String spendHash, String outputPath, String outputHash);

        private native void librustzcashZip32XskMaster(byte[] data, int size, byte[] mBytes);

        private native void librustzcashZip32XskDerive(byte[] xskParent, int i, byte[] xskI);

        private native boolean librustzcashZip32XfvkAddress(byte[] xfvk, byte[] j, byte[] jRet, byte[] addrRet);

        private native void librustzcashAskToAk(byte[] ask, byte[] result);

        private native void librustzcashSaplingComputeNf(byte[] d, byte[] pkd, long value, byte[] r, byte[] ak, byte[] nk, long position, byte[] result);

        private native void librustzcashNskToNk(byte[] nsk, byte[] result);

        private native void librustzcashSaplingGenerateR(byte[] r);

        private native boolean librustzcashSaplingKaDerivepublic(byte[] diversifier, byte[] esk, byte[] result);

        private native void librustzcashCrhIvk(byte[] ak, byte[] nk, byte[] result);

        private native boolean librustzcashSaplingKaAgree(byte[] p, byte[] sk, byte[] result);

        private native boolean librustzcashCheckDiversifier(byte[] diversifier);

        private native boolean librustzcashIvkToPkd(byte[] ivk, byte[] diversifier, byte[] result);

        private native boolean librustzcashSaplingComputeCm(byte[] diversifier, byte[] pkd, long value, byte[] r, byte[] result);

        private native long librustzcashSaplingProvingCtxInit();

        private native boolean librustzcashSaplingSpendProof(long ctx, byte[] ak, byte[] nsk, byte[] diversifier, byte[] rcm, byte[] ar, long value, byte[] anchor, byte[] witness, byte[] cv, byte[] rk, byte[] zkproof);

        private native boolean librustzcashSaplingOutputProof(long ctx, byte[] esk, byte[] diversifier, byte[] pkd, byte[] rcm, long value, byte[] cv, byte[] zkproof);

        private native boolean librustzcashSaplingSpendSig(byte[] ask, byte[] ar, byte[] sighash, byte[] result);

        private native boolean librustzcashSaplingBindingSig(long ctx, long valueBalance, byte[] sighash, byte[] result);

        private native void librustzcashSaplingProvingCtxFree(long ctx);

        private native long librustzcashSaplingVerificationCtxInit();

        private native boolean librustzcashSaplingCheckSpend(long ctx, byte[] cv, byte[] anchor, byte[] nullifier, byte[] rk, byte[] zkproof, byte[] spendAuthSig, byte[] sighashValue);

        private native boolean librustzcashSaplingCheckOutput(long ctx, byte[] cv, byte[] cm, byte[] ephemeralKey, byte[] zkproof);

        private native boolean librustzcashSaplingFinalCheck(long ctx, long valueBalance, byte[] bindingSig, byte[] sighashValue);

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
        private native void librustzcashMerkleHash(int depth, byte[] a, byte[] b, byte[] result);

        /// Writes the "uncommitted" note value for empty leaves
        /// of the merkle tree. `result` must be a valid pointer
        /// to 32 bytes which will be written.
        private native void librustzcashTreeUncommitted(byte[] result);

        private native void librustzcashToScalar(byte[] input, byte[] result);

        private native boolean librustzcashSaplingCheckSpendNew(byte[] cv, byte[] anchor, byte[] nullifier, byte[] rk, byte[] zkproof, byte[] spendAuthSig, byte[] sighashValue);

        private native boolean librustzcashSaplingCheckOutputNew(byte[] cv, byte[] cm, byte[] ephemeralKey, byte[] zkproof);

        private native boolean librustzcashSaplingFinalCheckNew(long valueBalance, byte[] bindingSig, byte[] sighashValue, byte[] spendCv, int spendCvLen, byte[] outputCv, int outputCvLen);
    }
}
