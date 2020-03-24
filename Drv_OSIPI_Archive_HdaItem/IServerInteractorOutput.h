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
		virtual void ConnectionOpened(bool isOpenned) = 0;
		virtual void ConnectionClosed(bool isClosed) = 0;
		virtual ~IServerInteractorOutput() {};
	};
}