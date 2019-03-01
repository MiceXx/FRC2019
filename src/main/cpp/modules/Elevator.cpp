#include "Elevator.hpp"

namespace frc
{
namespace lcchs
{

void Elevator::moveLift( double speed ){
  m_liftmotor.Set(speed*scalingFactor);
}

void Elevator::setScaling(double scaling){
  if(scaling<0.){
      scalingFactor=0;
    }
    else if (scaling>1.){
      scalingFactor=1;
    } else {
      scalingFactor = scaling;
    }
}
void Elevator::initializeElevator()
{
  m_liftmotor.ConfigSelectedFeedbackSensor(CTRE_MagEncoder_Absolute);
  m_liftmotor.SetSensorPhase(false);
  //m_liftmotor.SetInverted(true);

}

int Elevator::getPosition()
{
  return m_liftmotor.GetSelectedSensorPosition();

}

int Elevator::getVelocity()
{
  return m_liftmotor.GetSelectedSensorVelocity();
}

void Elevator::resetEncoder()
{ 
  m_liftmotor.SetSelectedSensorPosition(0);
  m_liftmotor.StopMotor();
}

void Elevator::setPosition(int destination)
{
  m_liftmotor.Set(ctre::phoenix::motorcontrol::ControlMode::Position, destination);
} 
  
  
//bool Elevator::isGrounded()
//{
//  return limitSwitch.Get();
//}

} // namespace lcchs
} // namespace frc