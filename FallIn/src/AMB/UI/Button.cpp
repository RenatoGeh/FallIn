#include "Button.hpp"

#include <iostream>

namespace amb {
	namespace ui {
		Button::Button(const std::string& imgName, const Point2D<int>& pos, const Vector2D<int>& size) : Component(imgName, pos, size) {
			
		}
		
		void Button::onEvent(const events::MousePressed& e) { onMousePress(e); }
		void Button::onEvent(const events::MouseReleased& e) { onMouseRelease(e); }
		void Button::onEvent(const events::MouseEntered&) { std::cout << "hovering " << this << std::endl; }
		void Button::onEvent(const events::MouseExited&) { std::cout << "not-hovering " << this << std::endl; }
	}
}