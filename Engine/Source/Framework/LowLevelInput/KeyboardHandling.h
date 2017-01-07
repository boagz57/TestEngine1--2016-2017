#pragma once
#include "Universal/Macro.h"
//Needs to be included before the glfw.h (since RenderWindow contains glew.h)
#include "LowLevelWindow/WindowHandling.h"
#include "DataStructures/Array/Array.h"
#include "GLFW/glfw3.h"

namespace BlazeFramework
{
	enum Key
	{
		RightArrow = GLFW_KEY_RIGHT,
		LeftArrow = GLFW_KEY_LEFT,
		UpArrow = GLFW_KEY_UP,
		DownArrow = GLFW_KEY_DOWN,
		SpaceBar = GLFW_KEY_SPACE,
	};

	class KeyboardHandling
	{
	public:
		KeyboardHandling();

		static void SetWindowContextForKeyboard(WindowHandling::BlazeWindow* window);
		static bool IsKeyPressed(const uint16 key);

	private:
		friend void KeyCallBackFunction(WindowHandling::BlazeWindow* window, int keyCode, int scancode, int action, int mods);
		//This boolean array will be used to set different keycodes to either true 
		//or false, depending on what keys have been pressed
		static tArray<bool, GLFW_KEY_LAST> m_keyCodes;
	};
}