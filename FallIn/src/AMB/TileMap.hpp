#ifndef TILEMAP_HPP
#define	TILEMAP_HPP
#include "Tile.hpp"

#define override override // stops Netbeans from complaining about override keyword

namespace amb {
	class TileMap : public ugdk::graphic::Drawable {
	public:
		TileMap(int, int);
		~TileMap();
		
		void Draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const override;
		const ugdk::math::Vector2D& size() const override { return realSize_; }
		
		Tile **getTiles() { return tiles_; }
		
		//Assumes you're sending a tile from the same TileMap
		Tile& translate(const Tile& t, int tx, int ty) const { return tiles_[t.getIndex().x + tx][t.getIndex().y + ty]; }
	private:
		const Point2D<int> size_;
		ugdk::math::Vector2D realSize_;
		Tile **tiles_;
	};
}

#endif	/* TILEMAP_HPP */

