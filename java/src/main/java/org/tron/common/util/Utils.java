package org.tron.common.util;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import org.apache.commons.io.FileUtils;
import org.tron.common.zksnark.Librustzcash;

public interface Utils {

  static String getLibraryByName(String name) throws IOException {
    return getLibrary(name);
  }

  static String getLibrary(String name) throws IOException {
    String platform;
    String extension;
    String os = System.getProperty("os.name");
    if ("linux".equalsIgnoreCase(os)) {
      platform = "linux";
      extension = ".so";
    } else if ("macos".equalsIgnoreCase(os)) {
      platform = "macos";
      extension = ".dylib";
    } else {
      throw new RuntimeException("unsupportedPlatformException");
    }
    InputStream in = Librustzcash.class.getClassLoader().getResourceAsStream(
        "native-package" + File.separator + platform + File.separator + name + extension);
    File fileOut = new File(
        System.getProperty("java.io.tmpdir") + File.separator + name + extension);
    FileUtils.copyToFile(in, fileOut);
    return fileOut.getAbsolutePath();
  }



}
