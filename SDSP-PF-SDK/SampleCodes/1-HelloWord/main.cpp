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
}