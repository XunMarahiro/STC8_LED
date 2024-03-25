#include "main.h"

int main()
{
    gpio_config();
    while(1){
        LED_OFF();
        LED_ON();
    }
    return 0;
}