// This works with LLVM 3.9 but not with LLVM 3.8

/*
   g++ -I`llvm-config --includedir` -L`llvm-config --libdir` \
       test_IRBuilder_2.cc                                   \
       `llvm-config --libs` `llvm-config --system-libs`
*/

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>

using namespace llvm;

int main ()
{
  LLVMContext c;
  IRBuilder<ConstantFolder,IRBuilderDefaultInserter>  irb (c);

  return 0;
}
