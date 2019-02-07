
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
        
        if (button2->Get()){
            alignRobot();
        }

        //Set Scaling
        double scaling=frc::SmartDashboard::GetNumber("DB/Slider 0", 0.0) +1. ;
        powerTrain.setScaling( 1/scaling );
        manipulator.setScaling( 1/scaling );

        //start mechanum stuff
        
            if (abs(jStick->GetZ()) > 0.1) {gyro.Reset();}

            powerTrain.driveRobot(jStick->GetX(), jStick->GetY(), jStick->GetZ(), gyro.GetAngle());

            manipulator.moveLift(jStick->GetY());

        }
    }
}