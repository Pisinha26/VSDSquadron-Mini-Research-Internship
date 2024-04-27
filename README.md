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

|   Instructions    |          Name            |    FMT   |    opcode   |    funct3   |    funct7   |     Description       |
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

* add x28, x12, x13   # x28 = x12 + x13

  example - let x12 = 00100, x13 = 00110
            add -    00100
                     00110
              x28 =  01010

* slt x28, x13, x12   # if x13 < x12
                      # x28 = 1
                      # else
                      # x28 = 0

  example - let x12 = 00100, x13 = 00110
            slt -    (00110) < (00100)
                     x28 = 0

* or x28, x12, x13    # x28 = x12 | x13

  example - let x12 = 00100, x13 = 00110
            or -    00100
                    00110
              x28 = 00110  

* sll x28, x12, x13   # x28 = x12 << x13

  example - let x12 = 00100, x13 = 00010
            sll means shift x12(rs1) by x13(rs2) bits.
                x12 = 00100 -(4)
                      01000 -(8)
                x28 = 10000 -(16)
  - left shift also means multiply by 2.  
```


### I-Type Instruction


<pre>
| <sup>31</sup>           <b>imm[11:0]</b>           <sup>20</sup> | <sup>19</sup>  <b>rs1</b>  <sup>15</sup> | <sup>14</sup>  <b>funct3</b>  <sup>12</sup>| <sup>11</sup>  <b>rd</b>  <sup>7</sup> | <sup>6</sup>  <b>opcode</b>  <sup>0</sup> |


| <sup>31</sup>  <b>imm[11:5]</b>  <sup>25</sup> | <sup>24</sup>  <b>imm[4:0]</b>  <sup>20</sup> | <sup>19</sup>  <b>rs1</b>  <sup>15</sup> | <sup>14</sup>  <b>funct3</b>  <sup>12</sup>| <sup>11</sup>  <b>rd</b>  <sup>7</sup> | <sup>6</sup>  <b>opcode</b>  <sup>0</sup> |
</pre>          
          

* I-type involves a constant called `immediate value` for which 12 bits are allocated imm[11:0].
* There are two registers-- source register `rs1` and destination register `rd`.
* Function will be defined by `funct3` of 3 bits and operations will be performed between the source register(rs1) and the constant(immediate value).
* `Opcode` defines the instructions as of I-type.

|   Instructions    |           Name              |    FMT   |    opcode   |    funct3   |        funct7         |     Description        |
|:----------------: |---------------------------- |:-------: |:----------: |:----------: |:--------------------: |----------------------- |
|      _addi_       | ADD Immediate               |    I     |  001_0011   |     000     |                       | rd =rs1 + IMMI         |
|      _xori_       | XOR Immediate               |    I     |  001_0011   |     100     |                       | rd =rs1 ^ IMMI         |
|       _ori_       | OR Immediate                |    I     |  001_0011   |     110     |                       | rd =rs1 \| IMMI        |
|      _andi_       | AND Immediate               |    I     |  001_0011   |     111     |                       | rd =rs1 & IMMI         |
|      _slli_       | Shift left logical Imm      |    I     |  001_0011   |     001     | imm[11:5] = 000_0000  | rd =rs1 << imm[4:0]    |
|      _srli_       | Shift right logical Imm     |    I     |  001_0011   |     101     | imm[11:5] = 000_0000  | rd =rs1 >>u imm[4:0]   |
|      _srai_       | Shift right arithmetic Imm  |    I     |  001_0011   |     101     | imm[11:5] = 010_0000  | rd =rs1 >>s imm[4:0]   |
|      _slti_       | Set less than Imm           |    I     |  001_0011   |     010     |                       | rd =(rs1 s< IMMI)?1:0  |
|      _sltiu_      | Set less than Imm(U)        |    I     |  001_0011   |     011     |                       | rd =(rs1 u< IMMI)?1:0  |

`IMMI = SXT(imm[11:0])`

* `addi` is the arithmetic instruction.
* `andi`, `ori` & `xori` are the logical instructions.
* `slli`, `srli` & `srai` are the shift instructions.
* `slti` & `sltiu` are the comparison instructions.


* We calculate IMMI(immediate value) by doing a sign extension. There are 12 bits, so the remaining bits will be filled with sign bits, so eventually it is going to be 32 bits. So both `IMMI` and `rs1` are 32 bits, so the destination register `rd` will have the value of 32 bits.
* When it comes to shift operation, we use the subset of the immediate value i.e. `imm[4:0]` which defines the shift amount and how many bits we want to shift either left or right.
* Coming to the shift right arithmetic `srai`, it will add the sign bit.

examples:
```
addi x30, x12, 2   # x30 = x12 + 2
xori x30, x12, 2   # x30 = x12 ^ 2
srli x30, x12, 2   # x30 = x12 >> 2

# addi for subtraction:
addi x30, x12, -2   # x30 = x12 + (-2)     --(2's compliment binary value)
```

complex example:
```
* How to perform  a=((b+2)<<c)&5 ??

  source registers--- (x12 = b), (x13 = c)
  destination register(rd)--- (x30 = a)
  temporary registers--- (x28 for t1) and (x29 for t2)

  logic--- t1 = b+2;
           t2 = t1 << c;
           a = t2 & 5;

  The RISC-V Assembly program would look something like this:
         addi x28, x12, 2
         sll x29, x28, x13
         andi x30, x29, 5
```


 ### S-Type Instruction
 

`Load` and `Store` instructions transfer a value between the registers and memory. Loads are encoded in the I-type format and Stores are S-type. The effective byte address is obtained by adding register rs1 to the sign-extended 12-bit offset. Loads copy a value from memory to register rd. Stores copy the value in register rs2 to memory.

![image](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/0fd907e7-f025-4d42-a646-650f8b471674)

* Two kinds of instructions-- `Load I-type`  and  `Store S-type`
* We use Load and Store instructions to transfer the data between register and memory.
* Address= rs1 + SXT(imm[11:0])
* Load : rd= M[Address]
* Store : M[Address] = rs2
* Load is going to read the memory and load the register.
* Store is primarily used for writing the value in memory.


|    Instructions   |      Name        |    FMT   |    opcode   |    funct3   |     Description      |         Note           |
|:----------------: |----------------- |:-------: |:----------: |:----------: |--------------------- |----------------------- |
|       _lb_        | Load Byte        |    I     |  000_0011   |     000     | rd = M[rs1 + IMMI]   |                        |
|       _lh_        | Load Half        |    I     |  000_0011   |     001     | rd = M[rs1 + IMMI]   |                        |
|       _lw_        | Load Word        |    I     |  000_0011   |     010     | rd = M[rs1 + IMMI]   |  IMMI = SXT(imm[11:0]) |
|       _lbu_       | Load Byte (U)    |    I     |  000_0011   |     100     | rd = M[rs1 + IMMI]   |                        |
|       _lhu_       | Load Half (U)    |    I     |  000_0011   |     101     | rd = M[rs1 + IMMI]   |                        |
|------------------ |----------------- |--------- |------------ |------------ |--------------------- |----------------------- |
|       _sb_        | Store Byte       |    S     |  010_0011   |     000     | M[rs1 + IMMI] = rs2  |                        |
|       _sh_        | Store Half Word  |    S     |  010_0011   |     001     | M[rs1 + IMMI] = rs2  | IMMI = SXT(imm[11:0])  |
|       _sw_        | Store Word       |    S     |  010_0011   |     010     | M[rs1 + IMMI] = rs2  |                        |


example:
```
* lw rd, offset(rs1)     # rd = M[rs1 + offset]
     the address of the memory will be [rs1 + offset] and the value stored in that address will be loaded into the "rd" register.

* sw rs2, offset(rs1)    # M[rs1 + offset] = rs2
     the value of the register "rs2" will be stored in the memory at the address location [rs1 + offset].

* c = a ^ b
     "a" & "b" are the operands and "c" is the result and all three are stored in the memory location 0x8, 0xc, 0x14 respectively.
     assume x12 will have a value of "a",
            x13 will have a value of "b",
            x30 = x12 ^ x13 is the result.
     so we will use the "load" instruction to read the memory and "store" instruction to write the result back into memory.
            x12 = load(0x8)            //value of "a" stored in 0x8 will be loaded into x12 address. 
            x13 = load(0xc)            //value of "b" stored in 0xc will be loaded into x13 address. 
            x30 = x12 ^ x13            //xor operstion
            Store(0x14) x30            //value of result "c" will be stored into x30 address. 

      The RISC-V Assembly Program would look something like this:
            lw x12, 0x8(x0)             ---here source register rs1 value will be 
            lw x13, 0xc(x0)
            xor x30, x12, x13
            sw x30, 0x14(x0)
```


### B-Type Instruction


<pre>
| <sup>31</sup>  <b>imm[12]</b>  | <sup>30</sup>  <b>imm[10:5]</b>  <sup>25</sup> | <sup>24</sup>  <b>rs2</b>  <sup>20</sup> | <sup>19</sup>  <b>rs1</b>  <sup>15</sup> | <sup>14</sup>  <b>funct3</b>  <sup>12</sup> | <sup>11</sup>  <b>imm[4:1]</b>  <sup>8</sup> | <sup>7</sup>  <b>imm[11]</b> | <sup>6</sup>  <b>opcode</b>  <sup>0</sup> |
</pre>


* The `opcode` indicates the branch type.
* It involves immediate value which is [12:1] that is 12 bits. We need to do sign extension of immediate value and then add 0 at the lsb. This is how we have to calculate 32 bits from 12 bits and that is called immediate for branch type.
* `IMMB = SXT({imm[12:1], 1'b0})`;
* If the condition is true, the program counter will be updated as (pc + immediate value) primarily for non-sequential order execution.
* `PC = PC + IMMB`;
* and if the condition is false, the program counter will be increment by 4.
* `PC = PC + 4`;


|   Instructions    |     Name      |    FMT   |    opcode   |    funct3   |         Description               |           Note                |
|:----------------: |-------------- |:-------: |:----------: |:----------: |---------------------------------- |------------------------------ |
|       _beq_       | Branch ==     |    B     |  110_0011   |     000     | if(rs1 == rs2)<br>  PC += IMMB    |                               |
|       _bne_       | Branch !=     |    B     |  110_0011   |     001     | if(rs1 != rs2)<br>  PC += IMMB    |                               |
|       _blt_       | Branch <      |    B     |  110_0011   |     100     | if(rs1 s<rs2)<br>  PC += IMMB     | IMMB = SXT({imm[12:1],1'b0})  |
|       _bge_       | Branch ≥      |    B     |  110_0011   |     101     | if(rs1 >=s rs2)<br>  PC += IMMB   |                               |
|      _bltu_       | Branch < (U)  |    B     |  110_0011   |     110     | if(rs1 u< rs2)<br>  PC += IMMB    |                               |
|      _bgeu_       | Branch ≥ (U)  |    B     |  110_0011   |     111     | if(rs1 >=u rs2)<br>  PC +=  IMMB  |                               |


example:
```
* Consider the flow instruction:
      if(a>b)
      out = a;
      else
      out = b;

  To realize this logic, we allocate three registers-- two source registers x12 and x13 to have the value of "a" & "b" respectively.
                                                       one destination register x30 to have the value of "out".

  The RISC-V assembly program would look something like this:
                 blt x13, x12, TRUE      # if the condition true (PC=PC+IMMB), it jumps to TRUE instruction else (PC=PC+4) to the next line.
                 add x30, x13, x0        # out=b
                 beq x0, x0, END         # unconditionally it will jump to END
          TRUE:  add x30, x12, x0        #out=a
```


### J-Type Instruction


|   Instructions    |        Name          |    FMT   |   opcode    |    funct3   |         Description               |           Note                |
|:----------------: |--------------------- |:-------: |:----------: |:----------: |---------------------------------- |:----------------------------: |
|       _jal_       | Jump and link        |    J     |  110_1111   |             | rd=PC+4;<br>PC+=IMMJ              | IMMJ=SXT({imm[20:1],1'b0})    |
|      _jalr_       | Jump and link reg    |    I     |  110_0111   |     000     | rd=PC+4;<br>PC={(rs1+IMMI),1'b0}  | IMMI=SXT(imm[11:0])           |
|       _lui_       | Load upper Imm       |    U     |  011_0111   |             | rd=IMMU                           | IMMU={imm[31:12],12'b0}       |
|      _auipc_      | Add upper Imm to PC  |    U     |  001_0111   |             | rd=PC+IMMU                        |                 "             |
|      _ecall_      | Environment call     |    I     |  111_0011   |     000     | Transfer Control to OS            | imm[11:0]=0000_0000_0000      |
|     _ebreak_      | Environment break    |    I     |  111_0011   |     000     | Transfer Control to debugger      | imm[11:0]=0000_0000_0001      |


<b>Jump and Link</b>

<pre>
| <sup>31</sup>  <b>imm[20]</b> | <sup>30</sup>  <b>imm[10:1]</b>  <sup>21</sup> | <sup>20</sup>  <b>imm[11]</b> | <sup>19</sup>  <b>imm[19:12]</b>  <sup>12</sup> | <sup>11</sup>  <b>rd</b>  <sup>7</sup> | <sup>6</sup>  <b>opcode</b>  <sup>0</sup> |
</pre>

* JAL: J-Type
* `IMMJ = { SXT(IMM[20:1]), 1'b0}`  --This is how we basically calculate the offset.
* `JAL: rd=PC+4, PC=PC+IMMJ`

example:
```
jal rd, label
rd = PC + 4
PC = + imm

* jal does uncoditional jump and link.
* label encoded as an offset from the current address.
* only 20 bits allocated for IMM so it can maximum address only 2^20.
```


<b>JALR</b>

<pre>
| <sup>31</sup>  <b>imm[11:0]</b>  <sup>20</sup> | <sup>19</sup>  <b>rs1</b>  <sup>15</sup> | <sup>14</sup>  <b>funct3</b>  <sup>12</sup> | <sup>11</sup>  <b>rd</b>  <sup>7</sup> | <sup>6</sup>  <b>opcode</b>  <sup>0</sup> |
</pre>

* JALR: I-Type
* `IMMI = SXT(imm[11:0])`
* `JALR: rd=PC+4, PC={(rs1 + IMMI), 1'b0}`

* JAL: J-Type
* `IMMJ = { SXT(IMM[20:1]), 1'b0}`  --This is how we basically calculate the offset.
* `JAL: rd=PC+4, PC=PC+IMMJ`

example:
```
jalr rd, imm(rs)
rd = PC + 4
PC = rs +imm

* jalr does uncoditional jump to end link register.
* in this case, the jump will be calculated like (immediate value + rs).
  so, we can define 32 bits value through this register "rs".
* it can long jump within 2^32 locations and that's the difference between
  jal & jalr because in jal instruction, the max range was 0 to 2^20 locations
  but in case of jalr, the max range is 0 to 2^32 locations.
```


### U-Type Instruction


<pre>
| <sup>31</sup>  <b>imm[31:12]</b>  <sup>12</sup> | <sup>11</sup>  <b>rd</b>  <sup>7</sup> | <sup>6</sup>  <b>opcode</b>  <sup>0</sup> |
</pre>

| imm[31:12]      |    rd   |    0110111   |     LUI    |
|---------------- |-------- |------------- |----------- |
| **imm[31:12]**  | **rd**  | **0010111**  | **AUIPC**  |


* `LUI: rd = IMMU`
* `AUIPC: rd = PC + IMMU`
* where, IMMU: `{imm[31:12], 12'b0}`

example:
```
x12 = x, x13 = y
# small constants (0x123 of 12 bits)
x = y + 0x123
addi x12, x13, 0x123      --12 bits IMMI

# large constants (we can't directly use addi)
x = y + 0x12345678
lui x14, 0x12345          --20 bits MSB(we have only 20 bits for lui)
# x14 = 32'h12345000      --IMMU format specified above
addi x14, x14, 0x678
# x14 = 32'h12345678      --this is how we load the large constants value in a register.
add x12, x13, x14         --x12 is a destination register and x14 is the large constant value.
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






