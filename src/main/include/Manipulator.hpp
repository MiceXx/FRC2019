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
  
  void initializeManipulator();

  // 
  //bool bottomLift();

  int getPosition();

  int getVelocity();

  void resetEncoder();

  private: 

  double scalingFactor = 1;

  static constexpr int kLiftMotorChannel = 4;

  WPI_TalonSRX m_liftmotor{kLiftMotorChannel};

  


};





}  // namespace lcchs
}  // namespace frc

#endif