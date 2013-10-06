#ifndef MENU_HPP
#define	MENU_HPP

#include <list>
#include <ugdk/action/scene.h>

#include "Component.hpp"

namespace amb {
	namespace ui {
		class Menu {
			private:

			public:
				virtual void load(void) = 0;
				virtual void close(void) = 0;
				
				void addComponent(Component *c) { components_.push_back(c); c->addedTo(this); }
				
				virtual void draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const {};
				
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
		};
	}
}


#endif	/* MENU_HPP */

