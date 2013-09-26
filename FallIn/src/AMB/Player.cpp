#include <ugdk/input/keyboard.h>
#include <ugdk/input/manager.h>
#include <ugdk/input/module.h>
#include <ugdk/input/events.h>

#include "Player.hpp"
#include "Utils.hpp"

namespace {
	inline bool keyPressed(ugdk::input::Keycode key) {
		return ugdk::input::manager()->keyboard().IsPressed(key);
	}
	inline bool keyPressed(char key) {
		return keyPressed(ugdk::input::Keycode(key));
	}
}

namespace amb {
    Player::Player(const std::string& name, DrawableImage* img, Area *area, Tile *t) : 
		Actor(name, img, area, t) {init();}
	 
	 Player::Player(const std::string& name, DrawableImage *img, Area *area, const Point2D<int>& t) : 
		Actor(name, img, area, t) {init();}
    Player::~Player() {}
    
	 void Player::init() {
		
	 }
	 
    void Player::update(double dt) {
		 Tile *prev = tile_;
		 if(keyPressed('d'))
			 translate(1, 0);
		 if(keyPressed('a'))
			 translate(-1, 0);
		 if(keyPressed('w'))
			 translate(0, -1);
		 if(keyPressed('s'))
			 translate(0, 1);
		 if(tile_->ocuppied())
			 tile_ = prev;
		 else{
			 prev->occupy(nullptr);
			 tile_->occupy(this);
		 }
	 }
}
