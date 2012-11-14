#include "Pim.h"
#include "GameScene.h"



int main()
{
	{   // Stack cheating: avoid 'cd' from "leaking" memory
		Pim::WinStyle::CreationData cd;

		cd.resolution					= Pim::Vec2(960, 540);
		cd.defaultWindowedResolution	= cd.resolution;

		cd.renderResolution				= Pim::Vec2(384, 216);
		cd.coordinateSystem				= cd.renderResolution;

		cd.forcedAspectRatio			= true;
		cd.aspectRatio					= 16.f / 9.f;

		cd.winTitle						= "Trollberg";
		cd.winStyle						= Pim::WinStyle::WINDOWED;

		Pim::GameControl *gc = new Pim::GameControl;
		gc->go(new GameScene(1), cd);
		delete gc;
	}

#ifdef _DEBUG
	// Prints leaked memory TO THE OUTPUT TAB. Not the console. The outputtab in VS. 
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}

void TrollbergExit(std::string s)
{
	MessageBoxA(NULL, s.c_str(), "Trololol", MB_OK | MB_ICONEXCLAMATION);
	exit(1);
}