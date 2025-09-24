#pragma once
#include "ReplaceKernelCode.h"

void TestMemory(void);
void TestSEH(void);
void Breakpoint(void);
NTSTATUS ReadFromFile(HANDLE fileHandle, PVOID buffer, ULONG length, PULONG bytesRead);