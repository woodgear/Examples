// TestDll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "InterFace.h"
#define Log printf
using namespace std;
void hasErr(HINSTANCE res) {
	if (res)
	{
		DWORD errcode = GetLastError();
		Log("err=>%d",errcode);
	}
}
int main()
{
	HINSTANCE logdll= LoadLibrary(L"D:\\Project\\Windows\\TestDll\\Debug\\LogDll.dll");
	if (logdll==NULL)
	{
		DWORD errcode = GetLastError();
		Log("err=>%d", errcode);
		return -1;
	}

	cout << "LoadLibrary OK" << endl;
	
	InterFace * (*CreatePlugin)();
	CreatePlugin=(InterFace * (*)())GetProcAddress(logdll, "?CreatePlugin@@YAPAVInterFace@@XZ");
	cout << "GetProcAddress OK" << endl;

	InterFace* logPlugin = CreatePlugin();

	logPlugin->eval("test");
	FreeLibrary(logdll);
	system("pause");
	return 0;
}

