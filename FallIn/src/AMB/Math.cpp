#include "Math.hpp"

namespace amb {
	namespace math {
		
		unsigned sqrtFloor(unsigned n) {
			if(n == 0) return 0;
			unsigned x1 = (n + 1)/2;
			unsigned x2 = (x1*x1 + n)/(2*x1);
			while(x1 > x2) {
				x1 = x2;
				x2 = ((x2*x2 + n)/(2*x2));
			}
			return x1;
		}
		
		double sqrt(double n, double precision) {
			double x1 = n;
			double x2 = (x1 + n/x1)/2;
			while(x1 - x2 > precision) {
				x1 = x2;
				x2 = (x1 + n/x1)/2;
			}
			return x2;
		}
		
	}
}
