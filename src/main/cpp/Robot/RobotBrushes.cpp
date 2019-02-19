#include "Robot.h"
namespace frc
{
namespace lcchs
{

void Robot::operateBrush()
{
  bool grabCommand    = driveStation.getLeftBumper();
  bool releaseCommand = driveStation.getRightBumper();

  if(grabCommand)
  {
    grapple.openBrush();  
  }
  else if(releaseCommand)
  {
    grapple.closeBrush();
  }

}



}//namespace lcchs
}//namespace frc