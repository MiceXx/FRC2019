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
  m_liftmotor.Config_kP(0, 0.2);
  m_liftmotor.Config_kI(0, 0.04);
  //m_liftmotor.Config_kF(0, 0.0);
  //m_liftmotor.Config_kD(0, 0.0);
  m_liftmotor.ConfigMaxIntegralAccumulator(0, 1000);
  m_liftmotor.SetNeutralMode(NeutralMode::EEPROMSetting);
  m_liftmotor.ConfigPeakOutputForward(0.5);
  m_liftmotor.ConfigPeakOutputReverse(-0.75);
  m_liftmotor.ConfigMotionCruiseVelocity(3000);
  m_liftmotor.ConfigMotionAcceleration(4000);
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

void Elevator::stopMotor()
{
  m_liftmotor.StopMotor();
}

void Elevator::setPosition(int destination)
{
  m_liftmotor.Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, destination);
  //m_liftmotor.SetSelectedSensorPosition(destination, 0, 0);
}



//bool Elevator::isGrounded()
//{
//  return limitSwitch.Get();
//}

} // namespace lcchs
} // namespace frc