/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** error_lib
*/

#include "error_lib.hpp"

namespace arcade {

namespace error {

    const char *error_lib::what () const throw ()
    {
    	return "arcade lib Exception";
    }

    void error_lib::details() const
    {
        std::cerr << "lib : ";
        subDetails();
    }

    void error_lib::subDetails() const
    {
        std::cerr << "Unknown" << std::endl;
    }

}

}