#ifndef TILEMAP_HPP
#define	TILEMAP_HPP

#include	"ugdk/graphic/drawable.h"

#include "../AMB.hpp"
#include "Tile.hpp"


namespace amb {
	class TileMap : public ugdk::graphic::Drawable {
	public:
		TileMap(int, int);
		~TileMap();
		
		void Draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const override;
		void draw(const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) const { Draw(geo, eff); }
		const ugdk::math::Vector2D& size() const override { return realSize_; }
		
		Tile **tiles() { return tiles_; }
		
		//Assumes you're sending a tile from the same TileMap
		Tile& translate(const Tile& t, int tx, int ty) const { return tiles_[t.index().x + tx][t.index().y + ty]; }
	private:
		const Point2D<int> size_;
		ugdk::math::Vector2D realSize_;
		Tile **tiles_;
	};
}

#endif	/* TILEMAP_HPP */

