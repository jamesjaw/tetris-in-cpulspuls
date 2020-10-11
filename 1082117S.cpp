#include<iostream>
#include<string>
#include <fstream>
using namespace std;
void drawgame(int h,int w,int*);//繪製遊戲
int main(){
//讀取test case測資
    ifstream fin("1082117S_proj1.data.txt");

    if(!fin){
        cout << "Error in read file" << endl;
    }
    string testcase,line1,line2,line3,line4,line5,line6;


    getline(fin,testcase);

    getline(fin,line1);
    getline(fin,line2);
    getline(fin,line3);
    getline(fin,line4);
    getline(fin,line5);
    getline(fin,line6);

    fin.close();
    cout<<line5<<endl;
//遊戲場地初始化

    int mapH,mapW;
    mapH = (int)testcase[0]-48;
    mapW = (int)testcase[2]-48;
    int map[mapH][mapW];

     cout<<mapH<<" "<<mapW<<endl<<endl;


    for(int i=0;i<mapH;i++){
        for(int j=0;j<mapW;j++){
                if(j==0 || j==mapW-1)
                    map[i][j] = 7;//7表示兩側
                else
                    map[i][j] = 0;//0表示空的

                if(i== mapH-1)
                    map[i][j] = 2;//2表示底邊


        }

    }

    drawgame(mapH,mapW,*map);

//建立方塊
    int T1[4][3] = { {0,0,0}
                    ,{0,0,0}
                    ,{1,1,1}
                    ,{0,1,0}};


    int T2[4][3] = { {0,0,0}
                    ,{0,1,0}
                    ,{1,1,0}
                    ,{0,1,0}};

    int T3[4][3] = { {0,0,0}
                    ,{0,0,0}
                    ,{0,1,0}
                    ,{1,1,1}};

    int T4[4][3] = { {0,0,0}
                    ,{1,0,0}
                    ,{1,1,0}
                    ,{1,0,0}};


    int L1[4][3] = { {0,0,0}
                    ,{1,0,0}
                    ,{1,0,0}
                    ,{1,1,0}};

    int L2[4][3] = { {0,0,0}
                    ,{0,0,0}
                    ,{1,1,1}
                    ,{1,0,0}};

    int L3[4][3] = { {0,0,0}
                    ,{1,1,0}
                    ,{0,1,0}
                    ,{0,1,0}};

    int L4[4][3] = { {0,0,0}
                    ,{0,0,0}
                    ,{0,0,1}
                    ,{1,1,1}};


    int J1[4][3] = { {0,0,0}
                    ,{0,1,0}
                    ,{0,1,0}
                    ,{1,1,0}};

    int J2[4][3] = { {0,0,0}
                    ,{0,0,0}
                    ,{1,0,0}
                    ,{1,1,1}};

    int J3[4][3] = { {0,0,0}
                    ,{1,1,0}
                    ,{1,0,0}
                    ,{1,0,0}};

    int J4[4][3] = { {0,0,0}
                    ,{0,0,0}
                    ,{1,1,1}
                    ,{0,0,1}};


    int S1[4][3] = { {0,0,0}
                    ,{0,0,0}
                    ,{0,1,1}
                    ,{1,1,0}};

    int S2[4][3] = { {0,0,0}
                    ,{1,0,0}
                    ,{1,1,0}
                    ,{0,1,0}};

    int Z1[4][3] = { {0,0,0}
                    ,{0,0,0}
                    ,{1,1,0}
                    ,{0,1,1}};

    int Z2[4][3] = { {0,0,0}
                    ,{0,1,0}
                    ,{1,1,0}
                    ,{1,0,0}};


    int I1[4][4] = { {1,0,0,0}
                    ,{1,0,0,0}
                    ,{1,0,0,0}
                    ,{1,0,0,0}};

    int I2[4][4] = { {0,0,0,0}
                    ,{0,0,0,0}
                    ,{0,0,0,0}
                    ,{1,1,1,1}};


    int O[4][4] = { {0,0,0,0}
                    ,{0,0,0,0}
                    ,{1,1,0,0}
                    ,{1,1,0,0}};

//放置方塊
//方塊落下
//方塊消除





ofstream fout("1082117S_proj1.final.txt");// 輸出結果


    if(!fout){
        cout << "Error in write the output" << endl;
    }
        for(int i=1;i<mapH-1;i++){
            for(int j=1;j<mapW-1;j++){
                fout<<map[i][j]<<" ";
        }
    fout<<endl;
}


    fout.close();

return 0;
}

void drawgame(int h,int w,int*map){
    for(int i=1;i<h-1;i++){             //xxxxxx 只繪製o的部分，邊框讓他隱藏以達到要求
        for(int j=1;j<w-1;j++){         //xoooox
            cout<<map[i*(w)+j];         //xoooox
        }                               //xxxxxx
    cout<<endl;
}
}







