#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <iostream>
#include <random>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(int n, string s) {
	
    int counter=0, ans=0;
	
	if (n % 2 != 0) {
		return -1;
	}
	
	for (int i = 0; i < n; i ++) {
		if (s[i] == '(') {
			counter += 1;
		}
		else {
			counter -= 1;
		}
		
		if (counter < 0) {
			ans += 1;
			counter += 2;
		}
		if (counter == n-i-1) {
			for (int j = i+1; j < n; j ++) {
				if (s[j] == '(') {
					ans += 1;
				}
			}
			break;
		}
	}
	
	return ans;

}

int main(int argc, char **argv) {
	mt19937 mt_rand(atoi(argv[1]));
    
	int n = (mt_rand() % 1000000) + 1;
	string s{};
	cout << n << "\n";
	for (int i = 0; i < n; i++) {
		if (mt_rand() % 2 == 1) {
			s.append("(");
		}
		else {
			s.append(")");
		}
	}

	cout << s << "\n";
	cerr << solution(n, s) << "\n";

    return 0;
}
