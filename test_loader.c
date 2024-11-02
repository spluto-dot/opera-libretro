#include <stdio.h>
#include <windows.h>
#include <stdint.h>

typedef void (*lr_input_device_set_func)(const uint32_t, const uint32_t);

int main() {
    HINSTANCE dll = LoadLibrary("opera_libretro.dll");
    if (!dll) {
        printf("Failed to load DLL\n");
        return 1;
    }

    lr_input_device_set_func lr_input_device_set = 
        (lr_input_device_set_func)GetProcAddress(dll, "lr_input_device_set");
    
    if (!lr_input_device_set) {
        printf("Function 'lr_input_device_set' not found in DLL\n");
        FreeLibrary(dll);
        return 1;
    }

    // Chamada da função com valores de teste e confirmação visual
    printf("Calling 'lr_input_device_set' with port = 1, device = 1\n");
    lr_input_device_set(1, 1);
    printf("Function 'lr_input_device_set' called successfully\n");

    FreeLibrary(dll);
    return 0;
}
