#include "Robot.h"

namespace frc
{
namespace lcchs
{

void Robot::robotClimb()
{
    if (autoClimbState > 0)
    {
        }
    else
    {
        if (button9->Get())
        {
            boot.moveStrap(jStick->GetY());
        }
        else
        {
            boot.moveStrap(0);
        }
        if (jStick->GetPOV() == 0)
        {
            boot.moveFoot(1);
        }
        else if (jStick->GetPOV() == 180)
        {
            boot.moveFoot(-1);
        }
        else
        {
            boot.moveFoot(0);
        }
    }
}

} // namespace lcchs
} // namespace frc
