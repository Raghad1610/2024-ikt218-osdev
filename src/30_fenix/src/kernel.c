#include "libc/stdint.h"
#include "libc/stddef.h"
#include "libc/stdbool.h"
#include "libc/string.h"
#include <multiboot2.h>



struct multiboot_info {
    uint32_t size;
    uint32_t reserved;
    struct multiboot_tag *first;
};

int kernel_main();

int compute(int a, int b) {
    return a + b;
}

int main(uint32_t magic, struct multiboot_info* mb_info_addr) {
    char* hello_world = "Hello World!";
    size_t len = strlen(hello_world);
    
    //writing to the vid memory
    char* vid_memory = (char*)0xb8000;

    //write hello world to vid memory
    for(size_t i = 0; i < len; i++){
        vid_memory[i * 2] = hello_world[i];
        vid_memory[i * 2 + 1] = 0x07;
    }

    // Call cpp kernel_main (defined in kernel.cpp)
    return kernel_main();
}