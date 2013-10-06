#include "Button.hpp"

#include <iostream>

namespace amb {
	namespace ui {
		Button::Button(const std::string& imgName, const Point2D<int>& pos) : Component(imgName, pos) {};
		Button::Button(const std::string& imgName, const Point2D<int>& pos, const Vector2D<int>& size) : Component(imgName, pos, size) {}
		
		void Button::onEvent(const events::MousePressed& e)  { if(onMousePress) onMousePress(e); }
		void Button::onEvent(const events::MouseReleased& e) { if(onMouseRelease) onMouseRelease(e); }
		void Button::onEvent(const events::MouseEntered&) { std::cout << "hovering " << this << std::endl; }
		void Button::onEvent(const events::MouseExited&)  { std::cout << "not-hovering " << this << std::endl; }
		void Button::onEvent(const events::FocusGained&) { std::cout << this << " gained focus." << std::endl; }
		void Button::onEvent(const events::FocusLost&)   { std::cout << this << " lost focus." << std::endl; }
		void Button::onEvent(const events::KeyPressed& e)  { std::cout << '\'' << char(e.keyCode) << "' was pressed on " << this << std::endl; }
		void Button::onEvent(const events::KeyReleased& e) { std::cout << '\'' << char(e.keyCode) << "' was released on " << this << std::endl; }
	}
}