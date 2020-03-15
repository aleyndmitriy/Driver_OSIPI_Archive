#pragma once
#include<pilogex.h>

namespace DrvOSIPIArchValues
{
	class PIApplication
	{
	public:
		static PIApplication& Instance();
		PIApplication(const PIApplication& src) = delete;
		PIApplication& operator=(const PIApplication& src) = delete;
		PIApplication(PIApplication&& src) = delete;
		PIApplication& operator=(PIApplication&& src) = delete;
		~PIApplication();
		bool StartApplication();
	private:
		PIApplication();
		HINSTANCE m_hAppInstance;
	};
}