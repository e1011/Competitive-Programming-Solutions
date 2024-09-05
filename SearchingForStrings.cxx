#include <iostream>
#include <vector>
#include <set>

using namespace std;

long long binexp(long long a, long long b, long long m) {
    a %= m;
    long long result = 1;
    while (b) {
        if (b & 1) {
            result *= a;
            result %= m;
        }
        b = (b >> 1);
        a *= a;
        a %= m;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s1, s2;
    cin >> s1 >> s2;
    
    if (s1.size() > s2.size()) {
        cout << "0\n";
        return 0;
    }
    
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    vector <int> frequency1(26, 0);
    for (int i = 0; i < s1.size(); i ++) {
        frequency1[alphabet.find(s1[i])] += 1;
    }
    
    int mod1=1000000007, mod2=1000000009, p=1000;
    vector <long long int> prefixhash1(1, 0);
    vector <long long int> inverses1(0);
    vector <long long int> prefixhash2(1, 0);
    vector <long long int> inverses2(0);
    for (int i = 0; i < s2.size(); i ++) {
        prefixhash1[i] += s2[i]*binexp(p, i, mod1);
        prefixhash1[i] %= mod1;
        prefixhash2[i] += s2[i]*binexp(p, i, mod2);
        prefixhash2[i] %= mod2;
        prefixhash1.push_back(prefixhash1[i]);
        prefixhash2.push_back(prefixhash2[i]);
        inverses1.push_back(binexp(binexp(p, i, mod1), mod1-2, mod1));
        inverses2.push_back(binexp(binexp(p, i, mod2), mod2-2, mod2));
    }
    
    int ans = 0;
    vector <int> frequency2(26, 0);
    set <int> hashes1;
    set <int> hashes2;
    for (int i = 0; i < s1.size(); i ++) {
        frequency2[alphabet.find(s2[i])] += 1;
    }
    for (int i = s1.size(); i < s2.size()+1; i ++) {
        if (frequency1 == frequency2) {
            long long int hash1 = prefixhash1[i-1];
            long long int hash2 = prefixhash2[i-1];
            if (i != s1.size()) {
                hash1 = ((hash1 - prefixhash1[i-1-s1.size()]) % mod1 + mod1) % mod1;
                hash2 = ((hash2 - prefixhash2[i-1-s1.size()]) % mod2 + mod2) % mod2;
                hash1 = (hash1*inverses1[i-s1.size()]) % mod1;
                hash2 = (hash2*inverses2[i-s1.size()]) % mod2;
            }
            if (hashes1.count(hash1) == 0 || hashes2.count(hash2) == 0) {
                hashes1.insert(hash1);
                hashes2.insert(hash2);
                ans += 1;
            }
        }
        
        if (i == s2.size()) {
            // ensures check starting pos and also ending pos
            break;
        }
        frequency2[alphabet.find(s2[i])] += 1;
        frequency2[alphabet.find(s2[i-s1.size()])] -= 1;
    }
    
    cout << ans << "\n";
    
    return 0;
}
