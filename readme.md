# Basic statistical treatment

<p align="center">
  <a href="https://github.com/Evgenk2020/one-row-stat-linux/blob/main/LICENSE">
    <img src="https://img.shields.io/github/license/Evgenk2020/one-row-stat-linux" alt="license">
  </a>
  <a href="https://github.com/Evgenk2020/one-row-stat-linux/commits">
    <img src="https://img.shields.io/github/last-commit/Evgenk2020/one-row-stat-linux" alt="last commit">
  </a>
  <a href="https://github.com/Evgenk2020/one-row-stat-linux">
    <img src="https://img.shields.io/github/repo-size/Evgenk2020/one-row-stat-linux" alt="repo size">
  </a>
  <a href="https://github.com/Evgenk2020/one-row-stat-linux/stargazers">
    <img src="https://img.shields.io/github/stars/Evgenk2020/one-row-stat-linux" alt="stars">
  </a>
  <a href="https://github.com/Evgenk2020/one-row-stat-linux/network/members">
    <img src="https://img.shields.io/github/forks/Evgenk2020/one-row-stat-linux" alt="forks">
  </a>
  <a href="https://github.com/Evgenk2020/one-row-stat-linux">
    <img src="https://img.shields.io/github/languages/top/Evgenk2020/one-row-stat-linux" alt="top language">
  </a>
  <a href="https://github.com/Evgenk2020/one-row-stat-linux/releases">
    <img src="https://img.shields.io/github/v/release/Evgenk2020/one-row-stat-linux" alt="latest release">
  </a>
</p>

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

> You need
> <br>
> [CMake](https://cmake.org/)
> <br>
> to be installed on your Linux system previously

<hr>

<b>To compile and run the utility</b>

1. Select empty folder, open terminal and clone the repository

```SH

git clone https://github.com/Evgenk2020/one-row-stat-linux

cd one-row-stat-linux

```

2. Check for `rpm-build` package to be installed in your system

```SH

rpm -q rpm-build

```

If so you will see `rpm-build-6.0.0-1.fc43.x86_64` or something like that.

If not it will be `package rpm-build is not installed`. Then install it from system repository

```SH

sudo dnf install rpm-build

```

3. Build the Project with `.rpm` setup package for Fedora/CentOS Stream by default

```SH

./build.sh

```

4. Install `.rpm` package from build folder

```SH

sudo dnf install *.rpm

```

<hr>

If using either than Fedora/CentOS Stream change the first string `set(assemble_tgz OFF)` in CMakeLists.txt to `set(assemble_tgz ON)` before building the Project. Move `.tar.gz` file to any folder and unpack it.

Then run `./onerow -d | -df [data...]` in terminal from unpacked folder.

For more convenience you may add path to the application into `.bashrc` file

```SH

export PATH=$PATH:/%path_to_application_folder%/

```

In this case it will be possible to run `onerow -d | -df [data...]` in terminal directly.
