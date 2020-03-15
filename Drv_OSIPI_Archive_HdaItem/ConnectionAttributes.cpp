#include"pch.h"
#include"ConnectionAttributes.h"

DrvOSIPIArchValues::ServerConfiguration::ServerConfiguration(const std::string& computer, const std::string& server, unsigned int number) :
	computerName(computer), serverName(server), port(number)
{

}

DrvOSIPIArchValues::ServerConfiguration::ServerConfiguration(const std::string& computer, unsigned int number) :
	ServerConfiguration(computer, std::string(), number)
{

}

DrvOSIPIArchValues::ServerConfiguration::ServerConfiguration(const std::string& computer) :
	ServerConfiguration(computer, 0)
{

}

DrvOSIPIArchValues::ServerConfiguration::ServerConfiguration() :
	ServerConfiguration(std::string())
{

}

DrvOSIPIArchValues::ServerConfiguration::~ServerConfiguration()
{
	computerName.clear();
	serverName.clear();
	port = 0;
}

bool DrvOSIPIArchValues::operator==(const ServerConfiguration& lhs, const ServerConfiguration& rhs)
{
	return lhs.computerName == rhs.computerName && lhs.serverName == rhs.serverName && lhs.port == rhs.port;
}

bool DrvOSIPIArchValues::operator!=(const ServerConfiguration& lhs, const ServerConfiguration& rhs)
{
	return lhs.computerName != rhs.computerName || lhs.serverName != rhs.serverName || lhs.port != rhs.port;
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


DrvOSIPIArchValues::SecurityAccessConfiguration::SecurityAccessConfiguration(const SecurityUserNameAccess& user) :
	m_userLogin(user)
{

}


DrvOSIPIArchValues::SecurityAccessConfiguration::SecurityAccessConfiguration() :
	SecurityAccessConfiguration(SecurityUserNameAccess())
{

}

DrvOSIPIArchValues::SecurityAccessConfiguration::~SecurityAccessConfiguration()
{

}

bool DrvOSIPIArchValues::operator==(const SecurityAccessConfiguration& lhs, const SecurityAccessConfiguration& rhs)
{
	return lhs.m_userLogin == rhs.m_userLogin;
}

bool DrvOSIPIArchValues::operator!=(const SecurityAccessConfiguration& lhs, const SecurityAccessConfiguration& rhs)
{
	return lhs.m_userLogin != rhs.m_userLogin;
}

DrvOSIPIArchValues::ConnectionAttributes::ConnectionAttributes(const ServerConfiguration& server, const SecurityAccessConfiguration& accessType) :
	configuration(server), configurationAccess(accessType)
{

}

DrvOSIPIArchValues::ConnectionAttributes::ConnectionAttributes(const ServerConfiguration& server) :
	ConnectionAttributes(server, SecurityAccessConfiguration())
{

}


DrvOSIPIArchValues::ConnectionAttributes::ConnectionAttributes() :
	ConnectionAttributes(ServerConfiguration())
{

}

DrvOSIPIArchValues::ConnectionAttributes::~ConnectionAttributes()
{

}

bool DrvOSIPIArchValues::operator==(const ConnectionAttributes& lhs, const ConnectionAttributes& rhs)
{
	return lhs.configuration == rhs.configuration && lhs.configurationAccess == rhs.configurationAccess;
}

bool DrvOSIPIArchValues::operator!=(const ConnectionAttributes& lhs, const ConnectionAttributes& rhs)
{
	return lhs.configuration != rhs.configuration || lhs.configurationAccess != rhs.configurationAccess;
}