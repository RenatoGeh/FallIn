#ifndef AREA_HPP
#define	AREA_HPP

#include <ugdk/graphic/geometry.h>
#include <ugdk/graphic/visualeffect.h>
#include "TileMap.hpp"

#define override override // stops Netbeans from complaining about override keyword

namespace amb {
	class Area : public ugdk::graphic::Drawable{
	public:
		Area(int, int, const ugdk::math::Vector2D& = ugdk::math::Vector2D());
		
		void Draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const override;
		const ugdk::math::Vector2D& size() const override { return map_.size(); }
	private:
		TileMap map_;
		ugdk::math::Vector2D position_;
	};
}
#endif	/* AREA_HPP */

