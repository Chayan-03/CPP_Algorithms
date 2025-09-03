#include <bits/stdc++.h>
#include <iostream>
using namespace std;



/* 
1. Use Segment over prefix su because it uses o(log n) TC and o(n) SC
2. Use in case of range sum query
*/


//Build a segment Tree 
void buildtree(int i, int l, int r, vector<int> arr, vector<int> strees) {
  if (l == r) {
    strees[i] = arr[l];
    return;
  }
  int mod = (l + r) / 2;
  buildtree(2 * i + 1, l, mod, arr, strees);
  buildtree(2 * i + 2, mod + 1, r, arr, strees);
  strees[i] = strees[2 * i + 1] + strees[2 * i + 2];
}

//Update a value at a index in the segmen tree
void update_buildtree(int i, int l, int r, vector<int> strees,
                      int index, int value) {
  if (l == r) {
    strees[i] = value;
    return;
  }
  int mid = (l + r) / 2;
  if (index > mid) {
    // move to right side
    update_buildtree(2 * i + 2, mid + 1, r, strees, index, value);
  } else {
    // move to left side as
    update_buildtree(2 * i + 1, l, mid,  strees, index, value);
  }
  strees[i] = strees[2 * i + 1] + strees[2 * i + 2];
}

//Rnage Sum Query usinG Segmen Tree
int range_sum_query(int i, int l, int r, vector<int> strees, int ql, int qr){
  if (l >= ql && r <= qr) {
    return strees[i];
  }
  
  //int his there can be 3 situations as  - 
  //1. Out of bound conditions
  if(l  > qr  || r < ql){
    return 0;
  }

  //2. Overlapping conditions
  if(l>=ql && r <=qr){
    return strees[i];
  }

  //3. Partial Overlapping conditions
  //move to left and right side
  int mid = (l+r)/2;
  return range_sum_query(2*i+1,l,mid,strees,ql,qr) + range_sum_query(2*i+2,mid+1,r,strees,ql,qr);
}

int main() {
  return 0;
}
