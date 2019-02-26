/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "PIDHelper/GyroPID.h"

GyroPID::GyroPID() {}

frc::PIDSourceType GyroPID::GetPIDSourceType()
{
    return frc::PIDSourceType::kDisplacement;
}

double GyroPID::PIDGet()
{
    return heading;
}

void GyroPID::SetHeading(double h)
{
    heading = h;
}