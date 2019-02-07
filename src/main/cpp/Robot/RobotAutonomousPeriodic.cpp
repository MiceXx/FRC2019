#include "Robot.h"

#include <iostream>
#include <string>

namespace frc {
    namespace lcchs{
        void Robot::AutonomousPeriodic() {
        if (m_autoSelected == kAutoNameCustom) {
            // Custom Auto goes here
        } else {
            // Default Auto goes here
        }

        //Set Scaling
        double scaling=frc::SmartDashboard::GetNumber("DB/Slider 0", 0.0) +1. ;
        powerTrain.setScaling( 1/scaling );
        manipulator.setScaling( 1/scaling );


        double x = frc::SmartDashboard::GetNumber("DB/Slider 1", 0.0);
        double y = frc::SmartDashboard::GetNumber("DB/Slider 2", 0.0);
        double z = frc::SmartDashboard::GetNumber("DB/Slider 3", 0.0);

// gyro output
std::string GyroAngle= std::to_string(gyro.GetAngle());
            frc::SmartDashboard::PutString("DB/String 3", GyroAngle);



        //double gyroAngle = frc::SmartDashboard::GetNumber("DB/Slider 4", 0.0);

        //powerTrain.DrivebaseStrafe(x, y, z, 0.0);

        }
    }
}