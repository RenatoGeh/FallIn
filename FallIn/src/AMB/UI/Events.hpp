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
			class MousePressed {
				public:
					MousePressed(const ugdk::input::MouseButtonPressedEvent& e) : position(ugdk::input::manager()->mouse().position()), button(e.button) {}
					Point2D<int> position;
					ugdk::input::MouseButton button;
			};
			
			class MouseReleased {
				public:
					MouseReleased(const ugdk::input::MouseButtonReleasedEvent& e) : position(ugdk::input::manager()->mouse().position()), button(e.button) {}
					Point2D<int> position;
					ugdk::input::MouseButton button;
			};
			
		}
	}
}

#endif	/* EVENTS_HPP */
