#include "Headers/complexeNumber.hpp"
#include <iostream>


using namespace Math::Headers;

namespace Math{

    inline void ComplexeNumber::SetImaginaryPart(double imaginary){m_imaginaryPart = imaginary;}

    inline double ComplexeNumber::GetImaginaryPart(){return m_imaginaryPart;}

    inline void ComplexeNumber::SetRealPart(double real){m_realPart = real;}

    inline double ComplexeNumber::GetRealPart() {return m_realPart;}

    void ComplexeNumber::SetAll(double real, double imaginary){
        SetRealPart(real);
        SetImaginaryPart(imaginary);
    }
    
    ComplexeNumber::ComplexeNumber(double real, double imaginary){
        SetAll(real, imaginary);
    }

    ComplexeNumber::ComplexeNumber(const ComplexeNumber& other){
        SetAll(other.m_imaginaryPart, other.m_realPart);
    }

    
}