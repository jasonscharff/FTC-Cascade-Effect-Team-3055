#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	/*
	motor[motorD] =  100;
//	motor[motorE] = -100;
	wait1Msec(570);

	motor[motorD] = -7;
	motor[motorE] = 7;
	wait1Msec(2000);

	*/



	motor[motorD] = 100;
	wait1Msec(800);
	motor[motorD] = -12;
	wait1Msec(1500);





}
