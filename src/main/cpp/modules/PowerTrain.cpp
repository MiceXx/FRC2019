
#include <frc/smartdashboard/SmartDashboard.h>
#include <cmath>
#include "PowerTrain.hpp"

namespace frc
{
namespace lcchs
{

void PowerTrain::setScaling(double scaling)
{
  if (scaling < 1.)
  {
    m_robotDrive.SetMaxOutput(1.);
  }
  else if (scaling > 6.)
  {
    m_robotDrive.SetMaxOutput(6.);
  }
  else
  {
    m_robotDrive.SetMaxOutput(scaling);
  }
}

void PowerTrain::driveRobot(double ySpeed, double xSpeed, double zRotation, double gyroAngle)
{
  /* Use the joystick X axis for lateral movement, Y axis for forward
     * movement, and Z axis for rotation.
     */
  m_robotDrive.DriveCartesian(ySpeed, -xSpeed, zRotation, -gyroAngle);
}

void PowerTrain::drivedoublejoystick(double ySpeedLeft, double xSpeedLeft, double ySpeedRight, double xSpeedRight)
{
  /* Use the joystick X axis for lateral movement, Y axis for forward
     * movement, and Z axis for rotation.
     */
  // m_robotDrive.DriveTank(-ySpeedLeft,xSpeedLeft,-ySpeedRight,xSpeedRight);
}

void PowerTrain::initalizePowerTrain()
{
  // Invert the left side motors. You may need to change or remove this to
  // match your robot.
  m_frontLeft.SetInverted(true);
  m_rearLeft.SetInverted(true);
  m_frontRight.SetInverted(true);
  m_rearRight.SetInverted(true);
}

} // namespace lcchs
} // namespace frc