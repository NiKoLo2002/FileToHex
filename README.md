# Arduino Tools & Utilities

This repository contains a set of modular libraries for Arduino projects, focusing on Command Line Interface (CLI) implementation and SD card file manipulation.

---

# 1. VORTEX CLI Framework

**VORTEX** - *Versatile Onboard Real Time EXecutor CLI*

VORTEX is a framework designed to bring responsive command-line execution to microcontrollers. It focuses on modularity to adapt to different memory constraints.

## 🔹 Acronym
**VORTEX** stands for:
**V**ersatile **O**nboard **R**eal **T**ime **EX**ecutor

---

## 🚀 Key Features (VORTEX_MICRO Core)

The core implementation, found in `vortex_micro`, is designed for extremely low RAM usage while providing essential CLI functionality:

* **Command Parsing:** Robust handling of user input and parsing of arguments into standard `argc`/`argv` format.
* **Basic Input Handling:** Supports `ENTER` to execute and `BACKSPACE` (`\b` or `\x7F`) to edit the line.
* **Help Command:** Built-in `help` command to list all registered user commands and their descriptions.
* **Low Overhead:** Optimized for microcontrollers with minimal RAM (e.g., ATmega328P).
* **Customizable Prompt:** Easily set the prompt string using `setPrompt()`.
* **ANSI Colors:** Uses simple ANSI escape codes for colored prompt and error messages.

## 🧩 VORTEX Modularity

The framework is structured into three versions to scale based on the target platform's resources:

| Model | Resource Focus | Core Features | Memory Usage |
| :--- | :--- | :--- | :--- |
| **VORTEX_MICRO** | Lowest RAM | Command Parsing (`argc`/`argv`), Basic Input, `help`. | Minimum |
| **VORTEX_LITE** | Balanced | *Placeholder for extended features (e.g., basic history).* | Low |
| **VORTEX_FULL** | Feature Rich | *Placeholder for advanced features (e.g., full history, auto-completion).* | High |

---

# 2. FileToHex Utility

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
