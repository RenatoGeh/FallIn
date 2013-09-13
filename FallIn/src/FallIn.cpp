#include <ugdk/system/engine.h>
#include <ugdk/action/scene.h>
#include <ugdk/graphic/manager.h>
#include <ugdk/graphic/module.h>
#include <ugdk/graphic/texture.h>
#include <ugdk/input.h>
#include <ugdk/input/events.h>

#include "AMB/Tile.hpp"
#include "AMB/DrawableImage.hpp"
#include "AMB/Area.hpp"
#include "AMB/Utils.hpp"
#include "AMB/Camera.hpp"
#include "AMB/Player.hpp"
#include "AMB/NPC.hpp"

#include <iostream>

void init() {
	namespace system = ugdk::system;
	system::Configuration conf;
	conf.window_title = "FallIn - indev 0.0.1";
	conf.window_resolution.x = 1280;
	conf.window_resolution.y = 720;
	system::Initialize(conf);
}

int main() {
	namespace system = ugdk::system;
	init();
	
	
	amb::Area area(16, 11, "resources/tile.png", {10, 10});
	amb::Player player("Lydia", new amb::DrawableImage("resources/Lydia.png"), &area, {1, 1});
	amb::NPC dat_stache("Pornstache", new amb::DrawableImage("resources/pornstache.png"), &area, {4, 3});
	
	area.addBody(&player);
	area.addBody(&dat_stache);
	
	//amb::utils::addEventListener<ugdk::input::KeyPressedEvent>(area.scene(), [] (const ugdk::input::KeyPressedEvent& e) { std::cout << "asd" << std::endl; });
        
	
	system::PushScene(area.scene());
	system::Run();
	system::Release();
	return 0;
}
