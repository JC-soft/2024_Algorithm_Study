#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using lld = long long;

priority_queue<lld,vector<lld>,greater<lld>>start;
priority_queue<lld,vector<lld>,greater<lld>>ee;

int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  int n;
  lld s,e,ans = 0;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> s >> e;
    start.push(s);
    ee.push(e);
  }
  lld ns=start.top(),ne=ee.top();
  start.pop();
  ee.pop();
  bool flag = 0;
  while(!start.empty()){
    if(start.top() < ne){
      start.pop();
      ne=ee.top();
      ee.pop();
      flag = 0;
    }
    else{
      ans += abs(ne-ns);
      ns = start.top();
      start.pop();
      ne = ee.top();
      ee.pop();
      flag=1;
    }
  }
  ans+=abs(ne-ns);
  cout << ans;
  return 0;
}
