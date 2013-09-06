#ifndef TILEMAP_HPP
#define	TILEMAP_HPP
#include "Tile.hpp"

namespace {
	using ugdk::math::Integer2D;
	using ugdk::math::Vector2D;
}

namespace amb {
	class TileMap : public ugdk::graphic::Drawable {
	public:
		TileMap(int, int);
		~TileMap();
		
		void Draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const override;
		const Vector2D& size() const override { return realSize_; }
		
		Tile **getTiles() { return tiles_; }
		
		//Assumes you're sending a tile from the same TileMap
		Tile& translate(const Tile& t, int x, int y) const { return tiles_[t.getIndex().x + x][t.getIndex().y + y]; }
	private:
		const Integer2D size_;
		Vector2D realSize_;
		Tile **tiles_;
	};
}

#endif	/* TILEMAP_HPP */

