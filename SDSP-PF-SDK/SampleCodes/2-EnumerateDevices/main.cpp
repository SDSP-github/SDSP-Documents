#include "SDSP-SDK-Wrapper.hpp"
#include <iostream>

int main()
{
	// Create an object of type SDSP::SDSP_PF_SDKWrapper, which will be your SDK.
	SDSP::SDSP_PF_SDKWrapper sdk;
	// Initialize the sdk.
	sdk.init();
	// Check that SDK is initialzed successfully.
	if (!sdk.isInit())
	{
		std::cerr << " can not initialize SDK" << std::endl;
		return -1;
	}

	std::cout << "SDK initialized successfully. " << std::endl;
	// Get list of devices  SDK return a vector of SDSP_PF_DeviceWrapper class 

	std::vector<SDSP::SDSP_PF_DeviceWrapper> allDevices = sdk.GetAllDevices();
	std::cout << "number of boards found: " << allDevices.size() << std::endl;
	// Each SDSP_PF_DeviceWrapper is abstracting one device and you can interact with the device via this class
	// In this example, we are printing each device information.
	for (int i = 0; i < allDevices.size(); i++)
	{
		allDevices[i].PrintDeviceInfo();
		
	}
}