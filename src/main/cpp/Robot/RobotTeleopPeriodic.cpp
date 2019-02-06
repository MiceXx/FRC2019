
#include "Robot.h"

#include <iostream>
#include <string>

namespace frc {
    namespace lcchs{
        double x = 0;
        double y = 0;
        void Robot::TeleopPeriodic() {
        //networking table test
        xEntry.SetDouble(x);
        yEntry.SetDouble(y);
        x += 0.05;
        y += 1.0;

        auto tv = networkTableInstance.GetTable("limelight")->GetNumber("tv", 0.0);
        auto tx = networkTableInstance.GetTable("limelight")->GetNumber("tx", 0.0);
        auto ty = networkTableInstance.GetTable("limelight")->GetNumber("ty", 0.0);
        if(tv) {
            printf("tx:%f ty:%f\n", tx, ty);
        }

        bool b = button1->Get();
            if (b){
            std::cout << "the botton was pressed" << std::endl;
            }
            

        //Set Scaling
        double scaling=frc::SmartDashboard::GetNumber("DB/Slider 0", 0.0) +1. ;
        powerTrain.setScaling( 1/scaling );
        manipulator.setScaling( 1/scaling );

        //start mechanum stuff
        
            if (abs(m_stick.GetZ()) > 0.1) {gyro.Reset();}

            powerTrain.driveRobot(m_stick.GetX(), m_stick.GetY(), m_stick.GetZ(), gyro.GetAngle());

            /// powerTrain.drivedoublejoystick(m_stick.GetY(), m_stick.GetX(), m_sticktwo.GetY(), m_sticktwo.GetX());
            
            std::string speedX= std::to_string(m_stick.GetX());
            frc::SmartDashboard::PutString("DB/String 0", speedX);

            std::string speedY= std::to_string(m_stick.GetY());
            frc::SmartDashboard::PutString("DB/String 1", speedY);

            std::string speedZ= std::to_string(m_stick.GetZ());
            frc::SmartDashboard::PutString("DB/String 2", speedZ);

            std::string GyroAngle= std::to_string(gyro.GetAngle());
            frc::SmartDashboard::PutString("DB/String 3", GyroAngle);

            manipulator.moveLift(m_sticktwo.GetY());

        }
    }
}