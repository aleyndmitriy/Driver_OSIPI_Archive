#pragma once
#include<string>
#include<vector>

namespace DrvOSIPIArchValues
{

	struct ServerConfiguration {
		std::string computerName;
		std::string serverName;
		unsigned int port;
		ServerConfiguration(const std::string& computer, const std::string& server, unsigned int number);
		ServerConfiguration(const std::string& computer, unsigned int number);
		ServerConfiguration(const std::string& computer);
		ServerConfiguration();
		~ServerConfiguration();
		ServerConfiguration(const ServerConfiguration& src) = default;
		ServerConfiguration& operator=(const ServerConfiguration& rhs) = default;
		ServerConfiguration(ServerConfiguration&& src) = default;
		ServerConfiguration& operator=(ServerConfiguration&& rhs) = default;
	};
	bool operator==(const ServerConfiguration& lhs, const ServerConfiguration& rhs);
	bool operator!=(const ServerConfiguration& lhs, const ServerConfiguration& rhs);


	struct SecurityUserNameAccess {
		std::string m_login;
		std::string m_password;
		SecurityUserNameAccess(const std::string& login, const std::string& password);
		SecurityUserNameAccess(const SecurityUserNameAccess& src) = default;
		SecurityUserNameAccess& operator=(const SecurityUserNameAccess& src) = default;
		SecurityUserNameAccess(SecurityUserNameAccess&& src) = default;
		SecurityUserNameAccess& operator=(SecurityUserNameAccess&& src) = default;
		SecurityUserNameAccess();
		~SecurityUserNameAccess();
	};
	bool operator==(const SecurityUserNameAccess& lhs, const SecurityUserNameAccess& rhs);
	bool operator!=(const SecurityUserNameAccess& lhs, const SecurityUserNameAccess& rhs);

	
	struct SecurityAccessConfiguration {
		SecurityUserNameAccess m_userLogin;
		
		SecurityAccessConfiguration(const SecurityUserNameAccess& user);
		SecurityAccessConfiguration();
		~SecurityAccessConfiguration();
		SecurityAccessConfiguration(const SecurityAccessConfiguration& src) = default;
		SecurityAccessConfiguration& operator=(const SecurityAccessConfiguration& rhs) = default;
		SecurityAccessConfiguration(SecurityAccessConfiguration&& src) = default;
		SecurityAccessConfiguration& operator=(SecurityAccessConfiguration&& rhs) = default;
	};

	bool operator==(const SecurityAccessConfiguration& lhs, const SecurityAccessConfiguration& rhs);
	bool operator!=(const SecurityAccessConfiguration& lhs, const SecurityAccessConfiguration& rhs);

	struct ConnectionAttributes {
		ServerConfiguration configuration;
		SecurityAccessConfiguration configurationAccess;
		ConnectionAttributes(const ServerConfiguration& server, const SecurityAccessConfiguration& accessType);
		ConnectionAttributes(const ServerConfiguration& server);
		ConnectionAttributes();
		~ConnectionAttributes();
		ConnectionAttributes(const ConnectionAttributes& src) = default;
		ConnectionAttributes& operator=(const ConnectionAttributes& rhs) = default;
		ConnectionAttributes(ConnectionAttributes&& src) = default;
		ConnectionAttributes& operator=(ConnectionAttributes&& rhs) = default;
	};

	bool operator==(const ConnectionAttributes& lhs, const ConnectionAttributes& rhs);
	bool operator!=(const ConnectionAttributes& lhs, const ConnectionAttributes& rhs);

	struct DataTypeAttributes {
		int m_iProcessed;
		std::pair<std::string, int> m_pAggregateType;
		double m_dProcessingInterval;
		std::vector<std::string> m_vDataQuantities;
	};
}