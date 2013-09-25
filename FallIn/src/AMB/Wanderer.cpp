#include "Wanderer.hpp"
#include "AwesomeTimer.hpp"


namespace amb {
	Wanderer::Wanderer(const std::string& name, DrawableImage* img, Area* area, Tile* tile) :
		NPC(name, img, area, tile), walkAction_(nullptr) {
		tile_->occupy(this);
		init();
	}
	
	Wanderer::Wanderer(const std::string& name, DrawableImage* img, Area* area, const Point2D<int>& pos) :
		NPC(name, img, area, pos), walkAction_(nullptr) {
		tile_->occupy(this);
		init();
	}
	
	Wanderer::~Wanderer() {}
	
	void Wanderer::init() {
		walkAction_ = new AwesomeAction([this](AwesomeAction*){
			this->translate(1, 1); // Go to random places once random is implemented.
		}, 1.5, true);
		AwesomeTimer::mainTimer.addTimer(walkAction_);
	}
}

