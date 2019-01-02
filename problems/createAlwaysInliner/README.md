# Problem with the IRBuilder<> template

## The problem

Starting with LLVM 4.0, llvm::createAlwaysInlinerPass has been removed
from LLVM's C++ API.

Prior to that, it was defined in `llvm/Transforms/IPO.h`.

