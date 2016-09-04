#include <iostream>
#include <string>
#include <Windows.h>
#include "Convert.h"

int main()
{
	setlocale(LC_ALL, "rus"); 
	
	// Declaration of object of class 
	Convert alConv;

	// Initialization of string 
	std::string strTemp{ "ё и ъ" }; 
	
	// Setting format of wide string (Unicode)
	std::wstring wcTemp(strTemp.length() + 1, '\0'); 
	
	// Initialization of wide string by transformed string
	wcTemp=alConv.StringToWideChar(strTemp);
	
	// Output of wide string 
	std::wcout << wcTemp << std::endl; 


	// Setting the member of class using created wide string 
	alConv.SetWideChar(wcTemp); 

	// Setting the member of class using member-function of transformation wstring->string
	alConv.SetMultiByte(alConv.WideCharToString(alConv.GetWideChar())); 

	// Output
	std::cout << alConv.GetMultiByte() << std::endl; 

	return 0; 
}