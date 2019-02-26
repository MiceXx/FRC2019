#include "Hinges.hpp"
#include <iostream>

namespace frc
{
namespace lcchs
{

void Hinges::rotateHinges(double Direction)
{

    hingeMotor.Set(Direction * scalingFactor);
}

void Hinges::setScaling(double scaling)
{
    if (scaling < 0.)
    {
        scalingFactor = 0;
    }
    else if (scaling > 1.)
    {
        scalingFactor = 1;
    }
    else
    {
        scalingFactor = scaling;
    }
}

void Hinges::angleForTime(double speed, double timeAllocated)
{
    double start = Timer().GetFPGATimestamp();
    while (Timer().GetFPGATimestamp() - start < timeAllocated)
    {
        this->rotateHinges(speed);
        std::cout << "the time.." << Timer().GetFPGATimestamp() << std::endl;
    }
}
} // namespace lcchs
} // namespace frc
