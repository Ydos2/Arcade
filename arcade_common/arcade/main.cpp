/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "core/Core.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    arcade::core::Core core;
    int ret = 0;

    if (argc != 2 && argc != 1)
        return 84;
    try {
        ret = core.execute(argc >= 2 ? argv[1] : "");
    } catch (std::exception &e) {
        std::cerr << "An unknown error occured. Aborting." << std::endl;
        return 81;
    }
    return ret;
}