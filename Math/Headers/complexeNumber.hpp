#ifndef COMPLEXE_NB
#define COMPLEXE_NB
#include <cstdint>
#include "../../Core/Headers/Writable.hpp"
#include <string>

class ComplexeNumber : public Writable
{
    private:
        #pragma region Attributes

        double m_realPart; 
        double m_imaginaryPart;

        #pragma endregion

    public:

        #pragma region Constructor and destructor

        ComplexeNumber();
        ComplexeNumber(double real, double imaginary);
        ComplexeNumber(const ComplexeNumber& other);
        ~ComplexeNumber();

        #pragma endregion

        #pragma region Getters and setters

        void SetAll(double real, double imaginary);

        void SetRealPart(double real);
        double GetRealPart() const;

        void SetImaginaryPart(double imaginary);
        double GetImaginaryPart() const;

        double GetMagnitude() const;
        double GetAngle() const;

        const ComplexeNumber GetConjugate() const;

        #pragma endregion

        #pragma region operators

        ComplexeNumber& operator =(const ComplexeNumber& other);
        ComplexeNumber& operator+=(const ComplexeNumber& other);
        const ComplexeNumber operator +(const ComplexeNumber& other)const;
        ComplexeNumber& operator+=(const double& other);
        const ComplexeNumber operator +(const double& other)const;
        ComplexeNumber& operator-=(const ComplexeNumber& other);
        const ComplexeNumber operator -(const ComplexeNumber& other)const;
        ComplexeNumber& operator-=(const double& other);
        const ComplexeNumber operator -(const double& other)const;
        ComplexeNumber& operator*=(const ComplexeNumber& other);
        const ComplexeNumber operator *(const ComplexeNumber& other)const;
        ComplexeNumber& operator*=(const double& other);
        const ComplexeNumber operator *(const double& other)const;
        ComplexeNumber& operator/=(const ComplexeNumber& other);
        const ComplexeNumber operator /(const ComplexeNumber& other)const;
        ComplexeNumber& operator/=(const double& other);
        const ComplexeNumber operator /(const double& other)const;

        #pragma endregion

        #pragma region Writable

        virtual std::string ToString()const;

        #pragma endregion
};

#endif