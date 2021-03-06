#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/DropDrive.h"
#include "Subsystems/UltrasonicSensor.h"
#include "Subsystems/LauncherPIDSubsystem.h"
#include "Subsystems/IntakeRoller.h"
#include "Subsystems/IntakeArms.h"
#include "Subsystems/VisionCalculation.h"
#include "Subsystems/LEDSystem.h"
#include "OI.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
OI* CommandBase::oi = NULL;
DropDrive* CommandBase::dropdrive = NULL;
UltrasonicSensor* CommandBase::ultrasonicsensor = NULL;
LauncherPIDSubsystem* CommandBase::leftlauncherpid = NULL;
LauncherPIDSubsystem* CommandBase::rightlauncherpid = NULL;
IntakeRoller* CommandBase::intakeroller = NULL;
IntakeArms* CommandBase::intakearms = NULL;
VisionCalculation* CommandBase::visioncalculation = NULL;
LEDSystem* CommandBase::ledsystem = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{

}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	examplesubsystem = new ExampleSubsystem();
	dropdrive = new DropDrive();
	ultrasonicsensor = new UltrasonicSensor();
	oi = new OI();
	leftlauncherpid = new LauncherPIDSubsystem("Left", 8,2);
	rightlauncherpid = new LauncherPIDSubsystem("Right", 9,4);
	intakeroller = new IntakeRoller();
	intakearms = new IntakeArms();
	visioncalculation = new VisionCalculation();
	ledsystem = new LEDSystem();

	SmartDashboard::PutData(ultrasonicsensor);
	SmartDashboard::PutData(leftlauncherpid);
	SmartDashboard::PutData(rightlauncherpid);
	SmartDashboard::PutString("Hello world!", "testing testing 123");
	SmartDashboard::PutNumber("Distance", ultrasonicsensor->GetDistance());
	SmartDashboard::PutNumber("Voltage", ultrasonicsensor->GetVoltage());
//	SmartDashboard::PutNumber("LeftPID", leftlauncherpid->ReturnPIDInput());
}
