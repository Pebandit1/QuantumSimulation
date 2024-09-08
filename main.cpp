#include <iostream>
#include <string>
#include "Core/Debugger.cpp"
#include "Math/complexeNumber.cpp"

int main()
{
    Debugger::SetDebugType(DebugType::console);
    Debugger::Debug("Start of the execution");

    ComplexeNumber a(.3,-.45);
    ComplexeNumber b(.34,.005);
    ComplexeNumber c = a + b;
    return 0;
}