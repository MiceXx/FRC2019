
#include <frc/smartdashboard/SmartDashboard.h>
#include <cmath>
#include "PowerTrain.hpp"

namespace frc {
namespace lcchs{

  void PowerTrain::setScaling(double scaling){
<<<<<<< HEAD
    
    m_robotDrive.SetMaxOutput(  scaling  );
    
    }
=======
    if(scaling<1.){
        m_robotDrive.SetMaxOutput(1.);
    } else if (scaling>6.){
        m_robotDrive.SetMaxOutput(  6.  );
    } else {
        m_robotDrive.SetMaxOutput(  scaling  );
    }
  }
>>>>>>> 467fe5552e190cdea959fe280ce1239d6ae0316c

  void PowerTrain::driveRobot( double xSpeed, double ySpeed, double zRotation, double gyroAngle)
  {
      
      double rotation = zRotation;
   

   /* Use the joystick X axis for lateral movement, Y axis for forward
     * movement, and Z axis for rotation.
     */
      
      m_robotDrive.DriveCartesian(-ySpeed,xSpeed,zRotation,-gyroAngle);


  }
  
  void PowerTrain::drivedoublejoystick(double ySpeedLeft, double xSpeedLeft, double ySpeedRight, double xSpeedRight)
  {

   /* Use the joystick X axis for lateral movement, Y axis for forward
     * movement, and Z axis for rotation.
     */
      m_robotDrive.DriveTank(-ySpeedLeft,xSpeedLeft,-ySpeedRight,xSpeedRight);


  }

  void PowerTrain::DrivebaseStrafe( double xSpeed, double ySpeed, double zRotation, double gyroAngle){
  
  PowerTrain::driveRobot(   xSpeed,  ySpeed,  zRotation,  gyroAngle);

  }

  void PowerTrain::initalizePowerTrain()
  {
    // Invert the left side motors. You may need to change or remove this to
    // match your robot.
    //m_frontLeft.SetInverted(true);
    //m_rearLeft.SetInverted(true);

  }
 

}   // namespacelcchs
}  // namespacefrc