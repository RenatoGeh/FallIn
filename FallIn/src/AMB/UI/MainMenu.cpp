#include "MainMenu.hpp"

#include <iostream>
#include <ugdk/system/engine.h>
#include "Button.hpp"
#include "Component.hpp"


namespace amb {
	namespace ui {
		void MainMenu::load() {
			Button *b = new Button({100, 100}, {100, 100});
			b->onMousePress = [this](const events::MousePressed&) {
				this->close();
			};
			components_.push_back(b);
			
			prepareScene();
			ugdk::system::PushScene(scene_);
		}
		
		void MainMenu::close() {
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