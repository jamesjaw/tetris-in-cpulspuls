#include<iostream>
#include<string>
#include <fstream>
using namespace std;
void drawgame(int h,int w,int*);//繪製遊戲函數
void block1(int block ,int w,int x,int y,int m,int*,int jt);
int charsh(int h,int w,int*,int flag);
void washmap(int h,int w,int*);



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
    int nb = 0;                       // nb代表輸入的方塊
    for(int i=0;i<1000;i++){
    fin>>blocknumber[i]>>startpostion[i]>>finalmove[i];
    nb+=1;
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
                    map[i][j] = 7;//7表示兩側當碰與側邊重疊返回上一部並停止
                else
                    map[i][j] = 0;//0表示空的

                if(i== mapH-1)
                    map[i][j] = 1;//1表示底邊當碰到底移動n格然後停止
                if(i==0)
                    map[i][j] = 5;//5表示屋頂當碰到屋頂遊戲結束

        }

    }
    //====================================================================
    cout<<nb<<endl;

    int x =1; int flag; int move=1;
    for(int i=x;i<mapH;++i){
    flag = 0;
    flag=charsh(mapH,mapW,*map,flag);
    washmap(mapH,mapW,*map);
    block1(13,mapW,i,2,0,*map,3);

    if(flag==1){
    washmap(mapH,mapW,*map);
    for(int k=0;k<4;k++){
    washmap(mapH,mapW,*map);
    block1(13,mapW,i-2,2,k,*map,2);

    drawgame(mapH,mapW,*map);

    }
    i=mapH;
    }
    flag=charsh(mapH,mapW,*map,flag);
    if(flag==2){

    washmap(mapH,mapW,*map);
    block1(13,mapW-1,mapH-1,-1,0,*map,1);  //maph,13還原要換成代數
    }

    cout<<flag<<endl;
     drawgame(mapH,mapW,*map);
    }










//放置方塊


//方塊落下


//方塊消除



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
            if(map[i*(w)+j]==9)
            map[i*(w)+j]=7;
            if(map[i*(w)+j]==2)
            map[i*(w)+j]=0;
        }
}

int charsh(int h,int w,int*map,int flag){
for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
                if(map[i*(w)+j]==4){      //撞到底
                    return 1;
                }
                if(map[i*(w)+j]==9){     //撞到牆
                    return 2;
                }

        }
}
return 0;
}







