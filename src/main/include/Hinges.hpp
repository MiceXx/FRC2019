#include <ctre/Phoenix.h>
#include <cmath>

namespace frc
{
namespace lcchs
{
class Hinges
{

public:
  void rotateHinges(double Direction);
  void setScaling(double scaling);
  void angleForTime(double speed, double time);
  void  initializeHinges();
private:
  double scalingFactor = 1;

  static constexpr int hingeMotorChannel = 8;
  WPI_TalonSRX hingeMotor{hingeMotorChannel};
};

} //namespace lcchs
} //namespace frc
