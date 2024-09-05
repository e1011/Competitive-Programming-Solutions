#include <iostream>
#include <random>

using namespace std;

int main(int argc, char **argv) {
	mt19937 mt_rand(atoi(argv[1]));
	
	int n = mt_rand() % 5 + 1;
	
	cout << n << "\n";
	if (n > 3) {
		cerr << "-1\n";
	}
	else if (n == 3) {
		cerr << "1 3 2\n";
	}
	else if (n == 2) {
		cerr << "1 2\n";
	}
	else {
		cerr << "1\n";
	}
	
	
	return 0;
}

