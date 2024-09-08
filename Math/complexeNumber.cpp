#include "Headers/ComplexeNumber.hpp"
#include "../Core/Debugger.cpp"
#include <string>
#include <math.h>
#pragma once

#pragma region Constructors and destructors

ComplexeNumber::ComplexeNumber() : m_realPart(0), m_imaginaryPart(0){
    Debugger::Debug("Created new complexe number " + ToString());
}

ComplexeNumber::ComplexeNumber(double real, double imaginary){
    SetAll(real, imaginary);
    Debugger::Debug("Created new complexe number " + ToString());
}

ComplexeNumber::ComplexeNumber(const ComplexeNumber& other){
    (*this) = other;
}

ComplexeNumber::~ComplexeNumber(){
    Debugger::Debug("Destroyed complexe number " + ToString());
}

#pragma endregion

#pragma region Getters and setters

void ComplexeNumber::SetAll(double real, double imaginary){
    m_realPart  = real;
    m_imaginaryPart = imaginary;
}

inline void ComplexeNumber::SetRealPart(double real){
    Debugger::Debug("Changed real part to " + std::to_string(real));
    m_realPart = real;
}

inline double ComplexeNumber::GetRealPart() const{
    return m_realPart;
}

inline void ComplexeNumber::SetImaginaryPart(double imaginary){
    Debugger::Debug("Changed imaginary part to " + std::to_string(imaginary));
    m_imaginaryPart = imaginary;
}

inline double ComplexeNumber::GetImaginaryPart() const{
    return m_imaginaryPart;
}

inline double ComplexeNumber::GetMagnitude() const{
    return std::sqrt(m_realPart * m_realPart + m_imaginaryPart * m_imaginaryPart);
}

inline double ComplexeNumber::GetAngle() const{
    double angle = std::acos(m_realPart / GetMagnitude());
    return m_imaginaryPart < 0 ? -angle : angle;
}

inline const ComplexeNumber ComplexeNumber::GetConjugate() const{
    return ComplexeNumber(m_realPart, -m_imaginaryPart);
}

#pragma endregion

#pragma region Writable

std::string ComplexeNumber::ToString() const{
    return "( " + std::to_string(m_realPart) + " + " + std::to_string(m_imaginaryPart) + " * i" + " )";
}

#pragma endregion

#pragma region Operators

ComplexeNumber& ComplexeNumber::operator=(const ComplexeNumber& other){
    SetAll(other.m_imaginaryPart, other.m_realPart);
    Debugger::Debug("Cloned complexe number " + ToString());
    return *this;
}


ComplexeNumber& ComplexeNumber::operator+=(const ComplexeNumber&other){
    std::string oldValue = ToString();
    m_realPart += other.m_realPart;
    m_imaginaryPart += other.m_imaginaryPart;
    Debugger::DebugOperation(oldValue, "+", other.ToString(), ToString());
    return *this;
}

const ComplexeNumber ComplexeNumber::operator+(const ComplexeNumber& other) const{
    return ComplexeNumber(*this) +=other;
}

ComplexeNumber& ComplexeNumber::operator+=(const double& other){
    std::string oldValue = ToString();
    m_realPart += other;
    Debugger::DebugOperation(oldValue, "+", std::to_string(other), ToString());
    return *this;
}

const ComplexeNumber ComplexeNumber::operator+(const double& other) const{
    return ComplexeNumber(*this) += other;
}

ComplexeNumber& ComplexeNumber::operator-=(const ComplexeNumber&other){
    std::string oldValue = ToString();
    m_realPart -= other.m_realPart;
    m_imaginaryPart -= other.m_imaginaryPart;
    Debugger::DebugOperation(oldValue, "-", other.ToString(), ToString());
    return *this;
}

const ComplexeNumber ComplexeNumber::operator-(const ComplexeNumber& other) const{
    return ComplexeNumber(*this) -= other;
}

ComplexeNumber& ComplexeNumber::operator-=(const double& other){
    std::string oldValue = ToString();
    m_realPart -= other;
    Debugger::DebugOperation(oldValue, "-", std::to_string(other), ToString());
    return *this;
}

const ComplexeNumber ComplexeNumber::operator-(const double& other) const{
    return ComplexeNumber(*this) -= other;
}

ComplexeNumber& ComplexeNumber::operator*=(const ComplexeNumber&other){
    std::string oldValue = ToString();
    double newReal = m_realPart * other.m_realPart - m_imaginaryPart * other.m_imaginaryPart;
    double newImaginary = m_realPart * other.m_imaginaryPart + m_imaginaryPart * other.m_realPart;
    m_realPart = newReal;
    m_imaginaryPart = newImaginary;
    Debugger::DebugOperation(oldValue, "*", other.ToString(), ToString());
    return *this;
}

const ComplexeNumber ComplexeNumber::operator*(const ComplexeNumber& other) const{
    return ComplexeNumber(*this) *= other;
}

ComplexeNumber& ComplexeNumber::operator*=(const double& other){
    std::string oldValue = ToString();
    m_realPart *= other;
    m_imaginaryPart *= other;
    Debugger::DebugOperation(oldValue, "*", std::to_string(other), ToString());
    return *this;
}

const ComplexeNumber ComplexeNumber::operator*(const double& other) const{
    return ComplexeNumber(*this) *= other;
}

ComplexeNumber& ComplexeNumber::operator/=(const ComplexeNumber&other){
    std::string oldValue = ToString();
    double newReal = m_realPart * other.m_realPart + m_imaginaryPart * other.m_imaginaryPart;
    double newImaginary = m_imaginaryPart * other.m_realPart - m_realPart * other.m_imaginaryPart;
    double otherMag = other.GetMagnitude();
    m_realPart = newReal / otherMag;
    m_imaginaryPart = newImaginary / otherMag;
    Debugger::DebugOperation(oldValue, "/", other.ToString(), ToString());
    return *this;
}

const ComplexeNumber ComplexeNumber::operator/(const ComplexeNumber& other) const{
    return ComplexeNumber(*this) /= other;
}

ComplexeNumber& ComplexeNumber::operator/=(const double& other){
    std::string oldValue = ToString();
    m_realPart /= other;
    m_imaginaryPart /= other;
    Debugger::DebugOperation(oldValue, "/", std::to_string(other), ToString());
    return *this;
}

const ComplexeNumber ComplexeNumber::operator/(const double& other) const{
    return ComplexeNumber(*this) /= other;
}

#pragma endregion