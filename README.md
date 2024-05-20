# VSDSquadron-Mini-Research-Internship
**STEP 1-- Download Oracle Virtual Box from [here](https://www.virtualbox.org/wiki/Downloads)**
<br>**STEP 2-- Download UBUNTU for the desktop which we will run inside the Virtual Box from [here](https://ubuntu.com/download/desktop)**
 * Then open the `Virtual box` and click on new and then give any name as `opensource_eda_ubuntu` and select `Linux` and `Ubuntu (64-bit)` from the dropdown box.
 * After that specify the size of the virtual box as `40GB` or more.
 * On the main screen of the Virtual box, click on the `optical drive` and add the downloaded Ubuntu file.
 * Then click on the `start arrow` ➡️ at the top.
 * Then fill in the `name`, `company name`, `username`, and `password`.
 * After that a dialog box will appear. click on `install ubuntu`.
 * Then wait for some time and after the installation of Ubuntu, `right-click -- open terminal`.
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
     "a" & "b" are the operands and "c" is the result and all three are stored in the memory location 0x8, 0xc, and 0x14 respectively.
     assume x12 will have a value of "a",
            x13 will have a value of "b",
            x30 = x12 ^ x13 is the result.
     so we will use the "load" instruction to read the memory and the "store" instruction to write the result back into memory.
            x12 = load(0x8)            //value of "a" stored in 0x8 will be loaded into x12 address. 
            x13 = load(0xc)            //value of "b" stored in 0xc will be loaded into x13 address. 
            x30 = x12 ^ x13            //xor operation
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
* `IMMB = SXT({imm[12:1], 1'b0})`
* If the condition is true, the program counter will be updated as (pc + immediate value) primarily for non-sequential order execution.
* `PC = PC + IMMB`
* and if the condition is false, the program counter will be increment by 4.
* `PC = PC + 4` for next instruction.


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

### Analyzing all the instructions 

* <b>add r6, r2, r1</b>
```
* R-Type Instruction
* opcode for add = 0110011
* rd = r6 = 00110
* rs1 = r2 = 00010
* rs2 = r1 = 00001
* funct3 = 000
* funct7 = 0000000
* 32-bit instruction: 0000000_00001_00010_000_00110_0110011
```

* <b>sub r7, r1, r2</b>
```
* R-Type Instruction
* opcode for sub = 0110011
* rd = r7 = 00111
* rs1 = r1 = 00001
* rs2 = r2 = 00010
* funct3 = 000
* funct7 = 0100000
* 32-bit instruction: 0100000_00010_000_00111_0110011
```

* <b>and r8, r1, r3</b>
```
* R-Type Instruction
* opcode for and = 0110011
* rd = r8 = 01000
* rs1 = r1 = 00001
* rs2 = r3 = 00011
* funct3 = 111
* funct7 = 0000000
* 32-bit instruction: 0000000_00011_00001_111_01000_0110011
```

* <b>or r9, r2, r5</b>
```
* R-Type Instruction
* opcode for or = 0110011
* rd = r9 = 00110
* rs1 = r2 = 00010
* rs2 = r5 = 00101
* funct3 = 110
* funct7 = 0000000
* 32-bit instruction: 0000000_00101_00010_110_01001_0110011
```

* <b>xor r10, r1, r4</b>
```
* R-Type Instruction
* opcode for xor = 0110011
* rd = r10 = 01010
* rs1 = r1 = 00001
* rs2 = r4 = 00100
* funct3 = 100
* funct7 = 0000000
* 32-bit instruction: 0000000_00100_00001_100_01010_0110011
```

* <b>slt r1, r2, r4</b>
```
* R-Type Instruction
* opcode for slt = 0110011
* rd = r1 = 00001
* rs1 = r2 = 00010
* rs2 = r4 = 00100
* funct3 = 010
* funct7 = 0000000
* 32-bit instruction: 0000000_00100_00010_010_00001_0110011
```

* <b>addi r12, r4, 5</b>
```
* I-Type Instruction
* opcode for addi = 0010011
* rd = r12 = 01100
* rs1 = r4 = 00100
* imm[11:0] = 5 = 000000000101
* funct3 = 000
* 32-bit instruction: 000000000101_00100_000_01100_0010011
```

* <b>sw r3, r1, 2</b>
```
* S-Type Instruction
* opcode for sw = 0100011
* rs2 = r3 = 00011
* rs1 = r1 = 00001
* imm[11:0] = 2 = 000000000010
* funct3 = 010
* 32-bit instruction: 0000000_00011_00001_010_00010_0100011
```

* <b>lw r13, r1, 2</b>
```
* I-Type Instruction
* opcode for lw = 0000011
* rd = r13 = 00110
* rs1 = r1 = 00010
* imm[11:0] = 2 = 000000000010
* funct3 = 010
* 32-bit instruction: 000000000010_00010_010_00110_0000011
```

* <b>beq r0, r0, 15</b>
```
* B-Type Instruction
* opcode for beq = 1100011
* rs1 = r0 = 00000
* rs2 = r0 = 00000
* imm[12:1] = 15 = 000000001111
* funct3 = 000
* 32-bit instruction: 0_000000_00000_00000_000_1111_0_1100011
```

* <b>bne r0, r1, 20</b>
```
* B-Type Instruction
* opcode for bne = 1100011
* rs1 = r0 = 00000
* rs2 = r1 = 00001
* imm[12:1] = 20 = 000000010100
* funct3 = 001
* 32-bit instruction: 0_000001_00001_00000_001_0100_0_1100011
```

* <b>sll r15, r1,r2</b>
```
* R-Type Instruction
* opcode for sll = 0110011
* rd = r15 = 01111
* rs1 = r1 = 00001
* rs2 = r2 = 00010
* funct3 = 001
* funct7 = 0000000
* 32-bit instruction: 0000000_00010_00001_001_01111_0110011
```


* <b>srl r16, r14, r2</b>
```
* R-Type Instruction
* opcode for srl = 0110011
* rd = r16 = 10000
* rs1 = r14 = 01110
* rs2 = r2 = 00010
* funct3 = 101
* funct7 = 0000000
* 32-bit instruction: 0000000_00010_01110_101_10000_0110011
```

## Lab Task 

### C-Program Compilation
**C-program to calculate  the sum of n natural numbers**.

* if "leafpad" is not installed, install using the command--
```
$ sudo snap install leafpad
```

![Screenshot 2024-04-29 204926](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/e67730e9-7bad-4203-b3c8-1c4e456c2fc5)

* to open the `leafpad` editor (where we will write our C code) in the terminal--
```
$ leafpad sum1ton.c
```

* now, we will write our C code in the editor as shown below.

![Screenshot 2024-04-29 205137](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/f136f9f8-dc7c-4e15-a876-20897d88b782)

* save the code and close the editor.
* now, in the terminal use the command as--
```
$ gcc sum1ton.c
```

* now to run this C-code and see the output, we have to use the command--
```
$ ./a.out
```

![Screenshot 2024-04-30 153659](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/8f2e4da6-90ed-462e-acbd-3bb96edde0ab)


**Now we will run the same C-code using RISCV GCC Compiler**

* Download a "vdi" file from the link [vsdsquadron.vdi](https://forgefunder.com/~kunal/vsdsquadron.vdi)
* we have to create a machine in the virtual box by adding this "vdi" file in the `optical drive` section at the start of the machine creation. Actually, this "vdi" file has all the preinstalled tools in the virtual box.
* Now in the terminal, use the command as--
```
$ cat sum1ton.c
```
* This command will open the C-code in the terminal itself.
* The next command should be--
```
$ riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
```
* This will generate an output file `sum1ton.o`.
* This command actually compiles a source file "sum1ton.c" into an object file named "sum1ton.o".
* One of the reasons we chose to install riscv64, so to give us flexibility to target any 32-bit or 64-bit architecture.
* Here's a breakdown of the options:
      </br> - `mabi=ilp32`: This option specifies the ABI (Application Binary Interface) to use ilp32, which is for a 32-bit integer, long, and pointer size. This ABI is used for 32-bit RISC-V architectures.
      </br> - `march=rv32i`: This option specifies the architecture to use rv32i, which indicates a 32-bit RISC-V base integer instruction set. This further confirms the targeting of a 32-bit architecture.
* So even though the compiler itself is a riscv64 version (indicating it is capable of handling 64-bit RISC-V code), these specific options are used to compile code for a 32-bit RISC-V processor.  
* Now, in the new tab, we will see what is the assembly code for the C-program that we are trying to run using the command--
```
$ riscv64-unknown-elf-objdump -d sum1ton.o | less
```
* This command will give a bunch of assembly language codes.
* The section we are interested in is the "main" section.
* So type "/main" and then press "n". The address of the main section here starts with `10184` and it increments by 4 because it is byte addressing as shown below--

![Screenshot 2024-05-03 003124](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/1bb1d1c1-03f5-455c-915a-2889835d2bca)

here, we have 11 instructions.

* Now, quit this tab and in the previous tab, run the same command with a slight change--
```
$ riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
```
* Now, again in the new tab, run the same command--
```
$ riscv64-unknown-elf-objdump -d sum1ton.o | less
```
* Type "/main" and press "n". This time, the address of the main section starts with `100b0` and it increments by 4 as usual as shown below--

![Screenshot 2024-05-03 004638](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/3d67e958-900b-4160-a918-b9975e04d2ee)

but here also, we have 11 instructions but in most of the cases, the no of instructions gets reduced.


### Installation of spike and pk(Proxy kernel)
* `Spike` is basically an open-source RISC-V ISA functional simulator developed primarily by the same team that created the RISC-V ISA Specification and serves as a reference for both software development and ISA verification with a primary purpose of simulating the behavior of a RISC-V processor executing RISC-V assembly code. Essentially, it allows developers to run RISC-V programs on their computers without needing actual RISC-V hardware.
* To know more about spike and its installation refer to this [spike-github](https://github.com/riscv-software-src/riscv-isa-sim)
* `pk(Proxy kernel)` is like a middleman between our computer's app and its hardware. It's like a basic manager that helps apps talk to the computer's parts, like the memory or the screen. It's simpler than a full-fledged operating system, and it's often used for learning or in small gadgets where there isn't much space for a big operating system. A proxy kernel in the context of RISC-V provides basic functionalities such as process management, memory management, and I/O operations.

**Spike installation**
```
$ git clone https://github.com/riscv/riscv-isa-sim.git      
$ cd riscv-isa-sim    
$ mkdir build  
$ cd build  
$ ../configure --prefix=/opt/riscv
$ sudo apt-get install device-tree-compiler
$ make  
$ sudo apt update  
$ sudo apt install g++-8  
$ make CXX=g++-8  
$ sudo make install  
$ echo 'export PATH=$PATH:/opt/riscv/bin' >> ~/.bashrc  
$ source ~/.bashrc
```

**pk installation**
```
$ git clone https://github.com/riscv/riscv-pk.git    
$ cd riscv-pk    
$ mkdir build    
$ cd build      
$ ../configure --prefix=/home/vsduser/riscv --host=riscv64-unknown-elf --with-arch=rv64gc    
$ make    
$ sudo make install
```

* Rather than following the above steps, we actually downloaded a [vdi file](https://forgefunder.com/~kunal/riscv_workshop.vdi) which had all the eda tools preinstalled in it.
* Now, we continue with our lab work. In the previous lab, we saw the contents of the assembly language program, and using the following command, we got the output--
```
$ gcc sum1ton.c
$ ./a.out
```
* To get the same output using the RISC-V compiler as well, we need to type the following command--
```
$ riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
$ spike pk sum1ton.o
```
* Now, we will try to debug and for that, we need to open the object dump using the command in the other tab--
```
$ riscv64-unknown-elf-objdump -d sum1ton.o | less
```
* We will get a bunch of assembly language code.

![Screenshot 2024-05-03 004638](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/3781a8be-0dad-403a-89ca-1befc6372368)

* To debug these codes, we need to open a debugger in spike using the command--
```
$ spike -d pk sum1ton.o
```
* The above command will open a debug over here. Now, we want the program counter(PC) to run till the starting address of the "main" i.e. 100b0 and after this address, we want to run it manually. For that, we need to write a command in the debug--
```
until pc 0 100b0
```
* The instruction in the address location `100b0` is `lui a0,0x21`. So, before this, we will try to know the content of "a0" in 64-bit format using the command--
```
reg 0 a0
```
* Now, press "enter", it will run the next instruction `lui a0,0x21` and now we will again try to know the content of "a0" using the same command--
```
reg 0 a0
```
* We will observe that the content of "a0" got modified and then press "enter" to get the next instruction `sp, sp, -16`. Here, we will look into the content of the stack pointer(sp) before using the command--
```
reg 0 sp
```
* 16 in decimal is 10 in hexadecimal. So, 10 was subtracted from the initial value.
* Actually we want to know the content of "sp" before running the instruction which is there on address `100b4`. So, first quit it by giving the command `q` and then type the following command again--
```
$ spike -d pk sum1ton.o
(spike) until pc 0 100b4
(spike) reg 0 sp
```
* The above command will get the initial content of "sp". Now, press "enter" and type the command--
```
reg 0 sp
```
* This will show the content of "sp" after subtracting 10(hex) from the initial value of "sp".

![Screenshot 2024-05-05 045328](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/eb549231-e124-449e-ace2-d8829d7ce214)

### Steps to perform functional simulation of RISC-V

* Create a new directory named "piyushriscv".
* Add two files `psinha_rv32.v`(verilog code) and `psinha_rv32_tb.v`(testbench code) in that directory.
* We have actually copied these two codes from this [github repo](https://github.com/vinayrayapati/rv32i) So, we will use these Verilog codes and the Testbench file of RISC-V that is already there.
* The above two codes are shown below--

`psinha_rv32.v`
```
module psinha_rv32(clk,RN,NPC,WB_OUT);
input clk;
input RN;
//input EN;
integer k;
wire  EX_MEM_COND ;
reg BR_EN;

//I_FETCH STAGE
reg[31:0] IF_ID_IR, IF_ID_NPC;                                

//I_DECODE STAGE
reg[31:0] ID_EX_A, ID_EX_B, ID_EX_RD, ID_EX_IMMEDIATE, ID_EX_IR, ID_EX_NPC;      

//EXECUTION STAGE
reg[31:0] EX_MEM_ALUOUT, EX_MEM_B, EX_MEM_IR;                        

parameter ADD=3'd0, SUB=3'd1, AND=3'd2, OR=3'd3, XOR=3'd4, SLT=3'd5,
          ADDI=3'd0, SUBI=3'd1, ANDI=3'd2, ORI=3'd3, XORI=3'd4,
          LW=3'd0, SW=3'd1,
          BEQ=3'd0, BNE=3'd1, SLL=3'd0, SRL=3'd1;

parameter AR_TYPE=7'd0, M_TYPE=7'd1, BR_TYPE=7'd2, SH_TYPE=7'd3;

//MEMORY STAGE
reg[31:0] MEM_WB_IR, MEM_WB_ALUOUT, MEM_WB_LDM;                      

output reg [31:0]WB_OUT, NPC;

//REG FILE
reg [31:0]REG[0:31];                                               
//64*32 IMEM
reg [31:0]MEM[0:31];                                             
//64*32 DMEM
reg [31:0]DM[0:31];   

//assign EX_MEM_COND = (EX_MEM_IR[6:0]==BR_TYPE) ? 1'b1 : 1'b0;
                           //1'b1 ? (ID_EX_A!=ID_EX_RD) : 1'b0;

always @(posedge clk or posedge RN) begin
    if(RN) begin
    NPC<= 32'd0;
    //EX_MEM_COND <=1'd0;
    BR_EN<= 1'd0; 
    REG[0] <= 32'h00000000;
    REG[1] <= 32'd1;
    REG[2] <= 32'd2;
    REG[3] <= 32'd3;
    REG[4] <= 32'd4;
    REG[5] <= 32'd5;
    REG[6] <= 32'd6;
    end

    //else if(EX_MEM_COND)
    //NPC <= EX_MEM_ALUOUT;

    //else if (EX_MEM_COND)
    //begin
    //NPC = EX_MEM_COND ? EX_MEM_ALUOUT : NPC +32'd1;
    //NPC <= EX_MEM_ALUOUT;
    //EX_MEM_COND = BR_EN;
    //NPC = BR_EN ? EX_MEM_ALUOUT : NPC +32'd1;
    //BR_EN = 1'd0;
    //EX_MEM_COND <= 1'd0;
    //end

    else
    begin
    NPC <= BR_EN ? EX_MEM_ALUOUT : NPC +32'd1;
    BR_EN <= 1'd0;
    //NPC <= NPC +32'd1;
    //EX_MEM_COND <=1'd0;
    IF_ID_IR <=MEM[NPC];
    IF_ID_NPC <=NPC+32'd1;
    end
end

always @(posedge RN)
   begin
     //NPC<= 32'd0;
      MEM[0] <= 32'h02208300;         // add r6,r1,r2.(i1)
      MEM[1] <= 32'h02209380;         //sub r7,r1,r2.(i2)
      MEM[2] <= 32'h0230a400;         //and r8,r1,r3.(i3)
      MEM[3] <= 32'h02513480;         //or r9,r2,r5.(i4)
      MEM[4] <= 32'h0240c500;         //xor r10,r1,r4.(i5)
      MEM[5] <= 32'h02415580;         //slt r11,r2,r4.(i6)
      MEM[6] <= 32'h00520600;         //addi r12,r4,5.(i7)
      MEM[7] <= 32'h00209181;         //sw r3,r1,2.(i8)
      MEM[8] <= 32'h00208681;         //lw r13,r1,2.(i9)
      MEM[9] <= 32'h00f00002;         //beq r0,r0,15.(i10)
      MEM[25] <= 32'h00210700;        //add r14,r2,r2.(i11)
     //MEM[27] <= 32'h01409002;       //bne r0,r1,20.(i12)
     //MEM[49] <= 32'h00520601;       //addi r12,r4,5.(i13)
     //MEM[50] <= 32'h00208783;       //sll r15,r1,r2(2).(i14)
     //MEM[51] <= 32'h00271803;       //srl r16,r14,r2(2).(i15) */

     //for(k=0;k<=31;k++)
     //REG[k]<=k;
     /*REG[0] <= 32'h00000000;
       REG[1] <= 32'd1;
       REG[2] <= 32'd2;
       REG[3] <= 32'd3;
       REG[4] <= 32'd4;
       REG[5] <= 32'd5;
       REG[6] <= 32'd6;
       REG[7] = 32'd7;
       REG[6] = 32'd6;
       REG[7] = 32'd7;
       REG[8] = 32'd8;
       REG[9] = 32'd9;
       REG[10] = 32'd10;
       REG[11] = 32'd11;
       REG[12] = 32'd12;
       REG[13] = 32'd13;
       REG[14] = 32'd14;
       REG[15] = 32'd15;
       REG[16] = 32'd16;
       REG[17] = 32'd17;*/
    /*end

  else
    begin
      if(EX_MEM_COND==1 && EX_MEM_IR[6:0]==BR_TYPE)
    begin
      NPC=EX_MEM_ALUOUT;
      IF_ID=MEM[NPC];
    end

   else
      begin
       NPC<=NPC+32'd1;
       IF_ID<=MEM[NPC];
       IF_ID_NPC<=NPC+32'd1;
      end
 end*/
 end

//I_FECT STAGE
/*always @(posedge clk) begin

//NPC <= rst ? 32'd0 : NPC+32'd1;
if(EX_MEM_COND==1 && EX_MEM_IR[6:0]==BR_TYPE)
   begin
     NPC=EX_MEM_ALUOUT;
     IF_ID=MEM[NPC];
   end
else
  begin
    NPC<=NPC+32'd1;
    IF_ID<=MEM[NPC];
    IF_ID_NPC<=NPC+32'd1;
end
end*/

//FETCH STAGE END

//I_DECODE STAGE 
always @(posedge clk)
  begin
    ID_EX_A <= REG[IF_ID_IR[19:15]];
    ID_EX_B <= REG[IF_ID_IR[24:20]];
    ID_EX_RD <= REG[IF_ID_IR[11:7]];
    ID_EX_IR <= IF_ID_IR;
    ID_EX_IMMEDIATE <= {{20{IF_ID_IR[31]}},IF_ID_IR[31:20]};
    ID_EX_NPC<=IF_ID_NPC;
end

//DECODE STAGE END
/*always@(posedge clk)
   begin
     if(ID_EX_IR[6:0]== BR_TYPE)
     EX_MEM_COND <= EN;
     else
     EX_MEM_COND <= !EN;
end*/

//EXECUTION STAGE
always@(posedge clk)
begin
EX_MEM_IR <=  ID_EX_IR;
//EX_MEM_COND <= (ID_EX_IR[6:0] == BR_TYPE) ? 1'd1 :1'd0;

 case(ID_EX_IR[6:0])
    AR_TYPE:begin
             if(ID_EX_IR[31:25]== 7'd1)
                     begin
                         case(ID_EX_IR[14:12])
                             ADD:EX_MEM_ALUOUT <= ID_EX_A + ID_EX_B;
                             SUB:EX_MEM_ALUOUT <= ID_EX_A - ID_EX_B;
                             AND:EX_MEM_ALUOUT <= ID_EX_A & ID_EX_B;
                             OR :EX_MEM_ALUOUT <= ID_EX_A | ID_EX_B;
                             XOR:EX_MEM_ALUOUT <= ID_EX_A ^ ID_EX_B;
                             SLT:EX_MEM_ALUOUT <= (ID_EX_A < ID_EX_B) ? 32'd1 : 32'd0;
                         endcase
                     end
             else
                     begin
                        case(ID_EX_IR[14:12])
                            ADDI:EX_MEM_ALUOUT <= ID_EX_A + ID_EX_IMMEDIATE;
                            SUBI:EX_MEM_ALUOUT <= ID_EX_A - ID_EX_IMMEDIATE;
                            ANDI:EX_MEM_ALUOUT <= ID_EX_A & ID_EX_B;
                            ORI:EX_MEM_ALUOUT  <= ID_EX_A | ID_EX_B;
                            XORI:EX_MEM_ALUOUT <= ID_EX_A ^ ID_EX_B;
                        endcase
                     end
          end

   M_TYPE:begin
           case(ID_EX_IR[14:12])
               LW  :EX_MEM_ALUOUT <= ID_EX_A + ID_EX_IMMEDIATE;
               SW  :EX_MEM_ALUOUT <= ID_EX_IR[24:20] + ID_EX_IR[19:15];
           endcase
          end

  BR_TYPE:begin
           case(ID_EX_IR[14:12])
               BEQ:begin 
                     EX_MEM_ALUOUT <= ID_EX_NPC+ID_EX_IMMEDIATE;
                     BR_EN <= 1'd1 ? (ID_EX_IR[19:15] == ID_EX_IR[11:7]) : 1'd0;
                    //BR_PC = EX_MEM_COND ? EX_MEM_ALUOUT : 1'd0; 
                   end
               BNE:begin 
                     EX_MEM_ALUOUT <= ID_EX_NPC+ID_EX_IMMEDIATE;
                     BR_EN <= (ID_EX_IR[19:15] != ID_EX_IR[11:7]) ? 1'd1 : 1'd0;
                   end
           endcase
         end
         SH_TYPE:begin
                   case(ID_EX_IR[14:12])
                     SLL:EX_MEM_ALUOUT <= ID_EX_A << ID_EX_B;
                     SRL:EX_MEM_ALUOUT <= ID_EX_A >> ID_EX_B;
                   endcase
                  end
 endcase
end

//EXECUTION STAGE END
		
//MEMORY STAGE
always@(posedge clk)
   begin
      MEM_WB_IR <= EX_MEM_IR;

           case(EX_MEM_IR[6:0])
             AR_TYPE:MEM_WB_ALUOUT <=  EX_MEM_ALUOUT;
             SH_TYPE:MEM_WB_ALUOUT <=  EX_MEM_ALUOUT;

   M_TYPE:begin
           case(EX_MEM_IR[14:12])
             LW:MEM_WB_LDM <= DM[EX_MEM_ALUOUT];
             SW:DM[EX_MEM_ALUOUT]<=REG[EX_MEM_IR[11:7]];
          endcase
        end
          endcase
   end

// MEMORY STAGE END

//WRITE BACK STAGE
always@(posedge clk)
     begin
        case(MEM_WB_IR[6:0])
            AR_TYPE:begin 
                  WB_OUT<=MEM_WB_ALUOUT;
                  REG[MEM_WB_IR[11:7]]<=MEM_WB_ALUOUT;
                    end
            SH_TYPE:begin
                  WB_OUT<=MEM_WB_ALUOUT;
                  REG[MEM_WB_IR[11:7]]<=MEM_WB_ALUOUT;
                    end
            M_TYPE:begin
                 case(MEM_WB_IR[14:12])
                    LW:begin
                        WB_OUT<=MEM_WB_LDM;
                        REG[MEM_WB_IR[11:7]]<=MEM_WB_LDM;
                       end
                endcase
                  end
        endcase
    end
//WRITE BACK STAGE END
endmodule
```

`psinha_rv32_tb.v`

```
module psinha_rv32_tb;
reg clk, RN;
wire [31:0]WB_OUT,NPC;

psinha_rv32 rv32(clk,RN,NPC,WB_OUT);

always #3 clk=!clk;

initial
begin 
    RN  = 1'b1;
    clk = 1'b1;
    $dumpfile ("psinha_rv32.vcd"); //by default vcd
    $dumpvars (0, psinha_rv32_tb);

    #5 RN = 1'b0;
    #300 $finish;
end
endmodule
```

* Now, as we have added this code in the created directory, we need to run and simulate this verilog code using the command--
```
$ iverilog -o piyushriscv psinha_rv32.v psinha_rv32_tb.v
$ ./piyushriscv
```
* Now, we will try to see the simulation waveform in the "gtkwave" using the command--
```
$ gtkwave psinha_rv32.vcd
```
* This command will open the GTKWAVE window --

![Screenshot 2024-05-10 020012](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/cfe1e6f4-f347-4f59-adad-b9c09715b3b6)

We have to analyze the output waveform of these instructions, but the problem is that these instructions are hard-coded by the designer itself, so they will not match the standard RISC-V ISA bit pattern--

![Screenshot 2024-05-12 192122](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/d8a4c4bd-9290-44f7-85af-f11740da4e29)

The above ISA shown in the figure is a hard-coded instruction, not the standard RISC-V ISA which we have figured out earlier.
* Now, let's analyze the waveform of each instruction using gtkwave.
```
1. ADD R6, R2, R1
```
This instruction belongs to R-type instruction set, where R6 is the destination register and it will store the sum of values stored in registers R1 and  R2.
![Screenshot 2024-05-10 024801](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/441b5916-9cec-429d-9001-027524886750)

```
2. SUB R7, R1, R2
```
This instruction belongs to R-type instruction set, where R7 is the destination register and it will store the difference of values stored in registers R1 and  R2.
![Screenshot 2024-05-10 024955](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/a3940f6d-d2ff-491f-9cb9-ad39230a4663)

```
3. AND R8, R1, R3
```
This instruction belongs to R-type instruction set, where R8 is the destination register and it will hold the value of AND operation(R1 & R3) of the registers R1 and R3 bit by bit.
![Screenshot 2024-05-10 025111](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/cf8f2685-5035-4cf7-8509-064b7d681360)
We can see in the above waveform the Bitwise AND operation of 3(0011) and 1(0001) which will give the output as 1(0001).

```
4. OR R9, R2, R5
```
This instruction belongs to R-type instruction set, where R9 is the destination register and it will hold the value of OR operation(R2 | R5) of the registers R2 and R5 bit by bit.
![Screenshot 2024-05-10 025256](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/cd83f553-d402-4ef2-bfd2-5ad25f7a98aa)
Bitwise OR operation of 2(0010) and 5(0101) will be 7(0111).

```
5. XOR R10, R1, R4
```
This instruction belongs to R-type instruction set, where R10 is the destination register and it will hold the value of XOR operation(R1 ^ R4) of the registers R1 and R4 bit by bit.
![Screenshot 2024-05-10 025421](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/d55d17be-a19c-46dc-be8d-e3da0d649245)
Bitwise XOR of 1(0001) and 4(0100) will be 5(0101).

```
6. SLT R1, R2, R4
```
This instruction belongs to R-type instruction set, where R1 is the destination register that sets to 1 if R2 is less than R4 else 0 if R2 is greater than R4.
![Screenshot 2024-05-10 025606](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/5f46772a-3fbc-42f3-9357-1ab7b01950d4)
The value 2 is less than 4, so we will get output as 1.

```
7. ADDI R12, R4, 5
```
This instruction belongs to I-type instruction set, where R12 is the destination register that will store the value of R5 sum up with the immediate value 5.
![Screenshot 2024-05-10 030416](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/29bc6ec7-4fc0-4119-8108-ab793802aa07)
The value 4 stored in the register will be added with an immediate value 5 and output is 9.

```
8. SW R3, R1, 2
```
This instruction belongs to S-type instruction set, that will store the value in the source register R3 at the address obtained by adding the immediate address 2 with the address located in register R1. 
![Screenshot 2024-05-10 031333](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/d94e57e3-51b5-4aca-b183-975c568f94b2)


```
9. LW R13, R1, 2
```
This instruction belongs to I-type instruction set where R13 is the destination register that will hold the value fetched from the memory location calculated as the "address value of R1 + immediate value".
![Screenshot 2024-05-10 031601](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/1890b48d-26da-498c-a1d5-fdafaa2b2833)

```
10. BEQ R0, R0, 15
```
This instruction belongs to B-type instruction. If the value stored in R0 is equal to(==) the value stored in R0, the program counter will be updated by (PC+15) else (PC+4) for the next instruction.
![Screenshot 2024-05-10 031855](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/f3340c9d-caaa-4a7c-aaf8-09101b146b16)
The values stored in both the registers are equal, it increments the PC by 15 as shown in the waveform.



### The VSDSquadron Mini RISC-V development board – Features and Interfaces:

* Core Processor – The board is powered by a CH32V003F4U6 chip with a 32-bit RISC-V core based on RV32EC instruction set, optimized for high-performance computing with support for 2-level interrupt nesting and supports 24MHz system main frequency in the product function.
* Clock and Reset Systems: Includes a built-in factory-trimmed 24MHz RC oscillator and a 128kHz RC oscillator, plus an external 24MHz oscillator option for varied clocking requirements.
* Robust GPIO Support: Boasts 3 groups of GPIO ports, totaling 15 I/O ports, enabling extensive peripheral connections and mapping to external interrupt capabilities.
* Flexible Communication Interfaces: Offers multiple communication protocols including USART, I2C, and SPI for versatile connectivity options.
* High-Speed Memory: Equipped with 2KB SRAM for volatile data storage, 16KB CodeFlash for program memory, and an additional 1920B for bootloader functionalities.
* On-board Programmer: Features on-board CH32V305FBP6 single-wire programming protocol, enhancing development efficiency with seamless code deployment and debugging. NO NEED to purchase any additional adapters.

#### Block Diagram
<b> The following block diagram shows the key components of the VSDSquadron Mini RISC-V development board.

![Screenshot 2024-04-26 183406](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/42265edd-3963-463e-88d7-fb47358d0c32)

#### Pin Configurations of CH32V003F4U6 Chip:

![photo_2024-05-20_21-19-51](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/cb8d027e-8ad9-42c8-a9d9-c4a5a7ae08a2)

#### Data Sheet
Refer to this pdf-- [vsd mini datasheet.pdf](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/files/15380577/vsd.mini.datasheet.pdf)

#### VSD Squadron Board

![Screenshot 2024-04-26 183650](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/54a19abd-a722-4560-b804-09ad22d1201d)

#### The following table shows CH32V003F4U6 RISC-V SoC IO Bank Assignment for communication Interface--

![Screenshot 2024-05-12 202919](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/84da2f7b-5d0c-4c3b-b5d6-d6947f664ae9)

#### The following table lists the important components of the VSDSquadron Mini RISC-V development board--


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
| Memory | SRAM: 2kb on-chip volatile SRAM, 16kb external program memory |


## 4-BIT ODD PARITY DETECTOR

An odd parity detector is primarily used in digital communication and data storage systems to ensure the integrity of data. Here are some key applications:

* 1. Error Detection in Data Transmission:
   - `Parity Bits`: When transmitting data over a network or between devices, a parity bit (either odd or even) is often appended to each byte or word of data. The odd parity detector at the receiver end checks if the data has been corrupted during transmission by ensuring the number of '1s matches the expected parity.
   - `Serial Communication`: Protocols like UART (Universal Asynchronous Receiver/Transmitter) use parity bits for error checking. If the parity bit doesn't match the expected value, the receiver knows there has been an error in transmission.

* 2. Memory Storage:
   - `Error Detection in Memory`: Computer memory (like RAM) can use parity bits to detect errors. Each byte of data stored in memory has an associated parity bit. When data is read from memory, an odd parity detector verifies the parity to ensure data integrity.

* 3. Digital Systems and Microcontrollers:
   - `Microcontroller Systems`: Embedded systems often include parity checks in communication protocols between microcontrollers and peripherals to detect errors.
   - `Bus Communication`: Data buses in computers and other digital systems use parity bits for error detection to ensure data integrity during data transfer between components.

* 4. File Transfer Protocols:
   - `Network Protocols`: Protocols such as FTP, HTTP, and others may use parity checks as part of their error-checking mechanisms to ensure data integrity during file transfers.

* 5. Disk Storage:
   - `Hard Drives and SSDs`: Storage devices use parity bits to detect and sometimes correct errors in data read from or written to the disk. RAID (Redundant Array of Independent Disks) systems often use parity for error detection and correction across multiple disks.

* 6. Communication Systems:
   - `Modems and Routers`: Devices involved in network communication use parity bits to detect errors in transmitted data packets, ensuring reliable data transfer across the network.

**Example Scenario:**
* Data Transmission:
Consider a simple data transmission scenario where a 4-bit data word is transmitted with an odd parity bit:

1. Transmitter Side:
   - Data to be transmitted: 1010
   - Calculate parity bit using an odd parity detector: The number of '1's in 1010 is 2 (even), so the parity bit should be 1 to make the total number of '1's odd.
   - Transmitted data: 10101 (4-bit data + 1-bit parity)

2. Receiver Side:
   - Received data: 10101
   - Separate the parity bit and the data: Data = 1010, Parity bit = 1
   - Use an odd parity detector to check the received data: Calculate the parity of 1010 (which is 2 '1's, so even) and compare with the received parity bit 1.
   - If the parity matches the expectation (odd number of '1's including the parity bit), the data is considered valid; otherwise, it indicates an error.

**Summary:**
Odd parity detectors are crucial for maintaining data integrity in various digital communication and storage systems by providing a simple yet effective method for error detection. They help ensure that data received or stored is the same as the data originally sent or written, thus safeguarding against data corruption and transmission errors.

* **TRUTH TABLE**

| **A** | **B** | **C** | **D** | **_Output(LED)_** |
|-------|-------|-------|-------|:-----------------:|
| 0     | 0     | 0     | 0     |         0         |
| 0     | 0     | 0     | 1     |         1         |
| 0     | 0     | 1     | 0     |         1         |
| 0     | 0     | 1     | 1     |         0         |
| 0     | 1     | 0     | 0     |         1         |
| 0     | 1     | 0     | 1     |         0         |
| 0     | 1     | 1     | 0     |         0         |
| 0     | 1     | 1     | 1     |         1         |
| 1     | 0     | 0     | 0     |         1         |
| 1     | 0     | 0     | 1     |         0         |
| 1     | 0     | 1     | 0     |         0         |
| 1     | 0     | 1     | 1     |         1         |
| 1     | 1     | 0     | 0     |         0         |
| 1     | 1     | 0     | 1     |         1         |
| 1     | 1     | 1     | 0     |         1         |
| 1     | 1     | 1     | 1     |         0         |

* **Boolean Expression:**
To determine the parity, we use XOR operations. The output P can be expressed as:
[ P = A \oplus B \oplus C \oplus D ]

* **Logic Diagram:**
![Screenshot 2024-05-20 210556](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/058dfc96-147f-4aca-836f-abbe901f3190)

### Project Objective:
The objective of this project is to design and implement a 4-bit odd parity detector using the RISC-V Squadron Mini Board and Embedded C programming. The project will involve developing a digital logic circuit that can determine if a 4-bit binary input has an odd number of '1s. This project aims to enhance understanding of digital logic design and embedded systems programming using the RISC-V architecture. It will also demonstrate the practical application of parity detection in ensuring data integrity in digital communication systems.

### Components Required
```
1. VSD Squadron Mini Board
2. Breadboard
3. Jumper wires
4. 4 Push Buttons
5. 1 piece of LED
```

### Circuit Diagram:
![Screenshot 2024-05-20 232646](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/assets/140955475/4658fdf1-fe7f-42ff-b672-64d2e1ed2a92)

### Embedded C Code to implement the 4-bit odd parity detector

```
#include <debug.h>
#include <ch32v00x.h>
int xor(int bit1, int bit2) {
    return bit1 ^ bit2;
}
void GPIO_Config(void) {
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); // Enable the clock for port D
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); // Enable the clock for port C
    
    // Input Pins Configuration
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // Input Type with pull-up
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    // Output Pin Configuration
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // Output Type
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Speed
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}
int main() {
    uint8_t bit1, bit2, bit3, bit4, parity;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SystemCoreClockUpdate();
    Delay_Init();
    GPIO_Config();

    while (1) {
        // Read the input values
        bit1 = GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_1);
        bit2 = GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_2);
        bit3 = GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_3);
        bit4 = GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_4);
        
        // Odd Parity Logic
        parity = xor(xor(bit1, bit2), xor(bit3, bit4)); // XOR all bits together
        
        // Write the Parity output
        if (parity == 1) {
            GPIO_WriteBit(GPIOC, GPIO_Pin_5, SET); // LED on for Odd Parity
        } else {
            GPIO_WriteBit(GPIOC, GPIO_Pin_5, RESET); // LED off for Even Parity
        }
    }
}
```
Coming to the software part, we will run the above code on the VSDSquadron Mini RISC-V development board using PlatformIO in the VSCode application. 
</br>Refer to this datasheet which contains the pin details of the VSDSquadron Mini Board and how to install the required software to run the Embedded C-code on the board. 
[vsd mini datasheet.pdf](https://github.com/Pisinha26/VSDSquadron-Mini-Research-Internship/files/15380577/vsd.mini.datasheet.pdf)


### Application Video














