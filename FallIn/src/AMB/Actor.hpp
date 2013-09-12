#ifndef ACTOR_HPP
#define	ACTOR_HPP

#include "Body.hpp"
#include "DrawableImage.hpp"

namespace amb {
    class Actor : public Body {
        public:
            Actor(DrawableImage*, const TilePosition& = TilePosition());
            virtual ~Actor(void);
        protected:
            DrawableImage* image_;
        public:
            virtual const ugdk::math::Vector2D& size() const { return image_->size(); }
				virtual void Draw(const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) const { image_->Draw(geo * ugdk::graphic::Geometry(tile_ * _TileSize), eff); }
    };
}

#endif	/* ACTOR_HPP */

