#pragma once
#include<System/ILog.h>

namespace DrvOSIPIArchValues
{

	class Log
	{
		struct LogBody;
	public:

		~Log();

		void Init(ODS::System::ILog* pILog);

		static Log* GetInstance();

		void WriteInfo(const TCHAR* szFormat, ...);

		void WriteInfoDebug(const TCHAR* szFormat, ...);

		void WriteError(const TCHAR* szFormat, ...);

		void WriteErrorDebug(const TCHAR* szFormat, ...);

	private:

		Log();

		void WriteImpl(int nLevel, int nMsgType, const TCHAR* szFormat, va_list argList);

		static Log* m_pInstance;
		LogBody* m_pBody;
	};
}