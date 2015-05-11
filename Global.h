#pragma warning(disable:4996)
#pragma warning(disable:4995)
#pragma warning(disable:4244)
#pragma warning(disable:4552)
#pragma warning(disable:4800)
#pragma once

//header files
#define WIN32_EXTRA_LEAN
#define DIRECTINPUT_VERSION 0x0800
#include <windows.h>

#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <xinput.h>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

//libraries
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"user32.lib")
#pragma comment(lib,"gdi32.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"xinput.lib")

//program values
extern const string APPTITLE;
extern const int SCREENW;
extern const int SCREENH;
extern bool gameover;

//macro to detect key presses
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

//Direct3D objects
extern LPDIRECT3D9 d3d; 
extern LPDIRECT3DDEVICE9 d3ddev; 
extern LPDIRECT3DSURFACE9 backbuffer;
extern LPD3DXSPRITE spriteobj;


///this is sprite and its properties 
class Objects{
public:
	LPDIRECT3DTEXTURE9 picture;// this will be the spirte
	float rot;//rotation
	float xpos;//x position
	float ypos;//y position
	float w;//width
	float h;// height
	float scal;//scaling
	float rots;//??
	int frm;//frame of the sprite
	int col;//column of sprite
	bool draw;// should it be drawn, possibly removed in future
	D3DCOLOR color;

	virtual void setDraw(LPDIRECT3DTEXTURE9 pic,float x, float y,float width, float height,float scaling,int frame,int column,float rotation);//sets the draw of the sprite
	virtual void Draw();//this will draw
	virtual void Animate();//this will animte
	virtual void Action();//this will be an action wich will be detremined based on the sub class ex. jumping shooting
	virtual void Movement();// this will move the object if can move
	virtual void Collided();// this what happens if they collide, this may tie in with action 
	Objects();
	~Objects();
};


//Direct3D functions
bool Direct3D_Init(HWND hwnd, int width, int height, bool fullscreen);
void Direct3D_Shutdown();
LPDIRECT3DSURFACE9 LoadSurface(string filename);



//DirectInput objects, devices, and states
extern LPDIRECTINPUT8 dinput;
extern LPDIRECTINPUTDEVICE8 dimouse;
extern LPDIRECTINPUTDEVICE8 dikeyboard;
extern DIMOUSESTATE mouse_state;
extern XINPUT_GAMEPAD controllers[4];

//DirectInput functions
bool DirectInput_Init(HWND);
void DirectInput_Update();
void DirectInput_Shutdown();
bool Key_Down(int);
int Mouse_Button(int);
int Mouse_X();
int Mouse_Y();
void XInput_Vibrate(int contNum = 0, int amount = 65535);
bool XInput_Controller_Found();

//game functions
bool Game_Init(HWND window);
void Game_Run(HWND window);
void Game_End();


//font functions
LPD3DXFONT MakeFont(string name, int size);
void FontPrint(LPD3DXFONT font, int x, int y, string text, D3DCOLOR color = D3DCOLOR_XRGB(255,255,255));
