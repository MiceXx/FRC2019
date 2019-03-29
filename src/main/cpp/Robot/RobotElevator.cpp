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
void Robot::operateLiftAuto()
{
    int currentPov = driveStation.getPov();

    bool ballButtonPress = driveStation.getBButton();

    if (gamePadPOV != 0 && currentPov == 0) //up
    {
        if (liftLevel < 3)
        {
            liftLevel++;
        }
        //elevatorAutoMode = true;
    }

    else if (gamePadPOV != 180 && currentPov == 180) //down
    {
        if (liftLevel > 0)
        {
            liftLevel--;
        }
        //elevatorAutoMode = true;
    }

    // Hatch Openings
    else if (gamePadPOV != 90 && currentPov == 90) //right
    {
        selectHatch = true;
        selectBall = false;
        //elevatorAutoMode = true;
    }

    else if (gamePadPOV != 270 && currentPov == 270) //left
    {
        selectBall = true;
        selectHatch = false;
        //elevatorAutoMode = true;
    }
    //
    else
    {
        if (selectHatch)
        {
            liftLevel = findClosestPositionIndex(liftPosition, hatchOpenings);
        }
        if (selectBall)
        {
            liftLevel = findClosestPositionIndex(liftPosition, ballOpenings);
        }
        else
        {
            liftLevel = 0;
        }
    }

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
        //elevatorAutoMode = true;
    }

    if (liftReset)
    {
        elevator.resetEncoder();
        liftDestination = elevator.getPosition();
        liftLevel = 0;

        selectHatch = false;
        selectBall = false;

        //elevatorAutoMode = false;
    }
    else if (std::abs(liftDestination - liftPosition) > 200)
    {
        elevator.setPosition(liftDestination);
    }
    else
    {
        elevator.stopMotor();
        //elevatorAutoMode = false;
    }
} //operateLift()

void Robot::operateLiftManual()
{
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

    if (std::abs(liftCommandFilter) > rampUpTime)
    {
        elevator.moveLift(liftCommandFilter);

        selectHatch = false;
        selectBall = false;

        //elevatorAutoMode = false;
    }
    else
    {
        elevator.stopMotor();
        //elevatorAutoMode = false;
    }
}

} //namespace lcchs
} //namespace frc
