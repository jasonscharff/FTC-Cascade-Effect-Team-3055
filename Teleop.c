#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ultrasonicSensor, sensorSONAR)
#pragma config(Motor,  mtr_S1_C1_1,     leftWheel,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     rightWheel,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     armMotor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     lawnMower,     tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    leftServo,            tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_1,    rightServo,           tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    armServo,             tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    hookServo,            tServoStandard)
#pragma config(Servo,  srvo_S2_C1_4,    servo10,              tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo12,              tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Add driving motors
#pragma DebuggerWindows("joystickGame")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Tele-Operation Mode Code Template
//
// This file contains a template for simplified creation of an tele-op program for an FTC
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

const int MOTOR_SCALAR = -128;
const int THRESHOLD = 10;

const int rightLaunchPos = 190;
const int rightClosed = 205;
const int rightOpen = 135;

const int leftLaunchPos = 30;
const int leftOpen = 75;
const int leftClosed = 15;

const int downArm = 200;

const int moveArm = 180;

const int small_small_Distance = 9;
const int medium_small_Distance = 9;
const int large_small_Distance = 9;

const int small_large_Distance = 9;
const int medium_large_Distance = 9;
const int large_large_Distance = 9;

const int hookUp = 210;

const int lockVal = 10;


bool turnSpinner = false;
bool bigBalls = true;



void initializeRobot()
{
	// Place code here to sinitialize servos to starting positions.
	// Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.
	servo[leftServo] = leftClosed;
	servo[rightServo] = rightClosed;
	servo[hookServo] = hookUp;
	wait1Msec(500);

	return;
}

void adjustDistanceToSmallUsingLarge()
{
	if(SensorValue(ultrasonicSensor) > small_large_Distance)
	{
		while(SensorValue(ultrasonicSensor) > small_large_Distance)
		{
			servo[armServo] = moveArm;
			motor[rightWheel] = -20;
			motor[leftWheel] = 20;
		}
	}
	else
	{
		while(SensorValue(ultrasonicSensor) < small_large_Distance)
		{
			servo[armServo] = moveArm;
			motor[rightWheel] = 20;
			motor[leftWheel] = -20;
		}
	}
}

void adjustDistancetoMediumUsingLarge()
{
	if(SensorValue(ultrasonicSensor) > medium_large_Distance)
	{
		while(SensorValue(ultrasonicSensor) > medium_large_Distance)
		{
			servo[armServo] = moveArm;
			motor[rightWheel] = -20;
			motor[leftWheel] = 20;
		}
	}
	else
	{
		while(SensorValue(ultrasonicSensor) < medium_large_Distance)
		{
			servo[armServo] = moveArm;
			motor[rightWheel] = 20;
			motor[leftWheel] = -20;
		}
	}
}

void adjustDistancetoLargeUsingLarge()
{
	if(SensorValue(ultrasonicSensor) > large_large_Distance)
	{
		while(SensorValue(ultrasonicSensor) > large_large_Distance)
		{
			servo[armServo] = moveArm;
			motor[rightWheel] = 20;
			motor[leftWheel] = -20;
		}
	}
	else
	{
		while(SensorValue(ultrasonicSensor) < large_large_Distance)
		{
			servo[armServo] = moveArm;
			motor[rightWheel] = 20;
			motor[leftWheel] = -20;
		}
	}
}

void adjustDistanceToSmallUsingSmall()
{
	if(SensorValue(ultrasonicSensor) > small_small_Distance)
	{
		while(SensorValue(ultrasonicSensor) > small_small_Distance)
		{
			servo[armServo] = moveArm;
			motor[rightWheel] = -20;
			motor[leftWheel] = 20;
		}
	}
	else
	{
		while(SensorValue(ultrasonicSensor) < small_small_Distance)
		{
			servo[armServo] = moveArm;
			motor[rightWheel] = 20;
			motor[leftWheel] = -20;
		}
	}
}

void adjustDistanceToMediumUsingSmall()
{
	if(SensorValue(ultrasonicSensor) > medium_small_Distance)
	{
		while(SensorValue(ultrasonicSensor) > medium_small_Distance)
		{
			servo[armServo] = moveArm;
			motor[rightWheel] = -20;
			motor[leftWheel] = 20;
		}
	}
	else
	{
		while(SensorValue(ultrasonicSensor) < medium_small_Distance)
		{
			servo[armServo] = moveArm;
			motor[rightWheel] = 20;
			motor[leftWheel] = -20;
		}
	}
}

void adjustDistancetoLargeUsingSmall()
{
	if(SensorValue(ultrasonicSensor) > large_small_Distance)
	{
		while(SensorValue(ultrasonicSensor) > large_small_Distance)
		{
			servo[armServo] = moveArm;
			motor[rightWheel] = -20;
			motor[leftWheel] = 20;
		}
	}
	else
	{
		while(SensorValue(ultrasonicSensor) < large_small_Distance)
		{
			servo[armServo] = moveArm;
			motor[rightWheel] = 20;
			motor[leftWheel] = -20;
		}
	}
}

void throwBig()
{
	int rightBefore = servo[rightServo];
	int leftBefore = servo[leftServo];

	servo[rightServo] = rightLaunchPos;
	servo[leftServo] = leftLaunchPos;

	wait1Msec(500);

	motor[armMotor] = 100;
	wait1Msec(800);
	motor[armMotor] = -12;
	wait1Msec(1500);
	motor[armMotor] = 0;

	servo[rightServo] = rightBefore;
	servo[leftServo] = leftBefore;
}

//NOT EDITED AT ALL
void throwSmall()
{
	int rightBefore = servo[rightServo];
	int leftBefore = servo[leftServo];

	servo[rightServo] = rightLaunchPos;
	servo[leftServo] = leftLaunchPos;

	wait1Msec(500);

	motor[armMotor] = 100;
	wait1Msec(800);
	motor[armMotor] = -12;
	wait1Msec(1500);
	motor[armMotor] = 0;

	servo[rightServo] = rightBefore;
	servo[leftServo] = leftBefore;
}



void forwards()
{
	motor[armMotor] = 30;
	wait1Msec(300);
	motor[armMotor] = 0;
}

void backwards()
{
	motor[armMotor] = -10;
	wait1Msec(500);
	motor[armMotor] = 0;
}






task main()
{
	ClearTimer(T1);
	ClearTimer(T2);
	ClearTimer(T3);
	ClearTimer(T4);

initializeRobot();

//	waitForStart();   // wait for start of tele-op phase

	while (true)
	{
			writeDebugStreamLine("%d", SensorValue(ultrasonicSensor));
		if(turnSpinner == true)
		{
			motor[lawnMower] = 100;
		}
		else
		{
			motor[lawnMower] = 0;
		}

		if ((abs(joystick.joy1_x1) > THRESHOLD) || (abs(joystick.joy1_y1) > THRESHOLD))
		{
			servo[armServo] = moveArm;
			motor[leftWheel] =  (((float)joystick.joy1_x1/MOTOR_SCALAR) - ((float)joystick.joy1_y1/MOTOR_SCALAR * -1))*100;
			motor[rightWheel] = (((float)joystick.joy1_x1/MOTOR_SCALAR) + ((float)joystick.joy1_y1/MOTOR_SCALAR * -1))*100;
		}
		else
		{
			motor[leftWheel] = 0;
			motor[rightWheel] = 0;
		}

		if(joystick.joy1_TopHat == 2)
		{
			if(time1(T4) > 500)
		{
			if(bigBalls == true)
			{
				bigBalls = false;
			}
			else
			{
				bigBalls = true;
			}
			ClearTimer(T4);
	}

		}

		if(joystick.joy1_TopHat == 6)
	 {
	   writeDebugStreamLine("MY PLACE");
		servo[armServo] = downArm;
   }

		if (joy1Btn(1))
		{
			writeDebugStreamLine("Small");
			if(bigBalls == true)
			{
				adjustDistanceToSmallUsingLarge();
				throwBig();
			}
			else
			{
			//	adjustDistanceToSmallUsingSmall();
				throwSmall();
			}


		}

		 if (joy1Btn(4))
		{
			writeDebugStreamLine("Medium");
			if(bigBalls == true)
			{
			  adjustDistancetoMediumUsingLarge();
				throwBig();
			}
			else
			{
		//		adjustDistanceToMediumUsingSmall();
				throwSmall();
			}

		}

		 if (joy1Btn(3))
		{
			writeDebugStreamLine("Large");
			if(bigBalls == true)
			{
				adjustDistancetoLargeUsingLarge();
				throwBig();
			}
			else
			{
		//	 adjustDistancetoLargeUsingSmall();
				throwSmall();
			}

		}

		 if (joy1Btn(8))
		{
			backwards();
		}

		if (joy1Btn(6))
	  {
			forwards();
		}

		if (joy1Btn(5))
		{
			servo[armServo] = downArm;
			if(time1(T2) > 500)
		{
				if (servo[leftServo] == leftClosed)
			{
				servo[leftServo] = leftOpen;
			}
			else
			{
				servo[leftServo] = leftClosed;
			}
			ClearTimer(T2);
		}


		}

		if (joy1Btn(7))
		{
			servo[armServo] = downArm;
			if(time1(T3) > 500)
		{
			if (servo[rightServo] == rightClosed)
			{
				servo[rightServo] = rightOpen;
			}
			else
			{
				servo[rightServo] = rightClosed;
			}
			ClearTimer(T3);
	}

		}

		if (joy1Btn(2))
		{
			if (time1(T1) > 500)
			{
				ClearTimer(T1);
				if (turnSpinner == true)
				{
					turnSpinner = false;
				}
				else
				{
					turnSpinner = true;
				}
			}
		}

	}

}
