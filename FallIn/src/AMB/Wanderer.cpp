#include "Wanderer.hpp"
#include "AwesomeTimer.hpp"
#include "Math.hpp"


namespace amb {
	Wanderer::Wanderer(const std::string& name, const std::string& img, Area* area, Tile* tile) :
		NPC(name, img, area, tile), walkAction_(nullptr) {
		tile_->occupy(this);
		init();
	}
	
	Wanderer::Wanderer(const std::string& name, const std::string& img, Area* area, const Point2D<int>& pos) :
		NPC(name, img, area, pos), walkAction_(nullptr) {
		tile_->occupy(this);
		init();
	}
	
	Wanderer::~Wanderer() {}
	
	void Wanderer::init() {
		walkAction_ = new AwesomeAction([this](AwesomeAction* ac){
			if(math::random() < .65) {
				Tile *oldTile = this->tile();
				if(math::randomBool())
					this->translate(0, math::randomSign());
				else
					this->translate(math::randomSign(), 0);
				if(!this->tile()->ocuppied()) {
					oldTile->occupy(nullptr);
					this->tile()->occupy(this);
				} else
					this->setTile(*oldTile);
			}
			ac->timeToCall = 1.0 + math::random();
		}, 1.5, true);
		AwesomeTimer::mainTimer.addTimer(walkAction_);
	}
}

