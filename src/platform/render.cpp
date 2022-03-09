#include "render.h"

#ifdef WIN32
#include "render/dx12_win32.h"
#endif

int ImGuiPlatformInit()
{
	NativePlatformInit();
}

int ImGuiOnUpdatePreRender(bool &done)
{
	NativeOnUpdatePreRender(done);
}

int ImGuiOnUpdatePostRender()
{
	NativeOnUpdatePostRender();
}

int ImGuiPlatformShutdown()
{
	NativePlatformShutdown();
}