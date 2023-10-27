=begin
#Echo Server API

#Echo Server API

The version of the OpenAPI document: 0.1.0
Contact: team@openapitools.org
Generated by: https://openapi-generator.tech
OpenAPI Generator version: 8.0.0-SNAPSHOT

=end

require 'cgi'

module OpenapiClient
  class FormApi
    attr_accessor :api_client

    def initialize(api_client = ApiClient.default)
      @api_client = api_client
    end
    # Test form parameter(s)
    # Test form parameter(s)
    # @param [Hash] opts the optional parameters
    # @option opts [Integer] :integer_form 
    # @option opts [Boolean] :boolean_form 
    # @option opts [String] :string_form 
    # @return [String]
    def test_form_integer_boolean_string(opts = {})
      data, _status_code, _headers = test_form_integer_boolean_string_with_http_info(opts)
      data
    end

    # Test form parameter(s)
    # Test form parameter(s)
    # @param [Hash] opts the optional parameters
    # @option opts [Integer] :integer_form 
    # @option opts [Boolean] :boolean_form 
    # @option opts [String] :string_form 
    # @return [Array<(String, Integer, Hash)>] String data, response status code and response headers
    def test_form_integer_boolean_string_with_http_info(opts = {})
      if @api_client.config.debugging
        @api_client.config.logger.debug 'Calling API: FormApi.test_form_integer_boolean_string ...'
      end
      # resource path
      local_var_path = '/form/integer/boolean/string'

      # query parameters
      query_params = opts[:query_params] || {}

      # header parameters
      header_params = opts[:header_params] || {}
      # HTTP header 'Accept' (if needed)
      header_params['Accept'] = @api_client.select_header_accept(['text/plain'])
      # HTTP header 'Content-Type'
      content_type = @api_client.select_header_content_type(['application/x-www-form-urlencoded'])
      if !content_type.nil?
          header_params['Content-Type'] = content_type
      end

      # form parameters
      form_params = opts[:form_params] || {}
      form_params['integer_form'] = opts[:'integer_form'] if !opts[:'integer_form'].nil?
      form_params['boolean_form'] = opts[:'boolean_form'] if !opts[:'boolean_form'].nil?
      form_params['string_form'] = opts[:'string_form'] if !opts[:'string_form'].nil?

      # http body (model)
      post_body = opts[:debug_body]

      # return_type
      return_type = opts[:debug_return_type] || 'String'

      # auth_names
      auth_names = opts[:debug_auth_names] || []

      new_options = opts.merge(
        :operation => :"FormApi.test_form_integer_boolean_string",
        :header_params => header_params,
        :query_params => query_params,
        :form_params => form_params,
        :body => post_body,
        :auth_names => auth_names,
        :return_type => return_type
      )

      data, status_code, headers = @api_client.call_api(:POST, local_var_path, new_options)
      if @api_client.config.debugging
        @api_client.config.logger.debug "API called: FormApi#test_form_integer_boolean_string\nData: #{data.inspect}\nStatus code: #{status_code}\nHeaders: #{headers}"
      end
      return data, status_code, headers
    end

    # Test form parameter(s) for oneOf schema
    # Test form parameter(s) for oneOf schema
    # @param [Hash] opts the optional parameters
    # @option opts [String] :form1 
    # @option opts [Integer] :form2 
    # @option opts [String] :form3 
    # @option opts [Boolean] :form4 
    # @option opts [Integer] :id 
    # @option opts [String] :name 
    # @return [String]
    def test_form_oneof(opts = {})
      data, _status_code, _headers = test_form_oneof_with_http_info(opts)
      data
    end

    # Test form parameter(s) for oneOf schema
    # Test form parameter(s) for oneOf schema
    # @param [Hash] opts the optional parameters
    # @option opts [String] :form1 
    # @option opts [Integer] :form2 
    # @option opts [String] :form3 
    # @option opts [Boolean] :form4 
    # @option opts [Integer] :id 
    # @option opts [String] :name 
    # @return [Array<(String, Integer, Hash)>] String data, response status code and response headers
    def test_form_oneof_with_http_info(opts = {})
      if @api_client.config.debugging
        @api_client.config.logger.debug 'Calling API: FormApi.test_form_oneof ...'
      end
      # resource path
      local_var_path = '/form/oneof'

      # query parameters
      query_params = opts[:query_params] || {}

      # header parameters
      header_params = opts[:header_params] || {}
      # HTTP header 'Accept' (if needed)
      header_params['Accept'] = @api_client.select_header_accept(['text/plain'])
      # HTTP header 'Content-Type'
      content_type = @api_client.select_header_content_type(['application/x-www-form-urlencoded'])
      if !content_type.nil?
          header_params['Content-Type'] = content_type
      end

      # form parameters
      form_params = opts[:form_params] || {}
      form_params['form1'] = opts[:'form1'] if !opts[:'form1'].nil?
      form_params['form2'] = opts[:'form2'] if !opts[:'form2'].nil?
      form_params['form3'] = opts[:'form3'] if !opts[:'form3'].nil?
      form_params['form4'] = opts[:'form4'] if !opts[:'form4'].nil?
      form_params['id'] = opts[:'id'] if !opts[:'id'].nil?
      form_params['name'] = opts[:'name'] if !opts[:'name'].nil?

      # http body (model)
      post_body = opts[:debug_body]

      # return_type
      return_type = opts[:debug_return_type] || 'String'

      # auth_names
      auth_names = opts[:debug_auth_names] || []

      new_options = opts.merge(
        :operation => :"FormApi.test_form_oneof",
        :header_params => header_params,
        :query_params => query_params,
        :form_params => form_params,
        :body => post_body,
        :auth_names => auth_names,
        :return_type => return_type
      )

      data, status_code, headers = @api_client.call_api(:POST, local_var_path, new_options)
      if @api_client.config.debugging
        @api_client.config.logger.debug "API called: FormApi#test_form_oneof\nData: #{data.inspect}\nStatus code: #{status_code}\nHeaders: #{headers}"
      end
      return data, status_code, headers
    end
  end
end
