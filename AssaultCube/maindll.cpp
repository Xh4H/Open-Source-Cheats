#include <Windows.h>
#include <iostream>
#include "stdafx.h"
/*
void WriteB(void* Address, void* ptr, int Size)
{
DWORD old_protect;
VirtualProtect(Address, Size, PAGE_EXECUTE_READWRITE, &old_protect);
memcpy(Address, ptr, Size);
VirtualProtect(Address, Size, old_protect, &old_protect);
}
*/
struct Player
{
public:
	DWORD baseAddress = 0x50F4F4;
	unsigned int name = 0x0224;
	unsigned int health = 0x00F8;
	unsigned int armour = 0xFC;
	unsigned int rifleAmmo = 0x150;
	unsigned int pistolAmmo = 0x13C;
	unsigned int grenadeAmmo = 0x158;
	unsigned int knifeWait = 0x0160;
	unsigned int pistolWait = 0x0164;
	unsigned int gunWait = 0x0178;
	unsigned int grenadeWait = 0x0180;
	unsigned int knifeShootCount = 0x0188;
	unsigned int pistolShootCount = 0x018C;
	unsigned int rifleShootCount = 0x01A0;
	unsigned int grenadeShootCount = 0x01A8;
	
}MyPlayer;

private void changeDesiredRecords()
{
	for (;; Sleep(10))
	{
		DWORD myBase = *(DWORD*)MyPlayer.baseAddress;

		if (myBase)
		{
			*(DWORD*)(myBase + MyPlayer.knifeWait) = 0;
			*(DWORD*)(myBase + MyPlayer.pistolWait) = 0;
			*(DWORD*)(myBase + MyPlayer.gunWait) = 0;
			*(DWORD*)(myBase + MyPlayer.grenadeWait) = 0;
			*(DWORD*)(myBase + MyPlayer.rifleAmmo) = 5000;
			*(DWORD*)(myBase + MyPlayer.pistolAmmo) = 5000;
			*(DWORD*)(myBase + MyPlayer.grenadeAmmo) = 30;
			*(DWORD*)(myBase + MyPlayer.health) = 4000;
			*(DWORD*)(myBase + MyPlayer.armour) = 2000;
		}
	}
}

BOOL WINAPI DllMain(HINSTANCE hModule, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changeDesiredRecords, 0, 0, 0);
		MessageBoxA(NULL, "Hey, good luck!", "Successfully attached.", MB_OK);
	}
	return TRUE;
}
