package org.tron.common.zksnark;

public class Libsodium {
  private static final LibsodiumJNI INSTANCE = new LibsodiumJNI();

  public long cryptoGenerichashBlake2BStateInit() {
    return INSTANCE.crypto_generichash_blake2b_state_init();
  }

  public void cryptoGenerichashBlake2BStateFree(long state) {
    INSTANCE.crypto_generichash_blake2b_state_free(state);
  }

  public int cryptoGenerichashBlake2BInitSaltPersonal(
      long state, byte[] key, int keylen, int outlen, byte[] salt, byte[] personal) {
    return INSTANCE.crypto_generichash_blake2b_init_salt_personal(
        state, key, keylen, outlen, salt, personal);
  }

  public int cryptoGenerichashBlake2BUpdate(
      long state, byte[] in, long inlen) {
    return INSTANCE.crypto_generichash_blake2b_update(state, in, inlen);
  }

  public int cryptoGenerichashBlake2BFinal(
      long state, byte[] out, int outlen) {
    return INSTANCE.crypto_generichash_blake2b_final(state, out, outlen);
  }

  public int cryptoGenerichashBlake2BSaltPersonal(
      byte[] out, int outlen, byte[] in, long inlen, byte[] key, int keylen, byte[] salt, byte[] personal) {
    return INSTANCE.crypto_generichash_blake2b_salt_personal(out, outlen, in, inlen, key, keylen, salt, personal);
  }

  public int cryptoAeadChacha20Poly1305IetfDecrypt(
      byte[] m, long[] mlen_p, byte[] nsec, byte[] c, long clen, byte[] ad, long adlen, byte[] npub, byte[] k) {
    return INSTANCE.crypto_aead_chacha20poly1305_ietf_decrypt(m, mlen_p, nsec, c, clen, ad, adlen, npub, k);
  }

  public int cryptoAeadChacha20Poly1305IetfEncrypt(
      byte[] c, long[] clen_p, byte[] m, long mlen, byte[] ad, long adlen, byte[] nsec, byte[] npub, byte[] k) {
    return INSTANCE.crypto_aead_chacha20poly1305_ietf_encrypt(c, clen_p, m, mlen, ad, adlen, nsec, npub, k);
  }

  private static class LibsodiumJNI {

    private native long crypto_generichash_blake2b_state_init();

    private native void crypto_generichash_blake2b_state_free(long state);

    private native int crypto_generichash_blake2b_init_salt_personal(
        long state, byte[] key, int keylen, int outlen, byte[] salt, byte[] personal);

    private native int crypto_generichash_blake2b_update(
        long state, byte[] in, long inlen);

    private native int crypto_generichash_blake2b_final(
        long state, byte[] out, int outlen);

    private native int crypto_generichash_blake2b_salt_personal(
        byte[] out, int outlen, byte[] in, long inlen, byte[] key, int keylen, byte[] salt, byte[] personal);

    private native int crypto_aead_chacha20poly1305_ietf_decrypt(
        byte[] m, long[] mlen_p, byte[] nsec, byte[] c, long clen, byte[] ad, long adlen, byte[] npub, byte[] k);

    private native int crypto_aead_chacha20poly1305_ietf_encrypt(
        byte[] c, long[] clen_p, byte[] m, long mlen, byte[] ad, long adlen, byte[] nsec, byte[] npub, byte[] k);
  }

}
