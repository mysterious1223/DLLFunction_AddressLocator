/*
  Author: Mysterious
  Title: DLLFunction to Address Locator
  
  Instruction:
    Start program enter a DLL, ex. Kernel32.dll, then enter function name, ex. Sleep. It will then return the address.
*/


#include <iostream>
#pragma comment(lib, "Wtsapi32.lib")
#include <Windows.h>
#include <Wtsapi32.h>
#include <TlHelp32.h>
#include <tchar.h>




int main()
{

	// DEFAULT
	CHAR PathToDLL [] = "kernel32.dll";
	CHAR function [] = "Sleep";


	HMODULE hMod = NULL;
	FARPROC func;


	std::cout << "Please enter DLL to load: ";

	std::cin >> PathToDLL;

	std::cout << std::endl;

	std::cout << "Please enter a function to locate: ";

	std::cin >> function;

	std::cout << std::endl;

	hMod = LoadLibrary(PathToDLL);


	if (hMod == NULL)
	{

		std::cerr << "LIBRARY ERROR" << std::endl;
		
	}

	func = GetProcAddress(hMod, function);

	if (func == NULL)
	{
		std::cerr << "FUNC ERROR" << std::endl;
		

	}




	if (hMod != NULL && func != NULL)
		printf("%s is located at 0x%08x in %s\n", function, (unsigned int)func, PathToDLL);


	
	main();


	system("PAUSE");
	CloseHandle(hMod);
	return 0;

}
