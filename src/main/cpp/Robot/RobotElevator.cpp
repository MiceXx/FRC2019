#include "Robot.h"
#include <iostream>

namespace frc
{
namespace lcchs
{

void Robot::operateLift()
{
    int currentPov = driveStation.getPov();

    bool ballButtonPress = driveStation.getBButton();

    // if (gyroAngle > -135 +tolerance || 45 )
    // {

    // }
    // else

    if (gamePadPOV != 0 && currentPov == 0)
    {
        if (liftLevel < 3)
        {
            liftLevel++;
        }
        elevatorAutoMode = true;
    }

    if (gamePadPOV != 180 && currentPov == 180)
    {
        if (liftLevel > 0)
        {
            liftLevel--;
        }
        elevatorAutoMode = true;
    }

    // Hatch Openings
    if (gamePadPOV != 90 && currentPov == 90)
    {
        selectHatch = true;
        selectBall = false;
        elevatorAutoMode = true;
    }

    if (gamePadPOV != 270 && currentPov == 270)
    {
        selectBall = true;
        selectHatch = false;
        elevatorAutoMode = true;
    }
    //

    gamePadPOV = currentPov;

    if (selectHatch)
    {
        liftDestination = hatchOpenings[liftLevel];
        wristDestination = wristAngles[liftLevel];
    }
    else if (selectBall)
    {
        liftDestination = ballOpenings[liftLevel];
        wristDestination = wristAngles[liftLevel];
    }
    else if (ballButtonPress)
    {
        liftDestination = loadingStation;
        wristDestination = 0.05;
        elevatorAutoMode = true;
    }

    if (liftReset)
    {
        elevator.resetEncoder();
        liftDestination = elevator.getPosition();
        liftLevel = 0;

        selectHatch = false;
        selectBall = false;

        elevatorAutoMode = false;
    }
    else if (std::abs(liftCommand) > 0.05)
    {
        elevator.moveLift(liftCommand);

        selectHatch = false;
        selectBall = false;

        elevatorAutoMode = false;
    }
    else if ((std::abs(liftDestination - liftPosition) > 300) && elevatorAutoMode)
    {
        elevator.setPosition(liftDestination);
    }
    else
    {
        elevator.stopMotor();
        elevatorAutoMode = false;
    }
} //operateLift()

} //namespace lcchs
} //namespace frc
