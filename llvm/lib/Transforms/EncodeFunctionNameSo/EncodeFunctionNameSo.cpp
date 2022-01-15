#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/EncodeFunctionName/EncodeFunctionNameSo.h"

using namespace llvm;
namespace {
    struct EncodeFunctionNameSo : public FunctionPass {
        static char ID;
        EncodeFunctionNameSo() : FunctionPass(ID) {}
        bool runOnFunction(Function &F) override {
            errs() << "EncodeFunctionName: " << F.getName() << "--->";
            if (F.getName().compare("main") != 0){

                llvm::MD5 Hasher;
                llvm::MD5::MD5Result Hash;
                Hasher.update("kanxue_");
                Hasher.update(F.getName());
                Hasher.final(Hash);
                SmallString<32> HexString;
                llvm::MD5::stringifyResult(Hash, HexString);
                F.setName(HexString);
            }

            errs() << F.getName() << '\n';
            //errs().write_escaped(F.getName()) << '\n';
            return false;
        }
    };
}

char EncodeFunctionNameSo::ID = 0;
static RegisterPass<EncodeFunctionNameSo> X("EncodeFunctionNameSo", "Encode Function Name Pass",
                             false /* Only looks at CFG */,
                             false /* Analysis Pass */);

//static llvm::RegisterStandardPasses Y(llvm::PassManagerBuilder::EP_EarlyAsPossible,
//        [](const llvm::PassManagerBuilder &Builder,
//                llvm::legacy::PassManagerBase &PM) { PM.add(new EncodeFunctionName()); });

//static RegisterStandardPasses Y(
//        PassManagerBuilder::EP_EarlyAsPossible,
//        [](const PassManagerBuilder &Builder,
//           legacy::PassManagerBase &PM) { PM.add(new EncodeFunctionNameSo()); });

//Pass* llvm::createEncodeFunctionName(){return new EncodeFunctionNameSo();}