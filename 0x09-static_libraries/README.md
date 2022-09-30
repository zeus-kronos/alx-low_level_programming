# 0x09. C - Static libraries

## Description

0-Create the static library libmy.a containing all files given:

| **Steps on CLI** 

*gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -c *.c |
ar -rc libmy.a *.o |

1 - Create a script called create_static_lib.sh that creates a static library called liball.a from all the .c files that are in the current directory.
