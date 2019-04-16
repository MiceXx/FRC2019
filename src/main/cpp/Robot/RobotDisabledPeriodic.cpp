#include "Robot.h"

namespace frc
{
namespace lcchs
{
void Robot::DisabledPeriodic()
{

    gyroArrayReadings[gyroIndex] = gyro.GetAngle();

    if (gyroIndex < gyroArraySize - 1)
    {
        gyroIndex++;
    }
    else
    {
        gyroIndex = 0;
    }
}

} // namespace lcchs
} // namespace frc