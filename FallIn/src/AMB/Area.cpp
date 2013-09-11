#include "Area.hpp"

namespace amb {
	Area::Area(int width, int height, const ugdk::math::Vector2D& position) : map_(width, height), position_(position) {}
        
	void Area::Draw(const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) const{
		map_.Draw(geo * ugdk::graphic::Geometry(position_), eff);
	}
}
