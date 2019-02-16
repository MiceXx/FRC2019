#ifndef ELEVATOR
#define ELEVATOR

#include <ctre/Phoenix.h>

namespace frc {
namespace lcchs {


class Elevator
{
  public:
  // Raise (+) or lower (-) the lift
  void moveLift( double speed );

  void setScaling( double scaling );
  
  void initializeElevator();

  // 
  //bool bottomLift();

  int getPosition();

  int getVelocity();

  void resetEncoder();
  
  void setPosition(int destination);

  private: 

  double scalingFactor = 1;

  static constexpr int kLiftMotorChannel = 5;

  WPI_TalonSRX m_liftmotor{kLiftMotorChannel};

  


};





}  // namespace lcchs
}  // namespace frc

#endif