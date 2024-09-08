#ifndef COMPLEXE_NB
#define COMPLEXE_NB
#endif

#pragma once
#include <cstdint>
#include "../../Core/Headers/Writable.hpp"
#include <string>

class ComplexeNumber : public Writable
{
    private:
        double m_realPart; 
        double m_imaginaryPart;
        void SetAll(double real, double imaginary);
    public:
        ComplexeNumber();
        ComplexeNumber(double real, double imaginary);
        ComplexeNumber(const ComplexeNumber& other);
        ~ComplexeNumber();

        void SetRealPart(double real);
        double GetRealPart();

        void SetImaginaryPart(double imaginary);
        double GetImaginaryPart();

        virtual std::string ToString();
};
