#include <ctre/Phoenix.h>
#include "MecanumDrive.h"

namespace frc {
namespace lcchs{

class PowerTrain {
public:
  void driveRobot( double xSpeed, double ySpeed, double zRotation, double gyroAngle);

  
  void drivedoublejoystick(double ySpeedLeft, double xSpeedLeft, double ySpeedRight, double xSpeedRight);

  void setScaling(double scaling);

  void initalizePowerTrain();

 private:

  
  
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

}   // namespacelcchs
}  // namespacefrc
