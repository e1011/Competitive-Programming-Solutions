#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

void transfer(int &blood, int &patient) {
	int x = min(blood, patient);
	ans += x;
	blood -= x;
	patient -= x;
}

int main() {
	int onb, opb, anb, apb, bnb, bpb, abpb, abnb;
	cin >> onb >> opb >> anb >> apb >> bnb >> bpb >> abnb >> abpb;
	int onp, opp, anp, app, bnp, bpp, abpp, abnp;
	cin >> onp >> opp >> anp >> app >> bnp >> bpp >> abnp >> abpp;
	
	// o negative
	transfer(onb, onp);
	// a negative
	transfer(anb, anp);
	transfer(onb, anp);
	// b negative
	transfer(bnb, bnp);
	transfer(onb, bnp);
	// o positive
	transfer(opb, opp);
	transfer(onb, opp);

	// a positive
	transfer(apb, app);
	transfer(opb, app);
	transfer(anb, app);
	transfer(onb, app);
	// b positive
	transfer(bpb, bpp);
	transfer(opb, bpp);
	transfer(bnb, bpp);
	transfer(onb, bpp);

	// ab negative
	transfer(abnb, abnp);
	transfer(anb, abnp);
	transfer(bnb, abnp);
	transfer(onb, abnp);
	// ab positive
	transfer(abnb, abpp);
	transfer(anb, abpp);
	transfer(bnb, abpp);
	transfer(onb, abpp);	
	transfer(abpb, abpp);
	transfer(apb, abpp);
	transfer(bpb, abpp);
	transfer(opb, abpp);
	
	cout << ans << "\n";
	
	return 0;
}

