#include "timer.h"
#include "led.h"
void TIM3_Int_Init(u16 arr,u16 psc)
{
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
NVIC_InitTypeDef NVIC_InitStructure;
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟TIM3使能
//定时器TIM3初始化
TIM_TimeBaseStructure.TIM_Period = arr; //设置自动重装载寄存器周期的值
TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置时钟频率除数的预分频值
TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割
TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM 向上计数
TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //初始化 TIM3
TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //允许更新中断
//中断优先级 NVIC 设置
NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn; //TIM3 中断
NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //先占优先级 0 级
NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3; //从优先级 3 级
NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ 通道被使能
NVIC_Init(&NVIC_InitStructure); //初始化 NVIC 寄存器
TIM_Cmd(TIM3, ENABLE); //使能 TIM3
}
//定时器 3 中断服务程序
void TIM3_IRQHandler(void) //TIM3 中断
{
if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //检查 TIM3 更新中断发生与否
{
TIM_ClearITPendingBit(TIM3, TIM_IT_Update ); //清除 TIM3 更新中断标志
} 
}
