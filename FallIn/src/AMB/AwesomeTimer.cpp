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
			if(t.timeElapsed_ >= t.timeToCall) {
				t.function_(timer);
				if(t.repeats_)
					t.timeElapsed_ -= t.timeToCall;
				else
					t.delete_ = true;
			}
		}
		
		timers_.remove_if([](AwesomeAction *a) {
			if(a->delete_) {
				delete a;
				return true;
			}
			return false;
		});
	}
}

