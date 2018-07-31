#include <Windows.h>

#include "stdafx.h"

#include "../Common/common.h"

#include "client.h"
#include "device.h"


/**
 *
 */
int main()
{
	wprintf(L"Starting %s v%.02f\n", CFB_PROGRAM_NAME_SHORT, CFB_VERSION);
	
	HANDLE hDev = OpenDevice();

	if (hDev == INVALID_HANDLE_VALUE)
	{
		wprintf(L"Failed to get a handle to '%s'\n", CFB_DEVICE_NAME);
		wprintf(L"Hint: is the driver registered?\n");
		return -1;
	}

	RunInterpreter();

	CloseHandle(hDev);

	wprintf(L"Thanks for using %s, have a nice day!\n- %s\n", CFB_PROGRAM_NAME_SHORT, CFB_AUTHOR);

    return 0;
}

