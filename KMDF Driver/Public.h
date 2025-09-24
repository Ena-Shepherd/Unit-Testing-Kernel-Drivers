/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_KMDFDriver,
    0x1147d261,0xdd2f,0x47a6,0x99,0x32,0x13,0x57,0xac,0xc0,0x2e,0x3c);
// {1147d261-dd2f-47a6-9932-1357acc02e3c}
