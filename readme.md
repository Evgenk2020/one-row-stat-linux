# Short sequence statistics

Lab utility for simple statistical estimation

Run it with specified keys

```

onerow -d [first_number] [second_number] ... [sequent_number]

```
Using `-df` key you may write data to `*.csv` file for the next importing to LibreOffice Calc, MS Excell or Google Tables

![Google table data import](/img/screen.png)

Use `build.sh` and `run.sh` from the `src` folder to compile and run the application

For more convenience you may add path to the application into `.bashrc` file

```

export PATH=$PATH:/%path_to_application_folder%/

```

and then use simple SH schemes e.g.

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

or for writing `one-rstat.csv` use

```SH

#!/bin/bash

onerow -df 1 2 3 4 5
onerow -df 1.1 2.4 -3 4.9 -5.3
onerow -df 0 0 3 4 5
onerow -df 1 2 3 0 0
onerow -df 23.1 18.6 19 20 20 24 19.5

exec $SHELL

```

This program runs with `uk_UA.utf8` locale. It can be changed in `output.cpp`

```C++

std::locale m_loc("uk_UA.utf8");

```

To see locale list use

```SH

locale -a

```
