#include "Manipulator.hpp"

namespace frc {
namespace lcchs {


void Manipulator::moveLift( double speed ){
  m_liftmotor.Set(speed*scalingFactor);
}

void Manipulator::setScaling(double scaling){
  if(scaling<1.){
      scalingFactor=1.;
    }
    else if (scaling>6.){
      scalingFactor=6.;
    } else {
      scalingFactor = scaling;
    }
}
<<<<<<< HEAD
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
  m_liftmotor.StopMotor();
}

void Manipulator::setPosition(int destination)
{
  m_liftmotor.Set(ctre::phoenix::motorcontrol::ControlMode::Position,destination);
}  
=======
>>>>>>> 23731a1799086f92069e8a959859ba24b98818ed

}  // namespace lcchs
}  // namespace frc