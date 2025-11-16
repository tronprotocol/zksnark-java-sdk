# libzksnark
a zksnark jni library

# Pull source
```
$ git clone git@github.com:lindaprotocol/zksnark-java-sdk.git --recursive
```
OR
```
$ git clone git@github.com:lindaprotocol/zksnark-java-sdk.git
$ git submodule update --init --recursive
```

# Required

    cmake (version >= 3.10.2)

    cargo

    libtool

    automake

    mvn

    jdk8(need JAVA_HOME set)

If make fails to curl [ibsodium-1.0.15](https://github.com/jedisct1/libsodium/releases/download/1.0.15/libsodium-1.0.15.tar.gz), download it manually and replace the existing  [download-libsodium.cmake](https://raw.githubusercontent.com/lindaprotocol/zksnark-java-sdk/feature/zk-snark-updates/download-libsodium.cmake) file with the one linked above in the zksnark-java-sdk/cpp/build/rust/src/libsodium-stamp directory.

# for m1
```shell
 cd cpp && mkdir build && cd build
 CC=cc cmake ..
 make 
```
