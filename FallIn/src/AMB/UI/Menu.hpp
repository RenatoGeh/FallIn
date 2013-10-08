#ifndef MENU_HPP
#define	MENU_HPP

#include <list>
#include <memory>
#include <ugdk/action/scene.h>
#include <ugdk/math/vector2D.h>

#include "Component.hpp"
#include "../DrawableImage.hpp"

namespace amb {
	namespace ui {
		class Menu {
			private:

			public:
				virtual void load(void) = 0;
				virtual void close(void) = 0;
				
				void addComponent(Component *c) { components_.push_back(c); c->addedTo(this); }
				
				virtual void draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const {};
				
				inline ugdk::action::Scene *scene() { return scene_; }
				
				virtual ~Menu() {}
			protected:
				Menu();
				
				/* Registers the listeners for the components */
				void prepareScene(void);
				
				/* Clears and deletes components, but doesn't do it right away, therefore, can be called from inside a component
				 * Warning: Uses the scene's defocus callback, so if you're using that, do the clearing yourself.
				 **/
				void safeClear(void);
				
				ugdk::action::Scene *scene_;
				std::list<Component*> components_;
				Component *focusedComponent_;
				
				std::unique_ptr<DrawableImage> image_;
		};
	}
}


#endif	/* MENU_HPP */

