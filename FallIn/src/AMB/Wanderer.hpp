#ifndef WANDERER_HPP
#define	WANDERER_HPP

#include "AwesomeTimer.hpp"
#include "NPC.hpp"


namespace amb {
	class Wanderer : public NPC {
	public:
		Wanderer(const std::string&, DrawableImage*, Area* = nullptr, Tile* = nullptr);
		Wanderer(const std::string&, DrawableImage*, Area* = nullptr, const Point2D<int>& = Point2D<int>());
		virtual ~Wanderer(void);
	private:
		Wanderer(const Wanderer& orig);
		void init(void);
		AwesomeAction *walkAction_;
	};
}

#endif	/* WANDERER_HPP */

