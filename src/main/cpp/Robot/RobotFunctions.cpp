#include "Robot.h"

#include <thread>

#include <iostream>
#include <string>

namespace frc {
    namespace lcchs{

        //gyro reset position
        void Robot::gyroResetPos(){
          double GyroAngle = gyro.GetAngle();
            if (GyroAngle > 1 ){
            powerTrain.DrivebaseStrafe( -0.1, 0.1, -0.5, 0);
            }
            else if(GyroAngle < -1 ){
              powerTrain.DrivebaseStrafe( 0.1, -0.1, 0.5, 0);
            }
      }

    }
}