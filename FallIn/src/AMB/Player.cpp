#include "Player.hpp"
#include "ugdk/input/keyboard.h"
#include "ugdk/input/manager.h"

namespace amb {
    Player::Player(DrawableImage* img, const TilePosition& pos) : Actor(img, pos) {
    
    }

    Player::~Player() {
    
    }
    
    void Player::Update(double dt) {
        /* if(ugdk::input::manager()->keyPressed(ugdk::input::K_d)) {
            translate(1, 0);
        } */
    }
}