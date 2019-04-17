#ifndef BOOT
#define BOOT

#include <ctre/Phoenix.h>

namespace frc
{
namespace lcchs
{

class Boot
{
public:
  void moveStrap(double bootSpeed);

  void moveFoot(double speed);

  int getPosition();

  void initializeBoot();

private:
  static constexpr int kFootMotorChannel = 9;
  static constexpr int kStrapMotorChannel = 10;

  WPI_TalonSRX m_footmotor{kFootMotorChannel};
  WPI_VictorSPX m_strapmotor{kStrapMotorChannel};
};

} // namespace lcchs
} // namespace frc

#endif