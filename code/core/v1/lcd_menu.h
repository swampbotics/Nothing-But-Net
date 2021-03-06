/********************************************************/
/*                   lcd_menu_blank.h                   */
/*                        v0.9                          */
/*                                                      */
/* This file was originally developed by:               */
/* Kristaps Berzinch                                    */
/* Programmer for Team 2105A                            */
/* Ware County High School                              */
/* Waycross, Georgia, USA                               */
/*                                                      */
/* Please drop me a line with questions or comments!    */
/* kberzinch@live.com                                   */
/* or on the VEX Forums: WCHS Programmer                */
/*                                                      */
/* You can do whatever you want with these files, but   */
/* please leave this and other credits sections intact. */
/*                                                      */
/* Neither I nor Ware County High School is responsible */
/* for any consequences.                                */
/********************************************************/


// note to kberzinch: add warning about unsigned chars

const char LCD_SizeOfMenu = 6; // MUST be at least 1 to prevent crash

#undef LCD_NotUsing_Menu       // Clear any statements against compiling LCD_Menu.
// If you don't want it, why would you include it?

typedef struct {
	bool IsBlue;
	bool Front;
	bool Set;
	bool Drive;
	char Auton;
	byte Status; // status is supposed to be updated by lcd_display?
} _Competition;

_Competition Competition;

#include "lcd.h";

void LCD_Menu_Define()
{
	char i;
	for (i = 0; i < LCD_SizeOfMenu; i++)
	{
		LCD.Menu[i].Title = "";
		LCD.Menu[i].Text = "";
		LCD.Menu[i].PrevIndex = i - 1;
		LCD.Menu[i].SelectIndex = -1;
		LCD.Menu[i].NextIndex = i + 1;
	}
	LCD.Menu[0].Title = "Color";
	LCD.Menu[0].Text = "Red";
	LCD.Menu[0].PrevIndex = 0;
	LCD.Menu[0].SelectIndex = 3;

	LCD.Menu[1].Title = LCD.Menu[0].Title;
	LCD.Menu[1].Text = "Blue";
	LCD.Menu[1].SelectIndex = 3;

	LCD.Menu[2].Title = "Program Skills";
	LCD.Menu[2].Text = "DO NOT SELECT";
	LCD.Menu[2].NextIndex = 2;
	LCD.Menu[2].SelectIndex = 3;

	LCD.Menu[3].Title = "Start Point";
	LCD.Menu[3].Text = "Stay";
	LCD.Menu[3].PrevIndex = 3;

	LCD.Menu[4].Title = LCD.Menu[3].Title;
	LCD.Menu[4].Text = "Front - Drive";

	LCD.Menu[5].Title = LCD.Menu[3].Title;
	LCD.Menu[5].Text = "Back - Drive";
	LCD.Menu[5].NextIndex = 5;


}

bool LCD_Menu_Execute()
{
	switch(LCD.Index)
	{
	case 0:
		Competition.IsBlue = false;
#if defined(_DEBUG)
		writeDebugStreamLine("Set as RED");
#endif
		break;
	case 1:
		Competition.IsBlue = true;
#if defined(_DEBUG)
		writeDebugStreamLine("Set as BLUE");
#endif
		break;
	case 3: // FRONT - DRIVE
		Competition.Drive = false;
#if defined(_DEBUG)
		writeDebugStreamLine("Set as STAY");
#endif
		break;
	case 4: // FRONT - DRIVE
		Competition.Front = true;
		Competition.Drive = true;
#if defined(_DEBUG)
		writeDebugStreamLine("Set as FRONT - DRIVE");
#endif
		break;
	case 5: // BACK - DRIVE
		Competition.Front = false;
		Competition.Drive = true;
#if defined(_DEBUG)
		writeDebugStreamLine("Set as BACK - DRIVE");
#endif
		break;
	case 2:
		Competition.Auton = 3;
#if defined(_DEBUG)
		writeDebugStreamLine("Set as Programming Skills");
#endif
		break;
	}
	if (LCD.Menu[LCD.Index].SelectIndex == -1)
	{
		while(nLCDButtons != 0) {} // wait for key(s) to be released
		return true;
		} else {
		LCD.Index = LCD.Menu[LCD.Index].SelectIndex;
		return false;
	}
}
