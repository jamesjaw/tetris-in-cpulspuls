#include<iostream>
#include<string>
#include <fstream>
using namespace std;
void drawgame(int h,int w,int*);//繪製遊戲函數
void block1(int block ,int w,int x,int y,int m,int*,int jt);
int charsh(int h,int w,int*,int flag);
void washmap(int h,int w,int*);
void washmap1(int h,int w,int*);
void line(int h,int w,int*);



int main(){
//讀取test case測資
    ifstream fin("1082117S_proj1.data.txt");

    if(!fin){
        cout << "Error in read file" << endl;
    }
     int row,col;
    string blocknumber[1000];
    int BN[1000];
    int startpostion[1000];
    int finalmove[1000];

    fin>>row>>col;
    cout<<row<<" "<<col<<endl;
    int nb = 0;                       // nb代表輸入的方塊
    for(int i=0;i<1000;i++){
    fin>>blocknumber[i]>>startpostion[i]>>finalmove[i];
    nb+=1;
    if(blocknumber[i]=="T1\0")
        BN[i] = 1;
    if(blocknumber[i]=="T2\0")
        BN[i] = 2;
    if(blocknumber[i]=="T3\0")
        BN[i] = 3;
    if(blocknumber[i]=="T4\0")
        BN[i] = 4;
    if(blocknumber[i]=="L1\0")
        BN[i] = 5;
    if(blocknumber[i]=="L2\0")
        BN[i] = 6;
    if(blocknumber[i]=="L3\0")
        BN[i] = 7;
    if(blocknumber[i]=="L4\0")
        BN[i] = 8;
    if(blocknumber[i]=="J1\0")
        BN[i] = 9;
    if(blocknumber[i]=="J2\0")
        BN[i] = 10;
    if(blocknumber[i]=="J3\0")
        BN[i] = 11;
    if(blocknumber[i]=="J4\0")
        BN[i] = 12;
    if(blocknumber[i]=="S1\0")
        BN[i] = 13;
    if(blocknumber[i]=="S2\0")
        BN[i] = 14;
    if(blocknumber[i]=="Z1\0")
        BN[i] = 15;
    if(blocknumber[i]=="Z2\0")
        BN[i] = 16;
    if(blocknumber[i]=="I1\0")
        BN[i] = 17;
    if(blocknumber[i]=="I2\0")
        BN[i] = 18;
    if(blocknumber[i]=="O\0")
        BN[i] = 19;

    if(blocknumber[i]=="End\0")                            //如果存到End則停止讀取檔案
        i = 1000;
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
                    map[i][j] = 1;//7表示兩側當碰與側邊重疊返回上一部並停止
                else
                    map[i][j] = 0;//0表示空的

                if(i== mapH-1)
                    map[i][j] = 1;//1表示底邊當碰到底移動n格然後停止
                if(i==0)
                    map[i][j] = 9;//5表示屋頂當碰到屋頂遊戲結束

        }
    }
    //====================================================================
    cout<<nb<<"  "<<finalmove[0]<<endl;


    int x =1;
    int flag;
    int moven=1;
    int nmove;
    int newi;
    int pos;
    int blockdh;
    for(int runtime=0;runtime<nb;runtime++){            //開始放方塊進去
    x=1;
    pos = startpostion[runtime];
    moven = finalmove[runtime];
    blockdh = BN[runtime];
        for(int i=x;i<mapH;++i){
        line(mapH,mapW,*map);
        flag = 0;
        newi =i;                                       //每下降一格都要重新檢測所以要先把flag初始化
        flag=charsh(mapH,mapW,*map,flag);              //charsh是一個掃描地圖有無出現4或6的function
        washmap(mapH,mapW,*map);                       //下一格前要先整理地圖把走過的痕跡消除方便之後的判斷
        block1(blockdh,mapW,newi,pos,0,*map,3);        //方塊印到地圖上

        if(flag==1){                                   //發生碰撞時
        washmap(mapH,mapW,*map);
        block1(blockdh,mapW,newi-2,pos,0,*map,0);


        if(moven>=0){
        for(int k=0;k<=moven;k++){
        washmap(mapH,mapW,*map);
        block1(blockdh,mapW,newi-2,pos,k,*map,5);
        cout<<" i="<<i<<" mapH="<<mapH<<" newi="<<newi;
        drawgame(mapH,mapW,*map);
        flag=charsh(mapH,mapW,*map,flag);
        flag=charsh(mapH,mapW,*map,flag);
        if(flag==2){
        washmap(mapH,mapW,*map);
        block1(blockdh,mapW,i-2,pos,k-1,*map,3);     //向左還原
        washmap(mapH,mapW,*map);
        flag=0;
        for(int q=1;q<mapH;q++){
        washmap(mapH,mapW,*map);
        block1(blockdh,mapW,i-2+q,pos,k-1,*map,3);
        flag=charsh(mapH,mapW,*map,flag);
        drawgame(mapH,mapW,*map);
        if(flag==1){
            washmap(mapH,mapW,*map);
            block1(blockdh,mapW,i-2+q-1,pos,k-1,*map,1);
            q = mapH+1;
        }
        }



        drawgame(mapH,mapW,*map);
        k=moven+1;
        }
        if(k==moven){
         washmap(mapH,mapW,*map);
         block1(blockdh,mapW,newi-2,pos,k,*map,1);

         drawgame(mapH,mapW,*map);
        }
    }
    }

    if(moven<0){
        nmove = moven*-1;
        for(int k=0;k<=nmove;k++){
        washmap(mapH,mapW,*map);
        block1(blockdh,mapW,newi-2,pos,k*-1,*map,5);
        cout<<" i="<<i<<" mapH="<<mapH<<" newi="<<newi;
        drawgame(mapH,mapW,*map);
        flag=charsh(mapH,mapW,*map,flag);
        flag=charsh(mapH,mapW,*map,flag);
        if(flag==2){
        washmap(mapH,mapW,*map);
        block1(blockdh,mapW,i-2,pos,(k*-1)+1,*map,3);     //向右還原
        washmap(mapH,mapW,*map);
        flag=0;
        for(int q=1;q<mapH;q++){
        washmap(mapH,mapW,*map);
        block1(blockdh,mapW,i-2+q,pos,(k*-1)+1,*map,3);
        flag=charsh(mapH,mapW,*map,flag);
        drawgame(mapH,mapW,*map);
        if(flag==1){
            washmap(mapH,mapW,*map);
            block1(blockdh,mapW,i-2+q-1,pos,(k*-1)+1,*map,1);
            q = mapH+1;
        }
        }
        drawgame(mapH,mapW,*map);
        k=nmove+1;
        }
        if(k==nmove){
         washmap(mapH,mapW,*map);
         block1(blockdh,mapW,newi-2,pos,k,*map,1);
         drawgame(mapH,mapW,*map);
        }
    }

    }


        i=mapH;
    }


     cout<<flag<<"i="<<i<<endl;
     drawgame(mapH,mapW,*map);
    }


    }           //一次rumtime結束









//==================================================================

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
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<map[i*(w)+j];
        }
    cout<<endl;
}
cout<<endl;
}

void block1(int block,int w,int x,int y,int m,int*map,int jt){
    switch(block)
    {
    case 1:
    map[(x)*w+y+m]+=jt;
    map[(x)*w+y+1+m]+=jt;
    map[(x)*w+y+2+m]+=jt;
    map[(x+1)*w+y+1+m]+=jt;
    break;

    case 2:
    map[(x)*w+y+m]+=jt;
    map[(x+1)*w+y-1+m]+=jt;
    map[(x+1)*w+y+m]+=jt;
    map[(x+2)*w+y+m]+=jt;
    break;

    case 3:
    map[(x)*w+y+m]+=jt;
    map[(x+1)*w+y-1+m]+=jt;
    map[(x+1)*w+y+m]+=jt;
    map[(x+1)*w+y+1+m]+=jt;
    break;

    case 4:
    map[(x)*w+y+m]+=jt;
    map[(x+1)*w+y+m]+=jt;
    map[(x+1)*w+y+1+m]+=jt;
    map[(x+2)*w+y+m]+=jt;
    break;

    case 5:
    map[(x)*w+y+m]+=jt;
    map[(x+1)*w+y+m]+=jt;
    map[(x+2)*w+y+m]+=jt;
    map[(x+2)*w+y+1+m]+=jt;
    break;

    case 6:
    map[(x)*w+y+m]+=jt;
    map[(x)*w+y+1+m]+=jt;
    map[(x)*w+y+2+m]+=jt;
    map[(x+1)*w+y+m]+=jt;
    break;

    case 7:
    map[(x)*w+y+m]+=jt;
    map[(x)*w+y+1+m]+=jt;
    map[(x+1)*w+y+1+m]+=jt;
    map[(x+2)*w+y+1+m]+=jt;
    break;

    case 8:
    map[(x)*w+y+m]+=jt;
    map[(x+1)*w+y-2+m]+=jt;
    map[(x+1)*w+y-1+m]+=jt;
    map[(x+1)*w+y+m]+=jt;
    break;

    case 9:
    map[(x)*w+y+m]+=jt;
    map[(x+1)*w+y+m]+=jt;
    map[(x+2)*w+y+m]+=jt;
    map[(x+2)*w+y-1+m]+=jt;
    break;

    case 10:
    map[(x)*w+y+m]+=jt;
    map[(x+1)*w+y+m]+=jt;
    map[(x+1)*w+y+1+m]+=jt;
    map[(x+1)*w+y+2+m]+=jt;
    break;

    case 11:
    map[(x)*w+y+m]+=jt;
    map[(x)*w+y+1+m]+=jt;
    map[(x+1)*w+y+m]+=jt;
    map[(x+2)*w+y+m]+=jt;
    break;

    case 12:
    map[(x)*w+y+m]+=jt;
    map[(x)*w+y+1+m]+=jt;
    map[(x)*w+y+2+m]+=jt;
    map[(x+1)*w+y+2+m]+=jt;
    break;

    case 13:
    map[(x)*w+y+m]+=jt;
    map[(x)*w+y+1+m]+=jt;
    map[(x+1)*w+y-1+m]+=jt;
    map[(x+1)*w+y+m]+=jt;
    break;

    case 14:
    map[(x)*w+y+m]+=jt;
    map[(x+1)*w+y+m]+=jt;
    map[(x+1)*w+y+1+m]+=jt;
    map[(x+2)*w+y+1+m]+=jt;
    break;

    case 15:
    map[(x)*w+y+m]+=jt;
    map[(x)*w+y+1+m]+=jt;
    map[(x+1)*w+y+1+m]+=jt;
    map[(x+1)*w+y+2+m]+=jt;
    break;

    case 16:
    map[(x)*w+y+m]+=jt;
    map[(x+1)*w+y-1+m]+=jt;
    map[(x+1)*w+y+m]+=jt;
    map[(x+2)*w+y-1+m]+=jt;
    break;

    case 17:
    map[(x)*w+y+m]+=jt;
    map[(x+1)*w+y+m]+=jt;
    map[(x+2)*w+y+m]+=jt;
    map[(x+3)*w+y+m]+=jt;
    break;

    case 18:
    map[(x)*w+y+m]+=jt;
    map[(x)*w+y+1+m]+=jt;
    map[(x)*w+y+2+m]+=jt;
    map[(x)*w+y+3+m]+=jt;
    break;

    case 19:
    map[(x)*w+y+m]+=jt;
    map[(x)*w+y+1+m]+=jt;
    map[(x+1)*w+y+m]+=jt;
    map[(x+1)*w+y+1+m]+=jt;
    break;

    default:
    printf("u fool");


    }
}

void washmap(int h,int w,int*map){
for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            if(map[i*(w)+j]==3)
            map[i*(w)+j]=0;
            if(map[i*(w)+j]==4)
            map[i*(w)+j]=1;
            if(map[i*(w)+j]==6)
            map[i*(w)+j]=1;
            if(map[i*(w)+j]==5)
            map[i*(w)+j]=0;
        }
}
void washmap1(int h,int w,int*map){
for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){

            if(map[i*(w)+j]==5)
            map[i*(w)+j]=1;
        }
}

int charsh(int h,int w,int*map,int flag){
for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
                if(map[i*(w)+j]==4){      //撞到底
                    return 1;
                }
                if(map[i*(w)+j]==6){     //撞到牆
                    return 2;
                }

        }
}
return 0;
}

void line(int h,int w,int*map){
    for(int i=1;i<h-1;i++){
            int islinefull=1;
            for(int j=1;j<w-1;j++){
                islinefull*=map[i*w+j];
                }
            if(islinefull==1){
                for(int j=1;j<w-1;j++){
                    map[i*w+j]=0;
                    for(;i>0;i--)
                        for(int j=1;j<w-1;j++){
                            if(map[i*w+j]==1){

                                map[i*w+j]=0;
                                map[(i+1)*w+j]=1;
                            }

                    }
                    }
                }



}
}







