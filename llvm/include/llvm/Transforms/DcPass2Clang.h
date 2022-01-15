//
// Created by t on 1/9/22.
//

#ifndef LLVM_DCPASS2CLANG_H
#define LLVM_DCPASS2CLANG_H



// LLVM include
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/Transforms/IPO.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/CommandLine.h"

// Namespace
using namespace llvm;
using namespace std;

namespace llvm {
    Pass *createDcPass2Clang ();
    Pass *createDcPass2Clang (bool flag);
}

#endif //LLVM_DCPASS2CLANG_H