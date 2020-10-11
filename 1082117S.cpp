#include<iostream>
#include<string>
#include <fstream>
using namespace std;
void drawgame(int h,int w,int*);//繪製遊戲函數


int main(){
//讀取test case測資
    ifstream fin("1082117S_proj1.data.txt");

    if(!fin){
        cout << "Error in read file" << endl;
    }
     int row,col;
    string blocknumber[1000];                              //有時間再改動態陣列
    int startpostion[1000];
    int finalmove[1000];
    fin>>row>>col;
    cout<<row<<" "<<col<<endl;
    int nb = 0;
    for(nb=0;nb<1000;nb++){
    fin>>blocknumber[nb]>>startpostion[nb]>>finalmove[nb];
    if(blocknumber[nb]=="End\0")                            //如果存到End則停止讀取檔案
        nb = 1000;
    }

    for(nb=0;nb<5;nb++){
        cout<<blocknumber[nb]<<" "<<startpostion[nb]<<" "<<finalmove[nb]<<endl;
        if(blocknumber[nb]=="End\0")
            cout<<"========================"<<endl;
    }




    fin.close();


//遊戲場地初始化

    int mapH,mapW;
    mapH = row+2;
    mapW = col+2;
    int map[mapH][mapW];

    for(int i=0;i<mapH;i++){
        for(int j=0;j<mapW;j++){
                if(j==0 || j==mapW-1)
                    map[i][j] = 7;//7表示兩側當碰與側邊重疊返回上一部並停止
                else
                    map[i][j] = 0;//0表示空的

                if(i== mapH-1)
                    map[i][j] = 2;//2表示底邊當碰到底移動n格然後停止
                if(i==0)
                    map[i][j] = 5;//5表示屋頂當碰到屋頂遊戲結束


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
    for(int i=0;i<h;i++){             //xxxxxx 只繪製o的部分，邊框讓他隱藏以達到要求
        for(int j=0;j<w;j++){         //xoooox
            cout<<map[i*(w)+j];         //xoooox
        }                               //xxxxxx
    cout<<endl;
}
}







