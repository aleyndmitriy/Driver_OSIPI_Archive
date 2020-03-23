#pragma once
#include<string>
#include<vector>

namespace DrvOSIPIArchValues
{
	class IServerInteractorOutput
	{
	public:
		virtual void SendMessageError(std::string&& message) = 0;
		virtual void SendWarning(std::string&& message) = 0;
		virtual void SendMessageInfo(std::string&& message) = 0;
		virtual void GetServers(std::vector<std::pair<std::string, long> >&& servers) = 0;
		virtual void SelectFoundedServer(const std::string& compName, unsigned int port, const std::string& serverName) = 0;
		virtual void GetNewConnectionGuide(std::string&& uuid) = 0;
		virtual void CloseConnectionWithGuide(std::string&& uuid) = 0;
		virtual ~IServerInteractorOutput() {};
	};
}