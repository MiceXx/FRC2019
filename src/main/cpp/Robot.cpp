#include "Robot.h"
#include "RobotVision.h"

#include <iostream>
#include <string>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Joystick.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>

namespace frc {
namespace lcchs{
  void Robot::setRobotScaling(){
    double scaling=frc::SmartDashboard::GetNumber("DB/Slider 0", 0.0) +1. ;

    if(scaling<1.)
    {
      scaling=1.;
    }
    else if (scaling>6.)
    {
      scaling=6.;
    }


    mecanumDrive.setScaling( 1/scaling );

    dentistryTools.setScaling( 1/scaling );
    }


  nt::NetworkTableEntry xEntry;
  nt::NetworkTableEntry yEntry;
  auto networkTableInstance= nt::NetworkTableInstance::GetDefault();

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

    RobotVision* rv = new RobotVision();
    rv->RobotVisionInit();
    
    
    
    mecanumDrive.initalizePowerTrain();
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

Robot::setRobotScaling();

double x = frc::SmartDashboard::GetNumber("DB/Slider 1", 0.0);
double y = frc::SmartDashboard::GetNumber("DB/Slider 2", 0.0);
double z = frc::SmartDashboard::GetNumber("DB/Slider 3", 0.0);
//double gyroAngle = frc::SmartDashboard::GetNumber("DB/Slider 4", 0.0);

mecanumDrive.DrivebaseStrafe(x, y, z, 0.0);

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

    //sets the scaling/speed of motors
   
   bool b = button1->Get();
    if (b){
    std::cout << "the botton was pressed" << std::endl;
    }
    
    
    
    setRobotScaling();


  //start mechanum stuff
  
    if (abs(m_stick.GetZ()) > 0.1) {gyro.Reset();}


    mecanumDrive.driveRobot(m_stick.GetX(), m_stick.GetY(), m_stick.GetZ(), gyro.GetAngle());

    /// mecanumDrive.drivedoublejoystick(m_stick.GetY(), m_stick.GetX(), m_sticktwo.GetY(), m_sticktwo.GetX());
    
    std::string speedX= std::to_string(m_stick.GetX());
    frc::SmartDashboard::PutString("DB/String 0", speedX);

    std::string speedY= std::to_string(m_stick.GetY());
    frc::SmartDashboard::PutString("DB/String 1", speedY);

    std::string speedZ= std::to_string(m_stick.GetZ());
    frc::SmartDashboard::PutString("DB/String 2", speedZ);

    std::string GyroAngle= std::to_string(gyro.GetAngle());
    frc::SmartDashboard::PutString("DB/String 3", GyroAngle);

    dentistryTools.moveLift(m_sticktwo.GetY());

}

void Robot::TestPeriodic() {}

}   // namespacelcchs
}  // namespacefrc
