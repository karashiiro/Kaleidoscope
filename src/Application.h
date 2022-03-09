#pragma once
#include <imgui.h>

class Application
{
public:
	void OnUpdate();

	ImVec4 ClearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

private:
	bool show_demo_window = true;
	bool show_another_window = false;
	float f = 0.0f;
	int counter = 0;
};