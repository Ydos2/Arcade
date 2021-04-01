/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** error_arcade
*/

#ifndef ERROR_ARCADE_HPP_
#define ERROR_ARCADE_HPP_

#include <stdexcept>
#include <iostream>

namespace arcade {

namespace error {

class error_arcade : public std::exception {
    public:
    virtual const char *what () const throw () override;
    void info() const throw ();

    protected:
    virtual void details() const;
};

}

}

#endif /* !ERROR_ARCADE_HPP_ */
