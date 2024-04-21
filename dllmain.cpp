#include <windows.h>
#include <fstream>

#include "ModLoader.h"

#pragma comment(linker, "/export:ApplyCompatResolutionQuirking=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.ApplyCompatResolutionQuirking")
#pragma comment(linker, "/export:CompatString=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.CompatString")
#pragma comment(linker, "/export:CompatValue=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.CompatValue")
#pragma comment(linker, "/export:DXGIDumpJournal=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.DXGIDumpJournal")
#pragma comment(linker, "/export:PIXBeginCapture=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.PIXBeginCapture")
#pragma comment(linker, "/export:PIXEndCapture=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.PIXEndCapture")
#pragma comment(linker, "/export:PIXGetCaptureState=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.PIXGetCaptureState")
#pragma comment(linker, "/export:SetAppCompatStringPointer=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.SetAppCompatStringPointer")
#pragma comment(linker, "/export:UpdateHMDEmulationStatus=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.UpdateHMDEmulationStatus")
#pragma comment(linker, "/export:CreateDXGIFactory1=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.CreateDXGIFactory1")
#pragma comment(linker, "/export:CreateDXGIFactory2=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.CreateDXGIFactory2")
#pragma comment(linker, "/export:CreateDXGIFactory=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.CreateDXGIFactory")
#pragma comment(linker, "/export:DXGID3D10CreateDevice=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.DXGID3D10CreateDevice")
#pragma comment(linker, "/export:DXGID3D10CreateLayeredDevice=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.DXGID3D10CreateLayeredDevice")
#pragma comment(linker, "/export:DXGID3D10GetLayeredDeviceSize=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.DXGID3D10GetLayeredDeviceSize")
#pragma comment(linker, "/export:DXGID3D10RegisterLayers=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.DXGID3D10RegisterLayers")
#pragma comment(linker, "/export:DXGIDeclareAdapterRemovalSupport=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.DXGIDeclareAdapterRemovalSupport")
#pragma comment(linker, "/export:DXGIDisableVBlankVirtualization=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.DXGIDisableVBlankVirtualization")
#pragma comment(linker, "/export:DXGIGetDebugInterface1=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.DXGIGetDebugInterface1")
#pragma comment(linker, "/export:DXGIReportAdapterConfiguration=C:\\\\Windows\\\\SysWOW64\\\\dxgi.dll.DXGIReportAdapterConfiguration")


DWORD WINAPI LoaderThread(LPVOID lpParam)
{
    ModLoader loader;
    loader.LoadMods();
    return S_OK;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{

    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        CreateThread(0, 0, &LoaderThread, 0, 0, NULL);
    }

    return TRUE;
}
