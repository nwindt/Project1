#include 	<stdio.h>
#include	<iostream>
#include	<string>
#include 	"rt.h"			// change pathlist to this header file according to where it is stored


int main() {
	printf("Creating Child Processes.....\n");
	UINT flags = NORMAL_PRIORITY_CLASS;
	DWORD Time = INFINITE;

	std::string p1 = "C:\\Users\\Nick\\source\\repos\\Project1\\Debug\\Child1.exe";
	std::string p2 = "C:\\Users\\Nick\\source\\repos\\Project1\\Debug\\Child2.exe";
	std::string p3 = "C:\\Users\\Nick\\source\\repos\\Project1\\Debug\\Child3.exe Hello_From_Child3 200";

	PROCESS_INFORMATION pInfo1;
	PROCESS_INFORMATION pInfo2;
	PROCESS_INFORMATION pInfo3;

	STARTUPINFO	StartupInfo1 = {
		sizeof(STARTUPINFO) ,
		NULL ,			// reserved
		NULL ,			// ignored in console applications
		(char *)(p1.c_str()) ,	// displayed in title bar for console applications
		0,0,			// dwx, dwy, offset of top left of new window relative to top left of screen in pixel
						// flags below must specify STARTF_USEPOSITION. Ignored for console apps'
		0,0,			// dwxsize, dwysize: Width and height of the window if new window specified
						// must use flags STARTF_USESIZE. Ignored for console apps'
		0,0,			// size of console in characters, only if STARTF_USECOUNTCHARS flag specified, 
						// Ignored for console apps
		0,				// Colour control, for background and text. Ignored for console apps
		0,				// Flags. Ignored for console applications
		0,				// ignored unless showwindow flag set
		0 ,
		NULL,
		0,0,0			// stdin, stdout and stderr handles (inherited from parent)
	};

	STARTUPINFO	StartupInfo2 = {
		sizeof(STARTUPINFO) ,
		NULL ,			// reserved
		NULL ,			// ignored in console applications
		(char *)(p2.c_str()) ,	// displayed in title bar for console applications
		0,0,			// dwx, dwy, offset of top left of new window relative to top left of screen in pixel
						// flags below must specify STARTF_USEPOSITION. Ignored for console apps'
		0,0,			// dwxsize, dwysize: Width and height of the window if new window specified
						// must use flags STARTF_USESIZE. Ignored for console apps'
		0,0,			// size of console in characters, only if STARTF_USECOUNTCHARS flag specified, 
						// Ignored for console apps
		0,				// Colour control, for background and text. Ignored for console apps
		0,				// Flags. Ignored for console applications
		0,				// ignored unless showwindow flag set
		0 ,
		NULL,
		0,0,0			// stdin, stdout and stderr handles (inherited from parent)
	};

	STARTUPINFO	StartupInfo3 = {
		sizeof(STARTUPINFO) ,
		NULL ,			// reserved
		NULL ,			// ignored in console applications
		(char *)(p3.c_str()) ,	// displayed in title bar for console applications
		0,0,			// dwx, dwy, offset of top left of new window relative to top left of screen in pixel
						// flags below must specify STARTF_USEPOSITION. Ignored for console apps'
		0,0,			// dwxsize, dwysize: Width and height of the window if new window specified
						// must use flags STARTF_USESIZE. Ignored for console apps'
		0,0,			// size of console in characters, only if STARTF_USECOUNTCHARS flag specified, 
						// Ignored for console apps
		0,				// Colour control, for background and text. Ignored for console apps
		0,				// Flags. Ignored for console applications
		0,				// ignored unless showwindow flag set
		0 ,
		NULL,
		0,0,0			// stdin, stdout and stderr handles (inherited from parent)
	};

	BOOL Success = CreateProcess(NULL,	// application name
		(char *)(p1.c_str()),			// Command line to the process if you want to pass one to main() in the process
		NULL,			// process attributes
		NULL,			// thread attributes
		TRUE,			// inherits handles of parent
		flags,			// Priority and Window control flags,
		NULL,			// use environent of parent
		NULL,			// use same drive and directory as parent
		&StartupInfo1,	// controls appearance of process (see above)
		&pInfo1			// Stored process handle and ID into this object
	);

	if (Success)
		std::cout << "Creted Thread 1";

	Success = CreateProcess(NULL,	// application name
		(char *)(p2.c_str()),			// Command line to the process if you want to pass one to main() in the process
		NULL,			// process attributes
		NULL,			// thread attributes
		TRUE,			// inherits handles of parent
		flags,			// Priority and Window control flags,
		NULL,			// use environent of parent
		NULL,			// use same drive and directory as parent
		&StartupInfo2,	// controls appearance of process (see above)
		&pInfo2			// Stored process handle and ID into this object
	);

	if (Success)
		std::cout << "Creted Thread 2";

	Success = CreateProcess(NULL,	// application name
		(char *)(p3.c_str()),			// Command line to the process if you want to pass one to main() in the process
		NULL,			// process attributes
		NULL,			// thread attributes
		TRUE,			// inherits handles of parent
		flags,			// Priority and Window control flags,
		NULL,			// use environent of parent
		NULL,			// use same drive and directory as parent
		&StartupInfo3,	// controls appearance of process (see above)
		&pInfo3			// Stored process handle and ID into this object
	);

	if (Success)
		std::cout << "Creted Thread 3";
	Sleep(2000);
	SuspendThread(pInfo1.hThread);
	SuspendThread(pInfo2.hThread);
	SuspendThread(pInfo3.hThread);
	Sleep(5000);
	ResumeThread(pInfo1.hThread);
	ResumeThread(pInfo2.hThread);
	ResumeThread(pInfo3.hThread);
	

	UINT Result = WaitForSingleObject(pInfo1.hProcess, Time);
	PERR(Result != WAIT_FAILED, string("Cannot Wait for Child Process: 1"));	// check for error and print message if appropriate== WAIT_OBJECT_0 ) 

	Result = WaitForSingleObject(pInfo2.hProcess, Time);
	PERR(Result != WAIT_FAILED, string("Cannot Wait for Child Process: 2"));	// check for error and print message if appropriate== WAIT_OBJECT_0 ) 

	Result = WaitForSingleObject(pInfo3.hProcess, Time);
	PERR(Result != WAIT_FAILED, string("Cannot Wait for Child Process: 3"));	// check for error and print message if appropriate== WAIT_OBJECT_0 ) 

}