#ifndef WRITABLE
#define WRITABLE
#endif

#include <string>

namespace Core::Headers{
    class Writable{
    public:
    virtual std::string ToString();
};
}