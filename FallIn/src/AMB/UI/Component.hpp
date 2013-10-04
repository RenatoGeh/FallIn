#ifndef COMPONENT_HPP
#define	COMPONENT_HPP

#include <functional>
#include <ugdk/graphic.h>

#include "Events.hpp"
#include "../Vector2D.hpp"

namespace amb {
	namespace ui {
		class Component {
			public:
				std::function<void(const events::MousePressed&)> onMousePress;
				std::function<void(const events::MouseReleased&)> onMouseRelease;
				
				virtual void draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const = 0;
				
				inline bool contains(const Point2D<int>& point) const { return point.inside(position_, size_); }
				
				virtual ~Component() {}
			protected:
				Component(const Point2D<int>& pos, const Vector2D<int>& size) : position_(pos), size_(size) {}
				
				Point2D<int> position_;
				Vector2D<int> size_;
		};
	}
}

#endif	/* COMPONENT_HPP */

