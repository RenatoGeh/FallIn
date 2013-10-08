#include "Actor.hpp"

namespace amb {
	Actor::Actor(const std::string& name, const std::string& imgName, Area *area, Tile *t) : 
		Body(area, t), image_(imgName), name_(name) {
		
	}

	Actor::Actor(const std::string& name,const std::string& imgName, Area *area, const Point2D<int>& tile) : 
		Body(area, &area->tileMap().tiles()[tile.x][tile.y]), image_(imgName), name_(name) {}

	Actor::~Actor() {}

	void Actor::draw(const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) const {
		image_.draw(tile_->index() * _TileSize, geo, eff);
	}
}
