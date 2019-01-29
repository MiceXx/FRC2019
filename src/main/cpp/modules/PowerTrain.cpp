
#include <frc/smartdashboard/SmartDashboard.h>
#include <cmath>
#include "PowerTrain.hpp"

namespace frc {
namespace lcchs{

  void PowerTrain::driveRobot( double xSpeed, double ySpeed, double zRotation, double gyroAngle)
  {
    
      double scaling=frc::SmartDashboard::GetNumber("DB/Slider 0", 0.0) +1. ;

      double rotation = zRotation;

    if(scaling<1.)
    {
      scaling=1.;
    }
    else if (scaling>6.)
    {
      scaling=6.;
    }


    /*
    if( rotation>0 )
    { rotation=sqrt(rotation); }
    else
    { rotation= -1.*sqrt( abs(rotation) ); }
    */
    

   /* Use the joystick X axis for lateral movement, Y axis for forward
     * movement, and Z axis for rotation.
     */
      m_robotDrive.DriveCartesian(-ySpeed/scaling,xSpeed/scaling,zRotation/scaling,-gyroAngle);


  }
  
  void PowerTrain::drivedoublejoystick(double ySpeedLeft, double xSpeedLeft, double ySpeedRight, double xSpeedRight)
  {
    
      double scaling=frc::SmartDashboard::GetNumber("DB/Slider 0", 0.0) +1. ;

    if(scaling<1.)
    {
      scaling=1.;
    }
    else if (scaling>6.)
    {
      scaling=6.;
    }


   /* Use the joystick X axis for lateral movement, Y axis for forward
     * movement, and Z axis for rotation.
     */
      m_robotDrive.DriveTank(-ySpeedLeft/scaling,xSpeedLeft/scaling,-ySpeedRight/scaling,xSpeedRight/scaling);


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