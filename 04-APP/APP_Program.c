
/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 19 Jan	2022                   			 */
/* Version  : V01                            			 */
/*********************************************************/

#include "../01-LIB/STD_TYPES.h"
#include "../01-LIB/BIT_MATH.h"

#include "../03-HAL/LCD/LCD.h"
#include "../03-HAL/motor/Motor.h"

#include "APP_Interface.h"
#include "APP_Private.h"
#include "APP_Config.h"


void APP_init()
{
	LCD_vidInit();
	MOTOR_init(MOTOR_1);
	MOTOR_init(MOTOR_2);

}

void APP_Prog()
{
	uint8_t state;

	switch (state)
	{
	case Home:

		break;
	case SET:
		break;
	case GET:
		break;
	case ERROR:
		break;
	default :
		break;
	}

}
