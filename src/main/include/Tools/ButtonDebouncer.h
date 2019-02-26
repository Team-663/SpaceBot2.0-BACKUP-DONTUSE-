/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "frc/WPILib.h"

#define BUTTON_DEBOUNCE_DEFAULT_PERIOD 0.5

class ButtonDebouncer{
private:
   std::shared_ptr<frc::Joystick> _joystick;
   int _buttonNum;
   double _latest;
   double _debouncePeriod;
public:
	ButtonDebouncer(std::shared_ptr<frc::Joystick> joystick, int buttonNum);
	ButtonDebouncer(std::shared_ptr<frc::Joystick> joystick, int buttonNum, float period);
	
	void GetDebouncePeriod(float period);
	bool Get();
};
