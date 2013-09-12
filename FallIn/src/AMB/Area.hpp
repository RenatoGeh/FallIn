#ifndef AREA_HPP
#define	AREA_HPP

#include	<list>

#include <ugdk/graphic/geometry.h>
#include <ugdk/graphic/visualeffect.h>

#include "../AMB.hpp"
#include "Camera.hpp"
#include "TileMap.hpp"

namespace amb {
	class Area {
	public:
		Area(int, int, const ugdk::math::Vector2D& = ugdk::math::Vector2D());
		~Area();
		
		void draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const;
		bool update(double);
		
		void cleanBodies(void);
		
		void addBody(Body *b) { bodies_.push_back(b); }
		void removeBody(Body *b) { bodies_.remove(b); }
		
		ugdk::action::Scene *scene() { return scene_; }
	private:
		Camera camera_;
		
		ugdk::action::Scene *scene_;
		bool hasFocus_;
		
		std::list<Body*> bodies_;
		TileMap map_;
		ugdk::math::Vector2D position_;
	};
}
#endif	/* AREA_HPP */

