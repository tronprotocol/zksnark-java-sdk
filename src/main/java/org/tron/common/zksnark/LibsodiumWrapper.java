package org.tron.common.zksnark;

public class LibsodiumWrapper {
  private static final Libsodium INSTANCE = new Libsodium();

  public static Libsodium getInstance() {
    return INSTANCE;
  }

}
