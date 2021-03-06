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
	Area::Area(int width, int height, const std::string& st, const ugdk::math::Vector2D& position) : scene_(new ugdk::action::Scene), image_(st), hasFocus_(false), map_(width, height), scale_(1) {
		using namespace std::placeholders;
		camera_.translate(position);
		scene_->set_focus_callback([this](ugdk::action::Scene*){ hasFocus_ = true; });
		scene_->set_defocus_callback([this](ugdk::action::Scene*){ hasFocus_ = false; });
		
		scene_->set_render_function(std::bind(&Area::draw, this, _1, _2));
		scene_->AddTask(ugdk::system::Task(std::bind(&Area::update, this, _1), .6));
		scene_->AddTask(ugdk::system::Task(std::bind(&Area::cleanBodies, this), .55));
		
		scene_->event_handler().AddListener<ugdk::input::MouseMotionEvent>(
			[this](const ugdk::input::MouseMotionEvent& e) {
				if(ugdk::input::manager()->mouse().IsDown(ugdk::input::MouseButton::LEFT))
					camera_.translate(e.motion);
			});
			
		scene_->event_handler().AddListener<ugdk::input::MouseWheelEvent>(
			[this](const ugdk::input::MouseWheelEvent& e) {
				// gotta make it scroll to the middle
				double scaleToApply =  1 + e.scroll.y * .1;
				auto off = camera_.getGeometry().offset();
				
				camera_.scale({scaleToApply, scaleToApply});
				//camera_.translate({1280*(scale_*(1-scaleToApply))/2, 720*(scale_*(1-scaleToApply))/2});
				camera_.setTranslation({1280*(scale_/2 - scale_*scaleToApply) + off.x, 720*(scale_/2 - scale_*scaleToApply) + off.y});
				
				scale_ *= scaleToApply;
			});
	}
	
	Area::~Area() { }
        
	void Area::draw(const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) const {
		ugdk::graphic::Geometry g = camera_.applyOn(geo);
		for(int i = 0; i < map_.size().x; i++)
			for(int j = 0; j < map_.size().y; j++)
				image_.draw(ugdk::math::Vector2D(i * _TileSize, j * _TileSize) , g, eff); //maybe raw less times somehow?
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
