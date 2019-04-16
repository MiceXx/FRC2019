#include "Robot.h"

#include <iostream>
#include <string>

namespace frc
{
namespace lcchs
{

void Robot::AutonomousInit() {

        gyro.Reset();
        gyroAccum = 0;
        
        TeleopInit();
        m_autoSelected = m_chooser.GetSelected();
        // m_autoSelected = SmartDashboard::GetString("Auto Selector",
        //     kAutoNameDefault);
        std::cout << "Auto selected: " << m_autoSelected << std::endl;

        /* start of networking tables*/
        auto smartDashboard = networkTableInstance.GetTable("SmartDashboard");
        /* end of networking tables*/


        if (m_autoSelected == kAutoNameCustom) {
          // Custom Auto goes here
        } else {
          // Default Auto goes here
        }
      }

void Robot::AutonomousPeriodic()
{
    TeleopPeriodic();
    if (m_autoSelected == kAutoNameCustom)
    {
        // Custom Auto goes here
    }
    else
    {
        // Default Auto goes here
    }

    // double x = frc::SmartDashboard::GetNumber("DB/Slider 1", 0.0);
    // double y = frc::SmartDashboard::GetNumber("DB/Slider 2", 0.0);
    // double z = frc::SmartDashboard::GetNumber("DB/Slider 3", 0.0);

    //double gyroAngle = frc::SmartDashboard::GetNumber("DB/Slider 4", 0.0);

    //powerTrain.DrivebaseStrafe(x, y, z, 0.0);
}
} // namespace lcchs
} // namespace frc



//Possible autonomous code: https://www.chiefdelphi.com/t/2220s-play-record-macro-for-autonomous/143379
//or https://github.com/DennisMelamed/FRC-Play-Record-Macro/tree/master/FRC2220-Play-Record-Macro-DM/src