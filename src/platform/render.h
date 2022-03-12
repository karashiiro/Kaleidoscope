#pragma once

#include <imgui.h>
#include <opencv2/core/mat.hpp>

/// Initializes ImGui using its platform-specific setup code.
int ImGuiPlatformInit();

/// Prepares the system to render an ImGui frame.
int ImGuiOnUpdatePreRender(bool& done);

/// Cleans up the renderer for the next ImGui frame.
int ImGuiOnUpdatePostRender();

/// Cleans up any resources used by ImGui.
int ImGuiPlatformShutdown();

/// Loads an image file to an ImTextureID.
bool LoadTextureFromFile(const char* filename, ImTextureID* out_tex, int* out_width, int* out_height);

/// Loads an OpenCV matrix to an ImTextureID.
bool LoadTextureFromMat(const cv::Mat& mat, ImTextureID* out_tex, int* out_width, int* out_height);

/// Frees an ImTextureID.
bool FreeTexture(ImTextureID* tex);