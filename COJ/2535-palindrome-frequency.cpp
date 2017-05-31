#include <bits/stdc++.h>
using namespace std;
int n, k;
string S;
set<string> done;
bool isPalindrome(int x, int y){
	for(int i = x; i <= (x + y)/2; i++){
		if(S[i] != S[y - i + x]) return false;
	}
	return true;
}
bool isP[510][510];
int main(){
	scanf("%d", &k);
	cin>>S;
	n = (int)S.length();
	string ans = "";
	int maxFreq = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			isP[i][j] = isPalindrome(i, j);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(isP[i][j] && j - i + 1 >= k){
				for(int r = i; r < j; r++){
					if(isP[i][r] && isP[r+1][j]){
						int F = 0;
						string st = S.substr(i, j - i + 1);
						size_t p = i-1;
						while((p = S.find(st, p+1)) != string::npos) F++;
						if(F > 0 && (F > maxFreq || F == maxFreq && st > ans)){
							maxFreq = F;
							ans = st;
						}
						break;
					}
				}
			}
		}
	}
	if(ans == "") printf("-\n");
	else printf("%s %d\n", ans.c_str(), maxFreq);
	return 0;
}