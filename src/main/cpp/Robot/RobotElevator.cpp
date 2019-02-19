#include "Robot.h"

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
    }

    if (gamePadPOV != 270 && currentPov == 270)
    {
        selectBall = true;
        selectHatch = false;
    }
    //

    gamePadPOV = currentPov;

    if (selectHatch)
    {
        liftDestination = hatchOpenings[liftLevel];
    }
    else if (selectBall)
    {
        liftDestination = ballOpenings[liftLevel];
    }

    //Move Wrist at top
    // if (liftLevel = 3 && selctball = true){

    // }

    if (liftReset)
    {
        elevator.resetEncoder();
        liftDestination = elevator.getPosition();
    }
    else if (abs(liftCommand) > 0.05)
    {
        elevator.moveLift(liftCommand);
        liftDestination = liftPosition;
        selectHatch = false;
        selectBall = false;
    }
    else
    {
        elevator.setPosition(liftDestination);
    }

    driveStation.setString(5, std::to_string(liftPosition));

    driveStation.setString(6, std::to_string(liftVelocity));

    driveStation.setString(7, std::to_string(liftCommand));

    driveStation.setString(8, std::to_string(liftDestination));

    driveStation.setString(9, std::to_string(gamePadPOV));

    driveStation.setString(4, std::to_string(liftLevel));

} //operateLift()

} //namespace lcchs
} //namespace frc
