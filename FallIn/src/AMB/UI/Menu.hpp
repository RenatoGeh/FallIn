#ifndef MENU_HPP
#define	MENU_HPP

#include <ugdk/action/scene.h>

namespace amb {
	namespace ui {
		class Menu {
			private:

			public:
				virtual ~Menu() {}
			protected:
				Menu() : scene_(nullptr) {}
				ugdk::action::Scene *scene_;
		};
	}
}


#endif	/* MENU_HPP */

