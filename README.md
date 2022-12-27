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

    cargo

    libtool

    automake

    mvn

    jdk8(need JAVA_HOME set)

# for m1
```shell
 cd cpp && mkdir build && cd build
 CC=cc cmake ..
 make 
```
