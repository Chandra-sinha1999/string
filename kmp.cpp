#include <bits/stdc++.h>
using namespace std;
int reset[100];
void kmppat(string pat){
    int i = 0, j = 1;
    while(i < pat.size()){
        while(j >= 0 and pat[i] != pat[j]){
            j = reset[j];
        }
        i++;
        j++;
        reset[i] = j;
    }
}
void kmpsearch(string pat,string main){
    int i = 0, j = 0;
    while(i < main.size()){
        while(j >= 0 and main[i] != pat[j]){
            j = reset[j];
        }
        i++;
        j++;
        if(j == pat.size()) cout << i - j<< endl;
    }
}
int main() {
	memset(reset,-1,sizeof(reset));
	string m,patt;
	cin >> m >> patt;
	kmppat(patt);
	kmpsearch(patt,m);
	return 0;
}
