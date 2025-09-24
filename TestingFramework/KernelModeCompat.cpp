#include "ReplaceKernelCode.h"

void TestMemory(void) {

  PVOID testMemory = ExAllocatePool2(POOL_FLAG_NON_PAGED, 1024, 'TEST');
  if (testMemory) {
    DbgPrint("Memory allocated successfully\n");
    ExFreePoolWithTag(testMemory, 'TEST');
    DbgPrint("Memory freed successfully\n");
  }
  else {
    DbgPrint("Memory allocation failed\n");
  }

}

void TestSEH(void) {

  __try {
    DbgPrint("In \"try\" block\n");

#ifndef _KERNEL_MODE
    throw 1; // Manually throw an exception in user mode
#endif
  }
  __finally {
    DbgPrint("In \"finally\" block\n");
  }

}