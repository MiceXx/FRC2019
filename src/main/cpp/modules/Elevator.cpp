#include "Elevator.hpp"

namespace frc
{
namespace lcchs
{

void Elevator::moveLift(double speed)
{
  m_liftmotor.Set(ControlMode::PercentOutput, speed * scalingFactor);
}

void Elevator::setScaling(double scaling)
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
void Elevator::initializeElevator()
{
  // m_liftmotor.SetSafetyEnabled(false);
  m_liftmotor.ConfigSelectedFeedbackSensor(CTRE_MagEncoder_Absolute);
  // m_liftmotor.SetStatusFramePeriod(StatusFrame::Status_1_General_, 5, 30);
  m_liftmotor.SetSensorPhase(false);

  m_liftmotor.SetNeutralMode(NeutralMode::Coast);
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
  // m_liftmotor.Set(ctre::phoenix::motorcontrol::ControlMode::Position, destination);
  m_liftmotor.SetSelectedSensorPosition(destination, 0, 0);
}

//bool Elevator::isGrounded()
//{
//  return limitSwitch.Get();
//}

} // namespace lcchs
} // namespace frc