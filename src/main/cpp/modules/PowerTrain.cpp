
#include <frc/smartdashboard/SmartDashboard.h>
#include <cmath>
#include "PowerTrain.hpp"

namespace frc {
namespace lcchs{

  void PowerTrain::setScaling(double scaling){
    
    m_robotDrive.SetMaxOutput(  scaling  );
    
    }

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

  void PowerTrain::DrivebaseStrafe(double ySpeedLeft, double xSpeedLeft, double ySpeedRight, double xSpeedRight){
  
  PowerTrain::driveRobot( ySpeedLeft,  xSpeedLeft,  ySpeedRight,  xSpeedRight);

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