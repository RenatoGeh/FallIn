#include "MainMenu.hpp"

#include <iostream>
#include <ugdk/system/engine.h>

#include "../Math.hpp"
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
			b->onMousePress = [this](const events::MousePressed&) {
				std::cout << "HEY YOU PRESSED ME DUDE" << std::endl;
			};
			addComponent(b);
			
			this->image_.reset(new DrawableImage("resources/pornstache.png", {1280, 720}));
			
			prepareScene();
			ugdk::system::PushScene(scene_);
		}
		
		void MainMenu::close() {
			this->safeClear();
		}
	}
}