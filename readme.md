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

<b>To compile and run the utility</b>

1. Clone the Repository

```SH

git clone https://github.com/Evgenk2020/one-row-stat-linux

cd one-row-stat-linux

```

2. Build the Project

```SH

./build.sh

```

3. Run the Project

```SH

./run.sh

```

For more convenience add path to the application into `.bashrc` and call `onerow` from any folder

```

export PATH=$PATH:[path_to_application_folder]

```
