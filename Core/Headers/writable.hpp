#ifndef WRITABLE
#define WRITABLE

#include <string>

class Writable{
    public:
        virtual std::string ToString()const = 0;
};

#endif