#ifndef SLIDER_HPP
#define	SLIDER_HPP

#include "Component.hpp"
#include "Events.hpp"
#include "../Vector2D.hpp"
#include "../DrawableImage.hpp"

namespace amb {
	namespace ui {
		class Slider : public Component{
			public:
				Slider(const Point2D<int>&, int, int, int);
				Slider(const Point2D<int>&, int, int, int, int);
				
				virtual void draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const override;
				
				virtual void onEvent(const events::MousePressed&);
				
				inline int getValue() { return cursorImage_; }
				
			private:
				int minValue_, maxValue_;
				int currentValue_;
				DrawableImage cursorImage_;
		};
	}
}

#endif	/* SLIDER_HPP */

