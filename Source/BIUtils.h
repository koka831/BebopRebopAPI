#include <map>
#include <string>
#include <string.h>
#include <stdarg.h>

#define ENUM(_n, ...)                   \
    struct _n {
    enum type {__VA_ARGS__, NUM};        \
    std::map<std::string,type>converter;\
    _n() {                              \
        createEnumMap(converter,#__VA_ARGS__,NUM,__VA_ARGS__); \
    }                                   \
    }_n;

template <class T> void createEnumMap(std::map<std::string,T> &_map, char* _list, int _num, ...)
    {
        char* listCpy = new char[255];
        char* tmp_key;
        strcpy(listCpy,_list);

        va_list args;
        va_start(args, _num);
        if ((tmp_key = strtok(listCpy, ", ")) != NULL) _map[tmp_key] = static_cast<T> (va_arg(args, int));
        for (int i = 1; i < _num; i++) {
            if ((tmp_key = strtok(NULL, ", ")) != NULL) _map[tmp_key] = static_cast<T> (va_arg(args, int));
        }
        va_end(args);
        delete[] listCpy;
    }
