#include <debug.h>
#include <ch32v00x.h>
int xor(int bit1, int bit2) {
    return bit1 ^ bit2;
}
void GPIO_Config(void) {
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); // Enable the clock for port D
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); // Enable the clock for port C
    
    // Input Pins Configuration
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // Input Type with pull-up
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    // Output Pin Configuration
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // Output Type
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Speed
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}
int main() {
    uint8_t bit1, bit2, bit3, bit4, parity;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SystemCoreClockUpdate();
    Delay_Init();
    GPIO_Config();

    while (1) {
        // Read the input values
        bit1 = GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_1);
        bit2 = GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_2);
        bit3 = GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_3);
        bit4 = GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_4);
        
        // Odd Parity Logic
        parity = xor(xor(bit1, bit2), xor(bit3, bit4)); // XOR all bits together
        
        // Write the Parity output
        if (parity == 1) {
            GPIO_WriteBit(GPIOC, GPIO_Pin_5, SET); // LED on for Odd Parity
        } else {
            GPIO_WriteBit(GPIOC, GPIO_Pin_5, RESET); // LED off for Even Parity
        }
    }
}
