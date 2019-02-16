#include "Robot.h"

namespace frc 
{
namespace lcchs
{

void Robot::operateHinges()
{
wrist.rotateHinges(driveStation.getRightHandY());
}



}//namespace lcchs
}//namespace frc