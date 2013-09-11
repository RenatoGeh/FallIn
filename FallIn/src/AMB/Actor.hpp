#ifndef ACTOR_HPP
#define	ACTOR_HPP

#include "Body.hpp"
#include "DrawableImage.hpp"

namespace amb {
    class Actor : public Body {
        public:
            Actor(DrawableImage*, const TilePosition& = TilePosition(0, 0));
            virtual ~Actor(void);
        protected:
            DrawableImage* image_;
        public:
            virtual const ugdk::math::Vector2D& size() const { return image_->size(); }
    };
}

#endif	/* ACTOR_HPP */

