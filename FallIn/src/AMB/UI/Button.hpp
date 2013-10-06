#ifndef BUTTON_HPP
#define	BUTTON_HPP

#include <functional>
#include "Component.hpp"

namespace amb {
	namespace ui {
		class Button : public Component {
			public:
				Button(const std::string&, const Point2D<int>&);
				Button(const std::string&, const Point2D<int>&, const Vector2D<int>&);
				
				std::function<void(const events::MousePressed&)> onMousePress;
				std::function<void(const events::MouseReleased&)> onMouseRelease;
				
				virtual void onEvent(const events::MousePressed&);
				virtual void onEvent(const events::MouseReleased&);
				virtual void onEvent(const events::MouseEntered&);
				virtual void onEvent(const events::MouseExited&);
				virtual void onEvent(const events::FocusGained&);
				virtual void onEvent(const events::FocusLost&);
				virtual void onEvent(const events::KeyPressed&);
				virtual void onEvent(const events::KeyReleased&);
		};
	}
}

#endif	/* BUTTON_HPP */

