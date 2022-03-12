#pragma once

#include <imgui.h>
#include <opencv2/core/mat.hpp>

int NativePlatformInit();
int NativeOnUpdatePreRender(bool& done);
int NativeOnUpdatePostRender();
int NativePlatformShutdown();
bool NativeLoadTextureFromFile(const char* filename, ImTextureID* out_srv, int* out_width, int* out_height);
bool NativeLoadTextureFromMat(const cv::Mat& mat, ImTextureID* out_srv, int* out_width, int* out_height);
bool NativeFreeTexture(ImTextureID* srv);