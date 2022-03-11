#pragma once

int NativePlatformInit();
int NativeOnUpdatePreRender(bool &done);
int NativeOnUpdatePostRender();
int NativePlatformShutdown();
bool NativeLoadTextureFromFile(const char* filename, void** out_srv, int* out_width, int* out_height);