#pragma once

class Application
{
public:
	Application();
	void OnUpdate();

private:
	void* tex = nullptr;
	int tex_width = 0;
	int tex_height = 0;
	bool show_demo_window = true;
	bool show_another_window = false;
	float f = 0.0f;
	int counter = 0;
};