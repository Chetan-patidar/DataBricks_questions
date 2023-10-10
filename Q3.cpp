#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int available(vector<int> &arr,int total_slots,int start_index,int total){
    int start = start_index;
    for(int i=0;i<total_slots;i++){
        if(arr[(start_index+i)%total_slots]==0){
            int p = (start_index+i)%total_slots;
            bool aval = true;
            for(int j=0;j<total;j++){
                if(arr[(p+j)%total_slots]!=0){
                    aval = false;
                    break;
                }
            }
            if(aval){
                return i+start_index;
            }
        }
    }
    return -1;
    
}


int main(){
    vector<vector<string>> requests;
    int n;
    int total_slots;
    vector<int> answer;
    
    //input start
    cin>>n;
    for(int i=0;i<n;i++){
        vector<string> temp;
        string op,index,slot;
        cin>>op>>index>>slot;
        temp.push_back(op);
        temp.push_back(index);
        temp.push_back(slot);
        requests.push_back(temp);
    }
    cin>>total_slots;
    
    //input finish
    
    int current_available = total_slots;
    vector<int> slots_status(total_slots,0);
    
    //starting every query
    
    for(int i=0;i<n;i++){
        string operation = requests[i][0];
        int start_index = stoi(requests[i][1]);
        int total = stoi(requests[i][2]);
        if(operation=="store"){
            if(total>current_available){
                answer.push_back(-1);
                continue;
            }
            
            int s = start_index;
            int position = available(slots_status,total_slots,s,total);
            if(position==-1){
                answer.push_back(-1);
            }
            else{
                answer.push_back(position);
                current_available = current_available - total;
                for(int i=0;i<total;i++){
                    slots_status[(start_index+i)%total_slots] = 1;    
                }
            } 
        }
        else{
            //int start = start_index;int end = start_index+total;
            answer.push_back(total);
            for(int i=0;i<total;i++){
                slots_status[(start_index+i)%total_slots] = 0;
            }
            current_available = current_available + total;
        }
    }
    
    int s = answer.size();
    for(int i=0;i<s;i++){
        cout<<answer[i]<<"   ";
    }
    
    
    
}
