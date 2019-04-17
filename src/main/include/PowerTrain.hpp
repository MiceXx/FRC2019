#include <ctre/Phoenix.h>
//#include "MecanumDrive.h"
#include <frc/drive/MecanumDrive.h>

namespace frc
{
namespace lcchs
{

class PowerTrain
{
public:
  void driveRobot(double xSpeed, double ySpeed, double zRotation, double gyroAngle = 0);

  void setScaling(double scaling);

  void initalizePowerTrain();

  void DrivebaseStrafe(double xSpeed, double ySpeed, double zRotation, double gyroAngle);

  //getting speeds from each motor (macro)
  double getSpeedFL();
  double getSpeedRL();
  double getSpeedFR();
  double getSpeedRR();

private:
  static constexpr int kFrontLeftChannel = 4;
  static constexpr int kFrontRightChannel = 1;
  static constexpr int kRearLeftChannel = 3;
  static constexpr int kRearRightChannel = 2;

  WPI_VictorSPX m_frontLeft{kFrontLeftChannel};
  WPI_VictorSPX m_rearLeft{kRearLeftChannel};
  WPI_VictorSPX m_frontRight{kFrontRightChannel};
  WPI_VictorSPX m_rearRight{kRearRightChannel};
  frc::MecanumDrive m_robotDrive{m_frontLeft, m_rearLeft, m_frontRight,
                                 m_rearRight};
};

} // namespace lcchs
} // namespace frc
