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

void Manipulator::initializeManipulator()
{
  m_liftmotor.ConfigSelectedFeedbackSensor(CTRE_MagEncoder_Absolute);
}

int Manipulator::getPosition()
{
  return m_liftmotor.GetSelectedSensorPosition();
}

int Manipulator::getVelocity()
{
  return m_liftmotor.GetSelectedSensorVelocity();
}

void Manipulator::resetEncoder()
{
m_liftmotor.SetSelectedSensorPosition(0);
}

}  // namespace lcchs
}  // namespace frc
