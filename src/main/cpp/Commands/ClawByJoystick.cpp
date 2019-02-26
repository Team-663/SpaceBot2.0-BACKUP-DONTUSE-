// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Commands/ClawByJoystick.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

ClawByJoystick::ClawByJoystick(): frc::Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::claw.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void ClawByJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ClawByJoystick::Execute() {
    int l1_b = Robot::oi->getJoyL()->GetRawButton(2);
    int r1_b = Robot::oi->getJoyR()->GetRawButton(2);
    //frc::SmartDashboard::PutNumber("ClawButton", b);
    if (l1_b || r1_b)
	{
        //frc::SmartDashboard::PutString("ClawSolenoid", "ON");
		Robot::claw->SetClawSolenoid(frc::DoubleSolenoid::kReverse);
	}
    else
    {
        //frc::SmartDashboard::PutString("ClawSolenoid", "OFF");
        Robot::claw->SetClawSolenoid(frc::DoubleSolenoid::kForward);
    }

    double tl = Robot::oi->GetXboxTriggerLeft() + Robot::oi->getJoyL()->GetRawButton(1);
	double tr = Robot::oi->GetXboxTriggerRight() + Robot::oi->getJoyR()->GetRawButton(1);
	double clawSpeed = 0.0;
	
	if ( (tl != 0.0) ^ (tr != 0.0))
	{
		if (tl)
			clawSpeed = tl * CLAW_IN_SPEED_SCALE;
		else
			clawSpeed = tr * CLAW_OUT_SPEED_SCALE;
	}

    Robot::claw->SetClawMotors(clawSpeed);

}

// Make this return true when this Command no longer needs to run execute()
bool ClawByJoystick::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void ClawByJoystick::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawByJoystick::Interrupted() {

}