#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
static int result[20][2];
static int numOfitem;
int save_file(char outfile[], int (*result)[2]);
void find_item(int (*valuePtr)[], int (*itemPtr)[], int weight, int i);
int main(){
    char infile[1024];
    char outfile[1024];
    int cnt=0, tmp;
    int number[50];
    for (int i=0 ; i<50 ; i++)
        number[i]=0;
    FILE *fp;

    printf("input file name? ");
    scanf("%s",infile);
    printf("output file name? ");
    scanf("%s",outfile);

    fp = fopen(infile,"r");

    if(!fp){
        fprintf(stderr,"cannot open file %s\n",infile);
        return -1;
    }
    if(fscanf(fp,"%d",&numOfitem)!=1 || numOfitem<=0){
        fprintf(stderr,"error) # of items : %d",numOfitem);
        return -1;
    }
    do{
        fscanf(fp,"%d",&tmp);
        number[cnt++]=tmp;
    }while( tmp!=-1 );
    tmp=0;
    if(cnt%2!=0){
        fprintf(stderr,"error) # of products and # of values are not matched\n");
        return -2;
    }
    int max_weight = number[cnt-2];
    int max_value = 0;
    int a,b;
    int item[numOfitem+1][2];
    int value[max_weight+1][numOfitem+1];
    // item배열 생성
    item[0][0] = 0;
    item[0][1] = 0;
    for(int i=1 ; i<numOfitem+1 ; i++){
        for(int j=0 ; j<2 ; j++){
            item[i][j] = number[tmp++];
        }
    }
    for(int i=0 ; i<numOfitem+1 ; i++){
        for(int j=0 ; j<2 ; j++){
            result[i][j]=0;
        }
    }
    int (*itemPtr)[2] = item;
    int (*valuePtr)[numOfitem+1] = value;
    int (*rlt)[2] = result;

    for(int i=0 ; i<=max_weight ; i++)
        value[i][0]=0;
    for(int i=0 ; i<=numOfitem ; i++)
        value[0][i]=0;

    for(int i=1 ; i<=numOfitem ; i++){
        for(int w=1 ; w<=max_weight ; w++){
            // w : 현재 가능한 최대 무게
            if (item[i][0]<=w){
                if(item[i][1]+value[w-item[i][0]][i-1] > value[w][i-1]){
                    value[w][i] = item[i][1] + value[w-item[i][0]][i-1];
                }else{
                    value[w][i] = value[w][i-1];
                }
            }else{
                value[w][i] = value[w][i-1];
            }
        }
    }
    // max_value 찾기
    for(int i=1 ; i<=numOfitem ; i++){
        for(int w=1 ; w<=max_weight ; w++){
            if(max_value<value[w][i]){
                max_value = value[w][i];
                a=w;
                b=i;
            }
        }
    }
    result[0][0] = max_value;

    find_item(valuePtr,itemPtr,max_weight,numOfitem);
    // output file
    save_file(outfile,rlt);
    fclose(fp);
    return 0;
}
void find_item(int (*valuePtr)[numOfitem+1], int (*itemPtr)[2], int weight, int i){
    if( valuePtr[weight][i]!=0){
        if( valuePtr[weight][i-1]==valuePtr[weight][i] ){
            find_item(valuePtr, itemPtr, weight, i-1);
        }else if( valuePtr[weight-1][i]==valuePtr[weight][i] ){
            find_item(valuePtr, itemPtr, weight-1,i);
        }else{
            result[i][0] = itemPtr[i][0];
            result[i][1] = itemPtr[i][1];
            find_item(valuePtr, itemPtr, weight-itemPtr[i][0], i-1);
        }
    }
}
int save_file(char outfile[], int (*result)[2]){
    FILE *fp = fopen(outfile,"w");
    if ( !fp ) {
        fprintf(stderr, "cannot open file for write %s\n",outfile);
        return -1;
    }
    else {
        for(int i=1 ; i<=numOfitem ; i++){
            if(result[i][0]!=0) fprintf(fp,"%d ",i);
        }
        fprintf(fp,"%d",result[0][0]);
        fclose(fp);
        return 0;
    }
}
