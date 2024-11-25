#include<bits/stdc++.h>
#include<map>
#include<algorithm>
#include<vector>
#include<string>
using namespace std ;

void print_grid(vector<vector<char>>v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool check(vector<vector<char>>v,int row,int col,char c){
    bool res=true;
    // one col check
    for(int i=0;i<3;i++){
        if(v[i][col]!=c){
            res=false;
            break;
        }

    }
    if(res==true){
        return true;
    }
    //one row check
    res=true;
    for(int i=0;i<3;i++){
        if(v[row][i]!=c){
            res=false;
            break;
        }
    }
    if(res==true){
        return true;
    }
    if(v[0][0]==c && v[1][1]==c && v[2][2]==c){
        return true;
    }
    if(v[0][1]==c && v[1][1]==c && v[2][0]==c){
        return true;
    }
    return false;
}

int main(){
    vector<vector<char>>match_grid={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int pos;
    int cnt=0;
    char c;
    int row=0,col=0;
    bool res=false;
    int gpoint=0;
    int upoint=0,cpoint=0;

   cout<<"3*3 matrix tic tac toe game"<<endl;
   cout<<"game point : ";
   cin>>gpoint;
   do{
        do{
                cout<<"now"<<endl;
                print_grid(match_grid);
                cout<<" <<<<<<<<-------USER------>>>>>>> "<<endl;
                cout<<"enter the position: "<<endl;;
                cin>>pos;
                row=(pos-1)/3;
                col=abs((row*3)-(pos-1));
                match_grid[row][col]='0';
                cnt++;
                cout<<endl;
                cout<<"after user"<<endl;
                print_grid(match_grid);

                res=check(match_grid,row,col,'0');
                if(res==true){
                    cout<<"<<<<<<<<--------!!!!!!!! USER WIN !!!!!!!!-------->>>>>>>>"<<endl;
                    upoint++;
                    break;
                }
                else{
                    cout<<" <<<<<<<<-------COMPUTER------>>>>>>> "<<endl;
                    bool corr=false;
                    while(!corr){
                        pos=rand()%10;
                        row=(pos-1)/3;
                        col=abs((row*3)-(pos-1));
                        if(match_grid[row][col]=='0' || match_grid[row][col]=='x'){
                            continue;
                        }
                        else{
                            match_grid[row][col]='x';
                            corr=true;
                            cnt++;
                        }
                    }
                    cout<<endl;
                    cout<<"after computer"<<endl;
                    print_grid(match_grid);
                    cout<<endl<<endl;
                    res=check(match_grid,row,col,'x');
                    if(res==true){
                        cout<<"<<<<<<<<--------!!!!!!!! COMPUTER WIN !!!!!!!!-------->>>>>>>>"<<endl;;
                        cpoint++;
                        break;
                    } 
                }
                //cout<<"do you want to continur(y/n):";
                //cin>>c;

        }while(cnt!=9 && res==false);
        cout<<"<<<<<<-----SCORE----->>>>>>"<<endl;
        cout<<"USER :-> "<<upoint<<"    "<<"computer :-> "<<cpoint<<endl<<endl;
        if(cnt==9 && res!=true){
            cout<<"----------MATCH TIE----------"<<endl;
        }
        match_grid={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
        cnt=0;

    }while(upoint!=gpoint && cpoint!=gpoint);
    cout<<endl<<"game complete"<<endl;
    if(upoint==gpoint){
        cout<<"@@@@@@@@ ######## USER WIN THIS MATCH ####### @@@@@@@@@"<<endl;
    }
    else{
        cout<<"@@@@@@@@ ######## COMPUTER WIN THIS MATCH ####### @@@@@@@@@"<<endl;
    }
}