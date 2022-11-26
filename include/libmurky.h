/*********************************************************************
 * Copyright (c) 2021-2022 STARSHORE. All rights reserved.
 *
 * @file   libmurky.h
 * @brief  library public symbols
 * 
 * @author starshore
 * @date   November 2022
 *********************************************************************/

#ifndef _LIBMURKY_H_
#define _LIBMURKY_H_

// Windows Header
#define WIN32_LEAN_AND_MEAN
#define WIN32_NO_STATUS
#include <windows.h>
#include <windowsx.h>

// NT Headers
#undef WIN32_NO_STATUS
#include <ntstatus.h>
#include <winioctl.h>

// NTSTATUS
typedef _Return_type_success_(return >= 0) LONG NTSTATUS;
typedef NTSTATUS *PNTSTATUS;

// Function Table
typedef struct _MKCTL {

    // Murky Library Version
    LONG(NTAPI *GetVersion)();

} MKCTL, *PMKCTL;

// Initialize Function Table
NTSTATUS NTAPI MurkyStartup(_In_ PMKCTL Mkctl);

#endif // defined(_LIBMURKY_H_)
