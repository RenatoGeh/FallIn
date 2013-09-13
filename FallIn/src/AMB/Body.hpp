#ifndef BODY_HPP
#define	BODY_HPP

#include	<ugdk/math/vector2D.h>
#include <ugdk/graphic.h>

#include "../AMB.hpp"
#include "Vector2D.hpp"

namespace amb {    
    class Body {
        public:
            typedef Point2D<int> TilePosition;

            virtual ~Body() {}

            virtual void update(double dt, const Area& area) = 0;
            virtual const ugdk::math::Vector2D& size() const = 0;
            virtual void draw(const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) const {}

            virtual void onDelete() {}

            TilePosition& tile() { return tile_; }
            const TilePosition& tile() const { return tile_; }
            void translate(const TilePosition& diff) { tile_ += diff; }
            void translate(int tx, int ty) { tile_.add(tx, ty); }
            void setTile(const TilePosition& tile) { tile_ = tile; }
            void setTile(int x, int y) { tile_.set(x, y); }

            bool shouldDelete() { return delete_; }
        protected:
            Body() : delete_(false) {} 
            TilePosition tile_;
            bool delete_;
    };
}

#endif	/* BODY_HPP */

