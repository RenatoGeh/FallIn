#ifndef ACTOR_HPP
#define	ACTOR_HPP

#include "../AMB.hpp"
#include "Body.hpp"
#include "DrawableImage.hpp"
#include "Tile.hpp"

namespace amb {
	class Actor : public Body {
		public:
			Actor(const std::string&, const std::string&, Area* = nullptr, Tile* = nullptr);
			Actor(const std::string&, const std::string&, Area*, const Point2D<int>& = Point2D<int>());
			virtual ~Actor(void);
		protected:
			DrawableImage image_;
			std::string name_;
		public:
			virtual void draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const;
	};
}

#endif

