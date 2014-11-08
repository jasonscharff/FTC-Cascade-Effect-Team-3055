/*
Sample driver control file using just one joystick 
*/

#include "JoystickDriver.c"

void updateMotors()
{
	getJoystickSettings(joystick);
	int xVal = scaleValue(joystick.joy1_x1, 128, 127)
	int yVal = scaleValue(joystick.joy1_y1, 128, 127)
	if (xVal < 10 && xVal > -10) //Ignore x value, probably accidental on driver part.
	{
		motor[leftWheel] = yVal
		motor[rightWheel] = yVal
	}
	else
	{
		//Turning right = left at -100, right at 100
		if(yVal < 10 && yVal > -10) //Pure turn
		{
			if(xVal > 0) //Turn right
			{
				motor[leftWheel] = xVal * -1;
				motor[rightWheel] = xVal;
			}
			else //Turn left
			{
				motor[leftWheel] = xVal;
				motor[rightWheel] = xVal * -1;
			}	
		}
		else
		{
			if (xVal > 0) //Turn Right
			{
				motor[leftWheel] = scaleValue(xVal * -1 + yVal, 200, 200)
				motor[rightWheel] = scaleValue(xVal + yVal, 200, 200)
			}	
			else
			{
				motor[leftWheel] = scaleValue(xVal + yVal, 200, 200)
				motor[rightWheel] = scaleValue(xVal * -1 + yVal, 200, 200)
			}
		}	
		
	}

}



int scaleValue(int value, int positiveBound, int negativeBound)
{
	if (reading >= 0)
	{
		float scaleFactor = 100/positiveBound;
		return int(scaleFactor * value)
	}
	else
	{
		float scaleFactor = 100/negativeBound
		return int(scaleFactor * value)
	}	
}
