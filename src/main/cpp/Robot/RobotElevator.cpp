#include "Robot.h"
#include <iostream>

namespace frc
{
namespace lcchs
{

int findClosestPositionIndex(double num, int targets[4]) //targets are in increasing order
{
    double minDif = 999999;
    int minIndex = 0;

    for (int i = 0; i < 4; i++)
    {
        double Dif = std::abs(targets[i] - num);
        if (Dif < minDif)
        {
            minIndex = i;
            minDif = Dif;
        }
        else
        {
            return minIndex;
        }
    }
    return minIndex;
}

void Robot::operateLift()
{
    int currentPov = driveStation.getPov();

    bool ballButtonPress = driveStation.getBButton();

    if (gamePadPOV != 0 && currentPov == 0) //up
    {
        if (liftLevel < 3)
        {
            liftLevel++;
        }
        elevatorAutoMode = true;
    }

    else if (gamePadPOV != 180 && currentPov == 180) //down
    {
        if (liftLevel > 0)
        {
            liftLevel--;
        }
        elevatorAutoMode = true;
    }

    // Hatch Openings
    else if (gamePadPOV != 90 && currentPov == 90) //right
    {
        selectHatch = true;
        selectBall = false;
        elevatorAutoMode = true;
        liftLevel = findClosestPositionIndex(liftPosition, hatchOpenings);
    }

    else if (gamePadPOV != 270 && currentPov == 270) //left
    {
        selectBall = true;
        selectHatch = false;
        elevatorAutoMode = true;
        liftLevel = findClosestPositionIndex(liftPosition, ballOpenings);
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

    //Rate Limiter (ramp up/down time)
    //we want tomake them asymetrical
    double rampUpTime = 0.07;

    if ((liftCommand - liftCommandFilter) > rampUpTime)
    {
        liftCommandFilter += rampUpTime;
    }
    else if ((liftCommand - liftCommandFilter) < -rampUpTime)
    {
        liftCommandFilter -= rampUpTime;
    }
    else
    {
        liftCommandFilter = liftCommand;
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
    else if (std::abs(liftCommandFilter) > 0.05)
    {
        elevator.moveLift(liftCommandFilter);

        selectHatch = false;
        selectBall = false;

        elevatorAutoMode = false;
    }
    else if ((std::abs(liftDestination - liftPosition) > 200) && elevatorAutoMode)
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
