#ifndef DEBUGGER
#define DEBUGGER
#endif

#include <iostream>
#include <string>
#pragma once

enum DebugType{
    console,
    file,
};

class Debugger{
    private: 
    //static std::string m_filePath;
    //static DebugType m_currType;

    public :
    static void Debug(std::string info){
        time_t timestamp = time(&timestamp);
        struct tm datetime = *localtime(&timestamp);
        std::string result =  "[" + std::to_string(datetime.tm_hour) + " : " + std::to_string(datetime.tm_min) + " : " + std::to_string(datetime.tm_sec) + " ] - " + info;

        //if(m_currType == console)
            std::cout<<result;
        //else{
            //Check if path is valide

            //Write to file
        //}
    }

    /*static void SetDebugType(DebugType type) {
        m_currType= type;
    }

    static void SetFilePath(std::string path){
        //Check if path valide

        //return
        //save path
        m_filePath = path;
    }
    */
};
