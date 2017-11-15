#!/usr/bin

g++ -I`llvm-config --includedir` -L`llvm-config --libdir` \
    test_IRBuilder_2.cc                                   \
    `llvm-config --libs` `llvm-config --system-libs`

./a.out
echo $?
