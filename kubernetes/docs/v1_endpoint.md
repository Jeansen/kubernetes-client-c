# v1_endpoint_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**addresses** | **list_t \*** | addresses of this endpoint. For EndpointSlices of addressType \&quot;IPv4\&quot; or \&quot;IPv6\&quot;, the values are IP addresses in canonical form. The syntax and semantics of other addressType values are not defined. This must contain at least one address but no more than 100. EndpointSlices generated by the EndpointSlice controller will always have exactly 1 address. No semantics are defined for additional addresses beyond the first, and kube-proxy does not look at them. | 
**conditions** | [**v1_endpoint_conditions_t**](v1_endpoint_conditions.md) \* |  | [optional] 
**deprecated_topology** | **list_t*** | deprecatedTopology contains topology information part of the v1beta1 API. This field is deprecated, and will be removed when the v1beta1 API is removed (no sooner than kubernetes v1.24).  While this field can hold values, it is not writable through the v1 API, and any attempts to write to it will be silently ignored. Topology information can be found in the zone and nodeName fields instead. | [optional] 
**hints** | [**v1_endpoint_hints_t**](v1_endpoint_hints.md) \* |  | [optional] 
**hostname** | **char \*** | hostname of this endpoint. This field may be used by consumers of endpoints to distinguish endpoints from each other (e.g. in DNS names). Multiple endpoints which use the same hostname should be considered fungible (e.g. multiple A values in DNS). Must be lowercase and pass DNS Label (RFC 1123) validation. | [optional] 
**node_name** | **char \*** | nodeName represents the name of the Node hosting this endpoint. This can be used to determine endpoints local to a Node. | [optional] 
**target_ref** | [**v1_object_reference_t**](v1_object_reference.md) \* |  | [optional] 
**zone** | **char \*** | zone is the name of the Zone this endpoint exists in. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


