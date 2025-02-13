# v2_metric_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**container_resource** | [**v2_container_resource_metric_status_t**](v2_container_resource_metric_status.md) \* |  | [optional] 
**external** | [**v2_external_metric_status_t**](v2_external_metric_status.md) \* |  | [optional] 
**object** | [**v2_object_metric_status_t**](v2_object_metric_status.md) \* |  | [optional] 
**pods** | [**v2_pods_metric_status_t**](v2_pods_metric_status.md) \* |  | [optional] 
**resource** | [**v2_resource_metric_status_t**](v2_resource_metric_status.md) \* |  | [optional] 
**type** | **char \*** | type is the type of metric source.  It will be one of \&quot;ContainerResource\&quot;, \&quot;External\&quot;, \&quot;Object\&quot;, \&quot;Pods\&quot; or \&quot;Resource\&quot;, each corresponds to a matching field in the object. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


