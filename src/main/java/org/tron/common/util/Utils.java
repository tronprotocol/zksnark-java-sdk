/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.tron.common.util;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import org.apache.commons.io.FileUtils;
import org.fusesource.hawtjni.runtime.Library;

public interface Utils {
    Library LIBRARY = new Library("zksnarkjni", Utils.class);

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
