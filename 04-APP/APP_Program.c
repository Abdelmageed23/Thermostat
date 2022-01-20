
/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 19 Jan	2022                   			 */
/* Version  : V01                            			 */
/*********************************************************/

#include "../01-LIB/STD_TYPES.h"
#include "../01-LIB/BIT_MATH.h"

#include "../02-MCAL/DIO/DIO_interface.h"
#include "../02-MCAL/Interrupt/Interrupt_interface.h"

#include "../03-HAL/LCD/LCD.h"
#include "../03-HAL/motor/Motor.h"
#include "../03-HAL/KEYPAD/KEYPAD_interface.h"
#include "../03-HAL/TEMP/TEMP_interface.h"

#include "APP_Interface.h"
#include "APP_Private.h"
#include "APP_Config.h"


void APP_init()
{
	GlobalInerruptEnable();
	KPD_init();
	LCD_vidInit();
	MOTOR_init(MOTOR_1);
	MOTOR_init(MOTOR_2);

}


void APP_Prog()
{
	uint8_t state = Home;
	volatile uint8_t Actual_Temp = 0;
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
			LCD_vidWriteString("2-GET Temp");
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
			while(key!=8 )// Enter Button //////////////////////////// NOTED
		{

			key =KPD_u8GetPressedKey();
			if(key != 255)
			{


				LCD_vidWriteNumber(key);
			}
			desired_temp = desired_temp *10+key;

		}

			if(desired_temp<Actual_Temp)
			{
				MOTOR_off(MOTOR_1);
			}
			else if ((desired_temp-Actual_Temp)<5)
			{
				MOTOR_speed(30);
				MOTOR_direction(MOTOR_1,FWD);


			}
			else if ( ((desired_temp-Actual_Temp)>7 ) && ((desired_temp-Actual_Temp)<10))
			{
				MOTOR_direction(MOTOR_1,FWD);
				MOTOR_speed(60);


			}
			else if ( (desired_temp-Actual_Temp) >13 )
			{
				MOTOR_speed(90);
				MOTOR_direction(MOTOR_1,FWD);

			}

			key =KPD_u8GetPressedKey();
			if(key == 8)	// NEED MODIFICATION TO HOME
			{
				state = Home;
			}
			break;
		case GET:
		//	LCD_vidClear();
			LCD_vidSetPosition(0,0);
			LCD_vidWriteString("Actual Temp:");
		//	LCD_vidSetPosition(1,5);
		//	LCD_vidWriteString("     ");
			LCD_vidSetPosition(1,12);
			Actual_Temp = TEMP_u8GetReading(0);// 0 = ADC channel   ** NEEDED
			LCD_vidWriteNumber(Actual_Temp);
			key =KPD_u8GetPressedKey();
			if(key == 8)	// NEED MODIFICATION TO HOME
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
