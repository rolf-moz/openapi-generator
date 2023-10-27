# #OpenAPI Petstore
#
##This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
#
#The version of the OpenAPI document: 1.0.0
#
#Generated by: https://openapi-generator.tech
#OpenAPI Generator version: 8.0.0-SNAPSHOT
#

require "uri"

module Petstore
  class FakeApi
    property api_client : ApiClient

    def initialize(api_client = ApiClient.default)
      @api_client = api_client
    end
    # parameter name mapping test
    # @param underscore_type [Int64] _type
    # @param _type [String] type
    # @param type_with_underscore [String] type_
    # @param type_with_dash [String] type-
    # @param http_debug_option [String] http debug option (to test parameter naming option)
    # @return [nil]
    def get_parameter_name_mapping(underscore_type : Int64, _type : String, type_with_underscore : String, type_with_dash : String, http_debug_option : String)
      get_parameter_name_mapping_with_http_info(underscore_type, _type, type_with_underscore, type_with_dash, http_debug_option)
      nil
    end

    # parameter name mapping test
    # @param underscore_type [Int64] _type
    # @param _type [String] type
    # @param type_with_underscore [String] type_
    # @param type_with_dash [String] type-
    # @param http_debug_option [String] http debug option (to test parameter naming option)
    # @return [Array<(nil, Integer, Hash)>] nil, response status code and response headers
    def get_parameter_name_mapping_with_http_info(underscore_type : Int64, _type : String, type_with_underscore : String, type_with_dash : String, http_debug_option : String)
      if @api_client.config.debugging
        Log.debug {"Calling API: FakeApi.get_parameter_name_mapping ..."}
      end
      # verify the required parameter "underscore_type" is set
      if @api_client.config.client_side_validation && underscore_type.nil?
        raise ArgumentError.new("Missing the required parameter 'underscore_type' when calling FakeApi.get_parameter_name_mapping")
      end
      # verify the required parameter "_type" is set
      if @api_client.config.client_side_validation && _type.nil?
        raise ArgumentError.new("Missing the required parameter '_type' when calling FakeApi.get_parameter_name_mapping")
      end
      # verify the required parameter "type_with_underscore" is set
      if @api_client.config.client_side_validation && type_with_underscore.nil?
        raise ArgumentError.new("Missing the required parameter 'type_with_underscore' when calling FakeApi.get_parameter_name_mapping")
      end
      # verify the required parameter "type_with_dash" is set
      if @api_client.config.client_side_validation && type_with_dash.nil?
        raise ArgumentError.new("Missing the required parameter 'type_with_dash' when calling FakeApi.get_parameter_name_mapping")
      end
      # verify the required parameter "http_debug_option" is set
      if @api_client.config.client_side_validation && http_debug_option.nil?
        raise ArgumentError.new("Missing the required parameter 'http_debug_option' when calling FakeApi.get_parameter_name_mapping")
      end
      # resource path
      local_var_path = "/fake/parameter-name-mapping"

      # query parameters
      query_params = Hash(String, String).new
      query_params["type"] = _type.to_s unless _type.nil?
      query_params["http_debug_option"] = http_debug_option.to_s unless http_debug_option.nil?

      # header parameters
      header_params = Hash(String, String).new
      header_params["_type"] = underscore_type
      header_params["type_"] = type_with_underscore
      header_params["type-"] = type_with_dash

      # form parameters
      form_params = Hash(Symbol, (String | ::File)).new

      # http body (model)
      post_body = nil

      # return_type
      return_type = nil

      # auth_names
      auth_names = [] of String

      data, status_code, headers = @api_client.call_api(:GET,
                                                        local_var_path,
                                                        :"FakeApi.get_parameter_name_mapping",
                                                        return_type,
                                                        post_body,
                                                        auth_names,
                                                        header_params,
                                                        query_params,
                                                        form_params)
      if @api_client.config.debugging
        Log.debug {"API called: FakeApi#get_parameter_name_mapping\nData: #{data.inspect}\nStatus code: #{status_code}\nHeaders: #{headers}"}
      end
      return nil, status_code, headers
    end
  end
end
