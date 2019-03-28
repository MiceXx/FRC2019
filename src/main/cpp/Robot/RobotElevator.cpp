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

    if (gamePadPOV != 0 && currentPov == 0) //up
    {
        if (liftLevel < 3)
        {
            liftLevel++;
        }
    }

    if (gamePadPOV != 180 && currentPov == 180) //down
    {
        if (liftLevel > 0)
        {
            liftLevel--;
        }
    }

    // Hatch Openings
    if (gamePadPOV != 90 && currentPov == 90) //right
    {
        selectHatch = true;
        selectBall = false;
    }

    if (gamePadPOV != 270 && currentPov == 270) //left
    {
        selectBall = true;
        selectHatch = false;
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

    if (liftReset)
    {
        elevator.resetEncoder();
        liftDestination = elevator.getPosition();
        liftLevel = 0;

        selectHatch = false;
        selectBall = false;
    }
    else if (std::abs(liftCommand) > 0.05)
    {
        elevator.moveLift(liftCommand);
        liftDestination = liftPosition;
        
        selectHatch = false;
        selectBall = false;
    }
    else if (std::abs(liftDestination - liftPosition) > 250)
    {
        elevator.setPosition(liftDestination);
    }
    else
    {
        elevator.moveLift(0.0);
    }

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
