#ifndef EVENTS_HPP
#define	EVENTS_HPP

#include <ugdk/input.h>
#include <ugdk/input/mouse.h>
#include <ugdk/input/events.h>
#include <ugdk/input/module.h>

#include "../Vector2D.hpp"

namespace amb {
	namespace ui {
		namespace events {
			struct MousePressed {
					MousePressed(const ugdk::input::MouseButtonPressedEvent& e) : position(ugdk::input::manager()->mouse().position()), button(e.button) {}
					const Point2D<int> position;
					const ugdk::input::MouseButton button;
			};
			
			struct MouseReleased {
					MouseReleased(const ugdk::input::MouseButtonReleasedEvent& e) : position(ugdk::input::manager()->mouse().position()), button(e.button) {}
					const Point2D<int> position;
					const ugdk::input::MouseButton button;
			};
			
			struct MouseEntered {};
			
			struct MouseExited {};
			
			struct FocusGained {};
			
			struct FocusLost {};
			
			struct KeyPressed {
				KeyPressed(const ugdk::input::KeyPressedEvent& e) : keyCode(e.keycode), scanCode(e.scancode), modifiers(e.modifiers) {}
				const ugdk::input::Keycode keyCode;
				const ugdk::input::Scancode scanCode;
				const ugdk::input::Keymod modifiers;
			};
			
			struct KeyReleased {
				KeyReleased(const ugdk::input::KeyReleasedEvent& e) : keyCode(e.keycode), scanCode(e.scancode), modifiers(e.modifiers) {}
				const ugdk::input::Keycode keyCode;
				const ugdk::input::Scancode scanCode;
				const ugdk::input::Keymod modifiers;
			};
		}
	}
}

#endif	/* EVENTS_HPP */

