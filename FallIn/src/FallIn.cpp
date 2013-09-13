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

#include <iostream>

int main() {
	namespace system = ugdk::system;
	system::Initialize();
	
	amb::Area area(10, 5, {50, 100});
	amb::Player player(new amb::DrawableImage("resources/Lydia.png"), &area, {0, 0});
	amb::Player player2(new amb::DrawableImage("resources/Lydia.png"), &area, {3, 3});
	area.addBody(&player);
	area.addBody(&player2);

	
	//amb::utils::addEventListener<ugdk::input::KeyPressedEvent>(area.scene(), [] (const ugdk::input::KeyPressedEvent& e) { std::cout << "asd" << std::endl; });
        
	
	system::PushScene(area.scene());
	system::Run();
	system::Release();
	return 0;
}