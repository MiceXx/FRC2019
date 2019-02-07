#include "Robot.h"

#include <iostream>
#include <string>

namespace frc {
    namespace lcchs{

        //gyro reset position
        void Robot::gyroResetPos(){
          double gyroAngle = gyro.GetAngle();
            if (gyroAngle > 1 ){
                powerTrain.driveRobot( -0.2, 0.2, -0.6, 0);
            }
            else if(gyroAngle < -1 ){
                powerTrain.driveRobot( 0.2, -0.2, 0.5, 0);
            }
        }

        void Robot::alignRobot(){
          double gyroAngle = gyro.GetAngle();
            auto limelightTable = networkTableInstance.GetTable("limelight");
            double tv = limelightTable->GetNumber("tv",0.0);
            double tx = limelightTable->GetNumber("tx",0.0);
            double ty = limelightTable->GetNumber("ty",0.0);
          //if(tv == 1 ){

           // powerTrain.driveRobot( -0.2, 0.2, 0.0, 0);

          //}
            if (gyroAngle > 1 ){
                powerTrain.driveRobot( -0.2, 0.2, -0.6, 0);
            }
            else if(gyroAngle < -1 ){
                powerTrain.driveRobot( 0.2, -0.2, 0.5, 0);
            }
        }

    }
}