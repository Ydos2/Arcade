/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "core/Core.hpp"

int main(int argc, char **argv)
{
    arcade::core::Core core;

    if (argc != 2)
        return 84;
    return core.execute(argv[1]);
}