#ifndef BODY_HPP
#define	BODY_HPP

#include	<ugdk/math/vector2D.h>
#include <ugdk/graphic.h>

#include "../AMB.hpp"
#include "Vector2D.hpp"
#include "Area.hpp"

namespace amb {    
    class Body {
        public:

            virtual ~Body() {}

            virtual void update(double dt) = 0;
            virtual const ugdk::math::Vector2D& size() const = 0;
            virtual void draw(const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) const {}

            virtual void onDelete() {}

            Tile *tile() { return tile_; }
            const Tile *tile() const { return tile_; }
				
				Area *area() { return area_; }
				const Area *area() const { return area_; }
				
				void translate(const Vector2D<int>& t) { translate(t.x, t.y); }
            void translate(int tx, int ty) { tile_ = &area_->tileMap().translate(*tile_, tx, ty); }
				
            void setTile(Tile& tile) { tile_ = &tile; }

            bool shouldDelete() { return delete_; }
        protected:
            Body() : delete_(false), tile_(NULL), area_(NULL) {}
				Body(Area *a, Tile *t) : delete_(false), tile_(t), area_(a) {}
            Tile *tile_;
				Area *area_;
            bool delete_;
    };
}

#endif	/* BODY_HPP */

