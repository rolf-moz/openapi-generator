/**
 * OpenAPI Petstore
 * This spec is mainly for testing Petstore server and contains fake endpoints, models. Please do not use this for any other purpose. Special characters: \" \\
 *
 * The version of the OpenAPI document: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 7.1.0-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */


#include <corvusoft/restbed/byte.hpp>
#include <corvusoft/restbed/string.hpp>
#include <corvusoft/restbed/settings.hpp>
#include <corvusoft/restbed/request.hpp>
#include <corvusoft/restbed/uri.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

#include "UserApi.h"

namespace org {
namespace openapitools {
namespace server {
namespace api {

using namespace org::openapitools::server::model;

namespace {
[[maybe_unused]]
std::string selectPreferredContentType(const std::vector<std::string>& contentTypes) {
    if (contentTypes.size() == 0) {
        return "application/json";
    }

    if (contentTypes.size() == 1) {
        return contentTypes.at(0);
    }

    static const std::array<std::string, 2> preferredTypes = {"json", "xml"};
    for (const auto& preferredType: preferredTypes) {
        const auto ret = std::find_if(contentTypes.cbegin(),
        contentTypes.cend(),
        [preferredType](const std::string& str) {
            return str.find(preferredType) != std::string::npos;});
        if (ret != contentTypes.cend()) {
            return *ret;
        }
    }

    return contentTypes.at(0);
}
}

UserApiException::UserApiException(int status_code, std::string what)
  : m_status(status_code),
    m_what(what)
{

}
int UserApiException::getStatus() const
{
    return m_status;
}
const char* UserApiException::what() const noexcept
{
    return m_what.c_str();
}


template<class MODEL_T>
MODEL_T extractJsonModelBodyParam(const std::string& bodyContent)
{
    std::stringstream sstream(bodyContent);
    boost::property_tree::ptree pt;
    boost::property_tree::json_parser::read_json(sstream, pt);

    auto model = MODEL_T(pt);
    return model;
}

template<class MODEL_T>
std::vector<MODEL_T> extractJsonArrayBodyParam(const std::string& bodyContent)
{
    std::stringstream sstream(bodyContent);
    boost::property_tree::ptree pt;
    boost::property_tree::json_parser::read_json(sstream, pt);

    auto arrayRet = std::vector<MODEL_T>();
    for (const auto& child: pt) {
        arrayRet.emplace_back(MODEL_T(child.second));
    }
    return arrayRet;
}

template <class KEY_T, class VAL_T>
std::string convertMapResponse(const std::map<KEY_T, VAL_T>& map)
{
    boost::property_tree::ptree pt;
    for(const auto &kv: map) {
    pt.push_back(boost::property_tree::ptree::value_type(
        boost::lexical_cast<std::string>(kv.first),
        boost::property_tree::ptree(
        boost::lexical_cast<std::string>(kv.second))));
    }
    std::stringstream sstream;
    write_json(sstream, pt);
    std::string result = sstream.str();
    return result;
}

namespace UserApiResources {
UserResource::UserResource(const std::string& context /* = "/v2" */)
{
	this->set_path(context + "/user");
	this->set_method_handler("POST",
		std::bind(&UserResource::handler_POST_internal, this,
			std::placeholders::_1));
}

std::pair<int, std::string> UserResource::handleUserApiException(const UserApiException& e)
{
    return std::make_pair<int, std::string>(e.getStatus(), e.what());
}

std::pair<int, std::string> UserResource::handleStdException(const std::exception& e)
{
    return std::make_pair<int, std::string>(500, e.what());
}

std::pair<int, std::string> UserResource::handleUnspecifiedException()
{
    return std::make_pair<int, std::string>(500, "Unknown exception occurred");
}

void UserResource::setResponseHeader(const std::shared_ptr<restbed::Session>& session, const std::string& header)
{
    session->set_header(header, "");
}

void UserResource::returnResponse(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result, std::multimap<std::string, std::string>& responseHeaders)
{
    responseHeaders.insert(std::make_pair("Connection", "close"));
    session->close(status, result, responseHeaders);
}

void UserResource::defaultSessionClose(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result)
{
    session->close(status, result, { {"Connection", "close"} });
}

void UserResource::handler_POST_internal(const std::shared_ptr<restbed::Session> session)
{
    const auto request = session->get_request();
    // body params or form params here from the body content string
    std::string bodyContent = extractBodyContent(session);
    auto user = extractJsonModelBodyParam<User>(bodyContent);
    
    int status_code = 500;
    std::string result = "";
    
    try {
        status_code =
            handler_POST(user);
    }
    catch(const UserApiException& e) {
        std::tie(status_code, result) = handleUserApiException(e);
    }
    catch(const std::exception& e) {
        std::tie(status_code, result) = handleStdException(e);
    }
    catch(...) {
        std::tie(status_code, result) = handleUnspecifiedException();
    }
    
    std::multimap< std::string, std::string > responseHeaders {};
    static const std::vector<std::string> contentTypes{
        "application/json"
    };
    static const std::string acceptTypes{
        "application/json, "
    };
    
    if (status_code == 0) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "successful operation";
    
        returnResponse(session, 0, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    defaultSessionClose(session, status_code, result);
    
    
}


int UserResource::handler_POST(
        User & user)
{
    return handler_POST_func(user);
}


std::string UserResource::extractBodyContent(const std::shared_ptr<restbed::Session>& session) {
  const auto request = session->get_request();
  int content_length = request->get_header("Content-Length", 0);
  std::string bodyContent;
  session->fetch(content_length,
                 [&bodyContent](const std::shared_ptr<restbed::Session> session,
                                const restbed::Bytes &body) {
                   bodyContent = restbed::String::format(
                       "%.*s\n", (int)body.size(), body.data());
                 });
  return bodyContent;
}

std::string UserResource::extractFormParamsFromBody(const std::string& paramName, const std::string& body) {
    const auto uri = restbed::Uri("urlencoded?" + body, true);
    const auto params = uri.get_query_parameters();
    const auto result = params.find(paramName);
    if (result != params.cend()) {
        return result->second;
    }
    return "";
}
UserCreateWithArrayResource::UserCreateWithArrayResource(const std::string& context /* = "/v2" */)
{
	this->set_path(context + "/user/createWithArray");
	this->set_method_handler("POST",
		std::bind(&UserCreateWithArrayResource::handler_POST_internal, this,
			std::placeholders::_1));
}

std::pair<int, std::string> UserCreateWithArrayResource::handleUserApiException(const UserApiException& e)
{
    return std::make_pair<int, std::string>(e.getStatus(), e.what());
}

std::pair<int, std::string> UserCreateWithArrayResource::handleStdException(const std::exception& e)
{
    return std::make_pair<int, std::string>(500, e.what());
}

std::pair<int, std::string> UserCreateWithArrayResource::handleUnspecifiedException()
{
    return std::make_pair<int, std::string>(500, "Unknown exception occurred");
}

void UserCreateWithArrayResource::setResponseHeader(const std::shared_ptr<restbed::Session>& session, const std::string& header)
{
    session->set_header(header, "");
}

void UserCreateWithArrayResource::returnResponse(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result, std::multimap<std::string, std::string>& responseHeaders)
{
    responseHeaders.insert(std::make_pair("Connection", "close"));
    session->close(status, result, responseHeaders);
}

void UserCreateWithArrayResource::defaultSessionClose(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result)
{
    session->close(status, result, { {"Connection", "close"} });
}

void UserCreateWithArrayResource::handler_POST_internal(const std::shared_ptr<restbed::Session> session)
{
    const auto request = session->get_request();
    // body params or form params here from the body content string
    std::string bodyContent = extractBodyContent(session);
    auto user = extractJsonArrayBodyParam<User>(bodyContent);
    
    int status_code = 500;
    std::string result = "";
    
    try {
        status_code =
            handler_POST(user);
    }
    catch(const UserApiException& e) {
        std::tie(status_code, result) = handleUserApiException(e);
    }
    catch(const std::exception& e) {
        std::tie(status_code, result) = handleStdException(e);
    }
    catch(...) {
        std::tie(status_code, result) = handleUnspecifiedException();
    }
    
    std::multimap< std::string, std::string > responseHeaders {};
    static const std::vector<std::string> contentTypes{
        "application/json"
    };
    static const std::string acceptTypes{
        "application/json, "
    };
    
    if (status_code == 0) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "successful operation";
    
        returnResponse(session, 0, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    defaultSessionClose(session, status_code, result);
    
    
}


int UserCreateWithArrayResource::handler_POST(
        std::vector<User> & user)
{
    return handler_POST_func(user);
}


std::string UserCreateWithArrayResource::extractBodyContent(const std::shared_ptr<restbed::Session>& session) {
  const auto request = session->get_request();
  int content_length = request->get_header("Content-Length", 0);
  std::string bodyContent;
  session->fetch(content_length,
                 [&bodyContent](const std::shared_ptr<restbed::Session> session,
                                const restbed::Bytes &body) {
                   bodyContent = restbed::String::format(
                       "%.*s\n", (int)body.size(), body.data());
                 });
  return bodyContent;
}

std::string UserCreateWithArrayResource::extractFormParamsFromBody(const std::string& paramName, const std::string& body) {
    const auto uri = restbed::Uri("urlencoded?" + body, true);
    const auto params = uri.get_query_parameters();
    const auto result = params.find(paramName);
    if (result != params.cend()) {
        return result->second;
    }
    return "";
}
UserCreateWithListResource::UserCreateWithListResource(const std::string& context /* = "/v2" */)
{
	this->set_path(context + "/user/createWithList");
	this->set_method_handler("POST",
		std::bind(&UserCreateWithListResource::handler_POST_internal, this,
			std::placeholders::_1));
}

std::pair<int, std::string> UserCreateWithListResource::handleUserApiException(const UserApiException& e)
{
    return std::make_pair<int, std::string>(e.getStatus(), e.what());
}

std::pair<int, std::string> UserCreateWithListResource::handleStdException(const std::exception& e)
{
    return std::make_pair<int, std::string>(500, e.what());
}

std::pair<int, std::string> UserCreateWithListResource::handleUnspecifiedException()
{
    return std::make_pair<int, std::string>(500, "Unknown exception occurred");
}

void UserCreateWithListResource::setResponseHeader(const std::shared_ptr<restbed::Session>& session, const std::string& header)
{
    session->set_header(header, "");
}

void UserCreateWithListResource::returnResponse(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result, std::multimap<std::string, std::string>& responseHeaders)
{
    responseHeaders.insert(std::make_pair("Connection", "close"));
    session->close(status, result, responseHeaders);
}

void UserCreateWithListResource::defaultSessionClose(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result)
{
    session->close(status, result, { {"Connection", "close"} });
}

void UserCreateWithListResource::handler_POST_internal(const std::shared_ptr<restbed::Session> session)
{
    const auto request = session->get_request();
    // body params or form params here from the body content string
    std::string bodyContent = extractBodyContent(session);
    auto user = extractJsonArrayBodyParam<User>(bodyContent);
    
    int status_code = 500;
    std::string result = "";
    
    try {
        status_code =
            handler_POST(user);
    }
    catch(const UserApiException& e) {
        std::tie(status_code, result) = handleUserApiException(e);
    }
    catch(const std::exception& e) {
        std::tie(status_code, result) = handleStdException(e);
    }
    catch(...) {
        std::tie(status_code, result) = handleUnspecifiedException();
    }
    
    std::multimap< std::string, std::string > responseHeaders {};
    static const std::vector<std::string> contentTypes{
        "application/json"
    };
    static const std::string acceptTypes{
        "application/json, "
    };
    
    if (status_code == 0) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "successful operation";
    
        returnResponse(session, 0, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    defaultSessionClose(session, status_code, result);
    
    
}


int UserCreateWithListResource::handler_POST(
        std::vector<User> & user)
{
    return handler_POST_func(user);
}


std::string UserCreateWithListResource::extractBodyContent(const std::shared_ptr<restbed::Session>& session) {
  const auto request = session->get_request();
  int content_length = request->get_header("Content-Length", 0);
  std::string bodyContent;
  session->fetch(content_length,
                 [&bodyContent](const std::shared_ptr<restbed::Session> session,
                                const restbed::Bytes &body) {
                   bodyContent = restbed::String::format(
                       "%.*s\n", (int)body.size(), body.data());
                 });
  return bodyContent;
}

std::string UserCreateWithListResource::extractFormParamsFromBody(const std::string& paramName, const std::string& body) {
    const auto uri = restbed::Uri("urlencoded?" + body, true);
    const auto params = uri.get_query_parameters();
    const auto result = params.find(paramName);
    if (result != params.cend()) {
        return result->second;
    }
    return "";
}
UserUsernameResource::UserUsernameResource(const std::string& context /* = "/v2" */)
{
	this->set_path(context + "/user/{username: .*}");
	this->set_method_handler("DELETE",
		std::bind(&UserUsernameResource::handler_DELETE_internal, this,
			std::placeholders::_1));
	this->set_method_handler("GET",
		std::bind(&UserUsernameResource::handler_GET_internal, this,
			std::placeholders::_1));
	this->set_method_handler("PUT",
		std::bind(&UserUsernameResource::handler_PUT_internal, this,
			std::placeholders::_1));
}

std::pair<int, std::string> UserUsernameResource::handleUserApiException(const UserApiException& e)
{
    return std::make_pair<int, std::string>(e.getStatus(), e.what());
}

std::pair<int, std::string> UserUsernameResource::handleStdException(const std::exception& e)
{
    return std::make_pair<int, std::string>(500, e.what());
}

std::pair<int, std::string> UserUsernameResource::handleUnspecifiedException()
{
    return std::make_pair<int, std::string>(500, "Unknown exception occurred");
}

void UserUsernameResource::setResponseHeader(const std::shared_ptr<restbed::Session>& session, const std::string& header)
{
    session->set_header(header, "");
}

void UserUsernameResource::returnResponse(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result, std::multimap<std::string, std::string>& responseHeaders)
{
    responseHeaders.insert(std::make_pair("Connection", "close"));
    session->close(status, result, responseHeaders);
}

void UserUsernameResource::defaultSessionClose(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result)
{
    session->close(status, result, { {"Connection", "close"} });
}

void UserUsernameResource::handler_DELETE_internal(const std::shared_ptr<restbed::Session> session)
{
    const auto request = session->get_request();
    // Getting the path params
    std::string username = request->get_path_parameter("username", "");
    
    int status_code = 500;
    std::string result = "";
    
    try {
        status_code =
            handler_DELETE(username);
    }
    catch(const UserApiException& e) {
        std::tie(status_code, result) = handleUserApiException(e);
    }
    catch(const std::exception& e) {
        std::tie(status_code, result) = handleStdException(e);
    }
    catch(...) {
        std::tie(status_code, result) = handleUnspecifiedException();
    }
    
    std::multimap< std::string, std::string > responseHeaders {};
    static const std::vector<std::string> contentTypes{
        "application/json"
    };
    static const std::string acceptTypes{
    };
    
    if (status_code == 400) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "Invalid username supplied";
    
        returnResponse(session, 400, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    if (status_code == 404) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "User not found";
    
        returnResponse(session, 404, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    defaultSessionClose(session, status_code, result);
    
    
}

// x-extension
void UserUsernameResource::handler_GET_internal(const std::shared_ptr<restbed::Session> session) {
    const auto request = session->get_request();
    // Getting the path params
    std::string username = request->get_path_parameter("username", "");
    
    int status_code = 500;
    User resultObject = User{};
    std::string result = "";
    
    try {
        std::tie(status_code, resultObject) =
            handler_GET(username);
    }
    catch(const UserApiException& e) {
        std::tie(status_code, result) = handleUserApiException(e);
    }
    catch(const std::exception& e) {
        std::tie(status_code, result) = handleStdException(e);
    }
    catch(...) {
        std::tie(status_code, result) = handleUnspecifiedException();
    }
    
    std::multimap< std::string, std::string > responseHeaders {};
    static const std::vector<std::string> contentTypes{
        "application/xml","application/json",
    };
    static const std::string acceptTypes{
    };
    
    if (status_code == 200) {
        responseHeaders.insert(std::make_pair("Content-Type", selectPreferredContentType(contentTypes)));
        if (!acceptTypes.empty()) {
            responseHeaders.insert(std::make_pair("Accept", acceptTypes));
        }
    
        result = resultObject.toJsonString();
        returnResponse(session, 200, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    if (status_code == 400) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "Invalid username supplied";
    
        returnResponse(session, 400, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    if (status_code == 404) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "User not found";
    
        returnResponse(session, 404, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    defaultSessionClose(session, status_code, result);
    
    
}
// x-extension
void UserUsernameResource::handler_PUT_internal(const std::shared_ptr<restbed::Session> session) {
    const auto request = session->get_request();
    // body params or form params here from the body content string
    std::string bodyContent = extractBodyContent(session);
    auto user = extractJsonModelBodyParam<User>(bodyContent);
    // Getting the path params
    std::string username = request->get_path_parameter("username", "");
    
    int status_code = 500;
    std::string result = "";
    
    try {
        status_code =
            handler_PUT(username, user);
    }
    catch(const UserApiException& e) {
        std::tie(status_code, result) = handleUserApiException(e);
    }
    catch(const std::exception& e) {
        std::tie(status_code, result) = handleStdException(e);
    }
    catch(...) {
        std::tie(status_code, result) = handleUnspecifiedException();
    }
    
    std::multimap< std::string, std::string > responseHeaders {};
    static const std::vector<std::string> contentTypes{
        "application/json"
    };
    static const std::string acceptTypes{
        "application/json, "
    };
    
    if (status_code == 400) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "Invalid user supplied";
    
        returnResponse(session, 400, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    if (status_code == 404) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "User not found";
    
        returnResponse(session, 404, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    defaultSessionClose(session, status_code, result);
    
    
}

int UserUsernameResource::handler_DELETE(
        std::string & username)
{
    return handler_DELETE_func(username);
}

std::pair<int, User> UserUsernameResource::handler_GET(
    std::string & username)
{
    return handler_GET_func(username);
}
int UserUsernameResource::handler_PUT(
    std::string & username, User & user)
{
    return handler_PUT_func(username, user);
}

std::string UserUsernameResource::extractBodyContent(const std::shared_ptr<restbed::Session>& session) {
  const auto request = session->get_request();
  int content_length = request->get_header("Content-Length", 0);
  std::string bodyContent;
  session->fetch(content_length,
                 [&bodyContent](const std::shared_ptr<restbed::Session> session,
                                const restbed::Bytes &body) {
                   bodyContent = restbed::String::format(
                       "%.*s\n", (int)body.size(), body.data());
                 });
  return bodyContent;
}

std::string UserUsernameResource::extractFormParamsFromBody(const std::string& paramName, const std::string& body) {
    const auto uri = restbed::Uri("urlencoded?" + body, true);
    const auto params = uri.get_query_parameters();
    const auto result = params.find(paramName);
    if (result != params.cend()) {
        return result->second;
    }
    return "";
}
UserLoginResource::UserLoginResource(const std::string& context /* = "/v2" */)
{
	this->set_path(context + "/user/login");
	this->set_method_handler("GET",
		std::bind(&UserLoginResource::handler_GET_internal, this,
			std::placeholders::_1));
}

std::pair<int, std::string> UserLoginResource::handleUserApiException(const UserApiException& e)
{
    return std::make_pair<int, std::string>(e.getStatus(), e.what());
}

std::pair<int, std::string> UserLoginResource::handleStdException(const std::exception& e)
{
    return std::make_pair<int, std::string>(500, e.what());
}

std::pair<int, std::string> UserLoginResource::handleUnspecifiedException()
{
    return std::make_pair<int, std::string>(500, "Unknown exception occurred");
}

void UserLoginResource::setResponseHeader(const std::shared_ptr<restbed::Session>& session, const std::string& header)
{
    session->set_header(header, "");
}

void UserLoginResource::returnResponse(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result, std::multimap<std::string, std::string>& responseHeaders)
{
    responseHeaders.insert(std::make_pair("Connection", "close"));
    session->close(status, result, responseHeaders);
}

void UserLoginResource::defaultSessionClose(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result)
{
    session->close(status, result, { {"Connection", "close"} });
}

void UserLoginResource::handler_GET_internal(const std::shared_ptr<restbed::Session> session)
{
    const auto request = session->get_request();
    // Getting the query params
    std::string username = request->get_query_parameter("username", "");
    std::string password = request->get_query_parameter("password", "");
    
    int status_code = 500;
    std::string resultObject = "";
    std::string result = "";
    
    try {
        std::tie(status_code, resultObject) =
            handler_GET(username, password);
    }
    catch(const UserApiException& e) {
        std::tie(status_code, result) = handleUserApiException(e);
    }
    catch(const std::exception& e) {
        std::tie(status_code, result) = handleStdException(e);
    }
    catch(...) {
        std::tie(status_code, result) = handleUnspecifiedException();
    }
    
    std::multimap< std::string, std::string > responseHeaders {};
    static const std::vector<std::string> contentTypes{
        "application/xml","application/json",
    };
    static const std::string acceptTypes{
    };
    
    if (status_code == 200) {
        responseHeaders.insert(std::make_pair("Content-Type", selectPreferredContentType(contentTypes)));
        if (!acceptTypes.empty()) {
            responseHeaders.insert(std::make_pair("Accept", acceptTypes));
        }
    
        result = resultObject;
        // Description: calls per hour allowed by the user
        setResponseHeader(session, "X-Rate-Limit");
        // Description: date in UTC when token expires
        setResponseHeader(session, "X-Expires-After");
        returnResponse(session, 200, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    if (status_code == 400) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "Invalid username/password supplied";
    
        returnResponse(session, 400, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    defaultSessionClose(session, status_code, result);
    
    
}


std::pair<int, std::string> UserLoginResource::handler_GET(
        std::string & username, std::string & password)
{
    return handler_GET_func(username, password);
}


std::string UserLoginResource::extractBodyContent(const std::shared_ptr<restbed::Session>& session) {
  const auto request = session->get_request();
  int content_length = request->get_header("Content-Length", 0);
  std::string bodyContent;
  session->fetch(content_length,
                 [&bodyContent](const std::shared_ptr<restbed::Session> session,
                                const restbed::Bytes &body) {
                   bodyContent = restbed::String::format(
                       "%.*s\n", (int)body.size(), body.data());
                 });
  return bodyContent;
}

std::string UserLoginResource::extractFormParamsFromBody(const std::string& paramName, const std::string& body) {
    const auto uri = restbed::Uri("urlencoded?" + body, true);
    const auto params = uri.get_query_parameters();
    const auto result = params.find(paramName);
    if (result != params.cend()) {
        return result->second;
    }
    return "";
}
UserLogoutResource::UserLogoutResource(const std::string& context /* = "/v2" */)
{
	this->set_path(context + "/user/logout");
	this->set_method_handler("GET",
		std::bind(&UserLogoutResource::handler_GET_internal, this,
			std::placeholders::_1));
}

std::pair<int, std::string> UserLogoutResource::handleUserApiException(const UserApiException& e)
{
    return std::make_pair<int, std::string>(e.getStatus(), e.what());
}

std::pair<int, std::string> UserLogoutResource::handleStdException(const std::exception& e)
{
    return std::make_pair<int, std::string>(500, e.what());
}

std::pair<int, std::string> UserLogoutResource::handleUnspecifiedException()
{
    return std::make_pair<int, std::string>(500, "Unknown exception occurred");
}

void UserLogoutResource::setResponseHeader(const std::shared_ptr<restbed::Session>& session, const std::string& header)
{
    session->set_header(header, "");
}

void UserLogoutResource::returnResponse(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result, std::multimap<std::string, std::string>& responseHeaders)
{
    responseHeaders.insert(std::make_pair("Connection", "close"));
    session->close(status, result, responseHeaders);
}

void UserLogoutResource::defaultSessionClose(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result)
{
    session->close(status, result, { {"Connection", "close"} });
}

void UserLogoutResource::handler_GET_internal(const std::shared_ptr<restbed::Session> session)
{
    const auto request = session->get_request();
    
    int status_code = 500;
    std::string result = "";
    
    try {
        status_code =
            handler_GET();
    }
    catch(const UserApiException& e) {
        std::tie(status_code, result) = handleUserApiException(e);
    }
    catch(const std::exception& e) {
        std::tie(status_code, result) = handleStdException(e);
    }
    catch(...) {
        std::tie(status_code, result) = handleUnspecifiedException();
    }
    
    std::multimap< std::string, std::string > responseHeaders {};
    static const std::vector<std::string> contentTypes{
        "application/json"
    };
    static const std::string acceptTypes{
    };
    
    if (status_code == 0) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "successful operation";
    
        returnResponse(session, 0, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    defaultSessionClose(session, status_code, result);
    
    
}


int UserLogoutResource::handler_GET(
        )
{
    return handler_GET_func();
}


std::string UserLogoutResource::extractBodyContent(const std::shared_ptr<restbed::Session>& session) {
  const auto request = session->get_request();
  int content_length = request->get_header("Content-Length", 0);
  std::string bodyContent;
  session->fetch(content_length,
                 [&bodyContent](const std::shared_ptr<restbed::Session> session,
                                const restbed::Bytes &body) {
                   bodyContent = restbed::String::format(
                       "%.*s\n", (int)body.size(), body.data());
                 });
  return bodyContent;
}

std::string UserLogoutResource::extractFormParamsFromBody(const std::string& paramName, const std::string& body) {
    const auto uri = restbed::Uri("urlencoded?" + body, true);
    const auto params = uri.get_query_parameters();
    const auto result = params.find(paramName);
    if (result != params.cend()) {
        return result->second;
    }
    return "";
}

} /* namespace UserApiResources */

UserApi::UserApi(std::shared_ptr<restbed::Service> const& restbedService)
: m_service(restbedService)
{
}

UserApi::~UserApi() {}

std::shared_ptr<UserApiResources::UserResource> UserApi::getUserResource() {
    if (!m_spUserResource) {
        setResource(std::make_shared<UserApiResources::UserResource>());
    }
    return m_spUserResource;
}
std::shared_ptr<UserApiResources::UserCreateWithArrayResource> UserApi::getUserCreateWithArrayResource() {
    if (!m_spUserCreateWithArrayResource) {
        setResource(std::make_shared<UserApiResources::UserCreateWithArrayResource>());
    }
    return m_spUserCreateWithArrayResource;
}
std::shared_ptr<UserApiResources::UserCreateWithListResource> UserApi::getUserCreateWithListResource() {
    if (!m_spUserCreateWithListResource) {
        setResource(std::make_shared<UserApiResources::UserCreateWithListResource>());
    }
    return m_spUserCreateWithListResource;
}
std::shared_ptr<UserApiResources::UserUsernameResource> UserApi::getUserUsernameResource() {
    if (!m_spUserUsernameResource) {
        setResource(std::make_shared<UserApiResources::UserUsernameResource>());
    }
    return m_spUserUsernameResource;
}
std::shared_ptr<UserApiResources::UserLoginResource> UserApi::getUserLoginResource() {
    if (!m_spUserLoginResource) {
        setResource(std::make_shared<UserApiResources::UserLoginResource>());
    }
    return m_spUserLoginResource;
}
std::shared_ptr<UserApiResources::UserLogoutResource> UserApi::getUserLogoutResource() {
    if (!m_spUserLogoutResource) {
        setResource(std::make_shared<UserApiResources::UserLogoutResource>());
    }
    return m_spUserLogoutResource;
}
void UserApi::setResource(std::shared_ptr<UserApiResources::UserResource> resource) {
    m_spUserResource = resource;
    m_service->publish(m_spUserResource);
}
void UserApi::setResource(std::shared_ptr<UserApiResources::UserCreateWithArrayResource> resource) {
    m_spUserCreateWithArrayResource = resource;
    m_service->publish(m_spUserCreateWithArrayResource);
}
void UserApi::setResource(std::shared_ptr<UserApiResources::UserCreateWithListResource> resource) {
    m_spUserCreateWithListResource = resource;
    m_service->publish(m_spUserCreateWithListResource);
}
void UserApi::setResource(std::shared_ptr<UserApiResources::UserUsernameResource> resource) {
    m_spUserUsernameResource = resource;
    m_service->publish(m_spUserUsernameResource);
}
void UserApi::setResource(std::shared_ptr<UserApiResources::UserLoginResource> resource) {
    m_spUserLoginResource = resource;
    m_service->publish(m_spUserLoginResource);
}
void UserApi::setResource(std::shared_ptr<UserApiResources::UserLogoutResource> resource) {
    m_spUserLogoutResource = resource;
    m_service->publish(m_spUserLogoutResource);
}
void UserApi::setUserApiUserResource(std::shared_ptr<UserApiResources::UserResource> spUserResource) {
    m_spUserResource = spUserResource;
    m_service->publish(m_spUserResource);
}
void UserApi::setUserApiUserCreateWithArrayResource(std::shared_ptr<UserApiResources::UserCreateWithArrayResource> spUserCreateWithArrayResource) {
    m_spUserCreateWithArrayResource = spUserCreateWithArrayResource;
    m_service->publish(m_spUserCreateWithArrayResource);
}
void UserApi::setUserApiUserCreateWithListResource(std::shared_ptr<UserApiResources::UserCreateWithListResource> spUserCreateWithListResource) {
    m_spUserCreateWithListResource = spUserCreateWithListResource;
    m_service->publish(m_spUserCreateWithListResource);
}
void UserApi::setUserApiUserUsernameResource(std::shared_ptr<UserApiResources::UserUsernameResource> spUserUsernameResource) {
    m_spUserUsernameResource = spUserUsernameResource;
    m_service->publish(m_spUserUsernameResource);
}
void UserApi::setUserApiUserLoginResource(std::shared_ptr<UserApiResources::UserLoginResource> spUserLoginResource) {
    m_spUserLoginResource = spUserLoginResource;
    m_service->publish(m_spUserLoginResource);
}
void UserApi::setUserApiUserLogoutResource(std::shared_ptr<UserApiResources::UserLogoutResource> spUserLogoutResource) {
    m_spUserLogoutResource = spUserLogoutResource;
    m_service->publish(m_spUserLogoutResource);
}


void UserApi::publishDefaultResources() {
    if (!m_spUserResource) {
        setResource(std::make_shared<UserApiResources::UserResource>());
    }
    if (!m_spUserCreateWithArrayResource) {
        setResource(std::make_shared<UserApiResources::UserCreateWithArrayResource>());
    }
    if (!m_spUserCreateWithListResource) {
        setResource(std::make_shared<UserApiResources::UserCreateWithListResource>());
    }
    if (!m_spUserUsernameResource) {
        setResource(std::make_shared<UserApiResources::UserUsernameResource>());
    }
    if (!m_spUserLoginResource) {
        setResource(std::make_shared<UserApiResources::UserLoginResource>());
    }
    if (!m_spUserLogoutResource) {
        setResource(std::make_shared<UserApiResources::UserLogoutResource>());
    }
}

std::shared_ptr<restbed::Service> UserApi::service() {
    return m_service;
}


}
}
}
}

