#include "stm32l1xx.h"
#include "stm32l1xx_ll_system.h"
#include "stm32l1xx_ll_bus.h"
#include "stm32l1xx_ll_utils.h"
#include "stm32l1xx_ll_rcc.h"
#include "stm32l1xx_ll_pwr.h"
#include "stm32l1xx_ll_gpio.h"
#include "stm32l1xx_ll_tim.h"
#include "stm32l1xx_ll_exti.h"
#include "stm32l1xx_ll_usart.h"
#include "stdio.h"
#include "stdlib.h"

///////////////////////////////////////////////////////////////////////////
/***************************Create Type value Zone***************************/
struct Player{
  int Money, Position, Status;
};
struct Motel{
  int Owner, Cost, Rent;
};
/***************************Create Type value Zone***************************/
///////////////////////////////////////////////////////////////////////////
/***************************Create Funtion Zone***************************/
void SystemClock_Config(void);
void Gpio_Config(void);
void Usart_Config(void);
void Show_Money(int P1, int P2);
void Dice(int Player);
void BuyOrNot(int Player);
void Usart_SendString(uint8_t*, uint8_t);
void WaitReady(void);
void GameRun(int Player);
void Run(void);
void WaitS(void);
/***************************Create Funtion Zone***************************/
///////////////////////////////////////////////////////////////////////////
/***************************Create Value Zone***************************/
uint32_t seg1[10] = {
	LL_GPIO_PIN_2 | LL_GPIO_PIN_10 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12 | LL_GPIO_PIN_13 |LL_GPIO_PIN_14,									//0
	LL_GPIO_PIN_10 | LL_GPIO_PIN_11, 																																										//1
	LL_GPIO_PIN_2 | LL_GPIO_PIN_10 | LL_GPIO_PIN_15 | LL_GPIO_PIN_13 | LL_GPIO_PIN_12, 																	//2
	LL_GPIO_PIN_2 | LL_GPIO_PIN_10 | LL_GPIO_PIN_15 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12, 																	//3
	LL_GPIO_PIN_14 | LL_GPIO_PIN_15 | LL_GPIO_PIN_10 | LL_GPIO_PIN_11,																									//4
	LL_GPIO_PIN_2 | LL_GPIO_PIN_14 | LL_GPIO_PIN_15 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12, 																	//5
	LL_GPIO_PIN_2 | LL_GPIO_PIN_14 | LL_GPIO_PIN_15 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12 | LL_GPIO_PIN_13,									//6
	LL_GPIO_PIN_2 | LL_GPIO_PIN_10 | LL_GPIO_PIN_11,																																		//7
	LL_GPIO_PIN_2 | LL_GPIO_PIN_10 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12 | LL_GPIO_PIN_13 |LL_GPIO_PIN_14 | LL_GPIO_PIN_15, //8
	LL_GPIO_PIN_2 | LL_GPIO_PIN_10 | LL_GPIO_PIN_15 | LL_GPIO_PIN_14 | LL_GPIO_PIN_11, 																	//9
};
uint32_t dig1[4] = {LL_GPIO_PIN_0, LL_GPIO_PIN_1, LL_GPIO_PIN_2, LL_GPIO_PIN_3};
uint32_t seg2[10] = {
	LL_GPIO_PIN_10 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8 | LL_GPIO_PIN_7 , 								//0
	LL_GPIO_PIN_9 | LL_GPIO_PIN_8 , 																																								//1
	LL_GPIO_PIN_10 | LL_GPIO_PIN_9 | LL_GPIO_PIN_6 | LL_GPIO_PIN_8 | LL_GPIO_PIN_7 , 																//2
	LL_GPIO_PIN_10 | LL_GPIO_PIN_9 | LL_GPIO_PIN_6 | LL_GPIO_PIN_8 | LL_GPIO_PIN_7 , 																//3
	LL_GPIO_PIN_7 | LL_GPIO_PIN_6 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8, 																									//4
	LL_GPIO_PIN_10 | LL_GPIO_PIN_7 | LL_GPIO_PIN_6 | LL_GPIO_PIN_8 | LL_GPIO_PIN_9, 																//5
	LL_GPIO_PIN_10 | LL_GPIO_PIN_7 | LL_GPIO_PIN_6 | LL_GPIO_PIN_8 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8 , 								//6
	LL_GPIO_PIN_10 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8 , 																																//7
	LL_GPIO_PIN_10 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8 | LL_GPIO_PIN_7 | LL_GPIO_PIN_6 ,//8
	LL_GPIO_PIN_10 | LL_GPIO_PIN_9 | LL_GPIO_PIN_6 | LL_GPIO_PIN_7 | LL_GPIO_PIN_8 , 																//9
};
uint32_t dig2[4] = {LL_GPIO_PIN_2, LL_GPIO_PIN_12, LL_GPIO_PIN_11, LL_GPIO_PIN_10};
char Num1[4], Num2[4];
int Dice_count, random, idx, Position, r = 0;
int status=0, turn = 1;
int yy=0;
char TxT_S[] = "S";		//Start
uint8_t TxT_D[] = "x";		//Dice x
uint8_t TxT_Y[] = "B";		//Yes
uint8_t TxT_N[] = "N";		//No
uint8_t TxT_E[] = "E";		//Can't buy
uint8_t TxT_OVER[] = "O";	//Game over
uint8_t rec[10];
struct Motel M[12] = {{0, 100, 20}, {0, 200, 60}, {0, 150, 40}, 
											{0, 120, 30}, {0, 250, 80}, {0, 130, 30},  
											{0, 110, 20}, {0, 300, 100},{0, 140, 40},  
											{0, 160, 50}, {0, 220, 70}, {0, 180, 50}
};
struct Player P[2] = {{100, 1, 0}, {100, 1, 0}};
/***************************Create Value Zone***************************/
////////////////////////////////////////////////////////////////////////
/***************************Main***************************/

int main(void)
{
	rec;
  SystemClock_Config();
	Gpio_Config();
	Usart_Config();
	Usart_SendString(TxT_S, sizeof(TxT_S)); 	//Restart
	while(1)
	{
			
			Run();
		
	}
}
/***************************Main***************************/
//////////////////////////////////////////////////////////////////////////
/***************************Edit Funtion Zone***************************/

void Run()
{
	while(1)
	{
		turn=1;
		status=2;
		Dice(1); //Dice player 1
		status=3;
		WaitReady();
		status=4;
		GameRun(1);
		
		turn=2;
		Dice(2); //Dice player 2
		WaitReady();
		GameRun(2);
		
		if(P[0].Money < 0 || P[1].Money < 0)
		{
			Usart_SendString(TxT_OVER, sizeof(TxT_OVER));
			break;
		}
	}
}

void GameRun(int Player)
{
	if(P[Player-1].Position > 1 && P[Player-1].Position < 5)
		Position = P[Player-1].Position - 2;
	else if(P[Player-1].Position > 5 && P[Player-1].Position < 9)
		Position = P[Player-1].Position - 3;
	else if(P[Player-1].Position > 9 && P[Player-1].Position < 13)
		Position = P[Player-1].Position - 4;
	else if(P[Player-1].Position > 13)
		Position = P[Player-1].Position - 5;
	
	if(P[Player-1].Position == 1)
	{
		Usart_SendString(TxT_E, sizeof(TxT_E));
		P[Player-1].Money += 300;
	}
	else if(P[Player-1].Position == 5)
	{
		Usart_SendString(TxT_E, sizeof(TxT_E));
		P[Player-1].Status = 1;
	}
	else if(P[Player-1].Position == 9)
	{
		random = (rand()%6);
		if(random == 0)
			P[Player-1].Money -= 40;
		else if(random == 1)
			P[Player-1].Money -= 20;
		else if(random == 2)
			P[Player-1].Money += 20;
		else if(random == 3)
			P[Player-1].Money += 40;
		else if(random == 4)
			P[Player-1].Money += 60;
		else if(random == 5)
			P[Player-1].Money += 80;
		Usart_SendString(TxT_E, sizeof(TxT_E));
	}
	else if(P[Player-1].Position == 13)
	{
		Usart_SendString(TxT_E, sizeof(TxT_E));
		P[Player-1].Money = P[Player-1].Money * 10 / 9;
	}
	else if(M[Position].Owner == 0)
		BuyOrNot(Player);
	else if(M[Position].Owner == Player)
	{
		Usart_SendString(TxT_E, sizeof(TxT_E));
		P[Player-1].Money = P[Player-1].Money;
	}
	else if(M[Position].Owner != Player)
	{
		Usart_SendString(TxT_E, sizeof(TxT_E));
		P[Player-1].Money -= M[Position].Rent;
	}
}

void BuyOrNot(int Player)
{
	if(P[Player-1].Position > 1 && P[Player-1].Position < 5)
		Position = P[Player-1].Position - 2;
	else if(P[Player-1].Position > 5 && P[Player-1].Position < 9)
		Position = P[Player-1].Position - 3;
	else if(P[Player-1].Position > 9 && P[Player-1].Position < 13)
		Position = P[Player-1].Position - 4;
	else if(P[Player-1].Position > 13)
		Position = P[Player-1].Position - 5;
	
	while(1)
	{
		if(Player == 1)
		{
			if(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_1) == SET && P[Player-1].Money >= M[Position].Cost)
			{
				while(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_1) == SET);
				M[Position].Owner = Player;
				P[Player-1].Money -= M[Position].Cost;
				Usart_SendString(TxT_Y, sizeof(TxT_Y));
				break;
			}
			else if(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_0) == SET)
			{
				while(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_0) == SET);
				Usart_SendString(TxT_N, sizeof(TxT_N));
				break;
			}
		}
		if(Player == 2)
		{
			if(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_5) == SET && P[Player-1].Money >= M[Position].Cost)
			{
				while(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_5) == SET);
				M[Position].Owner = Player;
				P[Player-1].Money -= M[Position].Cost;
				Usart_SendString(TxT_Y, sizeof(TxT_Y));
				break;
			}
			else if(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_11) == SET)
			{
				while(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_11) == SET);
				Usart_SendString(TxT_N, sizeof(TxT_N));
				break;
			}
		}
		Show_Money(P[0].Money, P[1].Money);
	}
}

void WaitReady(void)
{
	while(1)
	{
		Show_Money(P[0].Money, P[1].Money);
		if(r == 1)
			break;
	}
	r = 0;
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

void Dice(int Player)
{
	status=3;
	Dice_count = 0;
	if(P[Player-1].Status == 1)
	{
		while(1)
		{
			if(Player == 1)
			{
				if(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_1) == SET && P[Player-1].Money >= 50)
				{
					while(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_1) == SET);
					P[Player-1].Money -= 50;
					P[Player-1].Status = 0;
					break;
				}
				else if(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_0) == SET)
				{
					while(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_0) == SET);
					break;
				}
			}
			else if(Player == 2)
			{
				if(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_5) == SET && P[Player-1].Money >= 50)
				{
					while(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_5) == SET);
					P[Player-1].Money -= 50;
					P[Player-1].Status = 0;
					break;
				}
				else if(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_11) == SET)
				{
					while(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_11) == SET);
					break;
				}
			}
		}
	}
	status=4;
	while(Dice_count < 6)
	{
		status=5;
		if((LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_0) == SET || LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_1) == SET) && Player == 1)
			Dice_count = 1;
		if((LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_11) == SET || LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_5) == SET) && turn == 2)
			Dice_count = 1;
		random = (rand()%6)+1 ;
		if(random == 1)
		{
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_3);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_4);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_7);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_8);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_9);
		}
		else if(random == 2)
		{
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_3);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_4);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_7);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_8);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_9);
		}
		else if(random == 3)
		{
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_3);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_4);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_7);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_8);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_9);
		}
		else if(random == 4)
		{
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_3);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_4);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_7);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_8);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_9);
		}
		else if(random == 5)
		{
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_3);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_4);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_7);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_8);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_9);
		}
		else if(random == 6)
		{
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_3);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_4);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_7);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_8);
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_9);
		}

		if(Dice_count != 0)
			Dice_count++;

		for(int x=0; x<(150+(Dice_count*150))/4; x++)
		{
			Show_Money(P[0].Money, P[1].Money);
		}
		//LL_mDelay(150 + Dice_count*150);
	}
	
	
		if(P[Player-1].Status == 0)
		{
			P[Player-1].Position += random;
			if(P[Player-1].Position > 16){
				P[Player-1].Position %= 16;
				P[Player-1].Money += 300;
			}
			TxT_D[0] = '0'+random;
			Usart_SendString(TxT_D, sizeof(TxT_D));
		}
		else if(P[Player-1].Status == 1)
		{
			if(random >=  4)
			{
				P[Player-1].Status = 0;
				P[Player-1].Position += random;
				if(P[Player-1].Position > 16){
					P[Player-1].Position %= 16;
					P[Player-1].Money += 300;
				}
				TxT_D[0] = '0'+random;
				Usart_SendString(TxT_D, sizeof(TxT_D));
			}
			else
			{
				TxT_D[0] = '0';
				Usart_SendString(TxT_D, sizeof(TxT_D));
			}
		}
	
	yy=1;
}

void Show_Money(int P1, int P2)
{
	sprintf(Num1,"%04d",P1);
	sprintf(Num2,"%04d",P2);
	
	for(int i=0; i<4; i++)
	{
												//7 Segment 1 Zone
		
			//Reset
		LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_2 | LL_GPIO_PIN_3);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_2 | LL_GPIO_PIN_10 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12 | LL_GPIO_PIN_13 | LL_GPIO_PIN_14 | LL_GPIO_PIN_15);
			//End Reset
			//Show
		LL_GPIO_SetOutputPin(GPIOB, seg1[(int)(Num1[i]-'0')]);
		
		LL_GPIO_SetOutputPin(GPIOC, dig1[i]);
			//End Show
		
												//7 Segment 2 Zone
		
			//Reset
		LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_2);
		LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_12 | LL_GPIO_PIN_11 | LL_GPIO_PIN_10 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8 | LL_GPIO_PIN_7 | LL_GPIO_PIN_6);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_10 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8);
			//End Reset
			//Show
		if( (int)(Num2[i]-'0') == 1 || (int)(Num2[i]-'0') == 7)
			LL_GPIO_SetOutputPin(GPIOA, seg2[(int)Num2[i]-'0']);
		else if( (int)(Num2[i]-'0') == 0)
		{
			LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_10 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8);
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_9 | LL_GPIO_PIN_8 | LL_GPIO_PIN_7);
		}
		else if( (int)(Num2[i]-'0') == 2)
		{
			LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_10 | LL_GPIO_PIN_9);
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_9 | LL_GPIO_PIN_8 | LL_GPIO_PIN_6);
		}
		else if( (int)(Num2[i]-'0') == 3)
		{
			LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_10 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8);
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_9 | LL_GPIO_PIN_6);
		}
		else if( (int)(Num2[i]-'0') == 4)
		{
			LL_GPIO_SetOutputPin(GPIOA,	LL_GPIO_PIN_9 | LL_GPIO_PIN_8);
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_7 | LL_GPIO_PIN_6);
		}
		else if( (int)(Num2[i]-'0') == 5)
		{
			LL_GPIO_SetOutputPin(GPIOA,	LL_GPIO_PIN_10 | LL_GPIO_PIN_8);
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_9 | LL_GPIO_PIN_7 | LL_GPIO_PIN_6);
		}
		else if( (int)(Num2[i]-'0') == 6)
		{
			LL_GPIO_SetOutputPin(GPIOA,	LL_GPIO_PIN_10 | LL_GPIO_PIN_8);
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_9 | LL_GPIO_PIN_8 | LL_GPIO_PIN_7 | LL_GPIO_PIN_6);
		}
		else if( (int)(Num2[i]-'0') == 8)
		{
			LL_GPIO_SetOutputPin(GPIOA,	LL_GPIO_PIN_10 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8);
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_9 | LL_GPIO_PIN_8 | LL_GPIO_PIN_7 | LL_GPIO_PIN_6);
		}
		else if( (int)(Num2[i]-'0') == 9)
		{
			LL_GPIO_SetOutputPin(GPIOA,	LL_GPIO_PIN_10 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8);
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_9 | LL_GPIO_PIN_7 | LL_GPIO_PIN_6);
		}
			
		if(i == 0)
			LL_GPIO_SetOutputPin(GPIOD, dig2[i]);
		else
			LL_GPIO_SetOutputPin(GPIOC, dig2[i]);
			//End Show
		
		LL_mDelay(1);
	}
}

void EXTI3_IRQHandler(void)
{
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_3) == SET)
	{
		rec[idx] = LL_USART_ReceiveData8(USART2);
		if(rec[idx] == 'R')
			r = 1;

		idx++;
		idx%=10;
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_3);
	}
}

void Gpio_Config(void)
{
	LL_GPIO_InitTypeDef GPIO_set;
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
	
	//Init ALL PIN for 7segment of player1
	GPIO_set.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_set.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_set.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_set.Pull = LL_GPIO_PULL_NO;
	GPIO_set.Pin = LL_GPIO_PIN_2 | LL_GPIO_PIN_10 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12 | LL_GPIO_PIN_13 | LL_GPIO_PIN_14 | LL_GPIO_PIN_15;
	LL_GPIO_Init(GPIOB, &GPIO_set);
	GPIO_set.Pin = LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_2 | LL_GPIO_PIN_3;
	LL_GPIO_Init(GPIOC, &GPIO_set);
	
	//Init ALL PIN for 7segment of player2
	GPIO_set.Pin = LL_GPIO_PIN_10 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8;
	LL_GPIO_Init(GPIOA, &GPIO_set);
	GPIO_set.Pin = LL_GPIO_PIN_12 | LL_GPIO_PIN_11 | LL_GPIO_PIN_10 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8 | LL_GPIO_PIN_7 | LL_GPIO_PIN_6;
	LL_GPIO_Init(GPIOC, &GPIO_set);
	GPIO_set.Pin = LL_GPIO_PIN_2;
	LL_GPIO_Init(GPIOD, &GPIO_set);
	
	//Init ALL PIN for Dice
	GPIO_set.Pin = LL_GPIO_PIN_3 | LL_GPIO_PIN_4 | LL_GPIO_PIN_5 | LL_GPIO_PIN_6 | LL_GPIO_PIN_7 | LL_GPIO_PIN_8 | LL_GPIO_PIN_9;
	LL_GPIO_Init(GPIOB, &GPIO_set);
	
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
	
	//Init ALL PIN for Reset Switch
	GPIO_set.Pull = LL_GPIO_PULL_DOWN;
	GPIO_set.Mode = LL_GPIO_MODE_INPUT;
	GPIO_set.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_set.Pin = LL_GPIO_PIN_12;
	LL_GPIO_Init(GPIOA, &GPIO_set);

	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
	LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTA, LL_EXTI_LINE_12);
	LL_EXTI_InitTypeDef PA_12;
	PA_12.Mode = LL_EXTI_MODE_IT;
	PA_12.LineCommand = ENABLE;
	PA_12.Line_0_31 = LL_EXTI_LINE_12;
	PA_12.Trigger = LL_EXTI_TRIGGER_FALLING;
	LL_EXTI_Init(&PA_12);
	NVIC_EnableIRQ((IRQn_Type) 40);
	NVIC_SetPriority((IRQn_Type)40, 0);
	
	//Init ALL PIN for Switch
	GPIO_set.Mode = LL_GPIO_MODE_INPUT;
	GPIO_set.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_set.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_set.Pull = LL_GPIO_PULL_DOWN;
	GPIO_set.Pin = LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_11 | LL_GPIO_PIN_5;
	LL_GPIO_Init(GPIOA, &GPIO_set);

}
/***************************Edit Funtion Zone***************************/

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