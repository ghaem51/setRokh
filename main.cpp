#include <iostream>
using namespace std;
//map info:
//0=free
//1=wall
//2=Rokh
void printmap(int map[5][5]) {
    for(int i=1;i<=4;i++) {
        for (int j = 1; j <= 4; j++) {
            if (map[i][j] == 0)
                cout << "00";
            else if (map[i][j] == 1)
                cout << "##";
            else if (map[i][j] == 2)
                cout << "**";
            cout<<"|";
        }
        //------------
        cout <<"\n";
    }
}
int checkemap(int map[5][5]) {
    int counter=0;
    int i;
    int j;
    int sumcounter=0;
    for (i=1;i<=4;i++)//set emap numbers
        for (j=1;j<=4;j++) {
            counter=0;
            if (map[i][j] == 2) {
                int tempj = j;
                int tempi = i;
                tempj++;
                while (tempj <= 4) {//khone hay rast
                    if (map[tempi][tempj] == 1)
                        break;
                    if (map[tempi][tempj] == 2)
                        counter++;
                    tempj++;
                }
                tempj = j, tempi = i, tempj--;
                while (tempj >= 1) {//khone hay chap tar
                    if (map[tempi][tempj] == 1)
                        break;
                    if (map[tempi][tempj] == 2)
                        counter++;
                    tempj--;
                }
                tempj = j, tempi = i,tempi++;
                while (tempi <= 4) {//khone hay payen tar
                    if (map[tempi][tempj] == 1)
                        break;
                    if (map[tempi][tempj] == 2)
                        counter++;
                    tempi++;
                }
                tempj = j, tempi = i, tempi--;
                while (tempi >= 1) {//khone hay bala tar
                    if (map[tempi][tempj] == 1)
                        break;
                    if (map[tempi][tempj] == 2)
                        counter++;
                    tempi--;
                }
            }
            sumcounter+=counter;
        }
    return sumcounter;
}
void setemap(int map[5][5],int emap[5][5]){
    int i,j;
    for (i = 1; i <= 4; i++)//set emap numbers
        for (j = 1; j <= 4; j++) {
            int counter = 0;
            if (map[i][j] == 2) {
                int tempj = j;
                int tempi = i;
                tempj++;
                while (tempj <= 4) {//khone hay rast
                    if (map[tempi][tempj] == 1)
                        break;
                    if (map[tempi][tempj] == 2)
                        counter++;
                    tempj++;
                }
                tempj = j, tempi = i, tempj--;
                while (tempj >= 1) {//khone hay chap tar
                    if (map[tempi][tempj] == 1)
                        break;
                    if (map[tempi][tempj] == 2)
                        counter++;
                    tempj--;
                }
                tempj = j, tempi = i, tempi++;
                while (tempi <= 4) {//khone hay payen tar
                    if (map[tempi][tempj] == 1)
                        break;
                    if (map[tempi][tempj] == 2)
                        counter++;
                    tempi++;
                }
                tempj = j, tempi = i, tempi--;
                while (tempi >= 1) {//khone hay bala tar
                    if (map[tempi][tempj] == 1)
                        break;
                    if (map[tempi][tempj] == 2)
                        counter++;
                    tempi--;
                }
            }
            emap[i][j] = counter;
        }
}
void setrokh(int map[5][5],int emap[5][5]) {
    int i;
    int j;
    for (i = 1; i <= 4; i++) {//set all free space to 2 (rokh location)
        for (j = 1; j <= 4; j++) {
            if (map[i][j] == 0)
                map[i][j] = 2;
        }
    }
    int deln = checkemap(map);
    while (deln > 1) {
        deln = checkemap(map);
        if (deln==0)
            break;
        setemap(map, emap);
        int tempmax = 0;
        int k = 0;
        for (i = 1; i <= 4; i++)//find max error!!!
            for (j = 1; j <= 4; j++) {
                if (tempmax < emap[i][j]) {
                    tempmax = emap[i][j];
                }
            }
        for (i = 1; i <= 4; i++)//Number Of maxl need!!!
            for (j = 1; j <= 4; j++) {
                if (tempmax == emap[i][j]) {
                    k++;
                }
            }
        int **maxl=new int *[k];
        k = 0;
        for (i = 1; i <= 4; i++)//find max error semalation!!!
            for (j = 1; j <= 4; j++) {
                if (tempmax == emap[i][j]) {
                    maxl[k]=new int [2];
                    maxl[k][0] = i;
                    maxl[k][1] = j;
                    k++;
                }
            }
        int delet[2];
        int deln = 99;
        for (i = 0; i < k; i++) {
            map[maxl[i][0]][maxl[i][1]] = 0;
            if (deln >= checkemap(map)) {
                deln = checkemap(map);
                delet[0] = maxl[i][0];
                delet[1] = maxl[i][1];
            }
            map[maxl[i][0]][maxl[i][1]] = 2;
        }
        map[delet[0]][delet[1]] = 0;
        //printmap(map);//test
    }
}
//void changerokh(int map[5][5]){
//    int i,j;
//    int rokh=0;
//    for (i=1;i<=4;i++)
//        for(j=1;j<=4;j++)
//            if(map[i][j]==2)
//                rokh++;//counter for set all rokh we have
//    for (i=1;i<=4;i++)
//        for(j=1;j<=4;j++)
//            if(map[i][j]==2) {
//                map[i][j] = 0;
//                if(map[i-1][j]==0&i-1>=1) {
//                    map[i - 1][j] = 2;
//                    if (checkemap(map)==0)
//                        printmap(map);
//                    else {
//                        map[i - 1][j] = 0;
//                        map[i][j] = 2;
//                    }
//                }
//                else if(map[i+1][j]==0&i+1<=4) {
//                    map[i + 1][j] = 2;
//                    if (checkemap(map)==0)
//                        printmap(map);
//                    else {
//                        map[i + 1][j] = 0;
//                        map[i][j] = 2;
//                    }
//                }else
//                    map[i][j]=2;
//            }
//}
int main() {
    bool error1=1;
    int map[5][5];//map size 4*4 start from 1
    int emap[5][5];//map error counter
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            map[i][j]=0;
    int walls;
    while (error1==1) {
        cout << "enter Number Of Walls?";
        cin >> walls;
        if (walls >= 16)
            cout << "Out OF Range!!!\n";
        else
            error1=0;
    }
    char wallarray[2][4];
    int m=0;
    for(int i=1;i<=walls;i++){
        int x,y;
        bool error2=1,error3=1;
        while (error2==1) {
            cout << "enter j location*soton:Wall(" << i << ")\n";
            cin >> x;
            if(x>0&&x<=4)
                error2 = 0;
            else
                cout<<"Out Of Map Enter Number in Range(1-4)\n";
            wallarray[0][m] = x + 48;
        }
        while (error3==1) {
            cout << "enter i location*satr:Wall(" << i << ")\n";
            cin >> y;
            if(x>0&&x<=4)
                error3 = 0;
            else
                cout<<"Out Of Map Enter Number in Range(1-4)\n";
            wallarray[1][m] = y + 48;
        }
        map[y][x] = 1;
        m++;
    }
    printmap(map);
    cout<<"\nPress Enter To Continue...\n";
    system("read -n1 -p ' ' key");
    setrokh(map,emap);
    printmap(map);
    //changerokh(map);
    return 0;
}