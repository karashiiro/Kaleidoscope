#pragma once

#include <imgui.h>
#include <opencv2/opencv.hpp>
#include <shared_mutex>
#include <thread>

class Application
{
public:
	void Initialize();
	void PreRender();
	void Render();
	void Shutdown();

private:
	void CameraThreadStart();

	mutable std::shared_mutex camera_frame_mtx{};
	cv::Mat camera_frame{};
	bool camera_frame_expired = false;
	ImTextureID camera_tex = nullptr;
	int camera_tex_width = 0;
	int camera_tex_height = 0;
	bool camera_texture_loaded = false;

	ImTextureID tex = nullptr;
	int tex_width = 0;
	int tex_height = 0;
	bool show_demo_window = true;
	bool show_another_window = false;
	bool done = false;
	float f = 0.0f;
	int counter = 0;
};