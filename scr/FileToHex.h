#ifndef FILE_TO_HEX_H
#define FILE_TO_HEX_H

#include <Arduino.h>
#include <SD.h>

class FileToHex {
public:
    // Converte un file binario della SD in un file TXT contenente HEX
    static bool convert(const char* inputPath, const char* outputPath);
};

#endif
