#ifndef MANIPULATOR
#define MANIPULATOR

#include <ctre/Phoenix.h>

namespace frc {
namespace lcchs {


class Manipulator
{
  public:
  // Raise (+) or lower (-) the lift
  void moveLift( double speed );

  void setScaling( double scaling );
  

  // 
  //bool bottomLift();

  private: 

  double scalingFactor = 1;

  static constexpr int kLiftMotorChannel = 5;

  WPI_TalonSRX m_liftmotor{kLiftMotorChannel};

};





}  // namespace lcchs
}  // namespace frc

#endif