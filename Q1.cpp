#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i] = x;
    }
    
    vector<int> answer;
    bool first_turn = true;
    int start = 0;
    int end = n-1;
    cout<<"Input : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    while(start<=end){
        if(first_turn){
            answer.push_back(arr[start]);
            start++;
            first_turn = !first_turn;
        }
        else{
            answer.push_back(arr[end]);
            end--;
            first_turn = !first_turn;
        }
    }
    cout<<endl<<"Output : ";
    for(int i=0;i<n;i++){
        cout<<answer[i]<<"  ";
    }
}
