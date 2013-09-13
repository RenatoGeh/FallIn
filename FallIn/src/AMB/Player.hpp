#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include "../AMB.hpp"
#include "Actor.hpp"

namespace amb {
	class Player : public Actor {
		public:
			Player(const std::string&, DrawableImage*, Area* = nullptr, Tile* = nullptr);
			Player(const std::string&, DrawableImage*, Area*, const Point2D<int>& = Point2D<int>());
			virtual ~Player(void);
		public:
			virtual void update(double dt);
	 private:
		 void init(void);
    };
}

#endif

