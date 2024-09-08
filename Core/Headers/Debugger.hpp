#ifndef DEBUGGER
#define DEBUGGER

#include <iostream>
#include <string>

enum DebugType{
    console,
    file,
};

class Debugger{
    private: 
    static inline std::string m_filePath = "";
    static inline DebugType m_currType = DebugType::console;
    static std::string GetTime();

    public :
    static void Debug(std::string info);
    static void SetDebugType(DebugType type);
    static void SetFilePath(std::string path);
    static void DebugOperation(const std::string& input1, const std::string& operation, const std::string& input2, const std::string& result);
};

#endif