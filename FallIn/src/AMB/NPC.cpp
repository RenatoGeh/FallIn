#include "NPC.hpp"

namespace amb {
	NPC::NPC(const std::string& name, DrawableImage* img, Area* area, Tile* tile) :
		Actor(name, img, area, tile) {
		tile_->occupy(this);
	}
	
	NPC::NPC(const std::string& name, DrawableImage* img, Area* area, const Point2D<int>& pos) :
		Actor(name, img, area, pos) {
		tile_->occupy(this);
	}
	
	NPC::~NPC() {}
	
	void NPC::update(double dt) {
		//TODO: Stuff.
	}
	
	void NPC::draw(const ugdk::graphic::Geometry& geom, const ugdk::graphic::VisualEffect& eff) const {
		Actor::draw(geom, eff);
	}
}
