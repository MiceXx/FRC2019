#include "Robot.h"

namespace frc
{
namespace lcchs
{

void Robot::robotClimb()
{
    if (button10->Get() != autoClimbSwitch)
    {
        if (autoClimbState > 0) // aborts auto climb
        {
            autoClimbState = 0;
            timeClimber = 0;
        }
        else //start auto climb
        {
            autoClimbState = 1;
            timeClimber = tClimb;
        }
    }

    autoClimbSwitch = button10->Get();

    if (autoClimbState > 0)
    {
        switch (autoClimbState)
        {
        case 1: //extend foot, reverse drive belt

            if (timeClimber < t1)
            {
                autoClimbState = 2;
            }

            boot.moveFoot(1);

            boot.moveStrap(-1);

            powerTrain.driveRobot(0, 0.4, 0, 0);

            break;
        case 2:

            if (timeClimber < t2)
            {
                autoClimbState = 3;
            }

            powerTrain.driveRobot(0, 1, 0, 0);
            boot.moveStrap(1);
            //may need hold power for the foot
            break;
        case 3: //retract foot

            if (timeClimber < t3)
            {
                autoClimbState = 4;
            }

            boot.moveFoot(-1);
            boot.moveStrap(1);
            powerTrain.driveRobot(0, 0.15, 0, 0);
            break;
        case 4:

            if (timeClimber < t4)
            {
                autoClimbState = 0;
            }
            powerTrain.driveRobot(0, 1, 0, 0);
            boot.moveStrap(1);
            break;
        }
        if (timeClimber > 0)
        {
            timeClimber -= period;
        }
        else
        {
            timeClimber = 0;
        }
    }
    else
    {
        if (button9->Get())
        {
            boot.moveStrap(-jStick->GetY());
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
