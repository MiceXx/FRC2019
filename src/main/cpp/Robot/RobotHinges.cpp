#include "Robot.h"

namespace frc 
{
namespace lcchs
{

void Robot::operateHinges()
{
  wrist.rotateHinges(wristCommand);

}



}//namespace lcchs
}//namespace frc