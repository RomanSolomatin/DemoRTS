#pragma once
#include "Engine.h"

#if !UE_BUILD_SHIPPING
#define VLogFS(string) { \
if(GEngine) \
GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, string);\
}
#else 
#define VLogFS(string) ((void)0)
#endif
