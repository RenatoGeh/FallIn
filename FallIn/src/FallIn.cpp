#include <ugdk/system/engine.h>
#include <ugdk/action/scene.h>
#include <ugdk/graphic/manager.h>
#include <ugdk/graphic/module.h>
#include <ugdk/graphic/texture.h>
#include <ugdk/input.h>

#include "AMB/Tile.hpp"
#include "AMB/DrawableImage.hpp"
#include "AMB/Area.hpp"
#include "AMB/Utils.hpp"
#include "AMB/Camera.hpp"
#include "ugdk/input/events.h"

#include <iostream>

int main() {
	namespace system = ugdk::system;
	system::Initialize();
	
	ugdk::action::Scene *scene = new ugdk::action::Scene;
	
	amb::utils::addEventListener<ugdk::input::KeyPressedEvent>(scene, [] (const ugdk::input::KeyPressedEvent& e) { std::cout << "asd" << std::endl; });
        
	amb::Area area(10, 5, {200, 200});
        amb::Camera camera;
        camera.translate({-100, -100});
        
	scene->set_render_function([&](const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff){ 
            ugdk::graphic::Geometry g = camera.applyOn(geo);
            area.Draw(g, eff);
        });
	
	system::PushScene(scene);
	system::Run();
	system::Release();
	return 0;
}