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


## RISC-V RV32I Instruction Set</b>
* `R-type` : Register to Register instructions
* `I-type` : Register Immediate, Load, JLR, Ecall & Ebreak
* `S-type` : Store
* `B-type` : Branch
* `J-type` : Jump & Link
* `U-type` : Load/Add upper Immediate

![Screenshot 2024-04-27 100730](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/6f3ea028-4222-4439-9abc-21df61835c2b)

### R-type Instruction

<pre>
| <sup>31</sup>  <b>funct7</b>  <sup>25</sup> | <sup>24</sup>  <b>rs2</b>  <sup>20</sup> | <sup>19</sup>  <b>rs1</b>  <sup>15</sup>| <sup>14</sup>  <b>funct3</b>  <sup>12</sup> | <sup>11</sup>  <b>rd</b>  <sup>7</sup> | <sup>6</sup>  <b>opcode</b>  <sup>0</sup> |
</pre>

* There are two source registers `rs2` and `rs1`.
* Destination register `rd`.
* To address 32 registers, basically we use 5 bits.
* Together the `funct3` and `funct7` fields define the operation we want to do.
* Different operations could be like ADD/SLT/SLTU, AND/OR/XOR, SLL/SRL, SUB/SRA.
* `opcode` field of 7 bits defines whether instructions are of R-type.

| Instructions  | Name                 | FMT  | opcode  | funct3  | funct7  | Description       |
|:----------------: |------------------------- |:-------: |:----------: |:----------: |:----------: |---------------------- |
|       _add_       | ADD                      |    R     |  011_0011   |     000     |  000_0000   | rd =rs1 + rs2         |
|       _sub_       | SUB                      |    R     |  011_0011   |     000     |  010_0000   | rd =rs1 - rs2         |
|       _xor_       | XOR                      |    R     |  011_0011   |     100     |  000_0000   | rd =rs1 ^ rs2         |
|       _or_        | OR                       |    R     |  011_0011   |     110     |  000_0000   | rd =rs1 \| rs2        |
|       _and_       | AND                      |    R     |  011_0011   |     111     |  000_0000   | rd =rs1 & rs2         |
|       _sll_       | Shift left logical       |    R     |  011_0011   |     001     |  000_0000   | rd =rs1 << rs2        |
|       _srl_       | Shift right logical      |    R     |  011_0011   |     101     |  000_0000   | rd =rs1 >>u rs2       |
|       _sra_       | Shift right arithmetic   |    R     |  011_0011   |     101     |  010_0000   | rd =rs1 >>s rs2       |
|       _slt_       | Set less than            |    R     |  011_0011   |     010     |  000_0000   | rd =(rs1 s< rs2)?1:0  |
|      _sltu_       | Set less than(U)         |    R     |  011_0011   |     011     |  000_0000   | rd =(rs1 u< rs2)?1:0  |

* `add` & `sub` are the arithmetic instructions.
* `and`, `or` & `xor` are the logical instructions.
* `sll`, `srl` & `sra` are the shift instructions.
* `slt` & `sltu` are the comparison instructions.

examples:
```
Format: INSTR rd, rs1, rs2

add x28, x12, x13   # x28 = x12 + x13

example - let x12 = 00100, x13 = 00110
          add -    00100
                   00110
            x28 =  01010

slt x28, x13, x12   # if x13 < x12
                    # x28 = 1
                    # else
                    # x28 = 0

example - let x12 = 00100, x13 = 00110
          slt -    (00110) < (00100)
                   x28 = 0

or x28, x12, x13    # x28 = x12 | x13

example - let x12 = 00100, x13 = 00110
          or -    00100
                  00110
            x28 = 00110  

sll x28, x12, x13   # x28 = x12 << x13

example - let x12 = 00100, x13 = 00010
          sll means shift x12(rs1) by x13(rs2) bits.
              x12 = 00100 -(4)
                    01000 -(8)
              x28 = 10000 -(16)
- left shift also means multiply by 2.  
```


### The VSDSquadron Mini RISC-V development board – Features and Interfaces:

* Core Processor – The board is powered by a CH32V003F4U6 chip with a 32-bit RISC-V core based on RV32EC instruction set, optimized for high-performance computing with support for 2-level interrupt nesting and supports 24MHz system main frequency in the product function.
* Clock and Reset Systems: Includes a built-in factory-trimmed 24MHz RC oscillator and a 128kHz RC oscillator, plus an external 24MHz oscillator option for varied clocking requirements.
* Robust GPIO Support: Boasts 3 groups of GPIO ports, totaling 15 I/O ports, enabling extensive peripheral connections and mapping to external interrupt capabilities.
* Flexible Communication Interfaces: Offers multiple communication protocols including USART, I2C, and SPI for versatile connectivity options.
* High-Speed Memory: Equipped with 2KB SRAM for volatile data storage, 16KB CodeFlash for program memory, and an additional 1920B for bootloader functionalities.
* On-board Programmer: Features on-board CH32V305FBP6 single-wire programming protocol, enhancing development efficiency with seamless code deployment and debugging. NO NEED to purchase any additional adapters.

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






