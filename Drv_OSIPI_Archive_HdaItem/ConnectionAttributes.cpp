#include"pch.h"
#include"ConnectionAttributes.h"

DrvOSIPIArchValues::ServerConfiguration::ServerConfiguration(const std::string& server, unsigned int number) :
serverName(server), port(number)
{

}

DrvOSIPIArchValues::ServerConfiguration::ServerConfiguration():ServerConfiguration(std::string(),0)
{

}


DrvOSIPIArchValues::ServerConfiguration::~ServerConfiguration()
{
	serverName.clear();
	port = 0;
}

bool DrvOSIPIArchValues::operator==(const ServerConfiguration& lhs, const ServerConfiguration& rhs)
{
	return lhs.serverName == rhs.serverName && lhs.port == rhs.port;
}

bool DrvOSIPIArchValues::operator!=(const ServerConfiguration& lhs, const ServerConfiguration& rhs)
{
	return lhs.serverName != rhs.serverName || lhs.port != rhs.port;
}


DrvOSIPIArchValues::SecurityUserNameAccess::SecurityUserNameAccess(const std::string& login, const std::string& password) :
	m_login(login), m_password(password)
{

}

DrvOSIPIArchValues::SecurityUserNameAccess::SecurityUserNameAccess() :SecurityUserNameAccess(std::string(), std::string())
{

}

DrvOSIPIArchValues::SecurityUserNameAccess::~SecurityUserNameAccess()
{

}


bool DrvOSIPIArchValues::operator==(const SecurityUserNameAccess& lhs, const SecurityUserNameAccess& rhs)
{
	return lhs.m_login == rhs.m_login && lhs.m_password == rhs.m_password;
}

bool DrvOSIPIArchValues::operator!=(const SecurityUserNameAccess& lhs, const SecurityUserNameAccess& rhs)
{
	return lhs.m_login != rhs.m_login || lhs.m_password != rhs.m_password;
}



DrvOSIPIArchValues::ConnectionAttributes::ConnectionAttributes(const ServerConfiguration& server, const SecurityUserNameAccess& accessType) :
	configuration(server), userAccess(accessType)
{

}

DrvOSIPIArchValues::ConnectionAttributes::ConnectionAttributes(const ServerConfiguration& server) :
	ConnectionAttributes(server, SecurityUserNameAccess())
{

}

DrvOSIPIArchValues::ConnectionAttributes::ConnectionAttributes():
	ConnectionAttributes(ServerConfiguration())
{

}


DrvOSIPIArchValues::ConnectionAttributes::~ConnectionAttributes()
{

}

bool DrvOSIPIArchValues::operator==(const ConnectionAttributes& lhs, const ConnectionAttributes& rhs)
{
	return lhs.configuration == rhs.configuration && lhs.userAccess == rhs.userAccess;
}

bool DrvOSIPIArchValues::operator!=(const ConnectionAttributes& lhs, const ConnectionAttributes& rhs)
{
	return lhs.configuration != rhs.configuration || lhs.userAccess != rhs.userAccess;
}