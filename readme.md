# Keylogger (Spyware)

This script uses a DLL file to capture and store keystrokes in the Txt file. Then Every 30-minute interval it uploads the the TXT file in the Discord Server using the API.

## Badges


![Static Badge](https://img.shields.io/badge/C17-%2300599d?label=C)
![Static Badge](https://img.shields.io/badge/8.7.1.0-aeb8d4?label=libcurl.dll)
![Static Badge](https://img.shields.io/badge/API-%237289da?label=Discord)









## Modificaion
```Batch Script
Main.c
DLL.c
```

## How to Use

#### Run program 

```EXE
calculator.exe
```
    
## Malware Structure

![App Screenshot](https://raw.githubusercontent.com/Ahad160/Codeing/main/Python%20Language/Projects/Project_19_Keylogger/Spyware%20Structure.png?raw=true)


## Full Walkthrough
First, it opens the calculator application then it loads the d3d11.dll. This DLL captures all store keystrokes, including mouse left and right clicks, and stores them in the TXT file. after that, every 30-minute interval it uses the libcurl-x64.dll to upload the TXT file in the Discord Channel using the Discord API.
## Features

- Captures Keystrokes And Mouse Clicks
- DLL Included
- Discord API
- No Console

## Authors

- [Raiden Ray](https://github.com/Ahad160)


##  🚀 About Me
Cyber Security Student 