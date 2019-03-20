#include "Robot.h"
#include <iostream>

namespace frc
{
namespace lcchs
{

void Robot::operateLift()
{
    int currentPov = driveStation.getPov();

    //lift Ops
    liftPosition = elevator.getPosition();
    liftVelocity = elevator.getVelocity();
    liftCommand = driveStation.getLeftHandY();
    liftReset = driveStation.getYButton();
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
    }

    if (gamePadPOV != 180 && currentPov == 180)
    {
        if (liftLevel > 0)
        {
            liftLevel--;
        }
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
    }

    //Move Wrist at top
    if (liftPosition < -26000 && selectBall)
    {
        wrist.rotateHinges(0.4);
    }

    if (liftReset)
    {
        elevator.resetEncoder();
        liftDestination = elevator.getPosition();
        liftLevel = 0;
    }
    else if (!elevatorAutoMode)
    //else if (abs(liftCommand) > 0.05)
    {
        if (abs(liftCommand) > 0.05)
        {
            elevator.moveLift(liftCommand);
            liftDestination = liftPosition;
            selectHatch = false;
            selectBall = false;
        }
        else
        {
            elevator.moveLift(0.0);
        }
    }
    else if (elevatorAutoMode)
    {
        while (liftDestination != liftPosition)
        {
            elevator.setPosition(liftDestination);
        }

        elevator.moveLift(0.0);
    }
    else
    {
        elevator.moveLift(0.0);
    }

    elevatorAutoMode = false;

    // //large current draw fix
    // if ((liftPosition < -13600 && liftPosition > 12000) || (liftPosition < -34000 && liftPosition > -33000) || (liftPosition < -48500 && liftPosition > -47000) && (liftVelocity = 0))
    // {
    //     // elevator.moveLift(-0.1);

    //     //liftDestination = liftDestination - 1000;

    //     double start = Timer().GetFPGATimestamp();
    //     if (Timer().GetFPGATimestamp() - start < 2)
    //     {
    //         elevator.moveLift(-0.8);
    //     }
    // }
    // // else if (liftLevel = 0)
    // // {
    // // }

} //operateLift()

} //namespace lcchs
} //namespace frc
