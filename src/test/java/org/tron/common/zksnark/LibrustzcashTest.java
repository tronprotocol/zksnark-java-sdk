package org.tron.common.zksnark;

import com.sun.org.apache.xerces.internal.impl.dv.util.HexBin;
import java.util.Arrays;
import javax.rmi.CORBA.Util;
import javax.xml.bind.annotation.adapters.HexBinaryAdapter;
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
    boolean ret = LibrustzcashWrapper.getInstance().librustzcashCheckDiversifier(HexBin.decode("55ed53f0d6550b472cdf38"));
    Assert.assertFalse(ret);
    System.out.println(Arrays.toString(HexBin.decode("02D72D7702F90B0FE71165")));
    ret = LibrustzcashWrapper.getInstance().librustzcashCheckDiversifier(HexBin.decode("02D72D7702F90B0FE71165"));
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
  public void librustzcashToScalar() {
    byte[] result = new byte[32];
    LibrustzcashWrapper.getInstance().librustzcashToScalar(HexBin.decode("55ed53f0d6550b472cdf38"),result);
    Assert.assertFalse(Arrays.equals(result, new byte[32]));
  }


}
