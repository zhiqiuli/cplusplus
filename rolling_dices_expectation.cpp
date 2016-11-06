/*

You can roll a 6-side dice up to N times.
After the first or the second roll, if you get a number x, you can decide either
to get x dollars or to choose to continue rolling, but once you decide to continue,
you forgo the number you just rolled. If you get to the third
roll, you'll just get x dollars if the third roll is x and the game stops.

What is the game worth and what s your strategy?

See Zhou's green cover book for math solution.

Created by Zhiqiu Li

2016-10-08

*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

float Expect (float E, int n);

int main(){

	float E = 0.0;

	// number of rolling
	int n = 10;

	while (n > 0) {
		E = Expect(E, 6);
		cout << setprecision(3) << E << endl;
		n--;
	}

	return 0;

}

// n = 6 for dice
float Expect (float E, int n) {

	int id = ceil(E);

	// initial state
	if (ceil(E) == 0 )
		id = 1;

	float sum = 0.0;

	// expectation if keep rolling
	for (int i = id ; i <= n ; i++) {
		//cout << i << endl;
		sum = sum + static_cast<float>(i);
	}

	sum = sum/static_cast<float>(n);

	//cout << sum << endl;

	sum = sum + static_cast<float>(id-1)/static_cast<float>(n)*E;

	return sum;

}