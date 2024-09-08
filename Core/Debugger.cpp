#pragma once
#include "Headers/Debugger.hpp"


std::string Debugger::GetTime(){
    time_t timestamp = time(&timestamp);
    struct tm datetime = *localtime(&timestamp);
   return "[" + std::to_string(datetime.tm_hour) + " : " + std::to_string(datetime.tm_min) + " : " + std::to_string(datetime.tm_sec) + " ] - ";
}

void Debugger::Debug(std::string info){
    std::string result = GetTime() +  info + "\r\n";

    if(m_currType == console)
        std::cout<<result;
    else{
        //Check if path is valide

        //Write to file
    }
}

void Debugger::SetDebugType(DebugType type) {
    m_currType= type;
}

void Debugger::SetFilePath(std::string path){
    //Check if path valide

    //return
    //save path
    m_filePath = path;
}

void Debugger::DebugOperation(const std::string& input1, const std::string& operation, const std::string& input2, const std::string& result){
    Debug(input1 + " " + operation + " " + input2 + " = " + result);
}