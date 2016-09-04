#include "Convert.h"


Convert::Convert(){}

Convert::~Convert(){}

Convert::Convert(const std::string&mbStr, const std::wstring&wcStr) 
			:mbString(mbStr), wcString(wcStr){}

Convert::Convert(const Convert&alienConvert) 
			:mbString(alienConvert.mbString), wcString(alienConvert.wcString){}

Convert& Convert::operator=(const Convert&alienConvert)
{
	this->mbString = alienConvert.mbString; 
	this->wcString = alienConvert.wcString; 
	return *this; 
}

std::wstring Convert::StringToWideChar(const std::string&mbStr) 
{
	std::wstring wstrRet(mbStr.length()+1, '\0'); 
	int err=MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, mbStr.c_str(), mbStr.length(), &wstrRet[0], wstrRet.size()); 

	return wstrRet; 
}

std::string Convert::WideCharToString(const std::wstring&wcStr)
{
	std::string strRet(wcStr.length() + 1, '\0'); 
	int err=WideCharToMultiByte(CP_ACP, WC_NO_BEST_FIT_CHARS, wcStr.c_str(), wcStr.length(), &strRet[0], strRet.size(),0,0); 

	return strRet; 
}

int Convert::SetMultiByte(const std::string&mbStr)
{
	int iRet = 0; 
	
	this->mbString = mbStr; 
	if (this->mbString == mbStr)
		iRet = 1; 
	return iRet; 
}

int Convert::SetWideChar(const std::wstring&wcStr)
{
	int iRet = 0; 

	this->wcString = wcStr; 
	if (this->wcString == wcStr)
		iRet = 1; 
	return iRet; 
}

const std::string& Convert::GetMultiByte() const
{
	return this->mbString; 
}

const std::wstring& Convert::GetWideChar() const
{
	return this->wcString; 
}

