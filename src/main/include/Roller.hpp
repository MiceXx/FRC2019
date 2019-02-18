#pragma once

#include <ctre/Phoenix.h>

namespace frc
{
namespace lcchs
{
class Roller
{
  public:
    void shootBall()
    {

        m_rollerRight.Set(-1);
        m_rollerLeft.Set(1);
    };
    void captureBall()
    {

        m_rollerRight.Set(1);
        m_rollerLeft.Set(-1);
    };

    void stopRollers()
    {

        m_rollerRight.Set(0);
        m_rollerLeft.Set(0);
    }

  private:
    static constexpr int kRollerLeftChannel = 6;
    static constexpr int kRollerRightChannel = 7;

    WPI_TalonSRX m_rollerRight{kRollerRightChannel};
    WPI_TalonSRX m_rollerLeft{kRollerLeftChannel};
};

} // namespace lcchs
} // namespace frc