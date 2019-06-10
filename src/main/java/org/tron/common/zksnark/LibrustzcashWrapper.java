package org.tron.common.zksnark;

import java.io.IOException;
import org.tron.common.util.Utils;

public class LibrustzcashWrapper {
  private static final Librustzcash INSTANCE = new Librustzcash();

  static {
    try {
      System.load(Utils.getLibraryByName("libzksnarkjni"));
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
  }

  public static Librustzcash getInstance() {
    return INSTANCE;
  }

  public static void main(String[] args) throws IOException {
    INSTANCE.librustzcashInitZksnarkParams(
        "/tmp/params/sapling-spend.params",
        "8270785a1a0d0bc77196f000ee6d221c9c9894f55307bd9357c3f0105d31ca63991ab91324160d8f53e2bbd3c2633a6eb8bdf5205d822e7f3f73edac51b2b70c",
        "/tmp/params/sapling-output.params",
        "657e3d38dbb5cb5e7dd2970e8b03d69b4787dd907285b5a7f0790dcc8072f60bf593b32cc2d1c030e00ff5ae64bf84c5c3beb84ddc841d48264b4a171744d028"
    );
  }

}
