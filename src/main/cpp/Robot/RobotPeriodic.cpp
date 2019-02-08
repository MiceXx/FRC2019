#include "Robot.h"

#include <iostream>
#include <string>

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */

namespace frc {
    namespace lcchs{
        void Robot::RobotPeriodic() {
            frc::SmartDashboard::PutNumber("Joystick X", jStick->GetX());
            frc::SmartDashboard::PutNumber("Joystick Y", jStick->GetY());
            
            double scaling=driveStation.getSlider(0);
         
            if(scaling<0.){
             scaling=0.;
             }
             else if (scaling>5.){
            scaling=5.;
            }

            driveOutput=1/(scaling+1);
            liftOutput=1/(scaling+1);
            powerTrain.setScaling( driveOutput );
            manipulator.setScaling( liftOutput );
        }
    }
}