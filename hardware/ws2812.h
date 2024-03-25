//
// Created by XunMarahiro on 2024/3/25.
//

#ifndef WS2812_H
#define WS2812_H

#define WS2812_DG P35
#define sys_clock 12000000
#define count_1ns sys_clock/1000000
#define count_300ns count_1ns*300
//GRB is the color direction
void WS2812_color(int num,int color[3]);
void ws2812_Init();
#endif //SDCC_WS2812_H
