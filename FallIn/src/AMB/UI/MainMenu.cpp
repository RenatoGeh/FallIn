#include "MainMenu.hpp"

#include <iostream>
#include <ugdk/system/engine.h>
#include "Button.hpp"
#include "Component.hpp"


namespace amb {
	namespace ui {
		void MainMenu::load() {
			Button *b = new Button("resources/Lydia.png", {1200, 650});
			b->onMousePress = [this](const events::MousePressed&) {
				this->close();
			};
			addComponent(b);
			
			b = new Button("resources/tile.png", {200, 200});
			addComponent(b);
			
			prepareScene();
			ugdk::system::PushScene(scene_);
		}
		
		void MainMenu::close() {
			this->safeClear();
		}
	}
}