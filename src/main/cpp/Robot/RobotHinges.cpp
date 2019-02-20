#include "Robot.h"

namespace frc 
{
namespace lcchs
{

void Robot::operateHinges()
{
  wristCommand = driveStation.getRightHandY();

  wrist.rotateHinges(wristCommand);

}



}//namespace lcchs
}//namespace frc