#include "Camera.hpp"
#include "ugdk/math/vector2D.h"
#include "ugdk/graphic/geometry.h"

namespace amb {
    const ugdk::math::Vector2D Camera::_VectorZero(0, 0);
    const ugdk::math::Vector2D Camera::_VectorOne (1, 1);
    
    Camera::Camera() {
    }
    
    void Camera::setScale(const ugdk::math::Vector2D& s) {
        ugdk::math::Vector2D scale = geometry_.CalculateScale();
        geometry_.Compose(Geometry({0, 0}, ugdk::math::Vector2D(1/scale.x, 1/scale.y).Scale(s)));
    }
}