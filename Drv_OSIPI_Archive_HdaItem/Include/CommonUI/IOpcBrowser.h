#pragma once
#include <OdsString.h>
#include <vector>
#include <map>

namespace ODS
{
namespace Resources
{
class IOpcBrowser
{
public:
	enum class ServerType
	{
		DA,
		AE,
		HDA
	};
	virtual ~IOpcBrowser() {};
	virtual int GetServersList(ServerType type, const ODS::OdsString &hostName, std::vector<OdsString>& servers) =0;
	virtual int TestConnection(ServerType type, const ODS::OdsString &hostName, const ODS::OdsString &user, const ODS::OdsString &password, const OdsString & serverName) =0;
	virtual int GetHdaAggregateList(const ODS::OdsString& hostName, const OdsString& serverName, std::map<OdsString, DWORD>& aggregates) =0;
};
}
}