#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include "../AMB.hpp"
#include "Actor.hpp"

namespace amb {
    class Player : public Actor {
    public:
        Player(DrawableImage*, Area* = NULL, Tile* = NULL);
		  Player(DrawableImage*, Area*, const Point2D<int>& = Point2D<int>());
        virtual ~Player(void);
    public:
        virtual void update(double dt) override;
    };
}

#endif	/* PLAYER_HPP */

