#ifndef COMPONENT_HPP
#define	COMPONENT_HPP

#include <functional>
#include <ugdk/graphic.h>

#include "Events.hpp"
#include "../UI.hpp"
#include "../Vector2D.hpp"
#include "../DrawableImage.hpp"

namespace amb {
	namespace ui {
		class Component {
			public:
				virtual void onEvent(const events::MousePressed&)  {}
				virtual void onEvent(const events::MouseReleased&) {}
				virtual void onEvent(const events::MouseEntered&)  {}
				virtual void onEvent(const events::MouseExited&)   {}
				virtual void onEvent(const events::FocusGained&)   {}
				virtual void onEvent(const events::FocusLost&)     {}
				virtual void onEvent(const events::KeyPressed&)    {}
				virtual void onEvent(const events::KeyReleased&)   {}
				
				void draw(const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) const { image_.draw(position_, geo, eff); }; //may make it virtual in the future
				
				virtual void addedTo(Menu *menu) { currentMenu_ = menu; }
				virtual void removedFrom(Menu *menu) { currentMenu_ = nullptr; }
				
				inline bool contains(const Point2D<int>& point) const { return point.inside(position_, size_); }
				
				virtual ~Component() {}
			protected:
				Component(const std::string& imgName, const Point2D<int>& pos, const Vector2D<int>& size) : position_(pos), image_(imgName, size_), size_(size), currentMenu_(nullptr), isMouseHovering_(false) {}
				Component(const std::string& imgName, const Point2D<int>& pos) : position_(pos), image_(imgName), size_(image_.size()), currentMenu_(nullptr), isMouseHovering_(false) {}
				
				Point2D<int> position_;
				DrawableImage image_;
				Vector2D<int> size_;
				
				Menu *currentMenu_;
			private:
				bool isMouseHovering_;
				
				friend class Menu;
		};
	}
}

#endif	/* COMPONENT_HPP */

