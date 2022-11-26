/*********************************************************************
 * Copyright (c) 2021-2022 STARSHORE. All rights reserved.
 *
 * @file   libmurky.c
 * @brief  library public symbols
 *
 * @author starshore
 * @date   November 2022
 *********************************************************************/

#include "libmurky.h"

LONG MkGetVersion()
{
    return (LONG)1;
}

/**
 * @brief initialize function table.
 *
 * @param Mkctl function pointer table
 * @return status
 */
NTSTATUS NTAPI MurkyStartup(_In_ PMKCTL Mkctl)
{
    if (!Mkctl) {
        return STATUS_INVALID_PARAMETER;
    }

    Mkctl->GetVersion = MkGetVersion;

    return STATUS_SUCCESS;
}

/**
 * @brief shared library entry.
 *
 * @param InstanceHandle instance handle
 * @param Reason reason
 * @param Reserved reserved
 * @return
 */
BOOL WINAPI DllMain(HINSTANCE InstanceHandle, DWORD Reason, LPVOID Reserved)
{
    UNREFERENCED_PARAMETER(InstanceHandle);
    UNREFERENCED_PARAMETER(Reserved);

    switch (Reason) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}
