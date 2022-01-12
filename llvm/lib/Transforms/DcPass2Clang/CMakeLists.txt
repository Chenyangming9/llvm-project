add_llvm_library(LLVMDcPass2Clang
        DcPass2Clang.cpp
        )

add_dependencies(LLVMDcPass2Clang intrinsics_gen)