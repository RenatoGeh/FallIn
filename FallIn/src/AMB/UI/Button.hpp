#ifndef BUTTON_HPP
#define	BUTTON_HPP

#include "Component.hpp"

namespace amb {
	namespace ui {
		class Button : public Component {
			public:
				Button(const Point2D<int>&, const Vector2D<int>&);

				virtual void draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const;
		};
	}
}

#endif	/* BUTTON_HPP */

