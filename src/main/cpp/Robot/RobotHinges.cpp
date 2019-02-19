#include "Robot.h"

namespace frc 
{
namespace lcchs
{

void Robot::operateHinges()
{
  double wristCommand = driveStation.getRightHandY();

  wrist.rotateHinges(wristCommand);

}



}//namespace lcchs
}//namespace frc