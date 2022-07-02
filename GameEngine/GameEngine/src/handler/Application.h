#pragma once

struct GLFWwindow;

class Application
{
public:
	static Application* getInstance()
	{
		if (!instance)
		{
			instance = new Application();
		}

		return instance;
	}

	GLFWwindow* getWindow()
	{
		return this->window;
	}

	void setWindow(GLFWwindow* newWindow)
	{
		this->window = newWindow;
	}


private:
	static Application* instance;
	GLFWwindow* window;


	Application()
	{
		window = nullptr;
	}

};