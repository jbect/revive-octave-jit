# Problem with the IRBuilder<> template

In LLVM 3.8 and earlier, IRBuilder is defined as follows:

    template<bool preserveNames = true, typename T = ConstantFolder,  
      typename Inserter = IRBuilderDefaultInserter<preserveNames> >  
      class IRBuilder : public IRBuilderBase, public Inserter  

whereas in LLVM 3.9 (and later ?) it is defined as:

    template <typename T = ConstantFolder,  
      typename Inserter = IRBuilderDefaultInserter>  
      class IRBuilder : public IRBuilderBase, public Inserter  

Note that the number of template arguments has changed.

We need an autoconf macro...
