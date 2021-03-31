/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Library
*/

#ifndef LIBRARY_HPP_
#define LIBRARY_HPP_

#include "api/ILibrary.hpp"
#include "api/api.h"
#include <string>
#include <ctime>

namespace arcade {

namespace library {

    class Library {
        public:
            Library() = default;
            Library(const std::string &path);
            ~Library();

            void open(const std::string &path);
            void close();
            std::string getPath() const;
            library_info_t getData() const;
            std::string getName() const;
            std::string getDetails() const;
            time_t getDate() const;
            bool isGame() const;
            bool isGraphic() const;

            template<class T=arcade::lib::ILibrary>
            T *getLibrary() const {
                return static_cast<T *>(m_lib);
            }

        protected:
        private:
            std::string m_path = "";
            void *m_file = nullptr;
            library_info_t m_data;
            lib::ILibrary *m_lib = nullptr;

            void openError();
    };

}

}

#endif /* !LIBRARY_HPP_ */
