#include "frc/Servo.h"

namespace frc{
namespace lcchs{

class Brush {
public: 

void closeBrush();

void openBrush();

void  initializeBrush();

private:
static constexpr int toothbrushesChannel = 0;

frc::Servo toothbrushes{toothbrushesChannel};
};
}//namespace lcchs
}//namespace frc