#include "Actor.hpp"

namespace amb {
    Actor::Actor(DrawableImage* img, Area *area, Tile *t) : Body(area, t), image_(img) {
		 
	 }
	 
	 Actor::Actor(DrawableImage* img, Area *area, const Point2D<int>& tile) : Body(area, &area->tileMap().tiles()[tile.x][tile.y]), image_(img) {}

    Actor::~Actor() {}
    
}

