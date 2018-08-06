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

# Required by DataTypes.h (in all releases of LLVM ?)
CPPFLAGS="-D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS $CPPFLAGS"

# Add LLVM include directories
CPPFLAGS="-I${LLVM_SRC}/include -I${LLVM_SRC}/build/include ${CPPFLAGS}"

AC_MSG_NOTICE([CPPFLAGS=${CPPFLAGS}])

AC_LANG_PUSH([C++])

# This comes from Octave's configure.ac (with AC_MSG_ERROR instead of warn_llvm)
have_llvmcontext_h=no
AC_CHECK_HEADERS([llvm/IR/LLVMContext.h llvm/LLVMContext.h],
                 [have_llvmcontext_h=yes; break])
if test $have_llvmcontext_h = no; then
  AC_MSG_ERROR([LLVMContext.h not found])
fi

# This also comes from Octave's configure.ac
# but the third case has been added to support LLVM <= 3.2
have_irbuilder_h=no
AC_CHECK_HEADERS([llvm/IR/IRBuilder.h llvm/IRBuilder.h llvm/Support/IRBuilder.h],
                 [have_irbuilder_h=yes; break])
if test $have_irbuilder_h = no; then
  AC_MSG_ERROR([IRBuilder.h not found])
fi


### Check if llvm::IRBuilder's template has two arguments

AC_MSG_CHECKING([Checking if llvm::IRBuilder's template has two arguments])

AC_COMPILE_IFELSE(
  [
    AC_LANG_SOURCE([[
#if defined (HAVE_LLVM_IR_LLVMCONTEXT_H)
  #include <llvm/IR/LLVMContext.h>
#else
  #include <llvm/LLVMContext.h>
#endif
#if defined (HAVE_LLVM_IR_IRBUILDER_H)
  #include <llvm/IR/IRBuilder.h>
#elif defined (HAVE_LLVM_SUPPORT_IRBUILDER_H)
  #include <llvm/Support/IRBuilder.h>
#else
  #include <llvm/IRBuilder.h>
#endif
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
#if defined (HAVE_LLVM_IR_LLVMCONTEXT_H)
  #include <llvm/IR/LLVMContext.h>
#else
  #include <llvm/LLVMContext.h>
#endif
#if defined (HAVE_LLVM_IR_IRBUILDER_H)
  #include <llvm/IR/IRBuilder.h>
#elif defined (HAVE_LLVM_SUPPORT_IRBUILDER_H)
  #include <llvm/Support/IRBuilder.h>
#else
  #include <llvm/IRBuilder.h>
#endif
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
