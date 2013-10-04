#include "Button.hpp"

#include <iostream>

#include "../DrawableImage.hpp"


namespace amb {
	namespace ui {
		Button::Button(const Point2D<int>& pos, const Vector2D<int>& size) : Component(pos, size) {
			
		}
		
		void Button::draw(const ugdk::graphic::Geometry& geo, const ugdk::graphic::VisualEffect& eff) const {
			static amb::DrawableImage image("resources/tile.png", size_); //temp
			image.draw(geo * Geometry(position_), eff);
		}
	}
}