#include "Actor.hpp"

namespace amb {
    Actor::Actor(DrawableImage* img, const TilePosition& t) : image_(img) {
        setTile(t);
    }

    Actor::~Actor() {
        
    }
    
}

