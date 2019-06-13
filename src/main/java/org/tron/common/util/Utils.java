package org.tron.common.util;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import org.apache.commons.io.FileUtils;

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
    } else if ("macos".equalsIgnoreCase(os) || os.toLowerCase().contains("mac")) {
      platform = "macos";
      extension = ".dylib";
    } else {
      throw new RuntimeException("unsupportedPlatformException");
    }
    InputStream in = Utils.class.getClassLoader().getResourceAsStream(
        "native-package" + File.separator + platform + File.separator + name + extension);
    File fileOut = new File(
        System.getProperty("java.io.tmpdir") + File.separator + name + extension + "." + System.currentTimeMillis());
    FileUtils.copyToFile(in, fileOut);
    return fileOut.getAbsolutePath();
  }

  static String getParamsFile(String fileName) {
    InputStream in = Utils.class.getClassLoader()
        .getResourceAsStream("params" + File.separator + fileName);
    File fileOut = new File(System.getProperty("java.io.tmpdir") + File.separator + fileName);
    try {
      FileUtils.copyToFile(in, fileOut);
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
    return fileOut.getAbsolutePath();
  }

}
