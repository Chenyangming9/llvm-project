add_llvm_library(LLVMObfuscation
  CryptoUtils.cpp
  Substitution.cpp
  BogusControlFlow.cpp
  Utils.cpp
  SplitBasicBlocks.cpp
  Flattening.cpp
  StringObfuscation.cpp
  )

add_dependencies(LLVMObfuscation intrinsics_gen)


#add_llvm_library( LLVMObfuscation MODULE
#          CryptoUtils.cpp
#          Substitution.cpp
#          BogusControlFlow.cpp
#          Utils.cpp
#          SplitBasicBlocks.cpp
#          Flattening.cpp
#          StringObfuscation.cpp
#
#        DEPENDS
#        intrinsics_gen
#        PLUGIN_TOOL
#        opt
#        )
