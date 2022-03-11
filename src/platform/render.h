#pragma once

int ImGuiPlatformInit();
int ImGuiOnUpdatePreRender(bool &done);
int ImGuiOnUpdatePostRender();
int ImGuiPlatformShutdown();
bool LoadTextureFromFile(const char* filename, void** out_tex, int* out_width, int* out_height);