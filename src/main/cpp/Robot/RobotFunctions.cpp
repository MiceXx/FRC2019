#include "Robot.h"

#include <iostream>
#include <string>

namespace frc {
    namespace lcchs{

        //gyro reset position
        void Robot::gyroResetPos(){
        double GyroAngle = gyro.GetAngle();
        while (abs(GyroAngle) > 2){
          if (GyroAngle > 0 ){
           powerTrain.DrivebaseStrafe( 0, 0, -0.2, 0);
          }
          else{
            powerTrain.DrivebaseStrafe( 0, 0, 0.2, 0);
          }
        }
      }
    }
}