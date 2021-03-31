/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "Core.hpp"

int main(int argc, char **argv)
{
    arcade::Core core;

    if (argc != 2)
        return 84;
    return core.execute(argv[1]);
}