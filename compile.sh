#!/bin/sh
cc -Wall -Wextra -Iincludes -lncurses -o ft_shmup $(find sources -name '*.c')
