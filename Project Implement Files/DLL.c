#include <windows.h>

BOOL WINAPI
DllMain (HANDLE hDll, DWORD dwReason , LPVOID LpReserved){
    switch (dwReason){
        case DLL_PROCESS_ATTACH:
            MessageBox(NULL,// Owner)
            "Yew what up",//Message
            "Raiden", // Title
            MB_ICONERROR | MB_OK //Type
            );
        break;
    }
return TRUE;    
}