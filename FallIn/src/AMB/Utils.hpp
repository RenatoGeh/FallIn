#ifndef UTILS_HPP
#define	UTILS_HPP
#include <functional>

namespace amb {
    namespace utils {
        
        template <typename Event>
        void addEventListener(ugdk::action::Scene* scene, std::function<void(const Event&)> task, double priority = 0.5) {
            scene->event_handler().AddListener<Event>(
                [task](const Event& event){
                    return [&] (double) { task(event); return false; };
                }, priority);
        }
		  
		  //const ugdk::graphic::Font _DefFont;
    }
}

#endif	/* UTILS_HPP */

