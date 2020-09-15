# Todo-Manager
A planner written in C++ and Qt, designed to help users focus and organize. 

## Library Requirements 
Using this program requires the following be installed:
* C++17
* g++
* Qt 5.15

### Qt Requirements
These are items required by Qt, by Linux distro style </br>
For .deb based systems such Debian or Ubuntu:
* build-essential 
* libgl1-mesa-dev

For .rpm based systems such as CentOS or Fedora:
* 'C Development Tools and Libraries' (install with yum groupinstall)
* mesa-libGL-devel

For openSUSE:
* devel_basis
* pattern 

### Installing Qt
If Qt is not installed, it can be found [here](https://doc.qt.io/qt-5/gettingstarted.html) </br>

## Building and using
This program needs to be built before it can be run, navigate to the ToDo folder and
build using: </br>
`qmake Todo.pro` </br>

This will create a make file, which can be made using: </br>
`make`

After building the program can be run with </br>
`./Todo` </br>
on *NIX based machines such as Linux or Mac OSX

## In development:
* Ability to change daily list
* Colorscheme adjustments
* Daily Task Rollback
* Layout tweaks
* Overarching goals
* Percentage tasks completed
* Weekly goals
* Write Daily lists in advance
