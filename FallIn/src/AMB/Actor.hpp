#ifndef ACTOR_HPP
#define	ACTOR_HPP

#include "../AMB.hpp"
#include "Body.hpp"
#include "DrawableImage.hpp"
#include "Tile.hpp"

namespace amb {
    class Actor : public Body {
        public:
			   Actor(DrawableImage*, Area* = NULL, Tile* = NULL);
            Actor(DrawableImage*, Area*, const Point2D<int>& = Point2D<int>());
            virtual ~Actor(void);
        protected:
            DrawableImage* image_;
        public:
            virtual const ugdk::math::Vector2D& size() const override { return image_->size(); }
				virtual void draw(const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) const override { image_->draw(geo * ugdk::graphic::Geometry(tile_->index() * _TileSize), eff); }
    };
}

#endif	/* ACTOR_HPP */

