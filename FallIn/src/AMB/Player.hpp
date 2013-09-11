#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include "Actor.hpp"

namespace amb {
    class Player : public Actor {
    public:
        Player(DrawableImage*, const TilePosition& = TilePosition());
        virtual ~Player(void);
    public:
        virtual void Draw(const ugdk::graphic::Geometry& geom, const ugdk::graphic::VisualEffect& eff) const {
            image_->Draw(geom * ugdk::graphic::Geometry(tile_ * _TileSize), eff);
        }
        virtual void Update(double dt);
    };
}

#endif	/* PLAYER_HPP */

