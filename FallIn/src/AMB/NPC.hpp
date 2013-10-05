#ifndef NPC_HPP
#define	NPC_HPP

#include "../AMB.hpp"
#include "Actor.hpp"

namespace amb {
	class NPC : public Actor {
	public:
		NPC(const std::string&, const std::string&, Area* = nullptr, Tile* = nullptr);
		NPC(const std::string&, const std::string&, Area* = nullptr, const Point2D<int>& = Point2D<int>());
		virtual ~NPC();
		virtual void update(double dt);
	private:
	};
}

#endif

