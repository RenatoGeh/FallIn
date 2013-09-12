#include "Player.hpp"
#include "ugdk/input/keyboard.h"
#include "ugdk/input/manager.h"
#include "ugdk/input/module.h"

namespace {
	namespace keys = ugdk::input;
	bool keyPressed(ugdk::input::Key key) {
		return ugdk::input::manager()->KeyPressed(key);
	}
}

namespace amb {
    Player::Player(DrawableImage* img, const TilePosition& pos) : Actor(img, pos) {
    
    }

    Player::~Player() {
    
    }
    
    void Player::Update(double dt) {
		 if(keyPressed(keys::K_d))
			 translate(1, 0);
		 if(keyPressed(keys::K_a))
			 translate(-1, 0);
		 if(keyPressed(keys::K_w))
			 translate(0, -1);
		 if(keyPressed(keys::K_s))
			 translate(0, 1);
    }
}