
add_llvm_library( LLVMDcPass MODULE
        DcPass.cpp

        PLUGIN_TOOL
        opt
        )