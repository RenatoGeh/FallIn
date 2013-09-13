#include "Actor.hpp"

namespace amb {
	Actor::Actor(const std::string& name, DrawableImage* img, Area *area, Tile *t) : 
		Body(area, t), image_(img), name_(name) {
		
	}

	Actor::Actor(const std::string& name, DrawableImage* img, Area *area, const Point2D<int>& tile) : 
		Body(area, &area->tileMap().tiles()[tile.x][tile.y]), image_(img), name_(name) {}

	Actor::~Actor() {}

	const ugdk::math::Vector2D& Actor::size() const {return image_->size();}
	void Actor::draw(const ugdk::graphic::Geometry& geom, const ugdk::graphic::VisualEffect& eff) const {
		image_->draw(geom * ugdk::graphic::Geometry(tile_->index() * _TileSize), eff);
	}
}
