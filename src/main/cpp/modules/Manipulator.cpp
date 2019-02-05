#include "Manipulator.hpp"

namespace frc {
namespace lcchs {


void Manipulator::moveLift( double speed )
{
  m_liftmotor.Set(speed*scalingFactor);


}

void Manipulator::setScaling(double scaling)
{

scalingFactor = scaling;

}

}  // namespace lcchs
}  // namespace frc