#include "Robot.h"

#include <thread>

#include <iostream>
#include <string>

namespace frc {
    namespace lcchs{

        //gyro reset position
        void Robot::gyroResetPos(){
          double GyroAngle = gyro.GetAngle();
          if (abs(GyroAngle) > 2){
              if (button2->Get()){
                  break;
              }
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