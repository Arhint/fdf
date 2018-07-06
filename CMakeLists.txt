cmake_minimum_required(VERSION 3.10)
project(new_fdf C)

set(CMAKE_C_STANDARD 99)

add_executable(new_fdf fdf.c fdf.h ft_read.c map.c fr_put_lines.c)