#include "MainMenu.hpp"

#include <iostream>
#include <ugdk/system/engine.h>
#include "Button.hpp"
#include "Component.hpp"


namespace amb {
	namespace ui {
		void MainMenu::load() {
			Button *b = new Button("resources/tile.png", {100, 100}, {100, 100});
			b->onMousePress = [this](const events::MousePressed&) {
				this->close();
			};
			components_.push_back(b);
			
			prepareScene();
			ugdk::system::PushScene(scene_);
		}
		
		void MainMenu::close() {
			this->safeClear();
		}
	}
}