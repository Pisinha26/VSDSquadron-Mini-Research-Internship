# VSDSquadron-Mini-Research-Internship
## Installing the EDA Tools
### Steps to install git
$ sudo apt update
$ sudo apt install git

### Steps to install gcc
$ sudo apt update
$ sudo apt install gcc

### Steps to install yosys
$ git clone https://github.com/YosysHQ/yosys.git
$ cd yosys
$ sudo apt-get install build-essential clang bison flex libreadline-dev gawk tcl-dev libffi-dev git graphviz xdot pkg-config python3 libboost-system-dev libboost-python-dev libboost-filesystem-dev zlib1g-dev
$ make config-gcc
$ make
$ sudo make install

### Steps to install iverilog
$ sudo apt-get update
$ sudo apt-get -y install iverilog

### Steps to install gtkwave
$ sudo apt update
$ sudo apt install gtkwave

### Steps to install RISC-V GNU Compiler Toolchain
refer 

### Steps to install vim text editor
$ sudo apt update
$ sudo apt install vim
after installing Vim, create a C program code as hello.c
$ cd Documents
$ vim hello.c
press i to insert and type the code and save the file using esc:wq and enter.

### Steps to install Spike to fix error
$ sudo apt-get install device-tree-compiler
