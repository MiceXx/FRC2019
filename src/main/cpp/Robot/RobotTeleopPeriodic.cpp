
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

        
        //autonomous teleop

        if (button3->Get()){
            std::cout << "the botton was pressed" << std::endl;
        }
        
        if (button1->Get()){
            gyroResetPos();
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

            //Lift
            //manipulator.moveLift(m_sticktwo.GetY());

            liftPosition=manipulator.getPosition();
            liftVelocity=manipulator.getVelocity();
            liftCommand=driveStation.getLeftHandY();
            liftReset=driveStation.getYButton();
            if (liftReset)
            {
            manipulator.resetEncoder();
            }
            manipulator.moveLift(liftCommand);
         


            driveStation.setString( 5,std::to_string(liftPosition) );

            driveStation.setString( 6,std::to_string(liftVelocity) );

            driveStation.setString( 7,std::to_string(liftCommand) );

            driveStation.setString( 8,std::to_string(liftReset) );
        }
    }
}