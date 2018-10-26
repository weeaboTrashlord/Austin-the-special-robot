#pragma config(Sensor, in1,    Gyroscope,      sensorGyro)
#pragma config(Sensor, dgtl1,  LeftEncoder,    sensorRotation)
#pragma config(Sensor, dgtl2,  RightEncoder,   sensorRotation)
#pragma config(Motor,  port6,           Hasew,         tmotorNone, openLoop)
#pragma config(Motor,  port3,           BillandBob,    tmotorNone, openLoop)
#pragma config(Motor,  port2,           FredandJoseph, tmotorNone, openLoop)
#pragma config(Motor,  port4,           Pablo,         tmotorNone, openLoop)
#pragma config(Motor,  port5,           Raaj,          tmotorNone, openLoop)
#pragma config(Motor,  port7,          Schmeckle,     tmotorNone, openLoop)
#pragma config(Motor, port1,           Francis,       tmotorNone, openLoop)
#pragma config(Motor, port10,           Xavier,       tmotorNone, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"
void pre_auton()
{
  bStopTasksBetweenModes = true;
  SensorType[Gyroscope] = sensorNone;
  wait1Msec(1000);
  SensorType[Gyroscope] = sensorGyro;
  wait1Msec(2000);
  SensorScale[Gyroscope] = 150;
}
void turnLeft (int degreeInTens)
/*
Allows for the degree # when you call the function
to look like an actual degree amount, as opposed to
a 4 digit number
*/
{
	int degreeInOnes = (degreeInTens * 8.333);
	while(abs(SensorValue[Gyroscope]) < degreeInOnes)
	/*
	while loop allows for the gyroscope to turn a specific amount,
	as specified when the function is called
	*/
	{
		motor[BillandBob] = 60;
		motor[FredandJoseph] = -60;
	}
	motor[BillandBob] = 0;
	motor[FredandJoseph] = 0;
}
void turnRight (int degreeInTens)
/*
Allows for the degree # when you call the function
to look like an actual degree amount, as opposed to
a 4 digit number
*/
{
	int degreeInOnes = (degreeInTens * 8.333);
	while(abs(SensorValue[Gyroscope]) < degreeInOnes)
	/*
	while loop allows for the gyroscope to turn a specific amount,
	as specified when the function is called
	*/
	{
		motor[BillandBob] = -60;
		motor[FredandJoseph] = 60;
	}
	motor[BillandBob] = 0;
	motor[FredandJoseph] = 0;
}
void driveSquare (int distance, int power)
/* this sets it so that when the function is called
there is a set of parentheses with the #of squares
that will be traveled and the speed in which they
will be traversed*/
{
	SensorValue [LeftEncoder] = 0;
	int goalDistance = (1001 * distance);
	/*sets the distance traveled to our constant, which is 28,
	times the amount of squares needed, which one is 25, then
	multiplies the entire thing by the amount of squares needed,
	*/
  while(SensorValue[LeftEncoder] < goalDistance)
  {
  	motor[BillandBob] = power;
  	motor[FredandJoseph] = power;
  }
  motor[BillandBob] = 0;
  motor[FredandJoseph] = 0;
  /*
  While loop allows for you to only move specified amount in the
  "coordinates" given when you call the function
  */
}
void drivesquareReverse (int distance, int power)
/* this sets it so that when the function is called
there is a set of parentheses with the #of squares
that will be traveled and the speed in which they
will be traversed*/
{
	SensorValue [LeftEncoder] = 0;
	int goalDistance = (-1001 * distance);
	/*sets the distance traveled to our constant, which is 28,
	times the amount of squares needed, which one is 25, then
	multiplies the entire thing by the amount of squares needed,
	*/
  while(SensorValue[LeftEncoder] > goalDistance)
  {
  	motor[BillandBob] = power;
  	motor[FredandJoseph] = power;
  }
  motor[BillandBob] = 0;
  motor[FredandJoseph] = 0;
  /*
  While loop allows for you to only move specified amount in the
  "coordinates" given when you call the function
  */
}
void shoot(int shootTime)
/*
This is a funtion to shoot our ball launcher
*/
{
	motor[Rouf] = 60;
	motor[Ivan] = 60;
	wait1Msec(shootTime);
}
*/
task autonomous()
{
	driveSquare(4,127);
	//drives 2 squares a MAXIMUM EFFORT
	drivesquareReverse(2,-127);
	//drives backwards 2 squares at MAXIMUM EFFORT
	SensorValue[Gyroscope] = 0;
	turnLeft(90);
	SensorValue[Gyroscope] = 0;
	//turns 90 degrees counterclockwise
	driveSquare(2,127);
	//drives 2 squares forward at MAXIMUM EFFORT
	SensorValue[Gyroscope] = 0;
	turnRight(90);
	driveSquare(2,127);
}
task usercontrol()
{
	 while (true)
  {
    while(1 == 1)
			{
				//Movement System
				motor[BillandBob] = vexRT[Ch3];
				motor[FredandJoseph] = vexRT[Ch2];
				motor[Francis] = vexRT[Ch2];
				motor[Xavier] = vexRT[Ch3];
					//Arm System
				if(vexRT[Btn6U] == 1)
				{
					motor[Hasew] = 127;
					motor[Schmeckle] = -127;
				}
					else if(vexRT[Btn6D] == 1)
				{
					motor[Hasew] = -127;
					motor[Schmeckle] = 127;
				}
					else
				{
						motor[Hasew] = 0;
						motor[Schmeckle] = 0;
				}

						//Launcher System
						/*if(vexRT[Btn5U] == 1)
						{
							motor[Rouf] = 127;
							motor[Ivan] = 127;
						}
						else if(vexRT[Btn5D] == 1)
						{
							motor[Rouf] = -127;
							motor[Ivan] = -127;
						}
						else
						{
							motor[Rouf] = 0;
							motor[Ivan] = 0;
							*/
								//Claw System
							if(vexRT[Btn8R]==1)
							{
								motor[Raaj] = 36;
							}
							else if(vexRT[Btn8L]==1)
							{
								motor[Raaj] = -36;
							}
							else
							{
								motor[Raaj] = 0;
							}
							//ELbow system
							if(vexRT[Btn8U]==1)
							{
								motor[Pablo] = 63;
							}
							else if(vexRT[Btn8D]==1)
							{
								motor[Pablo] = -63;
							}
							else
							{
								motor[Pablo] = 0;
							}

				}
			}
		}
