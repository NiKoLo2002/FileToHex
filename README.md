# Arduino Tools & Utilities
FileToHex Utility

**FileToHex** is a simple, static utility class designed to convert any binary file stored on an SD card into a text file containing the file's hexadecimal representation.

## ✨ Utility Features

* **Binary to Hex Conversion:** Converts raw binary data (e.g., firmware, images, videos) into human-readable, space-separated hexadecimal strings.
* **SD Card Integration:** Requires the standard **SD.h** library to read the input file and write the output file directly to the SD card.
* **Static Method:** Easy to use without needing to instantiate an object (`FileToHex::convert(...)`).
* **Output Format:** Each byte is formatted as two uppercase hexadecimal characters, followed by a space (e.g., `"0A FF 1B 00..."`).

## 💡 Usage Example (`EXAMPLE.cpp`)

To use this utility, you must include the necessary headers and initialize the SD card in `setup()`.

```cpp
#include <SPI.h>
#include <SD.h>
#include "FileToHex.h"

void setup() {
    Serial.begin(115200);

    if (!SD.begin(10)) {  // CS Pin
        Serial.println("SD initialization error");
        return;
    }

    Serial.println("Converting file...");

    // Converts a file named "video.mp4" on the SD card 
    // into a text file named "video_hex.txt"
    if (FileToHex::convert("video.mp4", "video_hex.txt")) {
        Serial.println("Conversion completed successfully!");
    } 
    else {
        Serial.println("Error during conversion.");
    }
}

void loop() {}
