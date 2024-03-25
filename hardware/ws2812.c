//
// Created by XunMarahiro on 2024/3/25.
//
#include "ws2812.h"
#include "fw_hal.h"
//在这里处理GPIO的初始化函数和TIM定时器的初始化

void ws2812_Init(){
    GPIO_P3_SetMode(GPIO_Pin_6,GPIO_Mode_Output_PP);
    GPIO_SetPullUp(GPIO_Port_3,GPIO_Pin_6,1);

}
void up(){
    WS2812_DG=SET;
}
void down(){
    WS2812_DG=RESET;
}
void delay_300ns(){
    TCON=0x10;
    while((TL0+TH0<<8)<count_300ns);
    TCON=0x00;
    TL0=0;
    TH0=0;
}
void code_0(){
    up();
    delay_300ns();
    down();
    delay_300ns();
    delay_300ns();
}
void code_1(){
    up();
    delay_300ns();
    delay_300ns();
    down();
    delay_300ns();
    delay_300ns();
}
void code_reset(){
    down();
    delay_300ns();
}
void Send_8bit(int data){
    for(int i=0;i<8;i++){
        if(data&0x01){code_1();data>>1;}else{code_0();data>>1;}
    }
}
void send_color(int color[3]){
    for(int i=0;i<3;i++){
        Send_8bit(color[i]);
    }
}
void WS2812_color(int num,int color[3]){
    for (int i=0;i<num;i++){
        send_color(color);
    }
    code_reset();
}