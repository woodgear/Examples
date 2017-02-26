#include "stdafx.h"
#include "LogDll.h"
#include <InterFace.h>
#include "Plugin.h"
__declspec(dllexport) InterFace* __cdecl CreatePlugin()
{
	printf("CreatePlugin\n");
	Plugin* a=new Plugin(data);
	return a;
}

void ON_DLL_PROCESS_ATTACH(){
	printf("DLL_PROCESS_ATTACH\n");
	data = "lalalalalla";
}
void ON_DLL_THREAD_ATTACH() {
	printf("ON_DLL_THREAD_ATTACH\n");
}

void ON_DLL_THREAD_DETACH() {
	printf("ON_DLL_THREAD_DETACH\n");
}

void ON_DLL_PROCESS_DETACH() {
	printf("ON_DLL_PROCESS_DETACH\n");
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		ON_DLL_PROCESS_ATTACH();
		break;
	case DLL_THREAD_ATTACH:
		ON_DLL_THREAD_ATTACH();
		break;
	case DLL_THREAD_DETACH:
		ON_DLL_THREAD_DETACH();
		break;
	case DLL_PROCESS_DETACH:
		ON_DLL_PROCESS_DETACH();
		break;
	}
	return TRUE;
}