#include "Robot.h"

namespace frc
{
namespace lcchs
{

void Robot::robotClimb()
{
    if (button10)
    {
        bootLevel++;
    }
    else if (button9)
    {
        bootLevel--;
    }
    bootDestination = bootOrientations[bootLevel];

    if (button8)
    {
        boot.moveStrap(jStick->GetY());
    }
    else
    {
        boot.moveStrap(0);
    }
    boot.elevateBoot(bootDestination);
}

} // namespace lcchs
} // namespace frc
