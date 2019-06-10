package org.tron.common.zksnark;

public class Libsodium {
  private static final LibrustzcashJNI INSTANCE = new LibrustzcashJNI();

  private static class LibrustzcashJNI {
    private native int crypto_generichash_blake2b_init_salt_personal(
        crypto_generichash_blake2b_state.ByReference state, byte[] key, int keylen, int outlen,
        byte[] salt, byte[] personal);

    private native int crypto_generichash_blake2b_update(crypto_generichash_blake2b_state.ByReference state,
        byte[] in, long inlen);

    private native int crypto_generichash_blake2b_final(crypto_generichash_blake2b_state.ByReference state,
        byte[] out, int outlen);

    private native int crypto_generichash_blake2b_salt_personal(byte[] out, int outlen, byte[] in, long inlen,
        byte[] key, int keylen, byte[] salt, byte[] personal);

    private native int crypto_aead_chacha20poly1305_ietf_decrypt(byte[] m, long[] mlen_p, byte[] nsec, byte[] c,
        long clen, byte[] ad, long adlen, byte[] npub, byte[] k);

    private native int crypto_aead_chacha20poly1305_ietf_encrypt(byte[] c, long[] clen_p, byte[] m,
        long mlen, byte[] ad, long adlen, byte[] nsec, byte[] npub, byte[] k);


  }

}
