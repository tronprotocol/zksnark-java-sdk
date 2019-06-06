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

  public static void main(String[] args) throws IOException {
    INSTANCE.librustzcashInitZksnarkParams(new byte[]{}, 0, "", new byte[]{}, 0, "");
  }

}
