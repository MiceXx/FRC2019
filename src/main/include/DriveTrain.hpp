#include <ctre/Phoenix.h>
#include "MecanumDrive.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <cmath>

class DriveTrain {
public:
  void driveRobot( double xSpeed, double ySpeed, double zRotation, double gyroAngle)
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

void drivedoublejoystick(double ySpeedLeft, double xSpeedLeft, double ySpeedRight, double xSpeedRight)
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

  void initalizeDriveTrain()
  {
    // Invert the left side motors. You may need to change or remove this to
    // match your robot.
    //m_frontLeft.SetInverted(true);
    //m_rearLeft.SetInverted(true);

  }
 private:
  
      //changes from 1 joystick to 2 joysticks
    //boul doublejoystick=true

    //frc::SmartDashboard::PutBoolean("DB/Button 0", true);
  
  
  static constexpr int kFrontLeftChannel = 1;
  static constexpr int kRearLeftChannel = 2;
  static constexpr int kFrontRightChannel = 0;
  static constexpr int kRearRightChannel = 3;

  // possible patch for double stick
//  static constexpr int kFrontLeftChannel  = 0;
//  static constexpr int kRearLeftChannel   = 1;
//  static constexpr int kFrontRightChannel = 2;
//  static constexpr int kRearRightChannel  = 3;

  WPI_TalonSRX m_frontLeft{kFrontLeftChannel};
  WPI_TalonSRX m_rearLeft{kRearLeftChannel};
  WPI_TalonSRX m_frontRight{kFrontRightChannel};
  WPI_TalonSRX m_rearRight{kRearRightChannel};
  frc::lcchs::MecanumDrive m_robotDrive{m_frontLeft, m_rearLeft, m_frontRight,
                                 m_rearRight};
};