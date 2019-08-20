//arr：自动重装值。
//psc：时钟预分频数
int main(void)
{
  delay_init(); //延时函数初始化
  NVIC_Configuration(); //设置 NVIC 中断分组 2:2 位抢占优先级，2 位响应优先级
  uart_init(9600); //串口初始化波特率为 9600
  LED_Init(); //LED 端口初始化
  TIM3_Int_Init(4999,7199); //10Khz 的计数频率，计数到 5000 为 500ms
  while(1)
  {
   LED0=!LED0;
   delay_ms(200);
  }
}
Tout= ((arr+1)*(psc+1))/Tclk；
//Tclk：TIM3 的输入时钟频率（单位为 Mhz）。
//Tout：TIM3 溢出时间（单位为 us）。
