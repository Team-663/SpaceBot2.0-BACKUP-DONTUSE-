/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "frc/WPILib.h"
#include "OI.h"
#include "frc/PIDSource.h"

class GyroPID : public frc::PIDSource {
  public:
    GyroPID();
    double PIDGet();
    frc::PIDSourceType GetPIDSourceType();
    void SetHeading(double h);
  private:
    double heading;
};
