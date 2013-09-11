#include <ugdk/system/engine.h>
#include <ugdk/action/scene.h>
#include <ugdk/graphic/manager.h>
#include <ugdk/graphic/module.h>
#include <ugdk/graphic/texture.h>

#include "AMB/Tile.hpp"
#include "AMB/DrawableImage.hpp"
#include "AMB/Area.hpp"
#include "ugdk/internal/sdleventhandler.h"
#include "ugdk/input/events.h"
#include <iostream>

int main() {
	namespace system = ugdk::system;
	system::Initialize();
	
	ugdk::action::Scene *scene = new ugdk::action::Scene;
	
	/* scene->event_handler().AddListener([](const ugdk::input::KeyPressedEvent& ev) {
		return ([] (double) { std::cout << "asd"; return false;});
	}); */
	amb::Area area(10, 5, {200, 200});
	
	scene->set_render_function([&area](const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff){ area.Draw(geo, eff); });
	
	system::PushScene(scene);
	system::Run();
	system::Release();
	return 0;
}