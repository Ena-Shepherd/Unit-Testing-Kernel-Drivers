#pragma once
#ifndef _KERNEL_MODE

#ifdef _DEBUG
#define DBG 1
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define CLONG ULONG

#ifndef _AMD64_
#define _AMD64_ 1
#endif

#define UMDF_USING_NTSTATUS 1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ntstatus.h>

#define DbgPrint(...) printf(__VA_ARGS__)
#define DbgBreakPoint() DebugBreak()

#undef TraceEvents
#define TraceEvents(...)

  typedef UCHAR KIRQL;
  typedef KIRQL* PKIRQL;

  typedef struct _IO_STATUS_BLOCK {
    union {
      NTSTATUS Status;
      PVOID Pointer;
    };

    ULONG_PTR Information;
  } IO_STATUS_BLOCK, * PIO_STATUS_BLOCK;

#define ZwReadFile(handle, buffer, size, bytesRead) \
    ReadFile(handle, buffer, size, bytesRead, NULL)

#define PAGE_SIZE 0x1000
#define PAGE_SHIFT 12L

#define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0)

#ifdef _MSC_VER
#define __try try
#define __finally catch(...)
#endif

#define POOL_FLAG_NON_PAGED 0
#define ExAllocatePool2(poolType, size, tag) malloc(size)
#define ExFreePoolWithTag(ptr, tag) free(ptr)

#ifdef __cplusplus
}
#endif

#else
#include <ntddk.h>
#include <wdf.h>
#include <initguid.h>
#endif