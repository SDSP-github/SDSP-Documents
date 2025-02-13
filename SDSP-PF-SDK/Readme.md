# SDSP-PF-SDK
This SDK allow user to work with PolarFire based boards from a windows based host PC.   
The main features of this SDK is presented here:    

1. Easy enumerate the PolarFire based board on the host PCIe bus. (Only Boards made by Sundance DSP is supported)
2. find information about each board such as their bus number, board model and several other information.
3. Accessing LSRAM and DDR4 memory of the board using direct access (suitable for accessing a few memory position) and DMA access (suitable when the data required to be transfer is significant) 
4. Sample code to show how to enumerate the devices and access their resources.

# Getting and setting up SDK
To get the SDK, Please contact Sundance DSP team (sales@sundancedsp.com).   
The SDK will be shipped as a zip file. extract it in your drive and then run `install.bat`. The installation will create an environment variable called `SDSP-PF-SDK-ROOT` which points to the directory that the binary and source code for wrapper exist.
# Installing Hardware
Install hardware into PC and ensure that PolarFire Driver is installed and the board can be seen in device manager as a working board.
# Installing required software
1. To build software in windows, we support [Visual Studio](https://visualstudio.microsoft.com/)   
1. We use [CMake](https://cmake.org/) extensively in our documentation and it is required  to install it   
1. It is also recommended to install [vcpkg](https://vcpkg.io/en/) for advanced package management.   

# Creating 'Hello word' project
To create your first project, run create_project.bat in SampleCode/HelloWord.  
Open the generated project (helloWorld.sln) in build directory and run it.    
Read code in `main.cpp` to understand how to initialize SDK and how to check if it is initialized.

# Enumerating devices
The project `EnumerateDevice` shows how to use SDK to enumerate devices and find how many device is present in the host system. Please note that the SDK will only enumerate SundanceDSP boards and not boards manufactured by other companies. 

# Direct memory access
This project shows how you can read and write to a specific memory location on the FPGA. 
The system first write 10 X 32 bit words to the LSRAM at offset 0 and then read them back. The project then do the same process with DDR4 (writing 10 X 32 bit words to DDR4 at offset 0 and read them back). The code uses direct memory access and is suitable for reading and writing small number of words. 

# DMA memory access
This project shows how you can read and write to a specific memory location on the FPGA using DMA. 
The system first write 1024 X 32 bit words to the LSRAM at offset 0 and then read them back. The project then do the same process with DDR4 (writing 1024 X 32 bit words to DDR4 at offset 0 and read them back). The code uses DMA and is suitable for reading and writing small number of words. 

## Notes: 
1. There are some overhead in setting up DMA engine, so if you want to read or write a small number of registers in the FPGA, it is faster to use direct memory access. For larger data transfer use DMA.
2. It is possible to mix and match direct access and DMA access if required. For example one may write to a portion of memory using direct access and then read it via DMA.
