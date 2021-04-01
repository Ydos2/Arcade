/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** error_arcade
*/

#include "error_arcade.hpp"

namespace arcade {

namespace error {

    void error_arcade::info() const throw () {
        std::cerr << "Arcade Exception : ";
        details();
    }

    const char *error_arcade::what () const throw ()
    {
    	return "arcade Exception";
    }

    void error_arcade::details() const
    {
        std::cerr << "Unknown." << std::endl;
    }

}

}