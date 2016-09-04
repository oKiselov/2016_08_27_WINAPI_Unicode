#pragma once

#include <iostream>
#include <string>
#include <Windows.h>

class Convert
{
	std::string mbString;
	std::wstring wcString; 
public:

	// Non-trivial member-functions and constructors 
	Convert();
	Convert(const std::string &, const std::wstring&);
	Convert(const Convert&); 
	virtual ~Convert();
	Convert&operator=(const Convert&); 

	// Member-function of transformation from wide string into string
	static std::string WideCharToString(const std::wstring&); 

	// Member-function of transformation from string into wide string 
	static std::wstring StringToWideChar(const std::string&); 

	// Member-functions of values settings  
	int SetMultiByte(const std::string&); 
	int SetWideChar(const std::wstring&); 

	// Member-functions of values gettings  
	const std::string&GetMultiByte(void)const; 
	const std::wstring&GetWideChar(void)const; 
};

