#pragma config(Sensor, in1,    PowerExpander,  sensorAnalog)
#pragma config(Sensor, dgtl1,  enc,            sensorQuadEncoder)
#pragma config(Sensor, dgtl10, jumper1,        sensorTouch)
#pragma config(Sensor, dgtl11, jumper2,        sensorTouch)
#pragma config(Sensor, dgtl12, jumper3,        sensorTouch)
#pragma config(Motor,  port1,           LLT,           tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           LLM,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           LLB,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           CollectionA,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           DriveLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           DriveRight,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           CollectionB,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LRT,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           LRM,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          LRB,           tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// TO CHANGE LCD THING, GO TO LCD FILE LINE: 272
// LINE 58 COMP.H
#define NoLiftLimits
 #define OneLiftEncoder
//#define NoPowerExpander
//#define MultiDriveEncoders.
#if defined(_DEBUG)
const string FILE = __FILE__;
#endif

int motorSpeed;
char Robot = 'B';
#include "core/v1/pid/b.h"
#include "core/v1/core.h"
#include "core/DriverProfiles/2105B.h"
#include "core/auton/2105B-all.h"
#include "core/misc/2105A-autonmanager.h"

void ResetDriveEncoders() {
}

void init() {
}
