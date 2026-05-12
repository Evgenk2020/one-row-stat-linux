[![license](https://img.shields.io/github/license/Evgenk2020/one-row-stat-linux)](https://github.com/Evgenk2020/one-row-stat-linux/blob/main/LICENSE)
[![last commit](https://img.shields.io/github/last-commit/Evgenk2020/one-row-stat-linux)](https://github.com/Evgenk2020/one-row-stat-linux/commits)
[![repo size](https://img.shields.io/github/repo-size/Evgenk2020/one-row-stat-linux)](https://github.com/Evgenk2020/one-row-stat-linux)
[![stars](https://img.shields.io/github/stars/Evgenk2020/one-row-stat-linux)](https://github.com/Evgenk2020/one-row-stat-linux/stargazers)
[![forks](https://img.shields.io/github/forks/Evgenk2020/one-row-stat-linux)](https://github.com/Evgenk2020/one-row-stat-linux/network/members)
[![top language](https://img.shields.io/github/languages/top/Evgenk2020/one-row-stat-linux)](https://github.com/Evgenk2020/one-row-stat-linux)
[![latest release](https://img.shields.io/github/v/release/Evgenk2020/one-row-stat-linux)](https://github.com/Evgenk2020/one-row-stat-linux/releases)
[![version](https://img.shields.io/badge/version-1.0.1-blue)](https://github.com/Evgenk2020/one-row-stat-linux)

# Basic statistical treatment

Lab utility for simple statistical estimation

Run it with specified keys

```

onerow -d | -df [data...]

```
Using `-df` key you may write data to `*.csv` file for the next importing to LibreOffice Calc, MS Excell or Google Tables

![Google table data import](/.img/screen.png)

.sh file example for running in terminal

```SH

#!/bin/bash

onerow -d 1 2 3 4 5
echo "---------------"
onerow -d 1.1 2.4 -3 4.9 -5.3
echo "---------------"
onerow -d 0 0 3 4 5
echo "---------------"
onerow -d 1 2 3 0 0
echo "---------------"
onerow -d 23.1 18.6 19 20 20 24 19.5

exec $SHELL

```

.sh file example for writing to `.csv`

```SH

#!/bin/bash

onerow -df 1 2 3 4 5
onerow -df 1.1 2.4 -3 4.9 -5.3
onerow -df 0 0 3 4 5
onerow -df 1 2 3 0 0
onerow -df 23.1 18.6 19 20 20 24 19.5

exec $SHELL

```

<hr>

You need to be installed on your Linux system previously:

- GCC g++
- CMake

(Fedora/CentOS Stream)

- rpm-build

On Fedora based systems run
<br>

```SH

sudo dnf groupinstall "Development Tools"
sudo dnf install cmake
sudo dnf install rpm-build

```

On Debian based systems run
<br>

```SH

sudo apt update
sudo apt install build-essential
sudo apt install cmake

```

On other systems see the details of your distro

<hr>

<b>To compile and run the utility (Fedora/CentOS Stream)</b>

1. Clone the Repository

```SH

git clone https://github.com/Evgenk2020/one-row-stat-linux

cd one-row-stat-linux

```

2. Build the Project with `.rpm` setup package for Fedora/CentOS Stream by default

```SH

./build.sh

cd build

```

3. Install `.rpm` package from build folder

```SH

sudo dnf install *.rpm

```

4. Run the application in terminal directly

```SH

onerow -h

```

<hr>

<b>If using either than Fedora/CentOS Stream</b>

1. Clone the Repository

```SH

git clone https://github.com/Evgenk2020/one-row-stat-linux

cd one-row-stat-linux

```

2. Change the string `set(assemble_tgz OFF)` to `set(assemble_tgz ON)` in CMakeLists.txt

```SH

nano CMakeLists.txt

```

3. Build the Project

```SH

./build.sh

```

4. Move `.tar.gz` file from `build` folder to any folder and unpack it

5. Run the program to check it from unpacked folder

```SH

./onerow -h

```

For more convenience add the application path into `.bashrc` file

```SH

export PATH="$PATH:/path/to/application/folder"

```

This will allow you to run the application in terminal directly

```SH

onerow -h

```
