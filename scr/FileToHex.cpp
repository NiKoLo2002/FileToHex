#include "FileToHex.h"

bool FileToHex::convert(const char* inputPath, const char* outputPath) {
    File inFile = SD.open(inputPath, FILE_READ);
    if (!inFile) {
        return false;  // file di input non trovato
    }

    File outFile = SD.open(outputPath, FILE_WRITE);
    if (!outFile) {
        inFile.close();
        return false;  // impossibile creare file di output
    }

    while (inFile.available()) {
        byte b = inFile.read();
        char hexStr[4];
        sprintf(hexStr, "%02X ", b);  // formato: "FF "
        outFile.print(hexStr);
    }

    inFile.close();
    outFile.close();
    return true;
}
