# VSDSquadron-Mini-Research-Internship
**STEP 1-- Download Oracle Virtual Box from [here](https://www.virtualbox.org/wiki/Downloads)**
<br>**STEP 2-- Download UBUNTU for the desktop which we will run inside the Virtual Box from [here](https://ubuntu.com/download/desktop)**
 * Then open the `Virtual box` and click on new and then give any name as `opensource_eda_ubuntu` and select `Linux` and `Ubuntu (64-bit)` from the dropdown box.
 * After that specify the size of the virtual box as `40GB` or more.
 * On the main screen of the Virtual box, click on the `optical drive` and add the downloaded Ubuntu file.
 * Then click on the `start arrow` ➡️ at the top.
 * Then fill in the `name`, `company name`, `username` and `password`.
 * After that a dialog box will appear. click on `install ubuntu`.
 * Then wait for sometime and after the installation of ubuntu, `right-click -- open terminal`.
 * Now the command terminal gets opened as shown below.


![Screenshot 2024-04-23 185459](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/445e253e-71d5-49c5-a3ee-5d6d3e026989)


## Installing the EDA Tools
### Steps to install git
```
$ sudo apt update
$ sudo apt install git
```
![Screenshot 2024-04-22 170211](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/03aff4a5-7605-41f6-a047-760aab81c8f4)


### Steps to install gcc
```
$ sudo apt update
$ sudo apt install gcc
```

### Steps to install yosys
```
$ git clone https://github.com/YosysHQ/yosys.git
$ cd yosys
$ sudo apt-get install build-essential clang bison flex libreadline-dev gawk tcl-dev libffi-dev git graphviz xdot pkg-config python3 libboost-system-dev libboost-python-dev libboost-filesystem-dev zlib1g-dev
$ make config-gcc
$ make
$ sudo make install
```
![Screenshot 2024-04-23 192056](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/90264222-7ea1-4fc1-a4fd-efb187e0dcd0)


### Steps to install iverilog
```
$ sudo apt-get update
$ sudo apt-get -y install iverilog
```
![Screenshot 2024-04-23 193233](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/4fe55451-1826-4cc7-bbb2-fa13ac4187e9)


### Steps to install gtkwave
```
$ sudo apt update
$ sudo apt install gtkwave
```
![Screenshot 2024-04-23 193015](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/127b4ca4-8756-4219-8527-a2554e2f7b6e)


### Steps to install RISC-V GNU Compiler Toolchain
refer [risc-v gnu compiler toolchain](https://github.com/riscv-collab/riscv-gnu-toolchain)
```
$ git clone https://github.com/riscv/riscv-gnu-toolchain
$ sudo apt-get install autoconf automake autotools-dev curl python3 python3-pip libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev
$./configure --prefix=/opt/riscv
$ sudo make linux
```
![Screenshot 2024-04-24 014923](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/b92247d2-5787-4869-9e96-d9817b17fcfe)


### Steps to install vim text editor
```
$ sudo apt update
$ sudo apt install vim
```
after installing Vim, create a C program code as hello.c
```
$ cd Documents
$ vim hello.c
```
press i to insert and type the code and save the file using esc:wq and enter.


## RISC-V

### Why RISC-V Processors?

Any complex electronic system is composed of hardware and software.
We create hardware using complex SOC. So this SOC will have almost all the components needed for the system. And the processor is going to be the main component.
So whatever the application we run, all applications will be converted into processor instructions and eventually all the instructions will be executed by the processor.
The SOC can have a dual or quadcore processor to run multiple applications in parallel and that's what the operating system does.
For example-- when we click on any particular mobile application, the operating system loads the equivalent binary into RAM and then it loads the starting address of the binary into the program counter. All the processor has a special register called program counter and the program counter will increment sequentially and that is how the processor is going to fetch all the instructions from the memory.
So this particular application which we click on, has already been compiled into the processor instructions in terms of binary i.e. machine language and that is stored in storage memory.

Coming to the software, there could be many layers-- `application software` (created using a high-level language like C, C++, Java), `operating system` (manages i/o operations, and memory and is responsible for running many applications in parallel), `RISC-V compiler`, `RISC-V Assembler`.

![image](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/a1a03093-3cbe-434b-8e55-8bc4e718da86)


![image](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/bf18c839-dba9-4754-914f-849d1ae0a753)


![WhatsApp Image 2024-04-26 at 23 09 37](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/b8cec056-82c4-4d54-88a1-a4f0b0a2fbf2)


To convert the assembly language program into a machine language program, it follows RISC-V ISA which defines the format of the instructions like `R-type`, `I-type`, `S-type`, `B-type`, `U-type`, and `J-type`. So based on the format, the instructions get converted into binary.


## C-code Compilation Process

![Screenshot 2024-04-26 233426](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/3f9def57-ce31-4d0d-b072-7164ebdfee82)


## RISC-V ISA & Processor

![WhatsApp Image 2024-04-26 at 23 09 36](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/b9b1c971-cc44-4563-a559-a49a11d4ce9f)

It's an abstract interface between low-level software (compiler, Assembler) and low-level  hardware(processor). 
An embedded system engineer is going to refer to RISC-V ISA and based on the specifications he is going to design the compiler.
So basically the compiler should support all the instructions and be able to convert any kind of high-level language into RISC-V  assembly language.
VLSI engineer is also going to look at RISC-V ISA as a golden reference and he will implement the RTL design.


## RISC-V Execution Stages

![WhatsApp Image 2024-04-26 at 23 09 35](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/9cf57d4d-6e2c-4d35-981b-e00d54dcb50b)


The RISC-V processor works through 5 stages--
`Fetch`,  `decode`,  `execute`,  `memory`,  `write back`.
* <b>Fetch</b>-- The instructions will be loaded in instruction memory, so the processor is going to read the instructions mostly sequentially and sometimes in a non-sequential manner. the processor has got a special register called program counter which will always increment by 4 because in RISC-V we do byte addressing. This is how the processor will fetch the instructions from memory.
* <b>Decode</b>-- Then the decoder will decode the instructions.
* <b>Execute</b>-- The decoder will then communicate to the ALU what kind of operations it has to perform. So as part of the execution, the ALU is going to perform operations like arithmetic operations, logic operations, shift operations, etc. and based on the functionality, it is going to produce the output, and the results will be stored sometimes in memory and most of the time, it will be stored back  into the registers. 
* <b>Memory</b>-- the values will be written in the memory or sometimes read the values from the memory.
* <b>Write back</b>-- Most of the time whatever the results ALU produces will be written back to the register primarily in the destination registers.

### RISC-V Instruction Set Architecture



### The VSDSquadron Mini RISC-V development board – Features and Interfaces:

* Core Processor – The board is powered by CH32V003F4U6 chip with 32-bit RISC-V core based on RV32EC instruction set, optimized for high-performance computing with support for 2-level interrupt nesting and supports 24MHz system main frequency in the product function.
* Clock and Reset Systems: Includes a built-in factory-trimmed 24MHz RC oscillator and a 128kHz RC oscillator, plus an external 24MHz oscillator option for varied clocking requirements.
* Robust GPIO Support: Boasts 3 groups of GPIO ports, totaling 15 I/O ports, enabling extensive peripheral connections and mapping to external interrupt capabilities.
* Flexible Communication Interfaces: Offers multiple communication protocols including USART, I2C, and SPI for versatile connectivity options.
* High-Speed Memory: Equipped with 2KB SRAM for volatile data storage, 16KB CodeFlash for program memory, and additional 1920B for bootloader functionalities.
* On-board Programmer: Features on-board CH32V305FBP6 single-wire programming protocol, enhancing development efficiency with seamless code deployment and debugging. NO NEED to purchase any additional adapter.

### Block Diagram
<b> The following block diagram shows the key components of the VSDSquadron Mini RISC-V development board.

![Screenshot 2024-04-26 183406](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/42265edd-3963-463e-88d7-fb47358d0c32)

![Screenshot 2024-04-26 183650](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/54a19abd-a722-4560-b804-09ad22d1201d)


### The following table lists the important components of the VSDSquadron Mini RISC-V development board--


| <b>Board | <b>VSDSquadron Mini |
| --- | --- |
| Microcontroller | CH32V003F4U6 chip with 32-bit RISC-V core based on RV32EC instruction set |
| USB connector | USB 2.0 Type-C |
| Built-in LED Pin | 1x onboard user led (PD6) |
| Digital I/O pins | 15x |
| Analog I/O pins | 10-bit ADC, PD0-PD7, PA1, PA2, PC4 |
| PWM pins | 14x |
| External interrupts | 8 external interrupt edge detectors, mapped to any one of 18 external I/O ports |
| USART | 1x, PD6(RX), PD5(TX) |
| I2C | 1x, PC1(SDA), PC2(SCL) |
| SPI | 1x, PC5(SCK), PC1(NSS), PC6(MOSI), PC7(MISO) |
| Programmer/debugger | Onboard RISC-V programmer/debugger, USB to TTL serial port support |
| I/O voltage | 3.3 V |
| Input voltage (nominal) | 5V |
| Source Current per I/O Pin |8 mA |
| Sink Current per I/O Pin | 8mA |
| Clock speed Processor: | 24MHz |
| Memory | SRAM: 2kb on-chip volatile sram, 16kb external program memory |






