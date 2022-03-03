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
package org.tron.common.zksnark;

import org.tron.common.util.Utils;

public class LibsodiumWrapper
{
    private static final Libsodium INSTANCE = new Libsodium();

    static {
        Utils.LIBRARY.load();
    }

    private LibsodiumWrapper() throws IllegalAccessException
    {
        throw new IllegalAccessException();
    }

    public static Libsodium getInstance()
    {
        return INSTANCE;
    }
}
