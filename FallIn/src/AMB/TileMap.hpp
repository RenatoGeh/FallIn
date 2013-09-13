#ifndef TILEMAP_HPP
#define	TILEMAP_HPP

#include	"ugdk/graphic/drawable.h"

#include "../AMB.hpp"
#include "Tile.hpp"

namespace {
	inline int clamp(int x, int min, int max) { return x < min? min : x > max? max : x; }
}

namespace amb {
	class TileMap : public ugdk::graphic::Drawable {
	private:
		const Point2D<int> size_;
		ugdk::math::Vector2D realSize_;
		Tile **tiles_;
	public:
		TileMap(int, int);
		~TileMap();
	public:	
		void Draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const;
		inline void draw(const ugdk::graphic::Geometry& geo, 
			const ugdk::graphic::VisualEffect& eff) const { Draw(geo, eff); }
		inline const ugdk::math::Vector2D& size() const { return realSize_; }
	public:
		Tile **tiles() { return tiles_; }
	public:
		/* Assumes you're sending a tile from the same TileMap */
		inline Tile& translate(const Tile& t, int tx, int ty) const { 
			return tiles_[clamp(t.index().x + tx, 0, size_.x - 1)]
					  [clamp(t.index().y + ty, 0, size_.y - 1)]; 
		}
	};
}

#endif

