#include <iostream>
#include <cmath>

class	Job{
	public:
		int	id;
		int ready_time;
		int processing_time;
		int start_time;

		Job () {};
		Job (int i, int p, int r) {
			id = i;
			processing_time = p;
			ready_time = r;
		}
};