#include <windows.h>
#include <stdio.h>

typedef void (*lr_input_device_set_func)(const uint32_t, const uint32_t);

int main() {
    // Carrega a DLL
    HINSTANCE dll = LoadLibrary("opera_libretro.dll");
    if (!dll) {
        printf("Failed to load DLL\n");
        return 1;
    }

    // Obtém o ponteiro para a função lr_input_device_set
    lr_input_device_set_func lr_input_device_set = (lr_input_device_set_func)GetProcAddress(dll, "lr_input_device_set");
    if (!lr_input_device_set) {
        printf("Function not found in DLL\n");
        FreeLibrary(dll);
        return 1;
    }

    // Chama a função para testar e ver a saída
    lr_input_device_set(0, 1);  // Passa os valores 0 e 1 para a função
    
    // Libera a DLL
    FreeLibrary(dll);
    return 0;
}
