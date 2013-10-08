#include "Slider.hpp"
#include "Menu.hpp"
#include "../Math.hpp"

namespace amb {
	namespace ui {
		Slider::Slider(const Point2D<int>& pos, int size, int min, int max) : Slider(pos, size, min, max, (min + max)/2) {}
		
		Slider::Slider(const Point2D<int>& pos, int size, int min, int max, int cur) : Component("resources/SliderBase.png", pos, ugdk::math::Vector2D(size, size/4)), 
			minValue_(min), maxValue_(max), currentValue_(cur), cursorImage_("resources/SliderCursor.png", ugdk::math::Vector2D(size/4, size/4.8)) {}
		
#define CURSOR_TRANSLATION (image_.size().x*.35 + (double(currentValue_ - minValue_) / (maxValue_ - minValue_)) * .33 /* should actually be .3 */ * image_.size().x - cursorImage_.size().x/2)
		
		void Slider::draw(const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) const {
			image_.draw(position_, geo, eff);
			int tx = CURSOR_TRANSLATION;
			cursorImage_.draw(ugdk::math::Vector2D(position_.x + tx, position_.y), geo, eff);
		}
		
		void Slider::onEvent(const events::MousePressed& e) {
			if(e.button == ugdk::input::MouseButton::LEFT && e.position.inside(position_.x + CURSOR_TRANSLATION, position_.y, cursorImage_.size().x, cursorImage_.size().y)) {
				currentMenu_->scene()->AddTask([this](double){
					//This is being done on a Task but should be redone in an eventListeners when they're removable
					int x = math::clamp<int>(ugdk::input::manager()->mouse().position().x, position_.x + image_.size().x*.35, position_.x + image_.size().x*.73);
					currentValue_ = minValue_ + (maxValue_ - minValue_)*(x - position_.x - image_.size().x*.35)/(image_.size().x*.38);
					return ugdk::input::manager()->mouse().IsDown(ugdk::input::MouseButton::LEFT);
				});
			}
		}
		
#undef CURSOR_TRANSLATION
	}
}