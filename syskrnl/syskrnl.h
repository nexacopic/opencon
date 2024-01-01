// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the SYSKRNL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// SYSKRNL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SYSKRNL_EXPORTS
#define SYSKRNL_API __declspec(dllexport)
#else
#define SYSKRNL_API __declspec(dllimport)
#endif

// This class is exported from the dll
class SYSKRNL_API Csyskrnl {
public:
	Csyskrnl(void);
	// TODO: add your methods here.
};

extern SYSKRNL_API int nsyskrnl;

SYSKRNL_API int fnsyskrnl(void);
