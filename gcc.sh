#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 simple_shell.c _getline.c parse_line.c _strchr.c -o simple_shell
