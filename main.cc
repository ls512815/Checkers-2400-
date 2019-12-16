#include <iostream>
#include "colors.h"
#include "checkers.h"
using namespace std;
using namespace main_savitch_14;

int main () {
	game * x;
	x = new checkers;
	x -> play();
	return 0;
}
