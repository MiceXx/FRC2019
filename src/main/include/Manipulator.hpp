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
  
<<<<<<< HEAD
  void initializeManipulator();
=======
>>>>>>> 467fe5552e190cdea959fe280ce1239d6ae0316c

  // 
  //bool bottomLift();

<<<<<<< HEAD
  int getPosition();

  int getVelocity();

  void resetEncoder();

=======
>>>>>>> 467fe5552e190cdea959fe280ce1239d6ae0316c
  private: 

  double scalingFactor = 1;

  static constexpr int kLiftMotorChannel = 4;

  WPI_TalonSRX m_liftmotor{kLiftMotorChannel};

<<<<<<< HEAD
  


=======
>>>>>>> 467fe5552e190cdea959fe280ce1239d6ae0316c
};





}  // namespace lcchs
}  // namespace frc

#endif