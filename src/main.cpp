#include "core/Application.h"

#ifdef WIN32
#include "platform/dx12_win32.h"
#endif

int main(int, char**)
{
	// Initialize imgui with any platform-specific setup code
	if (ImGuiPlatformInit() != 0)
		return 1;

	Application app;

	// Main loop
	bool done = false;
	while (!done)
	{
		if (ImGuiOnUpdatePreRender(done) != 0)
			return 1;

		app.OnUpdate();
		ImGui::Render();

		if (ImGuiOnUpdatePostRender() != 0)
			return 1;
	}

	// Perform platform-specific cleanup
	if (ImGuiPlatformShutdown() != 0)
		return 1;
}