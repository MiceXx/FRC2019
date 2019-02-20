#include "Robot.h"

namespace frc
{
namespace lcchs
{

void Robot::operateHinges()
{
  double rootWristCommand;
  wristCommand = driveStation.getRightHandY();

  if (wristCommand < 0)
  {
    rootWristCommand = -sqrt(abs(wristCommand));
  }
  else
  {
    rootWristCommand = sqrt(wristCommand);
  }
  wrist.rotateHinges(wristCommand);

  if (driveStation.getXButton())
    {
        wrist.angleForTime(0.3, 2);
    }
}

} //namespace lcchs
} //namespace frc