#include "Application.h"

#include "../platform/render.h"
#include <cassert>
#include <mutex>

void Application::Initialize()
{
	std::thread camera_thread(&Application::CameraThreadStart, this);
	camera_thread.detach();

	assert(LoadTextureFromFile("../ok.png", &tex, &tex_width, &tex_height));
}

void Application::PreRender()
{
	// Set when a new camera frame is ready
	if (camera_frame_expired)
	{
		// Set if a camera frame is loaded (initially false)
		if (camera_texture_loaded)
		{
			FreeTexture(&camera_tex);
			camera_texture_loaded = false;
		}

		{
			// Get in and out of this load procedure ASAP
			std::shared_lock lock(camera_frame_mtx);
			assert(LoadTextureFromMat(camera_frame, &camera_tex, &camera_tex_width, &camera_tex_height));
		}

		// Our current texture is safe to use
		camera_frame_expired = false;
		camera_texture_loaded = true;
	}
}

void Application::Render()
{
	// Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
	if (show_demo_window)
		ImGui::ShowDemoWindow(&show_demo_window);

	// Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
	{
		// Create a window called "Hello, world!" and append into it.
		ImGui::Begin("Hello, world!");

		// Display some text (you can use a format strings too)
		ImGui::Text("This is some useful text.");

		// Edit booleans storing our window open/close state
		ImGui::Checkbox("Demo Window", &show_demo_window);
		ImGui::Checkbox("Another Window", &show_another_window);

		// Edit 1 float using a slider from 0.0f to 1.0f
		ImGui::SliderFloat("float", &f, 0.0f, 1.0f);

		// Buttons return true when clicked (most widgets return true when edited/activated)
		if (ImGui::Button("Button"))
			counter++;
		ImGui::SameLine();
		ImGui::Text("counter = %d", counter);

		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();
	}

	{
		ImGui::Begin("DirectX11 Texture Test");
		ImGui::Text("pointer = %p", tex);
		ImGui::Text("size = %d x %d", tex_width, tex_height);
		ImGui::Image(tex, ImVec2(static_cast<float>(tex_width), static_cast<float>(tex_height)));
		ImGui::End();
	}

	{
		ImGui::Begin("Camera");

		if (camera_texture_loaded)
		{
			ImGui::Image(camera_tex, ImVec2(static_cast<float>(camera_tex_width), static_cast<float>(camera_tex_height)));
		}

		ImGui::End();
	}

	if (show_another_window)
	{
		ImGui::Begin("Another Window", &show_another_window);
		ImGui::Text("Hello from another window!");
		if (ImGui::Button("Close Me"))
			show_another_window = false;
		ImGui::End();
	}
}

void Application::Shutdown()
{
	done = true;

	if (tex != nullptr)
	{
		FreeTexture(&tex);
	}
}

void Application::CameraThreadStart()
{
	cv::Mat camera_frame_temp;
	cv::VideoCapture camera(0);
	while (!done)
	{
		camera >> camera_frame_temp;
		cv::cvtColor(camera_frame_temp, camera_frame_temp, CV_BGR2RGBA);

		{
			// This probably has more computational overhead than just
			// working on one locked matrix, but working on a single matrix
			// introduces lock contention issues that tank our frame rate.
			std::unique_lock lock(camera_frame_mtx);
			camera_frame = camera_frame_temp;
		}

		// Notify that the frame texture needs to be refreshed
		camera_frame_expired = true;
	}
}
