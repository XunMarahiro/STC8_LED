//
// Created by XunMarahiro on 2024/3/25.
//
#include "ws2812.h"
#include "fw_hal.h"
//在这里处理GPIO的初始化函数和TIM定时器的初始化

void ws2812_Init(){
    GPIO_P5_SetMode(GPIO_Pin_5,GPIO_Mode_Output_PP);
    GPIO_SetPullUp(GPIO_Port_5,GPIO_Pin_5,1);

}
void up(){
    WS2812_DG=SET;
}
void down(){
    WS2812_DG=RESET;
}
//void delay_us(int s){
//    TCON=0x10;
//    while((TL0+TH0<<8)<s*count_100ns);
//    TCON=0x00;
//    TL0=0;
//    TH0=0;
//}
void code_0(){
    WS2812_DG=SET;
    NOP();NOP();
    WS2812_DG=RESET;
    SYS_DelayUs(50);
}
void code_1(){
    WS2812_DG=SET;
    SYS_DelayUs(50);
    WS2812_DG=RESET;
    SYS_DelayUs(50);
}
void code_reset(){
    WS2812_DG=RESET;
    SYS_DelayUs(500);
    SYS_Delay(2500);
}
void Send_8bit(int data){
    for(int i=0;i<8;i++){
        if((data&0x80)==0x80){code_1();data<<1;}else{code_0();data<<1;}
    }
}
void send_color(int color[3]){
    Send_8bit(color[0]);
    Send_8bit(color[1]);
    Send_8bit(color[2]);

}
void WS2812_color(int num,int color[3]){
    for (int i=0;i<num;i++){
        send_color(color);
    }
    code_reset();
}