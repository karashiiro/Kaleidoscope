#pragma once
#include <imgui.h>

class Application
{
public:
	void OnUpdate();

private:
	bool show_demo_window = true;
	bool show_another_window = false;
	float f = 0.0f;
	int counter = 0;
};