#ifndef MATH_HPP
#define	MATH_HPP
#include <iostream>
#include <random>

namespace amb {
	namespace math {
		
		/* Calculates the integer part of the square root of the given unsigned integer
		 */
		unsigned sqrtFloor(unsigned);
		
		double sqrt(double n, double precision = 1e-5);
		
		template <typename T>
		inline T abs(T t) { return t > 0? t : -t; }
		
		namespace {
			std::random_device rd;
			std::default_random_engine generator(rd());
			std::uniform_real_distribution<double> distribution(0.0, 1.0);
		}
		
		/* Returns a random number in the range [0,1[ */
		inline double random() { return distribution(generator); }
		
		/* Returns a random number n in the range 0 <= n < max */
		inline unsigned randomInt(unsigned max) { return random() * max; }
		
		/* Returns a random number n in the range min <= n <= max */
		inline int randomInt(int min, int max) { return min + randomInt(max - min + 1); }
		
		/* Returns a random boolean */
		inline bool randomBool() { return random() > .5; }
		
		/* Returns 1 or -1 with the given chance */
		inline int randomSign(double chance = .5) { return random() < chance ? -1 : 1; }
		
	}
}


#endif	/* MATH_HPP */

