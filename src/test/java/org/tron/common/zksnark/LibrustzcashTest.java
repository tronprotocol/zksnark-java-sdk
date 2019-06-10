package org.tron.common.zksnark;

import javax.rmi.CORBA.Util;
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



}
