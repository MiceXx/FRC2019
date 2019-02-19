#ifndef MANIPULATOR
#define MANIPULATOR

#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>

namespace frc
{
namespace lcchs
{

class Manipulator
{
public:
  // Raise (+) or lower (-) the lift
  void moveLift(double speed);

  void setScaling(double scaling);

  void initializeManipulator();

  //
  //bool bottomLift();

  int getPosition();

  int getVelocity();

  void resetEncoder();

  void setPosition(int destination);

private:
  double scalingFactor = 1;

  static constexpr int kLiftMotorChannel = 5;

  static constexpr int limitSwitchChannel = 0;

  WPI_TalonSRX m_liftmotor{kLiftMotorChannel};

  frc::DigitalInput limitSwitch{limitSwitchChannel};
};

} // namespace lcchs
} // namespace frc

#endif