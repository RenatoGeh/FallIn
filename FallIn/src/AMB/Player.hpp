#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include "Actor.hpp"

namespace amb {
    class Player : public Actor {
    public:
        Player(DrawableImage*, const TilePosition& = TilePosition());
        virtual ~Player(void);
    public:
        virtual void Update(double dt);
    };
}

#endif	/* PLAYER_HPP */

