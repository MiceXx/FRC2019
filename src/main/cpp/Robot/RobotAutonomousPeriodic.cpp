#include "Robot.h"

#include <iostream>
#include <string>

namespace frc
{
namespace lcchs
{
void Robot::AutonomousPeriodic()
{
    TeleopPeriodic();
    if (m_autoSelected == kAutoNameCustom)
    {
        // Custom Auto goes here
    }
    else
    {
        // Default Auto goes here
    }
}
} // namespace lcchs
} // namespace frc



//Possible autonomous code: https://www.chiefdelphi.com/t/2220s-play-record-macro-for-autonomous/143379
//or https://github.com/DennisMelamed/FRC-Play-Record-Macro/tree/master/FRC2220-Play-Record-Macro-DM/src