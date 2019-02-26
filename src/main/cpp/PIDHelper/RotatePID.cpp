/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "PIDHelper/RotatePID.h"

RotatePID::RotatePID() {}

void RotatePID::PIDWrite(double value)
{
    setpoint = value;
}

double RotatePID::GetPIDWrite()
{
    return setpoint;
}