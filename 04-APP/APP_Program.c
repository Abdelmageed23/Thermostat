
/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 19 Jan	2022                   			 */
/* Version  : V01                            			 */
/*********************************************************/

#include "../01-LIB/STD_TYPES.h"
#include "../01-LIB/BIT_MATH.h"

#include "../02-MCAL/Interrupt/Interrupt_interface.h"
//#include "../02-MCAL/ADC/ADC_interface.h"

#include "../03-HAL/LCD/LCD.h"
#include "../03-HAL/motor/Motor.h"
#include "../03-HAL/KEYPAD/KEYPAD_interface.h"
#include "../03-HAL/TEMP/TEMP_interface.h"
#include "../03-HAL/BUTTON/Button.h"

#include "APP_Interface.h"
#include "APP_Private.h"
#include "APP_Config.h"


void APP_init()
{
	TEMP_init();
	GlobalInerruptEnable();
	KPD_init();
	LCD_vidInit();
	BTN_vidInit(BTN_1);
	MOTOR_init(MOTOR_1);
	MOTOR_init(MOTOR_2);

}


void APP_Prog()
{
	uint8_t state = Home;
	volatile uint16_t Actual_Temp = 0;
	volatile uint8_t key =255;
	uint8_t desired_temp=0;

	while(1)
	{

	switch (state)
		{
		case Home:
			LCD_vidClear();
			LCD_vidSetPosition(0,0);
			LCD_vidWriteString("1-SET Temp");
			LCD_vidSetPosition(1,0);
			LCD_vidWriteString("2- RUN");
			key =KPD_u8GetPressedKey();
			while(key!=1 && key!=2)
			{
				key =KPD_u8GetPressedKey();
			}

			if(key ==1 )
			{
				state = SET;

			}
			else if (key ==2)
			{
				state = GET;
			}

			break;
		case SET:
			desired_temp=0;
			key =255;
			LCD_vidClear();
			LCD_vidSetPosition(0,0);
			LCD_vidWriteString("Desired Temp:");
			key =KPD_u8GetPressedKey();
			while(key==255)
			{
				key =KPD_u8GetPressedKey();
			}
			LCD_vidSetPosition(1,5);

			while(1 )// Enter Button //////////////////////////// NOTED
		{

				if(BTN_u8IsPressed(BTN_1) ==1)
				{
					break;
				}
			key =KPD_u8GetPressedKey();
			if(key != 255)
			{

				desired_temp = desired_temp *10+key;
				LCD_vidWriteNumber(key);
			}


		}
			state = Home;



		//	key =KPD_u8GetPressedKey();
	/*		if(key == 8)	// NEED MODIFICATION TO HOME
			{
				state = Home;
			}
*/
			break;
		case GET:
		//	LCD_vidClear();
			LCD_vidSetPosition(0,0);
			LCD_vidWriteString("Act. Temp:");
			LCD_vidSetPosition(0,11);
			LCD_vidWriteString("  ");

			LCD_vidSetPosition(0,11);
			LCD_vidWriteNumber(Actual_Temp);
			LCD_vidSetPosition(1,0);
			LCD_vidWriteString("Des. Temp:");
			LCD_vidSetPosition(1,11);
			LCD_vidWriteNumber(desired_temp);


			Actual_Temp = TEMP_u8GetReading();// 0 = ADC channel   ** NEEDED
			//LCD_vidWriteNumber(Actual_Temp);
			for(volatile uint32_t delay; delay<20000000;delay++);
			key =KPD_u8GetPressedKey();

			if(desired_temp>Actual_Temp)
					{
						MOTOR_off(MOTOR_1);
						LCD_vidSetPosition(0,14);
						LCD_vidWriteString("M");
						LCD_vidWriteNumber(0);
					}
					else if ((Actual_Temp -desired_temp)<4 &&(Actual_Temp -desired_temp)>0)

					{
						MOTOR_speed(20);
						MOTOR_direction(MOTOR_1,FWD);
						LCD_vidSetPosition(0,14);
						LCD_vidWriteString("M");
						LCD_vidWriteNumber(1);

					}
					else if ( ((Actual_Temp -desired_temp)<8 ) && ((Actual_Temp -desired_temp)>4))

					{
						MOTOR_direction(MOTOR_1,FWD);
						MOTOR_speed(60);

						LCD_vidSetPosition(0,14);
						LCD_vidWriteString("M");
						LCD_vidWriteNumber(2);
					}
					else if ( (Actual_Temp -desired_temp) >8 )

					{
						MOTOR_speed(90);
						MOTOR_direction(MOTOR_1,FWD);
						LCD_vidSetPosition(0,14);
						LCD_vidWriteString("M");
						LCD_vidWriteNumber(3);

					}
			if(BTN_u8IsPressed(BTN_1))	// NEED MODIFICATION TO HOME
			{
				state = Home;
			}


			break;
		case ERROR:
			break;
		default :
			break;
		}
	}


}
