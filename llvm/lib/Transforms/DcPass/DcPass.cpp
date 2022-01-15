//
// Created by t on 1/9/22.
//

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;
namespace {
    struct DcHello : public FunctionPass {
        static char ID;
        DcHello() : FunctionPass(ID) {}

        bool runOnFunction(Function &F) override {
            errs() << "DcHello: ";
            errs().write_escaped(F.getName()) << '\n';
            return false;
        }
//    }; // end of struct DcHello
//}  // end of anonymous namespace

    };

}

//We initialize pass ID here. LLVM uses ID’s address to identify a pass, so initialization value is not important.
char DcHello::ID = 0;

static RegisterPass<DcHello> X("DcHello", "DcHello World Pass",
                             false /* Only looks at CFG */,
                             false /* Analysis Pass */);

//static llvm::RegisterStandardPasses Y(
//        llvm::PassManagerBuilder::EP_EarlyAsPossible,
//[](const llvm::PassManagerBuilder &Builder,
//   llvm::legacy::PassManagerBase &PM) { PM.add(new DcHello()); });