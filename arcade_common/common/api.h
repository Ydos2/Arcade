/*
** EPITECH PROJECT, 2021
** Arcade-Toulouse
** File description:
** api
*/

#ifndef API_H_
#define API_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <time.h>

typedef enum {GAME, GRAPHIC} type_t;

typedef struct library_info {
    type_t type;
    const char *name;
    time_t date;
    const char *desc;
} library_info_t;

void *library_create();
void library_delete(void *library);
library_info_t library_get_data();

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* !API_H_ */
