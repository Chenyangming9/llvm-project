#add_llvm_library( LLVMEncodeFunctionNameSo
#        EncodeFunctionNameSo.cpp
#
#        PLUGIN_TOOL
#        opt
#        )
#
#add_llvm_library( LLVMHello MODULE
#        Hello.cpp
#
#        PLUGIN_TOOL
#        opt
#        )

add_llvm_library( LLVMEncodeFunctionNameSo MODULE BUILDTREE_ONLY
        EncodeFunctionNameSo.cpp

        DEPENDS
        intrinsics_gen
        PLUGIN_TOOL
        opt
        )