#ifndef TILEMAP_HPP
#define	TILEMAP_HPP

#include	"ugdk/graphic/drawable.h"

#include "../AMB.hpp"
#include "Tile.hpp"

namespace {
	inline int clamp(int x, int min, int max) { return x < min? min : x > max? max : x; }
}

namespace amb {
	class TileMap {
	private:
		const Point2D<int> size_;
		Tile **tiles_;
	public:
		TileMap(int, int);
		~TileMap();
	public:
		Tile **tiles() { return tiles_; }
		Tile& getTile(const Point2D<int>& pos) { return tiles_[pos.x][pos.y]; }
		const Point2D<int>& size() const { return size_; }
	public:
		/* Assumes you're sending a tile from the same TileMap */
		inline Tile& translate(const Tile& t, int tx, int ty) const { 
			return tiles_[clamp(t.index().x + tx, 0, size_.x - 1)]
					  [clamp(t.index().y + ty, 0, size_.y - 1)]; 
		}
	};
}

#endif

