#ifndef BUTTON_HPP
#define	BUTTON_HPP

#include "Component.hpp"

namespace amb {
	namespace ui {
		class Button : public Component {
			public:
				Button(const Point2D<int>&, const Vector2D<int>&);

				virtual void draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const;
				
				std::function<void(const events::MousePressed&)> onMousePress;
				std::function<void(const events::MouseReleased&)> onMouseRelease;
				
				virtual void onEvent(const events::MousePressed&);
				virtual void onEvent(const events::MouseReleased&);
		};
	}
}

#endif	/* BUTTON_HPP */

