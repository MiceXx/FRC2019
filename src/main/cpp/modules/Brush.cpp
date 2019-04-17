#include "Brush.hpp"

namespace frc{
namespace lcchs{

void Brush::closeBrush()
{
    toothbrushes.Set(0);

}
void Brush::openBrush()
{
    double ninetyDegrees = 90/(toothbrushes.GetMaxAngle()-toothbrushes.GetMinAngle());
    toothbrushes.Set(ninetyDegrees);

}

void  Brush::initializeBrush()
{

}

}//namespace lcchs
}//namespace frc
