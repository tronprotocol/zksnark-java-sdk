package org.tron.common.zksnark;

final class HexBin {
  private HexBin() {
  }

  static byte[] decode(String hex) {
    if (hex == null || (hex.length() & 1) != 0) {
      throw new IllegalArgumentException("Hex string must have even length");
    }

    byte[] out = new byte[hex.length() / 2];
    for (int i = 0; i < hex.length(); i += 2) {
      int high = Character.digit(hex.charAt(i), 16);
      int low = Character.digit(hex.charAt(i + 1), 16);
      if (high < 0 || low < 0) {
        throw new IllegalArgumentException("Invalid hex string");
      }
      out[i / 2] = (byte) ((high << 4) + low);
    }
    return out;
  }
}
