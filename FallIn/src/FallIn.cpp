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
#include "AMB/Wanderer.hpp"
#include "AMB/AwesomeTimer.hpp"
#include "AMB/Math.hpp"
#include "AMB/UI/MainMenu.hpp"

#include <iostream>

ugdk::action::Scene *mainScene;

void update(double);

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
	mainScene = new ugdk::action::Scene;
	mainScene->AddTask(update);
	system::PushScene(mainScene);
	mainScene->set_focus_callback([](ugdk::action::Scene* ms) { ms->Finish(); }); // Should never be focused
	
	//TEST TEST TEST
	
	/*amb::Area area(19, 11, "resources/tile.png", {11, 10});
	amb::Player player("Lydia", "resources/Lydia.png", &area, {1, 1});
	amb::Wanderer datStache("Pornstache", "resources/pornstache.png", &area, {4, 3});
	amb::Wanderer secondStache("Pornstache's Dad", "resources/pornstache.png", &area, {7, 2});
	amb::Wanderer thirdStache("Pornstache's Mom", "resources/pornstache.png", &area, {6, 10});
	
	area.addBody(&player);
	area.addBody(&datStache);
	area.addBody(&secondStache);
	area.addBody(&thirdStache);
	
	system::PushScene(area.scene()); */
	
	amb::ui::MainMenu m;
	m.load();
	
	system::Run();
	system::Release();
	return 0;
}

void update(double dt) {
	amb::AwesomeTimer::mainTimer.update(dt);
}