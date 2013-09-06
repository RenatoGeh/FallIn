#ifndef BODY_HPP
#define	BODY_HPP
#include <ugdk/action/entity.h>
#include <ugdk/graphic/drawable.h>

namespace {
    using ugdk::math::Integer2D;
}

namespace amb {
    const int _tileSize = 64;
    
    class Body : public ugdk::action::Entity, public ugdk::graphic::Drawable {
    public:        
        void Update(double dt) = 0;

        Integer2D& getTile() { return tile_; }
        void translate(const Integer2D& diff) { tile_ += diff; }
        void translate(int tx, int ty) {
            tile_.x += tx;
            tile_.y += ty;
        }
        void setTile(const Integer2D& tile) {
            tile_ = tile;
        }
        void setTile(int x, int y) {
            tile_.x = x;
            tile_.y = y;
        }
    protected:
        Integer2D tile_;
    };
}

#endif	/* BODY_HPP */

