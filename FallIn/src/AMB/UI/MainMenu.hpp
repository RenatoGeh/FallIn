#ifndef MAINMENU_HPP
#define	MAINMENU_HPP

#include "Menu.hpp"

namespace amb {
	namespace ui {
		class MainMenu : public Menu {
			public:
				virtual void load(void);
				virtual void close(void);
		};
		
	}
}

#endif	/* MAINMENU_HPP */

