# Todo-Manager
A planner written in C++ and Qt, designed to help users focus and organize. 

## Library Requirements 
Using this program requires the following be installed:
* C++17
* g++
* Qt 5.15

## Back and Front-end
### Front-end
The front end of the application is written in C++ and uses Qt to render the UI. <br>

### Back-end
The back end of the application uses C++ to parse data to and from a csv file. Using
a csv files means that a database is not necessary and helps keep the size
and complexity of the project down. <br>

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
#### Installing Qt from source
If Qt is not installed, installation can be found [here](https://doc.qt.io/qt-5/gettingstarted.html) </br>

#### Installing Qt from snap
If snap is enabled qt5.5 is available there as well. <br>
Below is the installation method used for manjaro: <br>
1. Install snapd from package manager, exact command may differ for distros: <br>
`sudo pacman -Syu snapd` <br>
2. Enable snap service: <br>
`sudo systemctl enable --now snapd.socket` <br>
3. Install qt551 package: <br>
`sudo snap install qt551` <br>
<br>
As an optional step, classic snap support can be enabled: <br>
`sudo ln -s /var/lib/snapd/snap /snap` <br>
Keep in mind this change will only take effect by logging out or rebooting. <br>
<br>
Information from [here](https://snapcraft.io/install/qt551/manjaro) <br>

## Building and using
This program needs to be built before it can be run, navigate to the ToDo folder and
build using: </br>
`qmake Todo.pro` </br>

This will create a make file, which can be executed using: </br>
`make`

After building the program can be run with </br>
`./Todo` </br>
on *NIX based machines such as Linux or Mac OSX

## In development:
* Colorscheme adjustments
* Daily Task Rollover
* Percentage tasks completed
* Back-end 
  - CSV file 
  - C++ parser 
* Binary for release
