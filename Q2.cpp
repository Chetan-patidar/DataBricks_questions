#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(int index,string panel,string str){
    int start = index;
    int n = panel.size();
    int p = 0;
    int n1 = str.size();
    
    while(start<n && p<n1){
        if(panel[start]!=str[p])
            return false;
        p++;
        start++;
    }
    if(p!=n1)
        return false;
    return true;
}


int main(){
    string panel;
    int n;
    cin>>panel;
    cin>>n;
    vector<string> answer;
    vector<string> codes(n,"");
    for(int i=0;i<n;i++){
        cin>>codes[i];
    }
    
    for(int i=0;i<n;i++){
        int len = codes[i].size();
        for(int end=0;end<(len-1);end++){
            int start = 0;
            int start_second = end+1;
            string str_index = codes[i].substr(0,end-0+1);
            int index = stoi(str_index);
            bool result = check(index,panel,codes[i].substr(start_second,len-1-start_second+1));
            if(result){
                answer.push_back(codes[i].substr(start_second,len-1-start_second+1));
            }
            else{
                answer.push_back("not found");
            }
        }
    }
    int s = answer.size();
    for(int i=0;i<s;i++){
        cout<<answer[i]<<"   ";
    }
    return 0;
}
