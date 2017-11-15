// This works in LLVM 3.8 but not in LLVM 3.9

/*
   g++ -I`llvm-config --includedir` -L`llvm-config --libdir` \
       test_IRBuilder_3.cc                                   \
       `llvm-config --libs` `llvm-config --system-libs`
*/

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>

using namespace llvm;

int main ()
{
  LLVMContext c;
  IRBuilder<true, ConstantFolder, IRBuilderDefaultInserter<true> >  irb (c);

  return 0;
}
