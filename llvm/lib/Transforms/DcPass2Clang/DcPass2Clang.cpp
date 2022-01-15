//
// Created by t on 1/9/22.
//

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/DcPass2Clang.h"

using namespace llvm;
namespace {
    struct DcHello2Clang : public FunctionPass {
        static char ID;
        bool enable_dcpass2clang;
        DcHello2Clang() : FunctionPass(ID) {enable_dcpass2clang = true;}
        DcHello2Clang(bool flag) : FunctionPass(ID) {enable_dcpass2clang = flag;}
        bool runOnFunction(Function &F) override {
            if (this->enable_dcpass2clang){
                errs() << "DcHello2Clang: ";
                errs().write_escaped(F.getName()) << '\n';
                return true;
            }
            return false;
        }
    };

}

//We initialize pass ID here. LLVM uses ID’s address to identify a pass, so initialization value is not important.
char DcHello2Clang::ID = 0;

static RegisterPass<DcHello2Clang> X("DcHello2Clang", "DcHello2Clang World Pass",
                             false /* Only looks at CFG */,
                             false /* Analysis Pass */);

Pass* llvm::createDcPass2Clang (){
    return new DcHello2Clang();
}
Pass* llvm::createDcPass2Clang (bool flag){
    return new DcHello2Clang(flag);
}
//namespace llvm {
//    Pass *createDcPass2Clang ();
//    Pass *createDcPass2Clang (bool flag);
//}

//static llvm::RegisterStandardPasses Y(
//        llvm::PassManagerBuilder::EP_EarlyAsPossible,
//[](const llvm::PassManagerBuilder &Builder,
//   llvm::legacy::PassManagerBase &PM) { PM.add(new DcHello2Clang()); });