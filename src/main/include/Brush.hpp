#include "frc/Servo.h"

namespace frc{
namespace lcchs{

class Brush {
public: 

void closeBrush();

void openBrush();

private:
static constexpr int toothbrushesChannel = 6;

frc::Servo toothbrushes{toothbrushesChannel};
};
}//namespace lcchs
}//namespace frc