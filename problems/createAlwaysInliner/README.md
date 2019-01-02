# Problem with the IRBuilder<> template

## The problem

In LLVM 3.8 and earlier, IRBuilder is defined as follows:

    template<bool preserveNames = true, typename T = ConstantFolder,  
      typename Inserter = IRBuilderDefaultInserter<preserveNames> >  
      class IRBuilder : public IRBuilderBase, public Inserter  

whereas in LLVM 3.9 (and later ?) it is defined as:

    template <typename T = ConstantFolder,  
      typename Inserter = IRBuilderDefaultInserter>  
      class IRBuilder : public IRBuilderBase, public Inserter  

Note that the number of template arguments has changed.


## Autoconf tests

Autoconf tests for this are provided in configure.ac.

To run the tests:

     autoheader && autoconf && ./configure --with-llvm-src=${PATH_TO_LLVM_SRC}

assuming that LLVM has been built in the `build` subdirectory of `${PATH_TO_LLVM_SRC}`.

Note that it is enough (and much faster) to build target `intrinsics_gen` only.


## Some results

Here are the results on a few LLVM releases:
 * 3.0, 3.1, 3.2, 3.3, 3.4.2, 3.5.2, 3.6.2, 3.7.1, 3.8.1: 3 arguments
 * 3.9.1, 4.0.1, 4.0.2, 6.0.1: 2 arguments

