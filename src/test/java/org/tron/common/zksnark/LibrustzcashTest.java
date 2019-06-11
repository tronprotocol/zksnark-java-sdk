package org.tron.common.zksnark;

import com.sun.org.apache.xerces.internal.impl.dv.util.HexBin;
import java.util.Arrays;
import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;
import org.tron.common.util.Utils;

public class LibrustzcashTest {

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
  public void librustzcashCheckDiversifier() {
    System.out.println(Arrays.toString(HexBin.decode("55ed53f0d6550b472cdf38")));
    boolean ret = LibrustzcashWrapper.getInstance()
        .librustzcashCheckDiversifier(HexBin.decode("55ed53f0d6550b472cdf38"));
    Assert.assertFalse(ret);
    System.out.println(Arrays.toString(HexBin.decode("02D72D7702F90B0FE71165")));
    ret = LibrustzcashWrapper.getInstance()
        .librustzcashCheckDiversifier(HexBin.decode("02D72D7702F90B0FE71165"));
    Assert.assertTrue(ret);
  }

  @Test
  public void librustzcashSaplingVerificationCtxInitAndFree() {
    long ctx = LibrustzcashWrapper.getInstance().librustzcashSaplingVerificationCtxInit();
    System.out.println(ctx);
    Assert.assertNotEquals(0L, ctx);
    LibrustzcashWrapper.getInstance().librustzcashSaplingVerificationCtxFree(ctx);
  }

  @Test
  public void librustzcashComputeCm() {
    byte[] diversifier = HexBin.decode("0000000000000000000000");
    byte[] pk_d = HexBin.decode("20001646fe036e09506e844a4acc668793a964cde6da3d5e2fd5f92c36546ba3");
    long value = 40;
    byte[] r = HexBin.decode("c7cd0ca6ad3c27cbea38e94575f221d0037d9076c4cf64cb37e9a72d657ad401");
    byte[] result = new byte[32];
    boolean ret = LibrustzcashWrapper.getInstance()
        .librustzcashSaplingComputeCm(diversifier, pk_d, value, r, result);
    Assert.assertFalse(ret);

    byte[] pk_d2 = HexBin
        .decode("2dc01646fe036e09506e844a4acc668793a964cde6da3d5e2fd5f92c36546ba3");

    boolean ret2 = LibrustzcashWrapper.getInstance()
        .librustzcashSaplingComputeCm(diversifier, pk_d2, value, r, result);
    Assert.assertTrue(ret2);
  }

  @Test
  public void librustzcashWholeProcessCorrect() {
    long ctx = LibrustzcashWrapper.getInstance().librustzcashSaplingProvingCtxInit();
    //generate spend proof
    {
      byte[] ak = HexBin.decode("2021c369f4b901cc4f37d80eac2d676aa41beb2a2d835d5120005714bc687657");
      byte[] nsk = HexBin
          .decode("48ea637742229ee87b8ebffd435b27469bee46ecb7732a6e3fb27939d442c006");

      byte[] d = HexBin.decode("5aafbda15b790d38637017");
      long value = 10 * 1000000;
      byte[] rcm = HexBin
          .decode("26328c28c46fb3c3a5e0648e5fc6b312a93f9fa93b5275cf79d4f71a30cd4d00");
      byte[] alpha = HexBin
          .decode("994f6f29a8205747c510406e331d2a49faa1b517e630a4c55d9fe3856a9e030b");
      byte[] anchor = HexBin
          .decode("f2097ce0e430f74a87d5d6c574f483165c781bd6b2423ec4824505890606554f");
      byte[] voucherPath = HexBin.decode(
          "2020b2eed031d4d6a4f02a097f80b54cc1541d4163c6b6f5971f88b6e41d35c538142012935f14b676509b81eb49ef25f39269ed72309238b4c145803544b646dca62d20e1f34b034d4a3cd28557e2907ebf990c918f64ecb50a94f01d6fda5ca5c7ef722028e7b841dcbc47cceb69d7cb8d94245fb7cb2ba3a7a6bc18f13f945f7dbd6e2a20a5122c08ff9c161d9ca6fc462073396c7d7d38e8ee48cdb3bea7e2230134ed6a20d2e1642c9a462229289e5b0e3b7f9008e0301cbb93385ee0e21da2545073cb582016d6252968971a83da8521d65382e61f0176646d771c91528e3276ee45383e4a20fee0e52802cb0c46b1eb4d376c62697f4759f6c8917fa352571202fd778fd712204c6937d78f42685f84b43ad3b7b00f81285662f85c6a68ef11d62ad1a3ee0850200769557bc682b1bf308646fd0b22e648e8b9e98f57e29f5af40f6edb833e2c492008eeab0c13abd6069e6310197bf80f9c1ea6de78fd19cbae24d4a520e6cf3023208d5fa43e5a10d11605ac7430ba1f5d81fb1b68d29a640405767749e841527673206aca8448d8263e547d5ff2950e2ed3839e998d31cbc6ac9fd57bc6002b15921620cd1c8dbf6e3acc7a80439bc4962cf25b9dce7c896f3a5bd70803fc5a0e33cf00206edb16d01907b759977d7650dad7e3ec049af1a3d875380b697c862c9ec5d51c201ea6675f9551eeb9dfaaa9247bc9858270d3d3a4c5afa7177a984d5ed1be245120d6acdedf95f608e09fa53fb43dcd0990475726c5131210c9e5caeab97f0e642f20bd74b25aacb92378a871bf27d225cfc26baca344a1ea35fdd94510f3d157082c201b77dac4d24fb7258c3c528704c59430b630718bec486421837021cf75dab65120ec677114c27206f5debc1c1ed66f95e2b1885da5b7be3d736b1de98579473048204777c8776a3b1e69b73a62fa701fa4f7a6282d9aee2c7a6b82e7937d7081c23c20ba49b659fbd0b7334211ea6a9d9df185c757e70aa81da562fb912b84f49bce722043ff5457f13b926b61df552d4e402ee6dc1463f99a535f9a713439264d5b616b207b99abdc3730991cc9274727d7d82d28cb794edbc7034b4f0053ff7c4b68044420d6c639ac24b46bd19341c91b13fdcab31581ddaf7f1411336a271f3d0aa52813208ac9cf9c391e3fd42891d27238a81a8a5c1d3a72b1bcbea8cf44a58ce738961320912d82b2c2bca231f71efcf61737fbf0a08befa0416215aeef53e8bb6d23390a20e110de65c907b9dea4ae0bd83a4b0a51bea175646a64c12b4c9f931b2cb31b4920d8283386ef2ef07ebdbb4383c12a739a953a4d6e0d6fb1139a4036d693bfbb6c20ffe9fc03f18b176c998806439ff0bb8ad193afdb27b2ccbc88856916dd804e3420817de36ab2d57feb077634bca77819c8e0bd298c04f6fed0e6a83cc1356ca1552001000000000000000000000000000000000000000000000000000000000000000000000000000000");
      byte[] cv = new byte[32];
      byte[] rk = new byte[32];
      byte[] zkproof = new byte[192];

      boolean ret = LibrustzcashWrapper.getInstance()
          .librustzcashSaplingSpendProof(ctx, ak,
              nsk,
              d,
              rcm,
              alpha,
              value,
              anchor,
              voucherPath,
              cv,
              rk,
              zkproof);
      Assert.assertTrue(ret);
      Assert.assertFalse(Arrays.equals(zkproof, new byte[192]));
    }
    //generate output proof
    {
      byte[] esk = HexBin
          .decode("a5e43cbfc344872d1c4c54d16ea11aeb3031925b2afcbdc84ffeddde644bce06");
      byte[] d = HexBin.decode("0000000000000000000000");
      byte[] pkD = HexBin
          .decode("a071d91f1d86ceffd5f19ad4187333ee820a4e018656e16380404e0c1696b9d8");
      byte[] rcm = HexBin
          .decode("95d90bb5efb179a739949293c81861821860678de7afa9a241588e414ebd7707");

      long value = 1000000;
      byte[] cv = new byte[32];
      byte[] zkproof = new byte[192];

      boolean ret = LibrustzcashWrapper.getInstance()
          .librustzcashSaplingOutputProof(ctx, esk,
              d,
              pkD,
              rcm,
              value,
              cv,
              zkproof);
      Assert.assertTrue(ret);
      Assert.assertFalse(Arrays.equals(zkproof, new byte[192]));
    }
    //create binding sig
    {
      long valueBalance = 9000000;
      byte[] sighash = HexBin
          .decode("2e99758548972a8e8822ad47fa1017ff72f06f3ff6a016851f45c398732bc50c");
      byte[] result = new byte[64];
      boolean ret = LibrustzcashWrapper.getInstance()
          .librustzcashSaplingBindingSig(ctx, valueBalance, sighash, result);
      Assert.assertTrue(ret);
      Assert.assertFalse(Arrays.equals(result, new byte[64]));
    }

    // create spend sig
    {
      byte[] ak = HexBin.decode("a12362562419d519ae4c53e40622af451a3f134d10edf499baaa2e4fd3c75204");
      byte[] alpha = HexBin
          .decode("994f6f29a8205747c510406e331d2a49faa1b517e630a4c55d9fe3856a9e030b");
      byte[] SigHash = HexBin
          .decode("2e99758548972a8e8822ad47fa1017ff72f06f3ff6a016851f45c398732bc50c");
      byte[] result = new byte[64];
      boolean ret = LibrustzcashWrapper.getInstance()
          .librustzcashSaplingSpendSig(ak, alpha, SigHash, result);
      Assert.assertTrue(ret);
      Assert.assertFalse(Arrays.equals(result, new byte[64]));
    }
    LibrustzcashWrapper.getInstance().librustzcashSaplingProvingCtxFree(ctx);

    ctx = LibrustzcashWrapper.getInstance().librustzcashSaplingVerificationCtxInit();
    // check spend proof
    {
      byte[] cv = HexBin.decode("e7a0d3dd2dfcac201a9d6d048275120ebe772a186dcc54c59126ed46b4d3ac2b");
      byte[] Anchor = HexBin
          .decode("f2097ce0e430f74a87d5d6c574f483165c781bd6b2423ec4824505890606554f");
      byte[] nf = HexBin.decode("f5c35350812bb75c8607e0283fe8c32bb92a529a025bd3f74ebb9bf89ac52348");
      byte[] rk = HexBin.decode("2b1c55975c854c1922330bea5786536a97d5b2b10b77b503b506b07e7b09ac22");
      byte[] zkproof = HexBin.decode(
          "8c01e0be140fbe19d6a54469993a06af6b7cb3dc432c3f96479642d0319cc304bd4de106c5ef682d0ed313c9fdae3308a319089650d7e92ad6180d2a4a9fa057c662b8bd2dffd74447fde4cca0c94e00e8c76c5beb0ef6893f67b86aae03dfec197e63326803633c264a8f683a0c1131ff25a2d9f9bff97a6011d986fb73925ec523f9edfcc645fe3b787919e4c47f838a3fd1b04682c1c3ab2f8c6f369d8c74712ca74ed28bc7f723d466a5830d0b18eefa58a9cf7f242c4d29047674bc3eff");
      byte[] spendAuthSig = HexBin.decode(
          "30dc7662f0621cbb4c4a93e8624b73ce6d110b4af6e9ec671e3072db6474339fa869c30020588c11c1ff5b268b183505d059f7870df4e223b7a73c18c3a07704");
      byte[] SighashValue = HexBin
          .decode("2e99758548972a8e8822ad47fa1017ff72f06f3ff6a016851f45c398732bc50c");
      boolean ret = LibrustzcashWrapper.getInstance()
          .librustzcashSaplingCheckSpend(ctx, cv, Anchor, nf, rk, zkproof, spendAuthSig,
              SighashValue);
      Assert.assertTrue(ret);
    }
    // check output proof
    {
      byte[] cv = HexBin.decode("b0faa6cc45d91d8fa0f17e0448459e3776ffb22556b1e33f5327127f471c5a8f");
      byte[] cm = HexBin.decode("01aa431f8bfe25f276240f9dd68fc173e5ec71f749343a3f2b0f6357703ed84c");
      byte[] EphemeralKey = HexBin
          .decode("36c787daee6dd8dcff688b1dda8188cc9554d668dcb8e343cd2d10c9005bb305");
      byte[] zkproof = HexBin.decode(
          "81acc51e1a35d1947ce66e5bfa0d4c4896fa4b4a54ec33ab1af451686ea7eda45ad1c41dcee745f590396dfb983c895aaf8fd10188e06246c4d1fcf273e40ad5caa6ca9f1f2dbede1c7b13a23154de15dbb8fc812daa2c70362fa1f02c9b133e090b2ed57fadb58f8c4e190670b0da51ad126964a0124dcc3fcae66417c3a82be69f4fa7184d2aa48044186f5deb7ccb88213f56fa5cc61be2b2616eba88f51c608d6a8d684b1368a8c863394a34b9937b859f0078752f31fd295401f79f6fc3");
      boolean ret = LibrustzcashWrapper.getInstance()
          .librustzcashSaplingCheckOutput(ctx, cv, cm, EphemeralKey, zkproof);
      Assert.assertTrue(ret);
    }
    // FinalCheck
    {
      byte[] bindingSig = HexBin.decode(
          "a52f10b92e15ba3783cc9ca1ebb4dd2aa700fb6da03ebffec7e4f9b46f2159d5ee7753100d4c10084ccdb0c2a2ad2ab6d068cce4bb87270323807641d937c50d");
      byte[] sighashValue = HexBin
          .decode("2e99758548972a8e8822ad47fa1017ff72f06f3ff6a016851f45c398732bc50c");
      long valueBalance = 9000000L;
      boolean ret = LibrustzcashWrapper.getInstance()
          .librustzcashSaplingFinalCheck(ctx, valueBalance, bindingSig, sighashValue);
      Assert.assertTrue(ret);
    }
    LibrustzcashWrapper.getInstance().librustzcashSaplingVerificationCtxFree(ctx);

  }

  @Test
  public void librustzcashSpendProofWrong() {

    byte[] ak = HexBin.decode("2021c369f4b901cc4f37d80eac2d676aa41beb2a2d835d5120005714bc687657");
    byte[] nsk = HexBin
        .decode("48ea637742229ee87b8ebffd435b27469bee46ecb7732a6e3fb27939d442c006");

    byte[] d = HexBin.decode("0000000000000000000000");
    long value = 100;
    byte[] rcm = HexBin
        .decode("d41c1e0da8e4c5cf8d9735db7d8a8333efc48c8efe90d722880ba659d6b13e00");
    byte[] alpha = HexBin
        .decode("1a0f72740973302408118db5a457d77848baa6c25439d1a33bcf8f376ef3120b");
    byte[] anchor = HexBin
        .decode("53cc21e123a0b6009f3f09ef6152027d81e84a83ce516da9b4720a7689435c42");
    byte[] voucherPath = HexBin.decode(
        "2020b2eed031d4d6a4f02a097f80b54cc1541d4163c6b6f5971f88b6e41d35c538142012935f14b676509b81eb49ef25f39269ed72309238b4c145803544b646dca62d20e1f34b034d4a3cd28557e2907ebf990c918f64ecb50a94f01d6fda5ca5c7ef722028e7b841dcbc47cceb69d7cb8d94245fb7cb2ba3a7a6bc18f13f945f7dbd6e2a20a5122c08ff9c161d9ca6fc462073396c7d7d38e8ee48cdb3bea7e2230134ed6a20d2e1642c9a462229289e5b0e3b7f9008e0301cbb93385ee0e21da2545073cb582016d6252968971a83da8521d65382e61f0176646d771c91528e3276ee45383e4a20fee0e52802cb0c46b1eb4d376c62697f4759f6c8917fa352571202fd778fd712204c6937d78f42685f84b43ad3b7b00f81285662f85c6a68ef11d62ad1a3ee0850200769557bc682b1bf308646fd0b22e648e8b9e98f57e29f5af40f6edb833e2c492008eeab0c13abd6069e6310197bf80f9c1ea6de78fd19cbae24d4a520e6cf3023208d5fa43e5a10d11605ac7430ba1f5d81fb1b68d29a640405767749e841527673206aca8448d8263e547d5ff2950e2ed3839e998d31cbc6ac9fd57bc6002b15921620cd1c8dbf6e3acc7a80439bc4962cf25b9dce7c896f3a5bd70803fc5a0e33cf00206edb16d01907b759977d7650dad7e3ec049af1a3d875380b697c862c9ec5d51c201ea6675f9551eeb9dfaaa9247bc9858270d3d3a4c5afa7177a984d5ed1be245120d6acdedf95f608e09fa53fb43dcd0990475726c5131210c9e5caeab97f0e642f20bd74b25aacb92378a871bf27d225cfc26baca344a1ea35fdd94510f3d157082c201b77dac4d24fb7258c3c528704c59430b630718bec486421837021cf75dab65120ec677114c27206f5debc1c1ed66f95e2b1885da5b7be3d736b1de98579473048204777c8776a3b1e69b73a62fa701fa4f7a6282d9aee2c7a6b82e7937d7081c23c20ba49b659fbd0b7334211ea6a9d9df185c757e70aa81da562fb912b84f49bce722043ff5457f13b926b61df552d4e402ee6dc1463f99a535f9a713439264d5b616b207b99abdc3730991cc9274727d7d82d28cb794edbc7034b4f0053ff7c4b68044420d6c639ac24b46bd19341c91b13fdcab31581ddaf7f1411336a271f3d0aa52813208ac9cf9c391e3fd42891d27238a81a8a5c1d3a72b1bcbea8cf44a58ce738961320912d82b2c2bca231f71efcf61737fbf0a08befa0416215aeef53e8bb6d23390a20e110de65c907b9dea4ae0bd83a4b0a51bea175646a64c12b4c9f931b2cb31b4920d8283386ef2ef07ebdbb4383c12a739a953a4d6e0d6fb1139a4036d693bfbb6c20ffe9fc03f18b176c998806439ff0bb8ad193afdb27b2ccbc88856916dd804e3420817de36ab2d57feb077634bca77819c8e0bd298c04f6fed0e6a83cc1356ca1552001000000000000000000000000000000000000000000000000000000000000000000000000000000");
    byte[] cv = new byte[32];
    byte[] rk = new byte[32];
    byte[] zkproof = new byte[192];
    long ctx = LibrustzcashWrapper.getInstance().librustzcashSaplingProvingCtxInit();

    boolean ret = LibrustzcashWrapper.getInstance()
        .librustzcashSaplingSpendProof(ctx, ak,
            nsk,
            d,
            rcm,
            alpha,
            value,
            anchor,
            voucherPath,
            cv,
            rk,
            zkproof);
    Assert.assertFalse(ret);

  }

  @Test
  public void librustzcashOutputProofWrong() {

    long ctx = LibrustzcashWrapper.getInstance().librustzcashSaplingProvingCtxInit();
    byte[] esk = HexBin
        .decode("a5e43cbfc344872d1c4c54d16ea11aeb3031925b2afcbdc84ffeddde644bce06");
    byte[] d = HexBin.decode("0000000000000000000000");
    byte[] pkD = HexBin
        .decode("1071d91f1d86ceffd5f19ad4187333ee820a4e018656e16380404e0c1696b9d8");
    byte[] rcm = HexBin
        .decode("95d90bb5efb179a739949293c81861821860678de7afa9a241588e414ebd7707");

    long value = 1000000;
    byte[] cv = new byte[32];
    byte[] zkproof = new byte[192];

    boolean ret = LibrustzcashWrapper.getInstance()
        .librustzcashSaplingOutputProof(ctx, esk,
            d,
            pkD,
            rcm,
            value,
            cv,
            zkproof);
    Assert.assertFalse(ret);
  }


  @Test
  public void librustzcashMerkleHash() {
    byte[] a =
        HexBin.decode("05655316a07e6ec8c9769af54ef98b30667bfb6302b32987d552227dae86a087");
    byte[] b =
        HexBin.decode("06041357de59ba64959d1b60f93de24dfe5ea1e26ed9e8a73d35b225a1845ba7");

    byte[] res = new byte[32];
    LibrustzcashWrapper.getInstance().librustzcashMerkleHash(4, a, b, res);
    Assert.assertFalse(Arrays.equals(res, new byte[32]));
  }

  @Test
  public void librustzcashTreeUncommitted() {
    byte[] res = new byte[32];
    LibrustzcashWrapper.getInstance().librustzcashTreeUncommitted(res);
    Assert.assertFalse(Arrays.equals(res, new byte[32]));
  }


  @Test
  public void librustzcashToScalar() {
    byte[] res = new byte[32];
    byte[] tmp =
        HexBin.decode("06041357de59ba64959d1b60f93de24dfe5ea1e26ed9e8a73d35b225a1845ba7");

    LibrustzcashWrapper.getInstance().librustzcashToScalar(tmp, res);
    Assert.assertFalse(Arrays.equals(res, new byte[32]));
  }

  @Test
  public void librustzcashBindingSigWrong()
  //create binding sig
  {
    long ctx = LibrustzcashWrapper.getInstance().librustzcashSaplingProvingCtxInit();

    long valueBalance = 9000000;
    byte[] sighash = HexBin
        .decode("2e99758548972a8e8822ad47fa1017ff72f06f3ff6a016851f45c398732bc50c");
    byte[] result = new byte[64];
    boolean ret = LibrustzcashWrapper.getInstance()
        .librustzcashSaplingBindingSig(ctx, valueBalance, sighash, result);
    Assert.assertFalse(ret);
  }

  @Test
  public void librustzcashSpendSigWrong()
  // create spend sig
  {
    //no false return
  }

  @Test
  public void librustzcashCheckSpendProofWrong()
  //check spend proof
  {
    long ctx = LibrustzcashWrapper.getInstance().librustzcashSaplingVerificationCtxInit();
    byte[] cv = HexBin.decode("e7a0d3dd2dfcac201a9d6d048275120ebe772a186dcc54c59126ed46b4d3ac2b");
    byte[] Anchor = HexBin
        .decode("f2097ce0e430f74a87d5d6c574f483165c781bd6b2423ec4824505890606554f");
    byte[] nf = HexBin.decode("f5c35350812bb75c8607e0283fe8c32bb92a529a025bd3f74ebb9bf89ac52348");
    byte[] rk = HexBin.decode("2b1c55975c854c1922330bea5786536a97d5b2b10b77b503b506b07e7b09ac22");
    byte[] zkproof = HexBin.decode(
        "8c01e0be140fbe19d6a54469993a06af6b7cb3dc432c3f96479642d0319cc304bd4de106c5ef682d0ed313c9fdae3308a319089650d7e92ad6180d2a4a9fa057c662b8bd2dffd74447fde4cca0c94e00e8c76c5beb0ef6893f67b86aae03dfec197e63326803633c264a8f683a0c1131ff25a2d9f9bff97a6011d986fb73925ec523f9edfcc645fe3b787919e4c47f838a3fd1b04682c1c3ab2f8c6f369d8c74712ca74ed28bc7f723d466a5830d0b18eefa58a9cf7f242c4d29047674bc3eff");
    byte[] spendAuthSig = HexBin.decode(
        "30dc7662f0621cbb4c4a93e8624b73ce6d110b4af6e9ec671e3072db6474339fa869c30020588c11c1ff5b268b183505d059f7870df4e223b7a73c18c3a07704");
    byte[] SighashValue = HexBin
        .decode("0e99758548972a8e8822ad47fa1017ff72f06f3ff6a016851f45c398732bc50c");
    boolean ret = LibrustzcashWrapper.getInstance()
        .librustzcashSaplingCheckSpend(ctx, cv, Anchor, nf, rk, zkproof, spendAuthSig,
            SighashValue);
    Assert.assertFalse(ret);
  }


  @Test
  public void librustzcashCheckOutputProofWrong()
  // check output proof
  {
    long ctx = LibrustzcashWrapper.getInstance().librustzcashSaplingVerificationCtxInit();
    byte[] cv = HexBin.decode("b0faa6cc45d91d8fa0f17e0448459e3776ffb22556b1e33f5327127f471c5a8f");
    byte[] cm = HexBin.decode("01aa431f8bfe25f276240f9dd68fc173e5ec71f749343a3f2b0f6357703ed84c");
    byte[] EphemeralKey = HexBin
        .decode("36c787daee6dd8dcff688b1dda8188cc9554d668dcb8e343cd2d10c9005bb305");
    byte[] zkproof = HexBin.decode(
        "01acc51e1a35d1947ce66e5bfa0d4c4896fa4b4a54ec33ab1af451686ea7eda45ad1c41dcee745f590396dfb983c895aaf8fd10188e06246c4d1fcf273e40ad5caa6ca9f1f2dbede1c7b13a23154de15dbb8fc812daa2c70362fa1f02c9b133e090b2ed57fadb58f8c4e190670b0da51ad126964a0124dcc3fcae66417c3a82be69f4fa7184d2aa48044186f5deb7ccb88213f56fa5cc61be2b2616eba88f51c608d6a8d684b1368a8c863394a34b9937b859f0078752f31fd295401f79f6fc3");
    boolean ret = LibrustzcashWrapper.getInstance()
        .librustzcashSaplingCheckOutput(ctx, cv, cm, EphemeralKey, zkproof);
    Assert.assertFalse(ret);
  }

  @Test
  public void librustzcashCheckFinalCheckWrong()
  // FinalCheck
  {
    long ctx = LibrustzcashWrapper.getInstance().librustzcashSaplingVerificationCtxInit();
    byte[] bindingSig = HexBin.decode(
        "a52f10b92e15ba3783cc9ca1ebb4dd2aa700fb6da03ebffec7e4f9b46f2159d5ee7753100d4c10084ccdb0c2a2ad2ab6d068cce4bb87270323807641d937c50d");
    byte[] sighashValue = HexBin
        .decode("2e99758548972a8e8822ad47fa1017ff72f06f3ff6a016851f45c398732bc50c");
    long valueBalance = 9000000L;
    boolean ret = LibrustzcashWrapper.getInstance()
        .librustzcashSaplingFinalCheck(ctx, valueBalance, bindingSig, sighashValue);
    Assert.assertFalse(ret);
  }
}
