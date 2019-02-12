#include "Robot.h"

#include <iostream>
#include <string>

namespace frc {
    namespace lcchs{

        //gyro reset position
        void Robot::gyroResetPos(){
          double gyroAngle = gyro.GetAngle();
            if (gyroAngle > 1 ){
                //powerTrain.driveRobot( -0.2, 0.2, -0.6, 0);
            }
            else if(gyroAngle < -1 ){
               // powerTrain.driveRobot( 0.2, -0.2, 0.5, 0);
            }
        }

        void Robot::alignRobot(){
          double gyroAngle = gyro.GetAngle();
            auto limelightTable = networkTableInstance.GetTable("limelight");
            
            bool tv = static_cast<bool>(limelightTable->GetNumber("tv",0.0));

            double ta = limelightTable->GetNumber("ta",0.0);
            double targetArea = 22.5;

            double tx = limelightTable->GetNumber("tx",0.0);
            double targetX = 0.9;

            double ty = limelightTable->GetNumber("ty",0.0);
            double targetY = 11;

            double tolerance = 5;
            std::cout << " Align start" << std::endl;
          if(tv){
              
            std::cout << " Align valid" << std::endl;
            if(ta > targetArea + tolerance){//move back
                //m_robotDrive.DriveCartesian(0,-0.3,0);
                powerTrain.driveRobot( 0, 1, 0);
                std::cout << "move back" << std::endl;
            }
            else if(ta < targetArea - tolerance){//move forward
                //m_robotDrive.DriveCartesian(0,0.3,0);
                powerTrain.driveRobot( 0, -1, 0);
                std::cout << "move forward" << std::endl;
            //}
            // else if(tx < targetX){//rotate right
            //     powerTrain.driveRobot( 0, 0, -1, 0);
            //     std::cout << "move right" << std::endl;
            // }
            // else if(tx > targetX){//rotate left
            //     powerTrain.driveRobot( 0, 0, 1, 0);
            //     std::cout << "move left" << std::endl;
            } else {
                //m_robotDrive.DriveCartesian(0,0,0);
                powerTrain.driveRobot( 0, 0, 0);
                std::cout << "Target reached" << std::endl;
            }
            // if(ty > targetY){//move back
            //     powerTrain.driveRobot( 0, -1, 0, 0);
            // }
            // else if(ty < targetY){//move forward
            //     powerTrain.driveRobot( 0, 1, 0, 0);
            // }
        }
           
           
            // if (gyroAngle > 1 ){
            //     powerTrain.driveRobot( -0.2, 0.2, -0.6, 0);
            // }
            // else if(gyroAngle < -1 ){
            //     powerTrain.driveRobot( 0.2, -0.2, 0.5, 0);
            //}
        }

    }
}