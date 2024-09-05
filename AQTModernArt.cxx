#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> ans(0);

int realcount(int count, int x1, int x2, int y1, int y2) {
	for (int i = 0; i < ans.size(); i ++) {
		if (ans[i][0] >= x1 && ans[i][1] <= x2) {
			if (ans[i][2] >= y1 && ans[i][3] <= y2) {
				count -= 1;
			}
		}
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	
	int lastright=1, rcount;
	while (n) {
		// find smallest x2 values of unprocessed rectangles
		int l=lastright, r=1000000000;
		while (l <= r) {
			int mid = (l+r)/2, raw;
			cout << "? " <<  "1 " << mid << " 1 1000000000\n";
			cin >> raw;
			
			rcount = realcount(raw, 1, mid, 1, 1000000000);
			if (rcount) {
				r = mid;
				if (l == r) {
					break;
				}
			}
			else {
				l = mid+1;
			}
		}
		lastright = l;
		
		// find x1 value for each rectangle
		int lastleft = lastright, rcount2;
		while (rcount) {
			l = 1;
			r = lastleft;
			while (l <= r) {
				int mid = (l+r+1)/2, raw;
				cout << "? " <<  mid << " " << lastright << " 1 1000000000\n";
				cin >> raw;
				
				rcount2 = realcount(raw, mid, lastright, 1, 1000000000);
				if (rcount2) {
					l = mid;
					if (l == r) {
						break;
					}
				}
				else {
					r = mid-1;
				}
			}
			lastleft = l;
			rcount -= rcount2;
			
			// for each leftposition (decreasing order) find y1 and y2
			int lasttop = 1, rcount3;
			while (rcount2) {
				l = lasttop;
				r = 1000000000;
				// find smallest unprocessed y2 for this interval
				while (l <= r) {
					int mid = (l+r)/2, raw;
					cout << "? " << lastleft << " " << lastright << " 1 " << mid << "\n";
					cin >> raw;
					
					rcount3 = realcount(raw, lastleft, lastright, 1, mid);
					if (rcount3) {
						r = mid;
						if (l == r) {
							break;
						}
					}
					else {
						l = mid+1;
					}
				}
				lasttop = l;
				rcount2 -= rcount3;
				
				// find corresponding y1 for each y2 found
				int lastbottom=lasttop, rcount4;
				while (rcount3) {
					r = lastbottom;
					l = 1;
					while (l <= r) {
						int mid = (l+r+1)/2, raw;
						cout << "? " << lastleft << " " << lastright << " " << mid << " " << lasttop << "\n";
						cin >> raw;
						
						rcount4 = realcount(raw, lastleft, lastright, mid, lasttop);
						if (rcount4) {
							l = mid;
							if (l == r) {
								break;
							}
						}
						else {
							r = mid-1;
						}
					}
					lastbottom = l;
					rcount3 -= rcount4;
					
					for (int i = 0; i < rcount4; i ++) {
						ans.push_back({lastleft, lastright, lastbottom, lasttop});
						n -= 1;
					}
				}
			}
		}
	}
	
	cout << "!\n";
	for (int i = 0; i < ans.size(); i ++) {
		cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << "\n";
	}
	
	return 0;
}

