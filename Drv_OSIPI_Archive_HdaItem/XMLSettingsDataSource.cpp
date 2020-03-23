#include"pch.h"
#include"XMLSettingsDataSource.h"
#include<pugixml.hpp>

bool DrvOSIPIArchValues::XMLSettingsDataSource::Save(const ConnectionAttributes& connectionAttributes, const DataTypeAttributes& dataAttributes, std::ostream& stream)
{
	pugi::xml_document doc;
	pugi::xml_node rootNode = doc.append_child("Settings");
	pugi::xml_node serverNode = rootNode.append_child("ServerConfiguration");
	serverNode.append_attribute("Server").set_value(connectionAttributes.configuration.serverName.c_str());
	serverNode.append_attribute("Port").set_value(connectionAttributes.configuration.port);
	
	pugi::xml_node connectionNode = rootNode.append_child("SecurityAccessConfiguration");
	connectionNode.append_attribute("UserName").set_value(connectionAttributes.userAccess.m_login.c_str());
	std::string encryptUserPass = connectionAttributes.userAccess.m_password;
	connectionNode.append_attribute("UserPassword").set_value(encryptUserPass.c_str());
	

	rootNode = doc.append_child("DataType");
	pugi::xml_node processedNode = rootNode.append_child("ReadType");
	processedNode.append_attribute("Processed").set_value(dataAttributes.m_iProcessed);
	processedNode.append_attribute("Aggregate").set_value(dataAttributes.m_pAggregateType.first.c_str());
	processedNode.append_attribute("Identifier").set_value(dataAttributes.m_pAggregateType.second);
	processedNode.append_attribute("Interval").set_value(dataAttributes.m_dProcessingInterval);
	pugi::xml_node qualitiesNode = rootNode.append_child("DataQualities");
	for (std::vector<std::string>::const_iterator itr = dataAttributes.m_vDataQuantities.cbegin(); itr != dataAttributes.m_vDataQuantities.cend(); ++itr) {
		pugi::xml_node qualityNode = qualitiesNode.append_child("Quality");
		qualityNode.append_attribute("Value").set_value(itr->c_str());
	}
	doc.save(stream);
	return true;
}

bool DrvOSIPIArchValues::XMLSettingsDataSource::Load(ConnectionAttributes& connectionAttributes, DataTypeAttributes& dataAttributes, std::istream& stream)
{
	pugi::xml_document doc;
	pugi::xml_parse_result res = doc.load(stream);
	if (!res) {
		return false;
	}
	pugi::xml_node rootNode = doc.child("Settings");
	pugi::xml_node serverNode = rootNode.child("ServerConfiguration");
	std::string serverName = std::string(serverNode.attribute("Server").as_string());
	unsigned int port = serverNode.attribute("Port").as_uint();
	ServerConfiguration serverConfiguration(serverName, port);

	
	pugi::xml_node connectionNode = rootNode.child("SecurityAccessConfiguration");
	std::string loginName = std::string(connectionNode.attribute("UserName").as_string());
	std::string loginPass = std::string(connectionNode.attribute("UserPassword").as_string());
	SecurityUserNameAccess userAccess(loginName, loginPass);

	connectionAttributes.configuration = serverConfiguration;
	connectionAttributes.userAccess = userAccess;

	rootNode = doc.child("DataType");
	pugi::xml_node processedNode = rootNode.child("ReadType");
	int processed = processedNode.attribute("Processed").as_int();
	std::string processedType = std::string(processedNode.attribute("Aggregate").as_string());
	int indexAggregateType = processedNode.attribute("Identifier").as_int();
	double interval = processedNode.attribute("Interval").as_double();
	pugi::xml_node qualitiesNode = rootNode.child("DataQualities");
	std::vector<std::string> qualities;
	for (pugi::xml_node qualityNode = qualitiesNode.child("Quality"); qualityNode; qualityNode = qualityNode.next_sibling("Quality"))
	{
		std::string quality = std::string(qualityNode.attribute("Value").as_string());
		qualities.push_back(quality);
	}
	dataAttributes.m_vDataQuantities.clear();
	dataAttributes.m_iProcessed = processed;
	dataAttributes.m_pAggregateType = std::make_pair<std::string, int>(std::move(processedType), std::move(indexAggregateType));
	dataAttributes.m_dProcessingInterval = interval;
	if (!qualities.empty()) {
		dataAttributes.m_vDataQuantities.assign(qualities.cbegin(), qualities.cend());
	}
	return true;
}

bool DrvOSIPIArchValues::XMLSettingsDataSource::LoadAttributesString(const char* source, size_t length, ConnectionAttributes& connectionAttributes, DataTypeAttributes& dataAttributes)
{
	pugi::xml_document doc;
	pugi::xml_parse_result res = doc.load_buffer(source, length);
	if (!res) {
		return false;
	}
	pugi::xml_node rootNode = doc.child("Settings");
	pugi::xml_node serverNode = rootNode.child("ServerConfiguration");
	std::string serverName = std::string(serverNode.attribute("Server").as_string());
	unsigned int port = serverNode.attribute("Port").as_uint();
	ServerConfiguration serverConfiguration(serverName, port);


	pugi::xml_node connectionNode = rootNode.child("SecurityAccessConfiguration");
	std::string loginName = std::string(connectionNode.attribute("UserName").as_string());
	std::string loginPass = std::string(connectionNode.attribute("UserPassword").as_string());
	SecurityUserNameAccess userAccess(loginName, loginPass);

	connectionAttributes.configuration = serverConfiguration;
	connectionAttributes.userAccess = userAccess;

	rootNode = doc.child("DataType");
	pugi::xml_node processedNode = rootNode.child("ReadType");
	int processed = processedNode.attribute("Processed").as_int();
	std::string processedType = std::string(processedNode.attribute("Aggregate").as_string());
	int indexAggregateType = processedNode.attribute("Identifier").as_int();
	double interval = processedNode.attribute("Interval").as_double();
	pugi::xml_node qualitiesNode = rootNode.child("DataQualities");
	std::vector<std::string> qualities;
	for (pugi::xml_node qualityNode = qualitiesNode.child("Quality"); qualityNode; qualityNode = qualityNode.next_sibling("Quality"))
	{
		std::string  quality = std::string(qualityNode.attribute("Value").as_string());
		qualities.push_back(quality);
	}
	dataAttributes.m_vDataQuantities.clear();
	dataAttributes.m_iProcessed = processed;
	dataAttributes.m_pAggregateType = std::make_pair<std::string, int>(std::move(processedType), std::move(indexAggregateType));
	dataAttributes.m_dProcessingInterval = interval;
	if (!qualities.empty()) {
		dataAttributes.m_vDataQuantities.assign(qualities.cbegin(), qualities.cend());
	}
	return true;
}