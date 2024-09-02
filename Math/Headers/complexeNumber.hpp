#ifndef COMPLEXE_NB
#define COMPLEXE_NB
#endif

#include <cstdint>
#include "Core\Headers\writable.hpp"

namespace Math::Headers{
    class ComplexeNumber : public Core::Headers::Writable
{
private:
    double m_realPart; 
    double m_imaginaryPart;
    void SetAll(double real, double imaginary);
public:
    ComplexeNumber(double real, double imaginary);
    ComplexeNumber();
    ComplexeNumber(const ComplexeNumber& other);
    ~ComplexeNumber();

    void SetRealPart(double real);
    double GetRealPart();

    void SetImaginaryPart(double imaginary);
    double GetImaginaryPart();
};
}