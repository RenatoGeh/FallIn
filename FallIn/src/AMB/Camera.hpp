#ifndef CAMERA_HPP
#define	CAMERA_HPP

#include <ugdk/graphic/geometry.h>
#include <ugdk/math.h>

namespace {
    using ugdk::graphic::Geometry;
}

namespace amb {
    class Camera {
    public:
        Camera();
        
        inline void translate(const ugdk::math::Vector2D& t) { geometry_.ChangeOffset(geometry_.offset() + t); }
        inline void setTranslation(const ugdk::math::Vector2D& t) { geometry_.ChangeOffset(t); }
        
        inline void scale(const ugdk::math::Vector2D& s) { geometry_.Compose(Geometry(_VectorZero, s)); }
        void setScale(const ugdk::math::Vector2D&);
        
        inline void rotate(double angle) { geometry_.Compose(Geometry(_VectorZero, _VectorOne, angle)); }
        inline void setRotation(double angle) { geometry_.Compose(Geometry(_VectorZero, _VectorOne, angle - geometry_.rotation())); }
        
        inline Geometry applyOn(const Geometry& geo) { return geo * geometry_; }
        inline Geometry& getGeometry() { return geometry_; }
        inline const Geometry& getGeometry() const { return geometry_; }
    private:
        Geometry geometry_;
        
        static const ugdk::math::Vector2D _VectorZero;
        static const ugdk::math::Vector2D _VectorOne;
    };
}

#endif	/* CAMERA_HPP */

