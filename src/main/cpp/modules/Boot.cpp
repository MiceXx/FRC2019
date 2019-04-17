#include "robot.h"

namespace frc
{
namespace lcchs
{

void Boot::moveStrap(double bootSpeed)
{
  m_strapmotor.Set(ControlMode::PercentOutput, bootSpeed);
}

void Boot::initializeBoot()
{

  m_footmotor.ConfigSelectedFeedbackSensor(CTRE_MagEncoder_Absolute);

  m_footmotor.SetSensorPhase(false);

  m_footmotor.SetNeutralMode(NeutralMode::EEPROMSetting);
}

void Boot::moveFoot(double speed)
{
  m_footmotor.Set(ControlMode::PercentOutput, speed);
  //m_footmotor.SetSelectedSensorPosition(destination, 0, 0);
}

int Boot::getPosition()
{
  return m_footmotor.GetSelectedSensorPosition();
}

} // namespace lcchs
} // namespace frc

