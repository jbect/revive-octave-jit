// This works with LLVM <= 3.9 but not with LLVM 4.0

/*
   export LC=`which llvm-config-4.0`
   g++ -I`${LC} --includedir` -L`${LC} --libdir` \
       test_createAlwaysInlinerPass.cc           \
       `${LC} --libs` `${LC} --system-libs`
*/

#include <llvm/Transforms/IPO.h>

int main ()  
{
  llvm::Pass *p;
  p = llvm::createAlwaysInlinerPass ();

  return 0;
}
