#include "main.h"
//int red[3]={220,20,60};
//int blue[3]={0,0,255};
int main()
{
    int red[3]={220,20,60};
    gpio_config();
    ws2812_Init();
    while(1){
        WS2812_color(100,red);
    }
    return 0;
}