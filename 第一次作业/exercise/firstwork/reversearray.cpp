#include<iostream>
#include<vector>
using namespace std;

void reversearray(int*arr,int n)
{
if(n==0)
 {
  return;
 }

  int*left = arr;
  int*right = arr+n-1;
  while(left<right)
  {
    int temp = *right;
    *right =*left;
    *left = temp;
    left++;
    right--;
  }
}

int main()
{
int n = 0;
cin >> n;
vector<int>arr(n);
for(int i = 0 ;i<n;i++)
{
  cin >> arr[i];
}
cout<<endl;
reversearray(arr.data(), n);
 for(int i = 0;i<n;i++)
 {
  cout << arr[i] <<" ";
 }
 return 0;
}