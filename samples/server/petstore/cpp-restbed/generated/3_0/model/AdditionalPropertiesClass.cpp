/**
 * OpenAPI Petstore
 * This spec is mainly for testing Petstore server and contains fake endpoints, models. Please do not use this for any other purpose. Special characters: \" \\
 *
 * The version of the OpenAPI document: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 8.0.0-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */



#include "AdditionalPropertiesClass.h"

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stdexcept>
#include <regex>
#include <boost/lexical_cast.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "helpers.h"

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

namespace org {
namespace openapitools {
namespace server {
namespace model {

AdditionalPropertiesClass::AdditionalPropertiesClass(boost::property_tree::ptree const& pt)
{
        fromPropertyTree(pt);
}


std::string AdditionalPropertiesClass::toJsonString(bool prettyJson /* = false */) const
{
	std::stringstream ss;
	write_json(ss, this->toPropertyTree(), prettyJson);
    // workaround inspired by: https://stackoverflow.com/a/56395440
    std::regex reg("\\\"([0-9]+\\.{0,1}[0-9]*)\\\"");
    std::string result = std::regex_replace(ss.str(), reg, "$1");
    return result;
}

void AdditionalPropertiesClass::fromJsonString(std::string const& jsonString)
{
	std::stringstream ss(jsonString);
	ptree pt;
	read_json(ss,pt);
	this->fromPropertyTree(pt);
}

ptree AdditionalPropertiesClass::toPropertyTree() const
{
	ptree pt;
	ptree tmp_node;
	// generate tree for Map_property
    if (!m_Map_property.empty()) {
        tmp_node = toPt(m_Map_property);
        pt.add_child("map_property", tmp_node);
    }
    tmp_node.clear();
	// generate tree for Map_of_map_property
    if (!m_Map_of_map_property.empty()) {
        tmp_node = toPt(m_Map_of_map_property);
        pt.add_child("map_of_map_property", tmp_node);
    }
    tmp_node.clear();
	return pt;
}

void AdditionalPropertiesClass::fromPropertyTree(ptree const &pt)
{
	ptree tmp_node;
    if (pt.get_child_optional("map_property")) {
        m_Map_property = fromPt<std::map<std::string, std::string>>(pt.get_child("map_property"));
    }
    if (pt.get_child_optional("map_of_map_property")) {
        m_Map_of_map_property = fromPt<std::map<std::string, std::map<std::string, std::string>>>(pt.get_child("map_of_map_property"));
    }
}

std::map<std::string, std::string> AdditionalPropertiesClass::getMapProperty() const
{
    return m_Map_property;
}

void AdditionalPropertiesClass::setMapProperty(std::map<std::string, std::string> value)
{
    m_Map_property = value;
}


std::map<std::string, std::map<std::string, std::string>> AdditionalPropertiesClass::getMapOfMapProperty() const
{
    return m_Map_of_map_property;
}

void AdditionalPropertiesClass::setMapOfMapProperty(std::map<std::string, std::map<std::string, std::string>> value)
{
    m_Map_of_map_property = value;
}



std::vector<AdditionalPropertiesClass> createAdditionalPropertiesClassVectorFromJsonString(const std::string& json)
{
    std::stringstream sstream(json);
    boost::property_tree::ptree pt;
    boost::property_tree::json_parser::read_json(sstream,pt);

    auto vec = std::vector<AdditionalPropertiesClass>();
    for (const auto& child: pt) {
        vec.emplace_back(AdditionalPropertiesClass(child.second));
    }

    return vec;
}

}
}
}
}

