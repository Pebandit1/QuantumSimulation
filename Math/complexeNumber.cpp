#include "Headers/ComplexeNumber.hpp"
#include "../Core/Headers/Debugger.cpp"
#include <string>
#pragma once


inline void ComplexeNumber::SetImaginaryPart(double imaginary){
    Debugger::Debug("Changed imaginary part to " + std::to_string(imaginary));
    m_imaginaryPart = imaginary;
}

inline double ComplexeNumber::GetImaginaryPart(){return m_imaginaryPart;}

inline void ComplexeNumber::SetRealPart(double real){
    Debugger::Debug("Changed real part to " + std::to_string(real));
    m_realPart = real;
    }

inline double ComplexeNumber::GetRealPart() {return m_realPart;}

void ComplexeNumber::SetAll(double real, double imaginary){
    m_realPart  = real;
    m_imaginaryPart = imaginary;
}
    
ComplexeNumber::ComplexeNumber(double real, double imaginary){
    SetAll(real, imaginary);
    Debugger::Debug("Created new complexe number" + ToString());
}

ComplexeNumber::ComplexeNumber(const ComplexeNumber& other){
    SetAll(other.m_imaginaryPart, other.m_realPart);
    Debugger::Debug("Cloned complexe number" + ToString());
}

ComplexeNumber::~ComplexeNumber(){
    Debugger::Debug("Destroyed complexe number" + ToString());
}

std::string ComplexeNumber::ToString(){
    return std::to_string(m_realPart) + " + " + std::to_string(m_imaginaryPart) + " * i";
}