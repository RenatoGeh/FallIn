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
				
				virtual void draw(const ugdk::graphic::Geometry&, const ugdk::graphic::VisualEffect&) const {};
				
				virtual ~Menu() {}
			protected:
				Menu();
				
				void prepareScene(void);
				
				ugdk::action::Scene *scene_;
				std::list<Component*> components_;
		};
	}
}


#endif	/* MENU_HPP */

