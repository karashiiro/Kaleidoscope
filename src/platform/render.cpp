#include "render.h"

#ifdef WIN32
#include "render/win32_dx11.h"
#endif

int ImGuiPlatformInit()
{
	return NativePlatformInit();
}

int ImGuiOnUpdatePreRender(bool &done)
{
	return NativeOnUpdatePreRender(done);
}

int ImGuiOnUpdatePostRender()
{
	return NativeOnUpdatePostRender();
}

int ImGuiPlatformShutdown()
{
	return NativePlatformShutdown();
}

bool LoadTextureFromFile(const char* filename, ImTextureID* out_tex, int* out_width, int* out_height)
{
	return NativeLoadTextureFromFile(filename, out_tex, out_width, out_height);
}

bool LoadTextureFromMat(const cv::Mat& mat, ImTextureID* out_tex, int* out_width, int* out_height)
{
	return NativeLoadTextureFromMat(mat, out_tex, out_width, out_height);
}

bool FreeTexture(ImTextureID* tex)
{
	return NativeFreeTexture(tex);
}