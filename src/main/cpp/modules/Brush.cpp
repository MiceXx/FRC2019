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


}//namespace lcchs
}//namespace frc
