#include<iostream>
#include<string>
#include <fstream>

using namespace std;
int main(){
//讀取test case測資
    ifstream fin("1082117S_proj1.data.txt");

    if(!fin){
        cout << "Error in read file" << endl;
    }
    string testcase;

    getline(fin,testcase);

    char restdata[100];

    //restdata= testcase;

    fin.close();



//製作遊戲場地

    int mapH,mapW;
    mapH = (int)testcase[0]-48;
    mapW = (int)testcase[2]-48;
    int map[mapH][mapW];
     cout<<mapH<<" "<<mapW<<endl;
    for(int i=0;i<mapH;i++){
        for(int j=0;j<mapW;j++){
                if(j==0 || j==mapW-1)
                    map[i][j] = 7;//7表示兩側
                else
                    map[i][j] = 0;//0表示空的

                if(i== mapH-1)
                    map[i][j] = 2;//2表示底邊
    
                cout<<map[i][j];
        }
    cout<<endl;
    }





    char T1[4][3] = {{' ',' ',' '}
                    ,{' ',' ',' '}
                    ,{'O','O','O'}
                    ,{' ','O',' '}};
    char T2[4][3] = {{' ',' ',' '}
                    ,{' ','O',' '}
                    ,{'O','O',' '}
                    ,{' ','O',' '}};
    char T3[4][3] = {{' ',' ',' '}
                    ,{' ',' ',' '}
                    ,{' ','O',' '}
                    ,{'O','O','O'}};
    char T4[4][3] = {{' ',' ',' '}
                    ,{'O',' ',' '}
                    ,{'O','O',' '}
                    ,{'O',' ',' '}};

    char L1[4][3] = {{' ',' ',' '}
                    ,{'O',' ',' '}
                    ,{'O',' ',' '}
                    ,{'O','O',' '}};
    char L2[4][3] = {{' ',' ',' '}
                    ,{' ',' ',' '}
                    ,{'O','O','O'}
                    ,{'O',' ',' '}};
    char L3[4][3] = {{' ',' ',' '}
                    ,{'O','O',' '}
                    ,{' ','O',' '}
                    ,{' ','O',' '}};
    char L4[4][3] = {{' ',' ',' '}
                    ,{' ',' ',' '}
                    ,{' ',' ','O'}
                    ,{'O','O','O'}};

    char J1[4][3] = {{' ',' ',' '}
                    ,{' ','O',' '}
                    ,{' ','O',' '}
                    ,{'O','O',' '}};
    char J2[4][3] = {{' ',' ',' '}
                    ,{' ',' ',' '}
                    ,{'O',' ',' '}
                    ,{'O','O','O'}};
    char J3[4][3] = {{' ',' ',' '}
                    ,{'O','O',' '}
                    ,{'O',' ',' '}
                    ,{'O',' ',' '}};
    char J4[4][3] = {{' ',' ',' '}
                    ,{' ',' ',' '}
                    ,{'O','O','O'}
                    ,{' ',' ','O'}};

    char S1[4][3] = {{' ',' ',' '}
                    ,{' ',' ',' '}
                    ,{' ','O','O'}
                    ,{'O','O',' '}};
    char S2[4][3] = {{' ',' ',' '}
                    ,{'O',' ',' '}
                    ,{'O','O',' '}
                    ,{' ','O',' '}};
    char Z1[4][3] = {{' ',' ',' '}
                    ,{' ',' ',' '}
                    ,{'O','O',' '}
                    ,{' ','O','O'}};
    char Z2[4][3] = {{' ',' ',' '}
                    ,{' ','O',' '}
                    ,{'O','O',' '}
                    ,{'O',' ',' '}};

    char I1[4][4] = {{'O',' ',' ',' '}
                    ,{'O',' ',' ',' '}
                    ,{'O',' ',' ',' '}
                    ,{'O',' ',' ',' '}};
    char I2[4][4] = {{' ',' ',' ',' '}
                    ,{' ',' ',' ',' '}
                    ,{' ',' ',' ',' '}
                    ,{'O','O','O','O'}};

    char O[4][4] = {{' ',' ',' ',' '}
                    ,{' ',' ',' ',' '}
                    ,{'O','O',' ',' '}
                    ,{'O','O',' ',' '}};


ofstream fout("1082117S_proj1.final.txt");// 輸出結果


    if(!fout){
        cout << "Error in write the output" << endl;
    }
    fout<<"把整個遊戲的最終一行一行掃描出去用01的樣式哈哈哈";

    fout.close();









return 0;
}









