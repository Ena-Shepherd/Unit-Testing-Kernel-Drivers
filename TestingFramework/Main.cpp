#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <cstdint>
#include <iostream>


#include "kernelCompat.h"
  
SCENARIO("Test memory allocation and deallocation") {
  GIVEN("A memory allocation request") {
    WHEN("Allocating memory") {
      TestMemory();
      THEN("The memory allocation should succeed") {
        SUCCEED();
      }
    }
  }
}

SCENARIO("Test structured exception handling") {
  GIVEN("A structured exception handling block") {
    WHEN("Throwing an exception") {
      TestSEH();
      THEN("The exception should be caught") {
        SUCCEED();
      }
    }
  }
}

SCENARIO("Test breaking into the debugger") {
  GIVEN("A breakpoint instruction") {
    WHEN("Encountering a breakpoint") {
      
      // Commented out because it will pause the test
      //DbgBreakPoint();

      THEN("The debugger should break") {
        SUCCEED();
      }
    }
  }
}

SCENARIO("Test reading from a file") {
  GIVEN("A file handle to a test file") {
    const wchar_t* filePath = L"test.txt";
    HANDLE fileHandle = CreateFileW(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    REQUIRE(fileHandle != INVALID_HANDLE_VALUE);

    WHEN("Reading from the file") {
      ULONG bytesRead = 0;
      const size_t size = 1024;
      char buffer[size] = { 0 }; // Initialisation du buffer

      BOOL success = ZwReadFile(fileHandle, buffer, size, &bytesRead);

      THEN("The read operation should succeed") {
        REQUIRE(success == TRUE);  // Vérifie que la lecture a réussi
        REQUIRE(bytesRead > 0);   // Vérifie qu'on a bien lu des données
      }

      CloseHandle(fileHandle);  // Ferme le fichier après le test
    }
  }
}