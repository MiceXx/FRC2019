#include "Robot.h"
namespace frc
{
namespace lcchs
{
    void Robot::operateBrush()
{
    if(driveStation.getLeftBumper())
    {
    grapple.openBrush();  
    }
    else if(driveStation.getRightBumper())
    {
    grapple.closeBrush();
    }
}



}//namespace lcchs
}//namespace frc