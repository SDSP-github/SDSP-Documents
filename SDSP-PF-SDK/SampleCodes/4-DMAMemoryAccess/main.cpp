#include "SDSP-SDK-Wrapper.hpp"
#include <iostream>

// test DMA memory access functions
void TestDMALSRAM(SDSP::SDSP_PF_DeviceWrapper& device, size_t numberOfSamples = 1024)
{
	std::vector<ULONG> writeBuffer(numberOfSamples); // Create a vector with numberOfSamples elements

	// Seed the random number generator with the current time
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	// Fill the vector with random values
	for (size_t i = 0; i < numberOfSamples; ++i) {
		writeBuffer[i] = std::rand() % 1000; // Random values between 0 and 999

	}
	// read and write on device 0;
	device.WriteDMALSRAM(writeBuffer, 0);
	std::vector<ULONG>  read_buffer = device.ReadDMALSRAM(numberOfSamples, 0);

	if (read_buffer != writeBuffer)
	{
		std::cout << "Error in Testing DMA Access To LSRAM." << std::endl;
	}
	else
	{
		std::cout << "Passed Testing DMA Access To LSRAM." << std::endl;
	}
}

void TestDMADDR4(SDSP::SDSP_PF_DeviceWrapper& device, size_t numberOfSamples = 1024)
{
	std::vector<ULONG> writeBuffer(numberOfSamples); // Create a vector with numberOfSamples elements

	// Seed the random number generator with the current time
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	// Fill the vector with random values
	for (size_t i = 0; i < numberOfSamples; ++i) {
		writeBuffer[i] = std::rand() % 1000; // Random values between 0 and 999
	}
	// read and write on device 0;
	device.WriteDMADDR4(writeBuffer, 0);
	std::vector<ULONG>  read_buffer = device.ReadDMADDR4(numberOfSamples, 0);

	if (read_buffer != writeBuffer)
	{
		std::cout << "Error in Testing DMA Access To DDR4." << std::endl;
	}
	else
	{
		std::cout << "Passed Testing DMA Access TO DDR4." << std::endl;
	}
}




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
	for (int i = 0; i < allDevices.size(); i++)
	{
		allDevices[i].PrintDeviceInfo();
		TestDMALSRAM(allDevices[i]);
		TestDMADDR4(allDevices[i]);
		
	}
}