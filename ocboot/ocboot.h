#ifdef OCBOOT_EXPORTS
#define OCBOOT_API __declspec(dllexport)
#else
#define OCBOOT_API __declspec(dllimport)
#endif
#include <SoftwareRenderer.h>
extern "C" OCBOOT_API int bootloadersystemain(SoftwareRenderer * renderer);
