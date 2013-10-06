#include <ugdk/input/events.h>
#include <ugdk/graphic.h>
#include "Menu.hpp"

namespace amb {
	namespace ui {
		Menu::Menu() : scene_(nullptr), focusedComponent_(nullptr) {}
		
		void Menu::prepareScene() {
			if(!scene_) scene_ = new ugdk::action::Scene;
			
			scene_->event_handler().AddListener<ugdk::input::MouseButtonPressedEvent>(
					[this](const ugdk::input::MouseButtonPressedEvent& e) {
						static const events::FocusGained focusGained;
						static const events::FocusLost focusLost;
						events::MousePressed event(e);
						Component *pressed = nullptr;
						for(Component* c : components_)
							if(c->contains(event.position)) {
								pressed = c;
								c->onEvent(event);
							}
						if(pressed != focusedComponent_) {
							if(focusedComponent_) focusedComponent_->onEvent(focusLost);
							if(focusedComponent_ = pressed) focusedComponent_->onEvent(focusGained);
						}
					});
			
			scene_->event_handler().AddListener<ugdk::input::MouseButtonReleasedEvent>(
				[this](const ugdk::input::MouseButtonReleasedEvent& e) {
					events::MouseReleased event(e);
					for(Component* c : components_)
						if(c->contains(event.position))
							c->onEvent(event);
				});
			
			scene_->event_handler().AddListener<ugdk::input::MouseMotionEvent>(
				[this](const ugdk::input::MouseMotionEvent& e) {
					static const events::MouseEntered mouseEntered;
					static const events::MouseExited mouseExited;
					const Point2D<int> position = ugdk::input::manager()->mouse().position();
					for(Component* c : components_) {
						if(c->contains(position) != c->isMouseHovering_) {
							if(c->isMouseHovering_ = !c->isMouseHovering_)
								c->onEvent(mouseEntered);
							else
								c->onEvent(mouseExited);
						}
					}
				});
			
			scene_->event_handler().AddListener<ugdk::input::KeyPressedEvent>(
				[this](const ugdk::input::KeyPressedEvent& e) {
					if(focusedComponent_) focusedComponent_->onEvent(events::KeyPressed(e));
				});
				
			scene_->event_handler().AddListener<ugdk::input::KeyReleasedEvent>(
				[this](const ugdk::input::KeyReleasedEvent& e) {
					if(focusedComponent_) focusedComponent_->onEvent(events::KeyReleased(e));
				});
			
			scene_->set_render_function([this](const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) {
				for(Component* c : components_)
					c->draw(geo, eff);
				this->draw(geo, eff);
			});
		}
		
		void Menu::safeClear() {
			scene_->set_defocus_callback([this](ugdk::action::Scene*) {
				//Will execute this later, when the scene is deleted, therefore, will not crash if deleted from inside a component
				for(Component* c : components_) 
					delete c;
				components_.clear();
			});
			scene_->Finish();
		}
	}
}
