#include "Area.hpp"

#include <functional>
#include <iostream>

#include <ugdk/action/scene.h>
#include <ugdk/math.h>

#include "../AMB.hpp"
#include "Body.hpp"
#include "Utils.hpp"
#include "ugdk/input/events.h"
#include "ugdk/input/module.h"


namespace amb {
	Area::Area(int width, int height, const std::string& st, const ugdk::math::Vector2D& position) : scene_(new ugdk::action::Scene), image_(st), hasFocus_(false), map_(width, height), position_(position) {
		using namespace std::placeholders;
		camera_.translate(position);
		scene_->set_focus_callback([&](ugdk::action::Scene*){ hasFocus_ = true; });
		scene_->set_defocus_callback([&](ugdk::action::Scene*){ hasFocus_ = false; });
		
		scene_->set_render_function(std::bind(&Area::draw, this, _1, _2));
		scene_->AddTask(std::bind(&Area::update, this, _1), .6);
		scene_->AddTask(std::bind(&Area::cleanBodies, this), .55);
	}
	
	Area::~Area() { }
        
	void Area::draw(const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) const {
		ugdk::graphic::Geometry g = camera_.applyOn(geo);
		for(int i = 0; i < map_.size().x; i++)
			for(int j = 0; j < map_.size().y; j++)
				image_.draw(g * Geometry(ugdk::math::Vector2D(i, j) *= _TileSize), eff);
		for(auto body : bodies_)
			body->draw(g, eff);
	}
	
	bool Area::update(double dt) {
		if(!hasFocus_) return true;
		for(auto body : bodies_)
			body->update(dt);
		return true;
	}
	
	void Area::cleanBodies() {
		bodies_.remove_if([&](Body *b) {
			bool remove = b->shouldDelete();
			if(remove) {
				b->onDelete();
                                delete b;
			}
			return remove;
		});
	}
}
