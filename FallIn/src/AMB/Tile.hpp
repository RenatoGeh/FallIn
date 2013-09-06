#ifndef TILE_HPP
#define	TILE_HPP

#include <ugdk/math/integer2D.h>
#include "Body.hpp"

namespace {
    using ugdk::math::Integer2D;
}
namespace amb {
	class Tile {
	public:
		Tile();
		Tile(int, int);
		
		void setIndex(int x, int y) {
			index_.x = x;
			index_.y = y;
		}
		const Integer2D& getIndex() const { return index_; }
		void occupy(Body* b) { body_ = b; }
		Body *getBodyOnTop() const { return body_; }
	private:
		Integer2D index_;
		Body *body_;
	};
}

#endif	/* TILE_HPP */

