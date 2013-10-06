#ifndef BUTTON_HPP
#define	BUTTON_HPP

#include <functional>
#include "Component.hpp"

namespace amb {
	namespace ui {
		class Button : public Component {
			public:
				Button(const std::string&, const Point2D<int>&, const Vector2D<int>&);
				
				std::function<void(const events::MousePressed&)> onMousePress;
				std::function<void(const events::MouseReleased&)> onMouseRelease;
				
				virtual void onEvent(const events::MousePressed&);
				virtual void onEvent(const events::MouseReleased&);
				virtual void onEvent(const events::MouseEntered&);
				virtual void onEvent(const events::MouseExited&);
		};
	}
}

#endif	/* BUTTON_HPP */

