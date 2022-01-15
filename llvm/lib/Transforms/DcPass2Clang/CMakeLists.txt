add_llvm_library(LLVMDcPass2Clang
        DcPass2Clang.cpp
        )
#依赖上级的Pass
add_dependencies(LLVMDcPass2Clang intrinsics_gen)