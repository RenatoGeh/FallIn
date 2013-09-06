#include <ugdk/system/engine.h>
#include <ugdk/action/scene.h>
#include <ugdk/graphic/manager.h>
#include <ugdk/graphic/module.h>
#include <ugdk/graphic/texture.h>

#include "AMB/Tile.hpp"
#include "AMB/DrawableImage.hpp"
#include "AMB/Area.hpp"

int main() {
	namespace system = ugdk::system;
	system::Initialize();
	
	ugdk::action::Scene *scene = new ugdk::action::Scene;
	//amb::Area area(10, 10, {200, 200});
	
	//scene->set_render_function([&area](const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff){ area.Draw(geo, eff); });
	
	system::PushScene(scene);
	system::Run();
	system::Release();
	return 0;
}