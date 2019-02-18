#include "Robot.h"

namespace frc
{
namespace lcchs
{

void Robot::operateLift()
{
    int currentPov = driveStation.getPov();

    //lift Ops
    liftPosition = manipulator.getPosition();
    liftVelocity = manipulator.getVelocity();
    liftCommand = driveStation.getLeftHandY();
    liftReset = driveStation.getYButton();

    // if (gyroAngle > -135 +tolerance || 45 )
    // {

    // }
    // else

    // Hatch Openings
    if (gamePadPOV != 90 && currentPov == 90)
    {
        selectHatch = true;
        selectBall = false;
    }

    if (gamePadPOV != -90 && currentPov == -90)
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
    else
    {
        liftDestination = ballOpenings[liftLevel];
    }

    

    if (liftReset)
    {
        manipulator.resetEncoder();
        liftDestination = manipulator.getPosition();
    }
    else if (abs(liftCommand) > 0.05)
    {
        manipulator.moveLift(liftCommand);
        liftDestination = liftPosition;
    }
    else
    {
        manipulator.setPosition(liftDestination);
    }

    driveStation.setString(5, std::to_string(liftPosition));

    driveStation.setString(6, std::to_string(liftVelocity));

    driveStation.setString(7, std::to_string(liftCommand));

    driveStation.setString(8, std::to_string(liftDestination));

    driveStation.setString(9, std::to_string(gamePadPOV));

} //operateLift()

} //namespace lcchs
} //namespace frc
