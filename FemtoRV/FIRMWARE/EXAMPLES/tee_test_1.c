#include <femtorv32.h>

#define TEE_REGION_ADDR 0x301000

int main() {
	while (1) {
		printf("Hello TEE!\r\n");
		printf("Freq: %d MHz\r\n", FEMTORV32_FREQ);

		// Access TEE region
		*(volatile uint32_t*)(TEE_REGION_ADDR) = 1;
		printf("TEE access violation detected\r\n");

		delay(500);

		// Manually turn off the LED

		*(volatile uint32_t*)(0x400004) = 0;
		delay(500);
	}
	return 0;
}
