#include <ugdk/input/events.h>
#include <ugdk/graphic.h>
#include "Menu.hpp"

namespace amb {
	namespace ui {
		Menu::Menu() : scene_(nullptr) {}
		
		void Menu::prepareScene() {
			if(!scene_) scene_ = new ugdk::action::Scene;
			
			scene_->event_handler().AddListener<ugdk::input::MouseButtonPressedEvent>(
					[this](const ugdk::input::MouseButtonPressedEvent& e) {
						events::MousePressed event(e);
							for(Component* c : components_) {
								if(c->onMousePress && c->contains(event.position))
									c->onMousePress(event);
							}
					});
			
			scene_->event_handler().AddListener<ugdk::input::MouseButtonReleasedEvent>(
				[this](const ugdk::input::MouseButtonReleasedEvent& e) {
					events::MouseReleased event(e);
						for(Component* c : components_) {
							if(c->onMouseRelease && c->contains(event.position))
								c->onMouseRelease(event);
						}
					});
			
			scene_->set_render_function([this](const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) {
				for(Component* c : components_)
					c->draw(geo, eff);
				this->draw(geo, eff);
			});
		}
	}
}
