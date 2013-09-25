#ifndef AWESOMETIMER_HPP
#define	AWESOMETIMER_HPP

#include <functional>
#include <list>

namespace amb {
	class AwesomeAction {
		public:
			typedef std::function<void(AwesomeAction*)> AwesomeFunction;
			AwesomeAction(AwesomeFunction f, double time, bool repeats = false, bool running = true) : function_(f), timeToCall_(time),
						timeElapsed_(0.), repeats_(repeats), running_(running), delete_(false) {}
			
			void toggleRunning() { running_ = !running_; }
			bool running() { return running_; }
			void remove() { delete_ = true; }
		private:
			AwesomeFunction function_;
			double timeToCall_, timeElapsed_;
			bool repeats_, running_, delete_;
			
			friend class AwesomeTimer;
	};
	
	class AwesomeTimer {
		public:
			static AwesomeTimer mainTimer;
			
			AwesomeTimer();
			~AwesomeTimer();

			void update(double);

			inline void addTimer(AwesomeAction *action) {
				timers_.push_back(action);
			}
			inline void addTimer(AwesomeAction::AwesomeFunction f, double time, bool repeats = false, bool running = true) {
				timers_.push_back(new AwesomeAction(f, time, repeats, running));
			}
		private:
			AwesomeTimer(const AwesomeTimer& orig);
			AwesomeTimer& operator = (const AwesomeTimer&);

			std::list<AwesomeAction*> timers_;
	};
}

#endif	/* AWESOMETIMER_HPP */

