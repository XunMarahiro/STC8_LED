#include "main.h"
//GRB is the color direction

//int Fire1[3]={41,167,32};
//int Fire2[3]={45,255,81};
//int Fire3[3]={88,226,34};
//int Fire4[3]={76,190,90};
//int Fire5[3]={45,255,81};
int fire6[3]={0,0,0};
int Red[3]={47,164,47};
int PaleGodenrod[3]={232,238,170};
int Navy[3]={0,0,128};
int Green[3]={128,0,0};
int Gold[3]={215,255,0};
//int Coral[3]={69,255,0};


//int num=1;
int main()
{

    gpio_config();
    ws2812_Init();

    while(1) {
        WS2812_color(1,Red);
        WS2812_color(2,PaleGodenrod);
        WS2812_color(3,Gold);
        WS2812_color(4,Navy);
        WS2812_color(5,Green);
        WS2812_color(5,fire6);
    }
    return 0;
}