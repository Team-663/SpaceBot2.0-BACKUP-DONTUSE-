/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Tools/ButtonDebouncer.h"

ButtonDebouncer::ButtonDebouncer(std::shared_ptr<frc::Joystick> joystick, int buttonNum)
{
   _joystick = joystick;
   _buttonNum = buttonNum;
   _latest = 0;
   _debouncePeriod = BUTTON_DEBOUNCE_DEFAULT_PERIOD;
}
ButtonDebouncer::ButtonDebouncer(std::shared_ptr<frc::Joystick> joystick, int buttonNum, float period)
{
   _joystick = joystick;
   _buttonNum = buttonNum;
   _latest = 0;
   _debouncePeriod = period;
}

void ButtonDebouncer::GetDebouncePeriod(float period)
{
   _debouncePeriod = period;
}

bool ButtonDebouncer::Get()
{
   double now = frc::Timer::GetFPGATimestamp();
   if(_joystick->GetRawButton(_buttonNum))
   {
      if((now-_latest) > _debouncePeriod)
      {
         _latest = now;
         return true;
      }
   }
   return false;
}
