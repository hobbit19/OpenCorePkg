/** @file
  Copyright (C) 2018, vit9696. All rights reserved.

  All rights reserved.

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
**/

#ifndef OC_BOOTSTRAP_PROTOCOL_H
#define OC_BOOTSTRAP_PROTOCOL_H

#include <Protocol/SimpleFileSystem.h>

///
/// BA1EB455-B182-4F14-8521-E422C325DEF6
///
#define OC_BOOTSTRAP_PROTOCOL_GUID                                                  \
  {                                                                                 \
    0xBA1EB455, 0xB182, 0x4F14, { 0x85, 0x21, 0xE4, 0x22, 0xC3, 0x25, 0xDE, 0xF6 }  \
  }

///
/// Forward declaration of OC_BOOTSTRAP_PROTOCOL structure.
///
typedef struct OC_BOOTSTRAP_PROTOCOL_ OC_BOOTSTRAP_PROTOCOL;

/**
  Restart OpenCore at specified file system, does not return.

  @param[in] This           This protocol.
  @param[in] FileSystem     File system to bootstrap in.
**/
typedef
VOID
(EFIAPI *OC_BOOTSTRAP_RERUN) (
  IN OC_BOOTSTRAP_PROTOCOL            *This,
  IN EFI_SIMPLE_FILE_SYSTEM_PROTOCOL  *FileSystem
  );

///
/// The structure exposed by the OC_BOOTSTRAP_PROTOCOL.
///
struct OC_BOOTSTRAP_PROTOCOL_ {
  UINTN               Revision;
  OC_BOOTSTRAP_RERUN  ReRun;
};

extern EFI_GUID gOcBootstrapProtocolGuid;

#endif // OC_BOOTSTRAP_PROTOCOL_H
