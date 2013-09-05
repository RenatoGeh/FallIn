#include <ugdk/system/engine.h>
#include <ugdk/action/scene.h>
#include <ugdk/graphic/manager.h>
#include <ugdk/graphic/module.h>
#include <ugdk/graphic/texture.h>

#include "AMB/DrawableImage.hpp"

int main() {
	namespace system = ugdk::system;
	system::Initialize();
	
	ugdk::action::Scene *scene = new ugdk::action::Scene;
	amb::DrawableImage di("resources/Lydia.png");
        di.setTile(2, 4);
	
	scene->set_render_function([&di](const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff){ di.Draw(geo, eff); });
	
	system::PushScene(scene);
	system::Run();
	system::Release();
	return 0;
}