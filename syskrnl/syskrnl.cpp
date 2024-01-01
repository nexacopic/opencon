// syskrnl.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "syskrnl.h"


// This is an example of an exported variable
SYSKRNL_API int nsyskrnl=0;

// This is an example of an exported function.
SYSKRNL_API int fnsyskrnl(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
Csyskrnl::Csyskrnl()
{
    return;
}
