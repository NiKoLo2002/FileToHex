#include <SPI.h>
#include <SD.h>
#include "FileToHex.h"

void setup() {
    Serial.begin(115200);

    if (!SD.begin(10)) {  // Pin CS
        Serial.println("Errore inizializzazione SD");
        return;
    }

    Serial.println("Converto file...");

    // Converte un file qualsiasi presente sulla SD
    if (FileToHex::convert("video.mp4", "video_hex.txt")) {
        Serial.println("Conversione completata!");
    } 
    else {
        Serial.println("Errore nella conversione.");
    }
}

void loop() {}
