#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include "../AMB.hpp"
#include "Actor.hpp"

namespace amb {
    class Player : public Actor {
    public:
        Player(DrawableImage*, const TilePosition& = TilePosition());
        virtual ~Player(void);
    public:
        virtual void update(double dt, const Area& area) override;
    };
}

#endif	/* PLAYER_HPP */

