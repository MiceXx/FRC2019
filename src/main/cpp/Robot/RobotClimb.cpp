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

//Possible autonomous code: https://www.chiefdelphi.com/t/2220s-play-record-macro-for-autonomous/143379
//or https://github.com/DennisMelamed/FRC-Play-Record-Macro/tree/master/FRC2220-Play-Record-Macro-DM/src