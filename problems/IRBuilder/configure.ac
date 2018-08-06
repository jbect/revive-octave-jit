AC_INIT([LLVM IRBuilder template tester], [0.0.1])

AC_CONFIG_HEADERS([config.h])

AC_ARG_WITH(
  [llvm-src],
  [LLVM source directory],
  [LLVM_SRC=$with_llvm_src],
  [AC_MSG_ERROR([Missing --with-llvm-src argument])]
)

AC_MSG_NOTICE([LLVM_SRC=$LLVM_SRC])

# This configure.ac assumes that the build directory is inside LLVM_SRC
# (note: building target intrincs_gen is enough)
LLVM_BUILD=${LLVM_SRC}/build
LLVM_CONFIG_H=${LLVM_BUILD}/include/llvm/Config/llvm-config.h
AC_CHECK_FILE([${LLVM_CONFIG_H}])

CPPFLAGS="${CPPFLAGS} -I${LLVM_SRC}/include -I${LLVM_SRC}/build/include"
AC_MSG_NOTICE([CPPFLAGS=${CPPFLAGS}])
AC_LANG_PUSH([C++])

AC_CHECK_HEADER([llvm/IR/LLVMContext.h],, [AC_MSG_ERROR([llvm/IR/LLVMContext.h not found])])
AC_CHECK_HEADER([llvm/IR/IRBuilder.h],, [AC_MSG_ERROR([llvm/IR/IRBuilder.h header not found])])


### Check if llvm::IRBuilder's template has two arguments

AC_MSG_CHECKING([Checking if llvm::IRBuilder's template has two arguments])

AC_COMPILE_IFELSE(
  [
    AC_LANG_SOURCE([[
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
using namespace llvm;
int main ()
{
  LLVMContext c;
  IRBuilder<ConstantFolder,IRBuilderDefaultInserter>  irb (c);
  return 0;
}
    ]])
  ],
  [
    AC_DEFINE([LLVM_IRBUILDER_TEMPLATE_2ARGS], [1],
              [Define if the IRBuilder template has two arguments.])
    AC_MSG_RESULT([yes])
  ],
  [
    AC_MSG_RESULT([no])
  ]
)


### Check if llvm::IRBuilder's template has three arguments

AC_MSG_CHECKING([Checking if llvm::IRBuilder's template has three arguments])

AC_COMPILE_IFELSE(
  [
    AC_LANG_SOURCE([[
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
using namespace llvm;
int main ()
{
  LLVMContext c;
  IRBuilder<true, ConstantFolder, IRBuilderDefaultInserter<true> >  irb (c);
  return 0;
}
    ]])
  ],
  [
    AC_DEFINE([LLVM_IRBUILDER_TEMPLATE_3ARGS], [1],
              [Define if the IRBuilder template has three arguments.])
    AC_MSG_RESULT([yes])
  ],
  [
    AC_MSG_RESULT([no])
  ]
)


AC_OUTPUT()
