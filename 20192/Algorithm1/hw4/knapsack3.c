#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// knapsack problem
// Dynamic Programming을 활용하는 문제
// 1번 문제와 조금 다름 : 이문제는 1번문제에서 딱한번 한 물건을 weight를 2배, value도 2배로 두고 knapsack문제를 푸는것이다
// 물론 1번문제방식이 가장 큰값이라면 똑같이 출력을 하면됨

// 2배하는 것은 int형을 사용해도 무방하므로 다시 int형으로 바꿈
static int result[20][2];
static int numOfitem;
int save_file(char outfile[], int (*result)[2]);
int* make_value_arr(int (*value)[numOfitem+1], int (*item)[2], int max_weight);
void find_item(int (*valuePtr)[numOfitem+1], int (*itemPtr)[2], int weight, int i);
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
        // input의 숫자는 -1까지 짝수개 이므로 홀수개가 입력되었으면 오류 설명후 종료
        fprintf(stderr,"error) # of products and # of values are not matched\n");
        return -2;
    }
    int max_weight = (int)(number[cnt-2]);
    int max_value = 0;
    int a,b;
    int item[numOfitem+1][2];
    int value[max_weight+1][numOfitem+1];

    // item배열 생성 : 1번문제와 동일
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

    for(int x=0 ; x<numOfitem+1 ; x++){
        // 각 물건 마다 2배를 한 경우에 대해 kanpsack문제를 풀어 그중 최대value값을 찾으면 되므로 for문을 통해 numOfitem수만큼 반복
        // x가 0일땐 1번 문제와 동일(아무 물건도 2배를 안한상태)
        itemPtr[x][0] *= 2;
        itemPtr[x][1] *= 2;

        // 0번행과 0번열은 0으로 처리
        for(int i=0 ; i<=max_weight ; i++)
            value[i][0]=0;
        for(int i=0 ; i<=numOfitem ; i++)
            value[0][i]=0;
        valuePtr = make_value_arr(valuePtr,itemPtr,max_weight);
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
        
        if(x==0){
            result[0][0] = max_value;
            result[0][1] = x;
        }else{
            if(max_value > result[0][0]){
                result[0][0] = max_value;
                result[0][1] = x;
            }
        }

        find_item(valuePtr,itemPtr,max_weight,numOfitem);

        // 원상복귀 : 다음 수를 2배하여 똑같이 수행 해야하므로 
        //           현재 수는 다시 2로 나누어 원래값으로 돌려줌
        itemPtr[x][0] /= 2;
        itemPtr[x][1] /= 2;
        for(int i=1 ; i<numOfitem+1 ; i++){
            result[i][0]=0;
            result[i][1]=0;
        }
    }
    itemPtr[(int)result[0][1]][0] *= 2;
    itemPtr[(int)result[0][1]][1] *= 2;

    valuePtr = make_value_arr(valuePtr,itemPtr,max_weight);
    find_item(valuePtr,itemPtr,max_weight,numOfitem);
    rlt=result;

    // output file
    save_file(outfile,rlt);

    fclose(fp);
    return 0;
}
int* make_value_arr(int (*value)[numOfitem+1], int (*item)[2], int max_weight){
    // 1번문제에선 메인함수 안에서 처리 했지만
    // 좀더 이해하기 쉽도록 따로 함수로 만들었다
    for(int i=1 ; i<=numOfitem ; i++){
        for(int w=1 ; w<=max_weight ; w++){     // w : 현재 가능한 최대 무게
            if (item[i][0]<=w){
                if(item[i][1]+value[w-(item[i][0])][i-1] > value[w][i-1]){
                    value[w][i] = item[i][1] + value[w-(item[i][0])][i-1];
                }else{
                    value[w][i] = value[w][i-1];
                }
            }else{
                value[w][i] = value[w][i-1];
            }
        }
    }
    return value;
}


void find_item(int (*valuePtr)[numOfitem+1], int (*itemPtr)[2], int weight, int i){
    // 완성된 value배열에서 최대value에 맞는 물건들을 찾는 과정
    // 가장 value배열의 가장 끝부터 시작하여 역추적해 나감
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
    // 1번 문제와 거의 같음
    // 다른점은 물건을 2배하였다면 몇번물건을 2배 했는지 output file에 write해주는 과정을 추가하였다
    FILE *fp = fopen(outfile,"w");
    if ( !fp ) {
        fprintf(stderr, "cannot open file for write %s\n",outfile);
        return -1;
    }
    else {
        for(int i=1 ; i<=numOfitem ; i++){
            if(result[i][0]!=0){
                if(i==(int)result[0][1]){
                    fprintf(fp,"%dx2 ",i);
                }else{
                    fprintf(fp,"%d ",i);
                }
            }
        }
        fprintf(fp,"%d",result[0][0]);
        fclose(fp);
        return 0;
    }
}
