#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int list[10], cnt[10]{0};
void show(int index, int n, int m) {
	if(index==m) {
		for(int i=0; i<m; i++) {
			cout<<list[i]<<" ";
		}
		cout<<'\n';
		return;
	}
	
	for(int i=0; i<n; i++) {
		if(cnt[v[i]]>0) {
			cnt[v[i]]-=1;
			list[index]=v[i];
			show(index+1,n,m);
			cnt[v[i]]+=1;
		}
	}
}

int main() {
	int n,m,num;
	cin>>n>>m;
	
	for(int i=0; i<n; i++) { 
		cin>>num;
		if(find(v.begin(), v.end(), num)==v.end()) v.push_back(num);
		cnt[num]+=1;
	}

	sort(v.begin(), v.end());
	
	show(0,n,m);

	return 0;
}

/*
boj.kr/15663

INPUT:
4 2
9 7 9 1

OUTPUT:
1 7
1 9
7 1
7 9
9 1
9 7
9 9
*/
