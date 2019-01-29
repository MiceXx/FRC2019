#include "Robot.h"
#include "RobotVision.h"

#include <iostream>
#include <string>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Joystick.h>

  nt::NetworkTableEntry xEntry;
  nt::NetworkTableEntry yEntry;
  auto networkTableInstance= nt::NetworkTableInstance::GetDefault();
  
void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

    RobotVision* rv = new RobotVision();
    rv->RobotVisionInit();
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
    frc::SmartDashboard::PutNumber("Joystick X", jStick.GetX());
    frc::SmartDashboard::PutNumber("Joystick Y", jStick.GetY());
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  /* start of networking tables*/
  auto dataTable = networkTableInstance.GetTable("datatable");
  auto smartDashboard = networkTableInstance.GetTable("SmartDashboard");
  xEntry = dataTable->GetEntry("X");
  yEntry = dataTable->GetEntry("Y");
  /* end of networking tables*/

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

double x = 0;
double y = 0;

void Robot::TeleopPeriodic() {
  //networking table test
  xEntry.SetDouble(x);
  yEntry.SetDouble(y);
  x += 0.05;
  y += 1.0;

}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
