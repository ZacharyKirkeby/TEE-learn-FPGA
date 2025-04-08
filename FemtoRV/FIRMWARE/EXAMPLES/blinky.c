// blinky.c
#include <femtorv32.h>

int main() {
    while (1) {
      printf("hello world!\r\n");
      printf("Freq: %d MHz\r\n", FEMTORV32_FREQ);

      // Enable LEDs
      *(volatile uint32_t*)(0x400004) = 3;
      delay(500);

      // Turn them off

      *(volatile uint32_t*)(0x400004) = 0;

      delay(500);
   }
   return 0;
}

