/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** error_lib
*/

#ifndef ERROR_LIB_HPP_
#define ERROR_LIB_HPP_

#include <stdexcept>
#include "error_arcade.hpp"

namespace arcade {

namespace error {

class error_lib : public error_arcade {
    public:
    virtual const char *what () const throw () override;

    protected:
    void details() const;
    virtual void subDetails() const;
};

}

}

#endif /* !ERROR_LIB_HPP_ */
