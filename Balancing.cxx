#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("balance.in", "r", stdin);
	//freopen("balance.out", "w", stdout);
	
	int n;
	cin >> n;
	
	vector <int> arr1(n, 0), arr2(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> arr2[i];
	}
	
	long long inv1=0, c1=0, inv2=0, c2=0, ans=0;
	for (int i = 0; i < n; i ++) {
		c1 += arr1[i];
		inv1 += c1*(!arr1[i]);
	}
	for (int i = 0; i < n; i ++) {
		c2 += arr2[i];
		inv2 += c2*(!arr2[i]);
	}
	ans = abs(inv1-inv2);
	
	vector <int> backup1 = arr1, backup2 = arr2;
	long long p1=n-1, p2=0, count=0, z1=0, z2=0, inv1a=inv1, inv2a=inv2;
	for (int i = 1; i < n; i ++) {
		while (p1 > 0 && arr1[p1] != 1) {
			p1 -= 1;
			z1 += (arr1[p1] == 0);
		}
		while (p2 < n && arr2[p2] != 0) {
			p2 += 1;
			z2 += (arr2[p2] == 1);
		}
		
		if (p1 == 0 || p2 == n) {
			break;
		}
		else {
			count += (n-p1)-i;
			inv1a -= z1;
			arr1[p1] = -1;
			
			count += (p2+1)-i;
			inv2a -= z2;
			arr2[p2] = -1;
			
		}
		ans = min(ans, i*i+count+abs((inv1a-i*(c1-i))-(inv2a-i*(n-c2-i))));
		//cout << ans << ", " << count << ", " << inv1a << ", " << inv2a << ", " << i << "\n";
	}
	
	
	arr1 = backup1, arr2 = backup2;
	p1=n-1, p2=0, count=0, z1=0, z2=0, inv1a=inv1, inv2a=inv2;
	for (int i = 1; i < n; i ++) {
		while (p1 > 0 && arr1[p1] != 0) {
			p1 -= 1;
			z1 += (arr1[p1] == 1);
		}
		while (p2 < n && arr2[p2] != 1) {
			p2 += 1;
			z2 += (arr2[p2] == 0);
		}
		
		if (p1 == 0 || p2 == n) {
			break;
		}
		else {
			count += (n-p1)-i;
			inv1a += z1;
			arr1[p1] = -1;
			
			count += (p2+1)-i;
			inv2a += z2;
			arr2[p2] = -1;
			
		}
		ans = min(ans, i*i+count+abs((inv1a-i*(c1))-(inv2a-i*(n-c2))));
		cout << ans << ", " << i*i+count << ", " << (inv1a-i*(c1)) << ", " << (inv2a-i*(n-c2)) << ", " << i << "\n";
	}
	
	cout << ans << "\n";
	
	return 0;
}

// it is always optimal to only swap two indices with different values
// when you swap two indices, you either reduce or increase inversions by 1
	// reduce if make 1 go to the right
	// increase if make 1 go to the left
// thus, if only allowed to swap left and right indices, the min swaps would be the difference in inversions
// when you swap the middle index, either reduce for both or increase for both
	// if 1 is on left, decrease by number of ones on left, number of zeros on right
	// if 0 is on left, increase by number of ones on left, decrease by number of zeros on right
// loop through both sides, put the i leftmost ones to the other side
	// calculate by first shifting other sides ones, then your ones
	// swaps are calculated at each index by moving obstructive index until it works, ignoring identical swaps
	// inversions are reduced by number of right 0s on the 1 shifting side, and vice versa
	// after, count number of inversions
	
// sol is incomplete
