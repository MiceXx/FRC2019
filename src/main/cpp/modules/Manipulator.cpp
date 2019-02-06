#include "Manipulator.hpp"

namespace frc {
namespace lcchs {


void Manipulator::moveLift( double speed ){
  m_liftmotor.Set(speed*scalingFactor);
}

void Manipulator::setScaling(double scaling){
  if(scaling<1.){
      scalingFactor=1.;
    }
    else if (scaling>6.){
      scalingFactor=6.;
    } else {
      scalingFactor = scaling;
    }
}

}  // namespace lcchs
}  // namespace frc