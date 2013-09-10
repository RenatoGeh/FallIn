#ifndef TILE_HPP
#define	TILE_HPP

#include "Body.hpp"

namespace amb {
	class Tile {
	public:
		typedef Point2D<int> TilePosition;
		
		Tile();
		Tile(int, int);
		
		void setIndex(int x, int y) { index_.set(x, y); }
		const TilePosition& getIndex() const { return index_; }
		void occupy(Body* b) { body_ = b; }
		Body *getBodyOnTop() const { return body_; }
	private:
		TilePosition index_;
		Body *body_;
	};
}

#endif	/* TILE_HPP */

