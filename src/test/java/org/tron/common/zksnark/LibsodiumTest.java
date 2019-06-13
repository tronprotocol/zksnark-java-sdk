package org.tron.common.zksnark;

import com.sun.org.apache.xerces.internal.impl.dv.util.HexBin;
import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;
import org.tron.common.util.Utils;

public class LibsodiumTest {
	public static int NOTEENCRYPTION_AUTH_BYTES = 16;
	public static int ZC_NOTEPLAINTEXT_LEADING = 1;
	public static int ZC_V_SIZE = 8;
	public static int ZC_R_SIZE = 32;
	public static int ZC_MEMO_SIZE = 512;
	public static int ZC_DIVERSIFIER_SIZE = 11;
	public static int ZC_JUBJUB_POINT_SIZE = 32;
	public static int ZC_JUBJUB_SCALAR_SIZE = 32;
	public static int NOTEENCRYPTION_CIPHER_KEYSIZE = 32;
	
	public static int ZC_ENCPLAINTEXT_SIZE =
			(ZC_NOTEPLAINTEXT_LEADING + ZC_DIVERSIFIER_SIZE + ZC_V_SIZE + ZC_R_SIZE + ZC_MEMO_SIZE);
	public static int ZC_OUTPLAINTEXT_SIZE = (ZC_JUBJUB_POINT_SIZE + ZC_JUBJUB_SCALAR_SIZE);
	public static int ZC_ENCCIPHERTEXT_SIZE =
			(ZC_ENCPLAINTEXT_SIZE + NOTEENCRYPTION_AUTH_BYTES);
	public static int ZC_OUTCIPHERTEXT_SIZE =
			(ZC_OUTPLAINTEXT_SIZE + NOTEENCRYPTION_AUTH_BYTES);
	
	public static byte[] ZTRON_EXPANDSEED_PERSONALIZATION = {'Z', 't', 'r', 'o', 'n', '_', 'E', 'x',
			'p', 'a', 'n', 'd', 'S', 'e', 'e', 'd'};
	
	public static final int crypto_generichash_blake2b_PERSONALBYTES = 16;
	public static final int crypto_aead_chacha20poly1305_ietf_NPUBBYTES = 12;
	public static final int crypto_aead_chacha20poly1305_IETF_NPUBBYTES = crypto_aead_chacha20poly1305_ietf_NPUBBYTES;
	
	public static Libsodium instance;
	
	@BeforeClass
	public static void init(){
		instance = LibsodiumWrapper.getInstance();
	}
	
	@BeforeClass
	public static void librustzcashInitZksnarkParams() {
		LibrustzcashWrapper.getInstance().librustzcashInitZksnarkParams(
				Utils.getParamsFile("sapling-spend.params"),
				"8270785a1a0d0bc77196f000ee6d221c9c9894f55307bd9357c3f0105d31ca63991ab91324160d8f53e2bbd3c2633a6eb8bdf5205d822e7f3f73edac51b2b70c",
				Utils.getParamsFile("sapling-output.params"),
				"657e3d38dbb5cb5e7dd2970e8b03d69b4787dd907285b5a7f0790dcc8072f60bf593b32cc2d1c030e00ff5ae64bf84c5c3beb84ddc841d48264b4a171744d028"
		);
	}
	
	@Test
	public void testCryptoGenerichashBlake2BInitSaltPersonal(){
		long state = instance.cryptoGenerichashBlake2BStateInit();
		
		byte t = 0x00;
		byte[] sk = HexBin.decode("ff2c06269315333a9207f817d2eca0ac555ca8f90196976324c7756504e7c9ee");
		byte[] ask = new byte[64];
		byte[] blob = new byte[33];
		System.arraycopy(sk, 0, blob, 0, 32);
		blob[32] = t;
		
		instance.cryptoGenerichashBlake2BInitSaltPersonal(
				state, null, 0, 64, null, ZTRON_EXPANDSEED_PERSONALIZATION);
		instance.cryptoGenerichashBlake2BUpdate(state, blob, 33);
		instance.cryptoGenerichashBlake2BFinal(state, ask, 64);
		
		Assert.assertArrayEquals(HexBin.decode("e1e61e6789fd867cf1556515a3aed68c76f691e3f3e6facb4fb3a9dc84bbdb7b5ab0ddd896907f683c41cc978ec1e9867c46a1be52e3047da2fc39e51f593f6c"),
				ask);
	}
	
	@Test
	public void testCryptoGenerichashBlake2BUpdate (){
		long state = instance.cryptoGenerichashBlake2BStateInit();
		
		byte t = 0x01;
		byte[] sk = HexBin.decode("ff2c06269315333a9207f817d2eca0ac555ca8f90196976324c7756504e7c9ee");
		byte[] nsk = new byte[64];
		byte[] blob = new byte[33];
		System.arraycopy(sk, 0, blob, 0, 32);
		blob[32] = t;
		
		instance.cryptoGenerichashBlake2BInitSaltPersonal(
				state, null, 0, 64, null, ZTRON_EXPANDSEED_PERSONALIZATION);
		instance.cryptoGenerichashBlake2BUpdate(state, blob, 33);
		instance.cryptoGenerichashBlake2BFinal(state, nsk, 64);
		
		Assert.assertArrayEquals(HexBin.decode("72cc2d7a4c51d11e0322c44bcab25ea379925d06a6fbc955e24cc27fea7f956cd9b9fee0471a6c950ae2ebc015b1b8aad21e6da97447f03d00cbe92410ac8a22"),
				nsk);
	}
	
	@Test
	public void testCryptoGenerichashBlake2BFinal(){
		long state = instance.cryptoGenerichashBlake2BStateInit();
		
		byte t = 0x02;
		byte[] sk = HexBin.decode("ff2c06269315333a9207f817d2eca0ac555ca8f90196976324c7756504e7c9ee");
		byte[] ovk = new byte[64];
		byte[] blob = new byte[33];
		System.arraycopy(sk, 0, blob, 0, 32);
		blob[32] = t;
		
		instance.cryptoGenerichashBlake2BInitSaltPersonal(
				state, null, 0, 64, null, ZTRON_EXPANDSEED_PERSONALIZATION);
		instance.cryptoGenerichashBlake2BUpdate(state, blob, 33);
		instance.cryptoGenerichashBlake2BFinal(state, ovk, 64);
		
		Assert.assertArrayEquals(HexBin.decode("a5d78d08a2450fcfd445bf260f8d35d130366a857ef40398121439d98eb84a8a0c934d89823282309fb3212488763bfe7c94e7e57dcab84060734fe45e74dc3a"),
				ovk);
	}
	
	@Test
	public void testCryptoGenerichashBlake2BSaltPersonal(){
		byte[] block = HexBin.decode("a5d78d08a2450fcfd445bf260f8d35d130366a857ef40398121439d98eb84a8a86e590debb08355db1fd611b57433abe0853ef8f777f6124ad4bebe4008e15ce87619091b2e7cb72d7912d2363890984307ccf9506c9f319d14e723b1b4ed71225db42bb79eecd05448e1be8ebb1ce6f333a1ff3e45e18985c954eb611a71e47");
		byte[] ock = new byte[NOTEENCRYPTION_CIPHER_KEYSIZE];
		byte[] personalization = new byte[crypto_generichash_blake2b_PERSONALBYTES];
		byte[] temp = "Ztron_Derive_ock".getBytes();
		System.arraycopy(temp, 0, personalization, 0, temp.length);
		if (instance.cryptoGenerichashBlake2BSaltPersonal(ock, NOTEENCRYPTION_CIPHER_KEYSIZE,
				block, 128,
				null, 0, // No key.
				null,    // No salt.
				personalization
		) != 0) {
			throw new RuntimeException("cryptoGenerichashBlake2BSaltPersonal function failure");
		}
		Assert.assertArrayEquals(HexBin.decode("1abde642b85656189e3b67196f3f18aa8856d7ede463d517b5ed800185732d9f"),
				ock);
	}
	
	@Test
	public void testCryptoAeadChacha20Poly1305IetfDecrypt(){
		byte[] cipher_nonce = new byte[crypto_aead_chacha20poly1305_IETF_NPUBBYTES];
		byte[] ock = HexBin.decode("1abde642b85656189e3b67196f3f18aa8856d7ede463d517b5ed800185732d9f");
		byte[] OutCiphertext = HexBin.decode("29998e86fb13139e441e9a2ce8e9131aae53ed31e26baed7be73a2a7e3b007c019e56cb55b7852a187220ea92161712d1e2f88fa3337dd369cc44801169fcdbab8ad8003f14dfc656850b50418e06839");
		byte[] plaintext = new byte[ZC_OUTPLAINTEXT_SIZE];
		//decrypt out by ock, get esk, pk_d
		if (instance.cryptoAeadChacha20Poly1305IetfDecrypt(plaintext, null,
				null,
				OutCiphertext, ZC_OUTCIPHERTEXT_SIZE,
				null,
				0,
				cipher_nonce, ock) != 0) {
			throw new RuntimeException("cryptoAeadChacha20Poly1305IetfDecrypt function failure");
		}
		Assert.assertArrayEquals(HexBin.decode("8d05b9988cc9f4216cc086eb7e4fec033aafc108f5866b770bffba5a675bbb9994fd11a331169bbd2dea726ced59947c716358fa4d4b35ecf42d1d5ae18f6402"),
				plaintext);
	}
	
	@Test
	public void testCryptoAeadChacha20Poly1305IetfEncrypt(){
		byte[] cipherNonce = new byte[crypto_aead_chacha20poly1305_IETF_NPUBBYTES];
		byte[] k_enc = HexBin.decode("cf9961c91dcea84ffdd0ce54ae2d86f815c988275701b47585d64dbf2b1b11ee");
		byte[] message = HexBin.decode("015aafbda15b790d38637017a00f00000000000083d36fd4c8eebec516c3a8ce2fe4832e01eb57bd7f9f9c9e0bd68cc69a5b0f06a357e71719903bd55db273738b68c16f01411f25ed190ba6d7e423f1f4652ec6c49a4f70dd8cdafc8f1bc5eeef59bb6836def5fa075d1a2bdd4af5a4af52efae47409cf5e19fd1a89f29fb89d0ad1f386bfefbc5a14cfcd78183d23465219ef0e0cfe347e4f046929c9e43104825ca1b0f4449bd6b2dc9623c40501a29dfd91277a487c48489bce90826123c33d57c19cadb3974a3d534b7d4408f6173e7c111916cca703599610bb406b2beceed5387dd10d778c7fae068bcddaf7941a2eb191ff81d6fbb97c10250bff130e6030ba3e2d87354a1aab08dea1f8edab0282452373d5d8e0cec6b4a5a5c5bbffd77aa4f5e6659e6355dc748821410876389b68b23b879a579c8a344479c6806b8c77f4e3f98ac0b19634b337744dce2f8db23fa237c7778e9be6a0f9cb06f76d478360e4e737c43a580125cd9d361f588e98c875b7234a56cf7f71df48859cb9996f4040a6aee420cd3a3001c2a905fce0cb9db65710c42494a800c50369da25a405e845bf1d87617704e556f2de5164fc9af9ac5f66b928cdec5bfb07e6973dc294089512cd36afa58aee34f0ae8586b92fd7d4b262868ca4d1addc34893a46445e97d01f8359226589269e4f9e4eb65e6872951d6ee16c841cece3633c3baf60a9ce970669b5c8f51cab9a8262554c40ac70558c50cb127ff04794278f0f7ca0eee4b89429148fde8eb57bf109a7db2ab0111");
		byte[] ciphertext = new byte[ZC_ENCCIPHERTEXT_SIZE];
		instance.cryptoAeadChacha20Poly1305IetfEncrypt(ciphertext, null, message,
				ZC_ENCPLAINTEXT_SIZE, null, 0, null, cipherNonce, k_enc);
		Assert.assertArrayEquals(HexBin.decode("261de089eb840f976828cd9e1307bf68f7f989b3f79588365cee1391ab341d2dbfb2969c577ed70dc4243937a136674f55fbd271d70e2fde8fec249ff9ba199036e701d3f993dbb443109ea8f3171779232fe8fc6c36ed9d4925d1344877ffe103b96324612ea97eecaedfeb3aad2f221ff5620a9b4fb5f7da3f06af67c08704e43e815f57f020310a661f593725c4a8ddd61cf5933d6f3ca0acc34e2d9a69be79055bfa6dfd8109d13355758e32efbb3c0fa9f9d1a99c589999f23055a54c3b13fe8dd8bcf7562509654932227525bbe2536c7ad3ae16f62390b69f4cd78dd777b1434a193b5cfb911b0bce4b762399667e73de2a3936916e5661886b476bf50564f7d3a909b875a46c215cc2170a1f33c6ad81cf9aabeaf05e8516abaa8b824aef6d1c12d1cbf8a7d06256f1e7a9ea4fdfd6648324ee4b6a0a16d7dfa88d1ba41451dec470ad87130b584b827a7731a981e474cefccab800e4d083ff7d71facf5da8d20c73f75b72106f5521094794cc325d68a3a37f59cc95df24512aae7abb472fed2116aa56ef26be584808f6f2039b07412670f21e142de1771396383976997015821a41a31e5e1229790779117c58f0b519d02f96a57d485455ffb0f3ae1f76c57e614cfa9c07532845b97e8472e01060c32d47a6538d989d717251bc9e7044d45b121ebf180e79cf4d7154d5a7c1342c2e42541bec4da04602ec6eedf92b6f64f13860ee5e74218ff41e638ca9fa10e75eb393a6a4790644284e9fe7fd2a898997dc3a8d8ede6e2a0fe861b437dfd8045b37e52770dc4aa0e860b6fd60c57650"),
				ciphertext);
	}
}
