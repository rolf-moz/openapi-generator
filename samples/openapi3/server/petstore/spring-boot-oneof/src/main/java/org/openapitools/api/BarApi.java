/**
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech) (8.0.0-SNAPSHOT).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */
package org.openapitools.api;

import org.openapitools.model.Bar;
import org.openapitools.model.BarCreate;
import io.swagger.v3.oas.annotations.ExternalDocumentation;
import io.swagger.v3.oas.annotations.Operation;
import io.swagger.v3.oas.annotations.Parameter;
import io.swagger.v3.oas.annotations.Parameters;
import io.swagger.v3.oas.annotations.media.ArraySchema;
import io.swagger.v3.oas.annotations.media.Content;
import io.swagger.v3.oas.annotations.media.Schema;
import io.swagger.v3.oas.annotations.responses.ApiResponse;
import io.swagger.v3.oas.annotations.security.SecurityRequirement;
import io.swagger.v3.oas.annotations.tags.Tag;
import io.swagger.v3.oas.annotations.enums.ParameterIn;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.context.request.NativeWebRequest;
import org.springframework.web.multipart.MultipartFile;

import javax.validation.Valid;
import javax.validation.constraints.*;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import javax.annotation.Generated;

@Generated(value = "org.openapitools.codegen.languages.SpringCodegen")
@Validated
@Tag(name = "Bar", description = "the Bar API")
public interface BarApi {

    default Optional<NativeWebRequest> getRequest() {
        return Optional.empty();
    }

    /**
     * POST /bar : Create a Bar
     *
     * @param barCreate  (required)
     * @return Bar created (status code 200)
     */
    @Operation(
        operationId = "createBar",
        summary = "Create a Bar",
        tags = { "Bar" },
        responses = {
            @ApiResponse(responseCode = "200", description = "Bar created", content = {
                @Content(mediaType = "application/json", schema = @Schema(implementation = Bar.class))
            })
        }
    )
    @RequestMapping(
        method = RequestMethod.POST,
        value = "/bar",
        produces = { "application/json" },
        consumes = { "application/json" }
    )
    
    default ResponseEntity<Bar> createBar(
        @Parameter(name = "BarCreate", description = "", required = true) @Valid @RequestBody BarCreate barCreate
    ) {
        getRequest().ifPresent(request -> {
            for (MediaType mediaType: MediaType.parseMediaTypes(request.getHeader("Accept"))) {
                if (mediaType.isCompatibleWith(MediaType.valueOf("application/json"))) {
                    String exampleString = "{ \"id\" : \"id\", \"fooPropB\" : \"fooPropB\", \"barPropA\" : \"barPropA\" }";
                    ApiUtil.setExampleResponse(request, "application/json", exampleString);
                    break;
                }
            }
        });
        return new ResponseEntity<>(HttpStatus.NOT_IMPLEMENTED);

    }

}
