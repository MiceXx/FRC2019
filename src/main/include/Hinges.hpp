#include <ctre/Phoenix.h>
namespace frc 
{
namespace lcchs
{
class Hinges {


public:

void rotateHinges(double Direction);


private:


static constexpr int hingeMotorChannel = 8;
WPI_VictorSPX hingeMotor{hingeMotorChannel};
};


}//namespace lcchs
}//namespace frc
