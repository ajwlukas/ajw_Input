#pragma once

#include <Windows.h>

#include "dll.h"

namespace ajwCommon
{
	class AJW_KEYBOARD_DLLEXPORT Input
	{
		const static DWORD KEYMAX = 256;
	private:
		enum
		{
			NONE,
			DOWN,
			UP,
			PRESS
		};
	
		BYTE curState[KEYMAX];
		BYTE oldState[KEYMAX];
		BYTE mapState[KEYMAX];

		Input();
		~Input();
	public:
		static Input& Get() { static Input instance;  return instance; }

		Input(Input const&) = delete;
		void operator=(Input const&) = delete;

	
		void Update();
	
		bool Down(UINT key) { return mapState[key] == DOWN; }
		bool Up(UINT key) { return mapState[key] == UP; }
		bool Press(UINT key) { return mapState[key] == PRESS; }

		POINT MousePos() { return mousePos; }
		POINT MouseDiff() { return mouseDiff; }
	private:
		POINT mousePos;
		POINT mouseDiff;

		POINT oldMousePos;
	};
}
