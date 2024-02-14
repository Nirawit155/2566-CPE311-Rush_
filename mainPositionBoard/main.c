#include "stm32l1xx.h"
#include "stm32l1xx_ll_gpio.h"
#include "stm32l1xx_ll_pwr.h"
#include "stm32l1xx_ll_rcc.h"
#include "stm32l1xx_ll_bus.h"
#include "stm32l1xx_ll_utils.h"
#include "stm32l1xx_ll_system.h"
#include "stm32l1xx_ll_usart.h"
#include "stm32l1xx_ll_exti.h"
#include "dwt_delay.h"
#include "stdio.h"
#include "string.h"
///////////////////////////////////////////////////////////////////////////
/***************************Create Funtion Zone***************************/
void SystemClock_Config(void);
void Gpio_Config(void);
void Usart_Config(void);
void Usart_SendString(uint8_t*, uint8_t);
void ShowPlayer(void);
void ShowMotel(void);
void WaitS(void);
void WaitD(void);
void WaitB(void);
void Move(void);
void Run(void);
/***************************Create Funtion Zone***************************/
//////////////////////////////////////////////////////////////////////////
/***************************Create Value Zone***************************/
struct Player{
  int Position;
};
int Motel[12] = 		{	0,0,0,
											0,0,0,
											0,0,0,
											0,0,0};
struct Player P[2] = {{1}, {1}};
uint8_t rec[10];
int dice = 7;
int Position;
int buy = 3; //0 = not buy, 1 = buy , 2 = nothing, 3 = wait
int status = 0;		// 0=stop , 1=playing , 2=Go RESET
int turn = 0; //0 = player1, 1 = player2
int idx=0;
int check =0;
char TxT_R[] = "R";
/***************************Create Value Zone***************************/
/////////////////////////////////////////////////////////////////////////
											
int main()
{
	/***************************config zone***************************/
	Gpio_Config();
	Usart_Config();
	/***************************Main Program zone***************************/
	while(1)
	{
		WaitS();
		Run();
	}
}

void Run(void)
{
	while(status != 2)
	{
		WaitD();
		Move();
		WaitB();
		turn++ ;
		turn%=2;
	}
}

void WaitB(void)
{
	check = 1;
	if(P[turn].Position != 1 && P[turn].Position != 5 && P[turn].Position != 9 && P[turn].Position != 13)
	{
		check = 2;
		while(buy == 3)
		{
			check = 3;
			ShowPlayer();
			ShowMotel();
			dice = 7;
		}
		
		if(P[turn].Position > 1 && P[turn].Position < 5)
			Position = P[turn].Position - 2;
		else if(P[turn].Position > 5 && P[turn].Position < 9)
			Position = P[turn].Position - 3;
		else if(P[turn].Position > 9 && P[turn].Position < 13)
			Position = P[turn].Position - 4;
		else if(P[turn].Position > 13)
			Position = P[turn].Position - 5;
		
		if(buy == 1)
			Motel[Position] = turn+1;
		buy = 3;
	}
}

void Move(void)
{
	for(; dice>0; dice--)
	{
		P[turn].Position++;
		if(P[turn].Position > 16)
			P[turn].Position %= 16;
		for(int x=0; x<580; x++)
		{
			ShowPlayer();
			ShowMotel();
		}
	}
	dice = 7;
	Usart_SendString(TxT_R, sizeof(TxT_R));
}

void WaitD(void)
{
	while(dice == 7)
	{
		ShowMotel();
		ShowPlayer();
		buy = 3;
	}
}

void WaitS(void)
{
	while(status != 2)
	{
		ShowPlayer();
		ShowMotel();
		dice = 7;
	}
	status = 1;
}

void ShowPlayer(void)
{
	LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_11);
	LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_12);
	
	if(P[0].Position == 1)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_4);
	else if(P[0].Position == 2)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5);
	else if(P[0].Position == 3)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_8);
	else if(P[0].Position == 4)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_9);
	else if(P[0].Position == 5)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_10);
	else if(P[0].Position == 6)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_11);
	else if(P[0].Position == 7)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_12);
	else if(P[0].Position == 8)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_15);
	else if(P[0].Position == 9)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_3);
	else if(P[0].Position == 10)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_4);
	else if(P[0].Position == 11)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	else if(P[0].Position == 12)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	else if(P[0].Position == 13)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_7);
	else if(P[0].Position == 14)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_8);
	else if(P[0].Position == 15)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_9);
	else if(P[0].Position == 16)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_10);
	DWT_Delay(100);
	
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_4);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_8);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_9);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_10);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_11);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_12);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_15);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_3);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_4);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_7);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_8);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_9);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_10);
	
	
	LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_11);
	LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_12);
	
	if(P[1].Position == 1)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_4);
	else if(P[1].Position == 2)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5);
	else if(P[1].Position == 3)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_8);
	else if(P[1].Position == 4)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_9);
	else if(P[1].Position == 5)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_10);
	else if(P[1].Position == 6)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_11);
	else if(P[1].Position == 7)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_12);
	else if(P[1].Position == 8)
		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_15);
	else if(P[1].Position == 9)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_3);
	else if(P[1].Position == 10)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_4);
	else if(P[1].Position == 11)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	else if(P[1].Position == 12)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	else if(P[1].Position == 13)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_7);
	else if(P[1].Position == 14)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_8);
	else if(P[1].Position == 15)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_9);
	else if(P[1].Position == 16)
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_10);
	DWT_Delay(100);
	
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_4);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_8);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_9);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_10);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_11);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_12);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_15);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_3);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_4);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_7);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_8);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_9);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_10);
	
}

void ShowMotel(void)
{
	for(int x=0;x<12;x++)
	{
		if(Motel[x] == 0)
		{
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_11);
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_12);
		}
		else if(Motel[x] == 1)
		{
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_11);
			LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_12);
		}
		else if(Motel[x] == 2)
		{
			LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_11);
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_12);
		}
		
		if(x == 0)
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_11);
		else if(x == 1)
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_12);
		else if(x == 2)
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_13);
		else if(x == 3)
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_14);
		else if(x == 4)
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_15);
		else if(x == 5)
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_0);
		else if(x == 6)
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_1);
		else if(x == 7)
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_2);
		else if(x == 8)
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_3);
		else if(x == 9)
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_6);
		else if(x == 10)
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_7);
		else if(x == 11)
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_8);
		DWT_Delay(100);
		
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_11);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_12);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_13);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_14);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_15);
			LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_0);
			LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_1);
			LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_2);
			LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_3);
			LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_6);
			LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_7);
			LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_8);
		
	}
}

void EXTI3_IRQHandler(void)
{
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_3) == SET)
	{
		rec[idx] = USART2->DR;
		if(rec[idx] >= '0' && rec[idx] < '7' )
			dice = rec[idx] - '0';
		else if(rec[idx] == 'S')
		{
			status = 2;
			for(int x=0;x<12;x++)
				Motel[x] = 0;
			P[0].Position = 1, P[1].Position = 1;
		}
		else if(rec[idx] == 'N')
			buy = 0;
		else if(rec[idx] == 'B')
			buy = 1;
		else if(rec[idx] == 'E')
			buy = 0;
		
		idx++;
		idx%=10;
		LL_USART_ClearFlag_IDLE(USART2);
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_3);
	}
}

void Usart_SendString(uint8_t* str, uint8_t size)
{
	uint8_t i = 0;
	while(i < size)
	{
		while(LL_USART_IsActiveFlag_TXE(USART2) == RESET);
		LL_USART_TransmitData8(USART2, str[i]);
		i++;
	}
}

void Gpio_Config(void)
{
	LL_GPIO_InitTypeDef GPIO_set;
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
	
	//Init ALL PIN for Usart
	GPIO_set.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_set.Pull = LL_GPIO_PULL_UP;
	GPIO_set.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_set.Mode = LL_GPIO_MODE_ALTERNATE;
	GPIO_set.Alternate = LL_GPIO_AF_7;
	GPIO_set.Pin = LL_GPIO_PIN_2 | LL_GPIO_PIN_3;
	LL_GPIO_Init(GPIOA, &GPIO_set);	
	
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
	LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTA, LL_EXTI_LINE_3);
	LL_EXTI_InitTypeDef PA_3;
	PA_3.Mode = LL_EXTI_MODE_IT;
	PA_3.LineCommand = ENABLE;
	PA_3.Line_0_31 = LL_EXTI_LINE_3;
	PA_3.Trigger = LL_EXTI_TRIGGER_RISING;
	LL_EXTI_Init(&PA_3);
	NVIC_EnableIRQ((IRQn_Type) 9);
	NVIC_SetPriority((IRQn_Type)9, 0);
	
	//Init ALL PIN for RGB
	GPIO_set.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_set.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_set.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_set.Pull = LL_GPIO_PULL_NO;
	GPIO_set.Pin = LL_GPIO_PIN_4 | LL_GPIO_PIN_5 | LL_GPIO_PIN_8 | LL_GPIO_PIN_9 | LL_GPIO_PIN_10 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12 | LL_GPIO_PIN_15;
	LL_GPIO_Init(GPIOA, &GPIO_set);
	GPIO_set.Pin = LL_GPIO_PIN_3 | LL_GPIO_PIN_4 | LL_GPIO_PIN_5 | LL_GPIO_PIN_6 | LL_GPIO_PIN_7 | LL_GPIO_PIN_8 | LL_GPIO_PIN_9 | LL_GPIO_PIN_10 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12 | LL_GPIO_PIN_13 | LL_GPIO_PIN_14 | LL_GPIO_PIN_15;
	LL_GPIO_Init(GPIOB, &GPIO_set);
	GPIO_set.Pin = LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_2 | LL_GPIO_PIN_3 | LL_GPIO_PIN_6 | LL_GPIO_PIN_7 | LL_GPIO_PIN_8 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12;
	LL_GPIO_Init(GPIOC, &GPIO_set); 
}

void Usart_Config(void)
{ 
	LL_USART_InitTypeDef usart_conf;
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_USART2);
	
	usart_conf.BaudRate = 9600;
  usart_conf.DataWidth = LL_USART_DATAWIDTH_8B;
	usart_conf.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
	usart_conf.Parity = LL_USART_PARITY_NONE;
	usart_conf.StopBits = LL_USART_STOPBITS_1;
	usart_conf.OverSampling = LL_USART_OVERSAMPLING_16;
	usart_conf.TransferDirection = LL_USART_DIRECTION_TX_RX;

	LL_USART_Init(USART2, &usart_conf);
	LL_USART_Enable(USART2);
}

void SystemClock_Config(void)
{
  /* Enable ACC64 access and set FLASH latency */ 
  LL_FLASH_Enable64bitAccess();; 
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_1);

  /* Set Voltage scale1 as MCU will run at 32MHz */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
  
  /* Poll VOSF bit of in PWR_CSR. Wait until it is reset to 0 */
  while (LL_PWR_IsActiveFlag_VOSF() != 0)
  {
  };
  
  /* Enable HSI if not already activated*/
  if (LL_RCC_HSI_IsReady() == 0)
  {
    /* HSI configuration and activation */
    LL_RCC_HSI_Enable();
    while(LL_RCC_HSI_IsReady() != 1)
    {
    };
  }
  
	
  /* Main PLL configuration and activation */
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSI, LL_RCC_PLL_MUL_6, LL_RCC_PLL_DIV_3);

  LL_RCC_PLL_Enable();
  while(LL_RCC_PLL_IsReady() != 1)
  {
  };
  
  /* Sysclk activation on the main PLL */
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {
  };
  
  /* Set APB1 & APB2 prescaler*/
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);

  /* Set systick to 1ms in using frequency set to 32MHz                             */
  /* This frequency can be calculated through LL RCC macro                          */
  /* ex: __LL_RCC_CALC_PLLCLK_FREQ (HSI_VALUE, LL_RCC_PLL_MUL_6, LL_RCC_PLL_DIV_3); */
  LL_Init1msTick(32000000);
  
  /* Update CMSIS variable (which can be updated also through SystemCoreClockUpdate function) */
  LL_SetSystemCoreClock(32000000);
}
