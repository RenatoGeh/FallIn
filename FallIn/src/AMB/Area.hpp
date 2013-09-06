#ifndef AREA_HPP
#define	AREA_HPP

#include <ugdk/graphic/geometry.h>
#include <ugdk/graphic/visualeffect.h>
#include "TileMap.hpp"

namespace {
	using ugdk::math::Vector2D;
}

namespace amb {
	class Area : public ugdk::graphic::Drawable{
	public:
		Area(int, int, const Vector2D& = Vector2D());
		
		void Draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const override;
		const Vector2D& size() const override { return map_.size(); }
	private:
		TileMap map_;
		Vector2D position_;
	};
}
#endif	/* AREA_HPP */

