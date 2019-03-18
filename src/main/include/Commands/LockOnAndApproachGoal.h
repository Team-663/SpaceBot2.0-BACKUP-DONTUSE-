// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef LOCKONANDAPPROACHGOAL_H
#define LOCKONANDAPPROACHGOAL_H

#define VisionOffset 0.0
#define ErrorThreshold 1.5
#define SpinMagnatude 0.35
#define useCalc false
#define useTrajectorySys false
#define trajSpd 0.4
#define hFov 82.1
#define yFov 52.2
#define xRes 640
#define yRes 480


#include "frc/commands/Subsystem.h"
#include "Robot.h"
#include "frc/WPILib.h"
#include <iostream>
#include "llvm/ArrayRef.h"
#include <chrono>
#include "time.h"
#include "math.h"

/**
 *
 *
 * @author daggerwolf45
 */
class LockOnAndApproachGoal: public frc::Command {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	LockOnAndApproachGoal();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;	
	
	std::shared_ptr<NetworkTable> table;

	double currentAngle = Robot::driveTrain->GetGyroBearing();
	double targetAngle;
	double t_error;
	double distFromRocket;
	double centerX;
	double centerY;
	double cRocketLocation[];
	double rocketLocation[];
	double trajectory[];

private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES
	//table = NetworkTable::GetTable("GRIP/myCountoursReport");
	void GetTargetLocation();
	double GetTargetAngle();
	void GetNetworkTable();
	void TurnToAngle(double targetAngle);
	void ApproachRocket();
	double GetTrajectory(int q, double trajTime);
	void GotoRocket();
	double ConvertToDouble(uint32_t dist1);
	double ConvertToRad(double deg);
	double ConvertToDeg(double rad);
	double GetTargetLocationCam(int t);
};

#endif
