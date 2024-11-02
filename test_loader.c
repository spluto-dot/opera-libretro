#include <windows.h>
#include <stdio.h>

typedef void (*lr_input_device_set_func)(const uint32_t, const uint32_t);

int main() {
    HINSTANCE dll = LoadLibrary("opera_libretro.dll");
    if (!dll) {
        printf("Failed to load DLL\n");
        return 1;
    }

    lr_input_device_set_func lr_input_device_set = (lr_input_device_set_func)GetProcAddress(dll, "lr_input_device_set");
    if (!lr_input_device_set) {
        printf("Function not found in DLL\n");
        FreeLibrary(dll);
        return 1;
    }

    lr_input_device_set(0, 1);  // Teste da função
    FreeLibrary(dll);
    return 0;
}
