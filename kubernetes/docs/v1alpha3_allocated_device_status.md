# v1alpha3_allocated_device_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**conditions** | [**list_t**](v1_condition.md) \* | Conditions contains the latest observation of the device&#39;s state. If the device has been configured according to the class and claim config references, the &#x60;Ready&#x60; condition should be True.  Must not contain more than 8 entries. | [optional] 
**data** | [**object_t**](.md) \* | Data contains arbitrary driver-specific data.  The length of the raw data must be smaller or equal to 10 Ki. | [optional] 
**device** | **char \*** | Device references one device instance via its name in the driver&#39;s resource pool. It must be a DNS label. | 
**driver** | **char \*** | Driver specifies the name of the DRA driver whose kubelet plugin should be invoked to process the allocation once the claim is needed on a node.  Must be a DNS subdomain and should end with a DNS domain owned by the vendor of the driver. | 
**network_data** | [**v1alpha3_network_device_data_t**](v1alpha3_network_device_data.md) \* |  | [optional] 
**pool** | **char \*** | This name together with the driver name and the device name field identify which device was allocated (&#x60;&lt;driver name&gt;/&lt;pool name&gt;/&lt;device name&gt;&#x60;).  Must not be longer than 253 characters and may contain one or more DNS sub-domains separated by slashes. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


