#include "Global.h"
//#include "Audio.h"

const string APPTITLE = "Horrible Hospital";
const int SCREENW = 1024;
const int SCREENH = 768;
IXAudio2SourceVoice* pSource;
IXAudio2SourceVoice* td;
IXAudio2* engine;
bool Game_Init(HWND window)
{
	//if(FAILED(hr=engine->CreateSourceVoice(&pSource,(WAVEFORMATEX*)&wfx)))
		//return hr;
	CoInitializeEx(NULL,COINIT_MULTITHREADED);//ignore
	if(FAILED(XAudio2Create(&engine))){
		CoUninitialize();
		return -1;
	}//ignore

    //initialize Direct3D
    Direct3D_Init(window, SCREENW, SCREENH, false);
	//if(FAILED(hr=pXAudio2->
    //initialize DirectInput
    DirectInput_Init(window);
	
	return true;
}

void Game_Run(HWND window)
{
	//make sure the Direct3D device is valid
	if (!d3ddev) return;
	//update input devices
	DirectInput_Update();
	//clear the scene
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);
	

	
	if (d3ddev->BeginScene())
	{
		//*** insert sprite code here ***
		spriteobj->Begin(D3DXSPRITE_ALPHABLEND);
		


	spriteobj->End();
	//stop rendering
	d3ddev->EndScene();
	d3ddev->Present(NULL, NULL, NULL, NULL);
}

    //exit when escape key is pressed
    if (KEY_DOWN(VK_ESCAPE)) gameover = true;

    //controller Back button also ends
    if (controllers[0].wButtons & XINPUT_GAMEPAD_BACK)
        gameover = true;
}

void Game_End()
{
    //free memory and shut down
    DirectInput_Shutdown();
    Direct3D_Shutdown();
}
