#include "Robot.h"

namespace frc
{
namespace lcchs
{

void Robot::operateHinges()
{
  double wristCommand = driveStation.getRightHandY();
  double rootWristCommand;
  if (wristCommand < 0)
  {
    rootWristCommand = -sqrt(abs(wristCommand));
  }
  else
  {
    rootWristCommand = sqrt(wristCommand);
  }
  wrist.rotateHinges(wristCommand);
}

} //namespace lcchs
} //namespace frc