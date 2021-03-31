/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** apiMacro
*/

#ifndef APIMACRO_HPP_
#define APIMACRO_HPP_

#include "api/api.h"
#include "api/ILibrary.hpp"

using LibCreate = void *(*)();
using LibDelete = void (*)(void *);
using LibData = library_info_t (*)();

#define LIB_CREATE(file) (arcade::lib::ILibrary *)\
    ((LibCreate)dlsym(file, "library_create"))()
#define LIB_DELETE(file, lib) ((LibDelete)dlsym(file, "library_delete"))(lib)
#define LIB_DATA(file) ((LibData)dlsym(file, "library_get_data"))()

#endif /* !APIMACRO_HPP_ */
