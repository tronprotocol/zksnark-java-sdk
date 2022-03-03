# libzksnark
a zksnark jni library

# Pull source
```
$ git clone git@github.com:tronprotocol/zksnark-java-sdk.git --recursive
```
OR
```
$ git clone git@github.com:tronprotocol/zksnark-java-sdk.git
$ git submodule update --init --recursive
```

# Required

cmake (version >= 3.10.2)
jdk8(need JAVA_HOME set)

# for m1
```shell
 cd cpp && mkdir build && cd build
 CC=cc cmake ..
 brew install cargo 
 brew install libtool
 brew install automake
 make
 cp libzksnarkjni.dylib cp libzksnarkjni.dylib ../../src/main/resources/native-package/macos/aarch64 
 
```
