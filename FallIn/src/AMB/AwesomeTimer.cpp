#include "AwesomeTimer.hpp"

namespace amb {
	AwesomeTimer AwesomeTimer::mainTimer;
	
	AwesomeTimer::AwesomeTimer() {
	}

	AwesomeTimer::~AwesomeTimer() {
	}
	
	void AwesomeTimer::update(double dt) {
		for(auto timer : timers_) {
			AwesomeAction& t = *timer;
			t.timeElapsed_ += dt;
			if(t.timeElapsed_ >= t.timeToCall_) {
				t.function_(timer);
				if(t.repeats_)
					t.timeElapsed_ -= t.timeToCall_;
			}
		}
		
		timers_.remove_if([](AwesomeAction *a) {
			if(a->delete_ || (!a->repeats_ && a->timeElapsed_ >= a->timeToCall_)) {
				delete a;
				return true;
			}
			return false;
		});
	}
}

