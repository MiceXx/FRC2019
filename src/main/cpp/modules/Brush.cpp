#include "Brush.hpp"

namespace frc{
namespace lcchs{

void Brush::closeBrush()
{
    toothbrushes.Set(0);

}
void Brush::openBrush()
{
    toothbrushes.Set(1);

}


}//namespace lcchs
}//namespace frc
