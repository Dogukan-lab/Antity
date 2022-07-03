#pragma once
#include <unordered_map>

constexpr size_t MAX_CALLBACKS = 20;

class InputHandler
{
public:

	static InputHandler* getInstance()
	{
		if(!instance)
		{
			instance = new InputHandler();
		}

		return instance;
	}

	std::unordered_map<int, int> getCallbacks()
	{
		return this->callbacks;
	}

	void setKeyCallbacks(int key, int action)
	{
		this->callbacks[key] = action;
	}

private:
	static InputHandler* instance;
	std::unordered_map<int, int> callbacks;

	InputHandler()
	{
		callbacks.reserve(MAX_CALLBACKS);
	}
};