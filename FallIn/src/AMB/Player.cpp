#include <ugdk/input/keyboard.h>
#include <ugdk/input/manager.h>
#include <ugdk/input/module.h>

#include "Player.hpp"

namespace {
	bool keyPressed(ugdk::input::Key key) {
		return ugdk::input::manager()->KeyPressed(key);
	}
}

namespace amb {
    Player::Player(const std::string& name, DrawableImage* img, Area *area, Tile *t) : 
		Actor(name, img, area, t) {}
	 
	 Player::Player(const std::string& name, DrawableImage *img, Area *area, const Point2D<int>& t) : 
		Actor(name, img, area, t) {}

    Player::~Player() {}
    
    void Player::update(double dt) {
		namespace keys = ugdk::input;
		 Tile *prev = tile_;
		 if(keyPressed(keys::K_d))
			 translate(1, 0);
		 if(keyPressed(keys::K_a))
			 translate(-1, 0);
		 if(keyPressed(keys::K_w))
			 translate(0, -1);
		 if(keyPressed(keys::K_s))
			 translate(0, 1);
		 if(tile_->ocuppied())
			 tile_ = prev;
		 else{
			 prev->occupy(nullptr);
			 tile_->occupy(this);
		 }
	 }
}
