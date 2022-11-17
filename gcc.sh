#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 ss_main.c ss_interactive.c ss_batch.c exec_job.c _getline.c parse_line.c _strchr.c _strcat.c _strcpy.c _strlen.c _strncmp.c _strcmp.c get_cmd_path.c exec_cmd.c _strdup.c _getenv.c rem_cmnt.c exec_builtin.c ss_exit.c shell_err.c env_handler.c cd_handler.c var_handler.c -o simple_shell
