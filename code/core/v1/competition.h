#pragma systemFile

void allMotorsOff();
void allTasksStop();
void pre_auton();
task autonomous();
task usercontrol();

bool bStopTasksBetweenModes = true;

#if defined(_DEBUG)
const string RobotDisabled = "Robot disabled";
#endif

task main() {
#if defined(_DEBUG)
	writeDebugStreamLine("Preauton start");
#endif
	pre_auton();
#if defined(_DEBUG)
	writeDebugStreamLine("Preauton end");
#endif
	while (true) {
#if defined(_DEBUG)
		if (bIfiRobotDisabled) {
			writeDebugStreamLine(RobotDisabled);
		}
#endif
		while (bIfiRobotDisabled)	{
			while (true) {
				if (!bIfiRobotDisabled)
					break;
				EndTimeSlice();
			}
		}
		if (bIfiAutonomousMode) {
#if defined(_DEBUG)
			writeDebugStreamLine("Autonomous start");
#endif
			startTask(autonomous);
			while (bIfiAutonomousMode && !bIfiRobotDisabled) {
				if (!bVEXNETActive) {
					if (nVexRCReceiveState == vrNoXmiters) // the transmitters are powered off!!
						allMotorsOff();
				}
				EndTimeSlice();
			}
			allMotorsOff();
#if defined(_DEBUG)
			writeDebugStreamLine(RobotDisabled);
#endif
			if(bStopTasksBetweenModes)
				allTasksStop();
			} else {
#if defined(_DEBUG)
			writeDebugStreamLine("Usercontrol start");
#endif

				startTask( FwControlTask );

			startTask(usercontrol);
			while (!bIfiAutonomousMode && !bIfiRobotDisabled) {
				if (nVexRCReceiveState == vrNoXmiters) // the transmitters are powered off!!
					allMotorsOff();
				EndTimeSlice();
			}
			allMotorsOff();
			if(bStopTasksBetweenModes)
				allTasksStop();
		}
	}
}

void allMotorsOff() {
	motor[port1] = 0;
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port6] = 0;
	motor[port7] = 0;
	motor[port8] = 0;
#if defined(VEX2)
	motor[port9] = 0;
	motor[port10] = 0;
#endif
}

void allTasksStop() {
	stopTask(1);
	stopTask(2);
	stopTask(3);
	stopTask(4);
#if defined(VEX2)
	stopTask(5);
	stopTask(6);
	stopTask(7);
	stopTask(8);
	stopTask(9);
	stopTask(10);
	stopTask(11);
	stopTask(12);
	stopTask(13);
	stopTask(14);
	stopTask(15);
	stopTask(16);
	stopTask(17);
	stopTask(18);
	stopTask(19);
#endif
#ifndef NoLCD
	startTask(LCD_Display);
#endif
}
