#ifndef NPC_HPP
#define	NPC_HPP

#include "../AMB.hpp"
#include "Actor.hpp"

namespace amb {
	class NPC : public Actor {
	public:
		NPC(const std::string&, DrawableImage*, Area* = nullptr, Tile* = nullptr);
		NPC(const std::string&, DrawableImage*, Area* = nullptr, const Point2D<int>& = Point2D<int>());
		virtual ~NPC();
	private:
		virtual void update(double dt);
		virtual void draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const;
	};
}

#endif
