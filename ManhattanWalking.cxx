#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	
	vector <long long> h(0), v(0), h2(0), v2(0), h3(n, -1), v3(n, -1);
	
	for (int i = 0; i < n; i ++) {
		char a;
		int b;
		cin >> a >> b;
		if (a == 'H') {
			h.push_back(b);
		}
		else {
			v.push_back(b);
		}
	}
	
	for (int i = 1; i < h.size(); i ++) {
		if ((h[i]-h[i-1]) % 2 == 1) {
			h2.push_back(h[i]);
			h3[i] = (int)h2.size()-1;
			cout << h[i] << "\n";
		}
	}
	cout << "\n";
	for (int i = 1; i < v.size(); i ++) {
		if ((v[i]-v[i-1]) % 2 == 1) {
			v2.push_back(v[i]);
			v3[i] = (int)v2.size()-1;
			cout << v[i] << " ";
		}
	}
	cout << "\n";
	
	
	v.push_back(2000000020);
	h.push_back(2000000020);
	sort(v.begin(), v.end());
	sort(h.begin(), h.end());
	
	for (int i = 0; i < q; i ++) {
		int x, y, d;
		cin >> x >> y >> d;
		
		int lh=0, rh=(int)h.size()-1;
		while (lh < rh) {
			int mid = (lh+rh)/2;
			if (h[mid] >= y) {
				rh = mid;
			}
			else {
				lh = mid+1;
			}
		}
		
		int lv=0, rv=(int)v.size()-1;
		while (lv < rv) {
			int mid = (lv+rv)/2;
			if (v[mid] >= x) {
				rv = mid;
			}
			else {
				lv = mid+1;
			}
		}
		
		long long ph=lh, pv=lv, time=0;
		if (y != h[ph]) {
			if (d < h[ph]-y) {
				cout << x << " " << y+d << "\n";
				continue;
			}
			else {
				time += (h[ph]-y);
				y = h[ph];
			}
		}
		else if (x != v[pv]) {
			if (d < v[pv]-x) {
				cout << x+d << " " << y << "\n";
				continue;
			}
			else {
				time += (v[pv]-x);
				x = v[pv];
			}
		}
		bool notfinished = false;
		while (true) {
			if (h3[ph] != -1 && v3[pv] != -1) {
				notfinished = true;
				break;
			}
			if (time % 2 == 0) {
				if ((ph+1) == h.size() || time + h[(ph+1)]-y >= d) {
					cout << x << " " << y+(d-time) << "\n";
					break;
				}
				else {
					time += (h[(ph+1)]-y);
					ph += 1;
					y = h[ph];
				}
			}
			else {
				if ((pv+1) == v.size() || time + v[(pv+1)]-x >= d) {
					cout << x+(d-time) << " " << y << "\n";
					break;
				}
				else {
					time += (v[(pv+1)]-x);
					pv += 1;
					x = v[pv];
				}
			}
		}
		
		if (notfinished) {
			cout << "eidhaijs\n";
			ph = h3[ph];
			pv = v3[pv];
			int ladd=0, radd=min((int)v2.size()-pv-1, (int)h2.size()-ph-1);
			while (ladd < radd) {
				int mid = (ladd+radd)/2;
				if (time+h2[ph+mid]-y+v2[pv+mid]-x >= d) {
					radd = mid;
				}
				else {
					ladd = mid+1;
				}
			}
			
			if (time+h2[ph+ladd]-y+v2[pv+ladd]-x == d) {
				cout << "penis1 ";
				cout << v2[pv+ladd] << " " << h2[ph+ladd] << "\n";
			}
			else if (time % 2 == 0) {
				if (time+h2[ph+ladd]-y > d) {
					cout << "penis2 ";
					cout << v2[pv+ladd-1]+(d-time) << " " << h2[ph+ladd-1] << "\n";
				}
				else {
					cout << "penis3 ";
					cout << v2[pv+ladd] << " " << h2[ph+ladd-1]+(d-time) << "\n";
				}
			}
			else {
				if (time+v2[pv+ladd]-x > d) {
					cout << "penis4 ";
					cout << v2[pv+ladd-1] << " " << h2[ph+ladd-1]+(d-time) << "\n";
				}
				else {
					cout << "penis5 ";
					cout << v2[pv+ladd-1]+(d-time) << " " << h2[ph+ladd] << "\n";
				}
			}
		}
	}
	
	return 0;
}
// wtf is this problem....

