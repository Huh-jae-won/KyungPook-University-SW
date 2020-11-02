// 알고리즘1 수업 과제3
/* Binary search tree using doubly-linked lists
 * COMP319 Algorithms, Fall 2019
 * School of Electronics Engineering, Kyungpook National University
 * Instructor: Gil-Jin Jang
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
//#pragma warning(disable:4996)
#define MEASURE_TIME	// to measure time

 /////////////////////////////////////////////////////////////
 // DATA STRUCTURE:
 // binary tree node definition using doubly linked lists
 // key is a string of a fixed length
 // KEYLENGTH	length of the key
 // BULK_SIZE	key is hidden in the "BULK"
 //	to retrieve key, we have to dig into the "BULK"
 //	so accessing key takes average "BULK_SIZE"/2 searches
 //	this is INTENTIONALLY to add extra overhead for search
 //	your program should reduce the number of key accesses at your best
 /////////////////////////////////////////////////////////////
#define KEYLENGTH	3
#define BULK_SIZE	4096
//#define BULK_SIZE	65536;
typedef struct BTNode BTN;
struct BTNode {
	// bulk에 key값이 숨겨져 있음
	// getkey를 통해서만 bulk에서 key값을 꺼낼 수 있음
	char bulk[BULK_SIZE];	// null character to be added
	BTN* left, * right;	// binary tree: left and right children
};

BTN* del_BTN(BTN* current, BTN* before);
BTN* sorting_left(BTN* before, BTN* head);

const char* getkey(BTN* a);
// return value: char array of KEYLENGTH+1 (+1 for '\0' character)
//  key is hidden in "bulk", so use the following function to
//  read key string of length KEYLENGTH
//  it will make BULK_SIZE/2 searches on average
//  so try to use it as rarely as possible

int setkey(BTN* a, const char kw[]);
// return value: 0 for failure (NULL a), 1 for success
//  the following function hides a string "kw" of KEYLENGTH
//  by randomly selecting the location to save key

int copykey(BTN* dst, BTN* src)
{
	return setkey(dst, getkey(src));
}
// copies the key of one node to the other
// very simple, single line, so implementation is given here

int comparekey(BTN* a, BTN* b);
// return value: (by character comparison)
//  -1 if a's key < b's key
//  0 if a's key == b's key
//  +1 if a's key > b's key
//  may be needed for binary search tree search and build-up

BTN* generate_btnode(const char kw[]);
// return value: pointer to a single BTNode (left/right are NULL)
//  generates a node for binary tree

void free_bt_recursive(BTN* bt);
// frees a binary tree

BTN* copy_bt_recursive(BTN* bt);
// return value: pointer to the root of the copy of the given binary tree "bt"

BTN* insert_left_bcnode(BTN* parent, BTN* newPtr);
//  adds a node to the left of a BTNode parent
//  it will be used to generate a left-half binary tree
//  (LHBT, all rights are NULL)
// pre-condition: left pointer to the new node should be NULL
// to store the left pointer to the parent node
// return value: parent if the given parent is not NULL; newPtr if parent NULL

BTN* readkeys_textfile_LHBT(const char infile[], int* pN);
// File I/O: read key words from the given file
// and generate a binary tree which is left-half
// (all right children are NULL)

/////////////////////////////////////////////////////////////
// FILL 1: generate a binary search tree using insertion
/////////////////////////////////////////////////////////////
BTN* insert_to_BST_leaf(BTN* bst, BTN* newPtr)
//BT와 BST는 다름  -> BST가 되야 바이너리 서치 트리 성질을 이용가능
{
	if (bst == NULL) return newPtr;	// new bst as the input node
	else if (newPtr == NULL) return bst;	// nothing to add
	else {
		if (comparekey(bst, newPtr) < 0) { // bst < newPter 경우
		  /* FILL */
			if (bst->right != NULL) {
				insert_to_BST_leaf(bst->right, newPtr);
			}
			else {
				bst->right = newPtr;
			}
		}
		else {
			/* FILL */
			if (bst->left != NULL) {
				insert_to_BST_leaf(bst->left, newPtr);
			}
			else {
				bst->left = newPtr;
			}
		}
	}
	return bst;
}

BTN* generate_BST_by_insertion(BTN* lhbt)
{
	// lhbt : left-half binary tree, 왼쪽으로만 정렬된 바이너리 트리
	// lhbt를 받아와 BST(Binary Search Tree)형태로 만드는 함수
	/* FILL */
	BTN* head, * temp;
	int cnt = 0;
	head = temp = NULL;
	// lhbt의 첫노드를 떼어내서 temp로 
	temp = lhbt;
	lhbt = lhbt->left;
	temp->left = NULL;
	temp->right = NULL;
	
	if (head == NULL) {
		// 해당노드가 첫노드일 경우
		head = temp;
		temp = lhbt;
		lhbt = lhbt->left;
		temp->left = NULL;
		temp->right = NULL;
		cnt++;
	}
	while (1) {
		// 첫노드 이후 부턴 while문을 통하여 insert_to_BST함수를 반복 호출
		cnt++;
		insert_to_BST_leaf(head, temp);
		temp = lhbt;
		if (temp == NULL)  break;
		lhbt = lhbt->left;
		temp->left = NULL;
		temp->right = NULL;
	}
	return head;
}
/////////////////////////////////////////////////////////////
// FILL 2: PRINT
/////////////////////////////////////////////////////////////
int print_LHBT(FILE* fp, BTN* lhbt)
// 단순히 LHBT를 순서대로 outfile에 write
// ___-___-___ 형태
//   lhbt: left-half binary tree (right pointers are all null)
// RETURNs number of NODES in the list
{
	int num_nodes;

	num_nodes = 0;
	while (lhbt) {
		if (lhbt->right != NULL) {	// check if left-half
			fprintf(stderr, "Non-left-half binary tree for %s\n", __FUNCTION__);
			break;
		}
		else {
			fprintf(fp, "%s", getkey(lhbt));
			if (lhbt->left != NULL) fprintf(fp, "-");
		}
		num_nodes++;
		lhbt = lhbt->left;
	}

	fprintf(fp, "\n");	// change the line at the end
	return num_nodes;
}

int print_BST_sortedorder(FILE* fp, BTN* bst, int level)
// bst를 오름차순 정렬하고 outfile에 write
// prints a binary search tree nodes by a single line
// in a SORTED ORDER
{
	// 오름차순으로 정렬해야하므로 왼쪽 -> 가운데 -> 오른쪽 순으로 key값을 가져옴
	int count;	// to count the number of nodes
	count = 0;
	int a = 0, b = 0;
	if (bst != NULL) {
		level++;	// root node of the current subtree exists
		/* FILL: print left subtree */
		a = print_BST_sortedorder(fp, bst->left, level);
		count += a;
		// center node
		fprintf(fp, "%s ", getkey(bst));
		count++;
		/* FILL: print right subtree */
		b = print_BST_sortedorder(fp, bst->right, level);
		count += b;
	}
	// change the line once - only at the bst node
	if (level <= 1) fprintf(fp, "\n");
	return count;
}

int print_BST_right_center_left(FILE* fp, BTN* bst, int level)
// BST를 왼쪽으로 90도 회전시켜 출력하는 함수
// 90도 회전 시켰기 때문에 오른쪽->가운데->왼쪽 순으로 출력하면 됨
// 띄우는 칸을 맞춰줘야함
// outfile에 write
// Note: key's length is fixed to KEYLENGTH, so there are
// (KEYLENGTH+1)*level spaces. 
// ex)
//         999
//     777
//         555
// 333
//     222
//         111
{
	/* FILL */
	int height = level, a = 0, b = 0;
	if (bst != NULL) {
		level++;
		/* FILL: RIGHT */
		a = print_BST_right_center_left(fp, bst->right, level);
		if (a > height)    height = a;
		// center node
		for (int i = 1; i < level; i++) {
			fprintf(fp, "    ");    // 빈칸 4칸 (key값과 같은 길이)
		}
		fprintf(fp, "%s\n", getkey(bst));
		/* FILL: LEFT */
		b = print_BST_right_center_left(fp, bst->left, level);
		if (b > height)    height = b;
	}
	return height;
}

int print_BST_1(FILE* fp, BTN* bst, int level)
// print_BST_right_center_left함수에서 오른쪽노드와 부모노드를 '/'을 구분으로 같은 라인에 배치하여 outfile에 출력함
// ex)
// 333/777/999
//        +555
//    +222
//        +111
// (or)
// 100/400/800/900
//                +900
//            +800
//                +500/700
//    +000
{
	/* FILL */
	int height = level, a = 0, b = 0;
	if (bst != NULL) {
		// 중앙 -> 오른쪽 -> 왼쪽 순으로 outfile에 write
		level++;
		// center node
		fprintf(fp, "%s", getkey(bst));
		if (bst->right != NULL) {
			fprintf(fp, "/");
		}
		/* RIGHT */
		a = print_BST_1(fp, bst->right, level);
		if (a > height)    height = a;
		/* LEFT */
		if (bst->left != NULL) {
			fprintf(fp, "\n");
			for (int i = 1; i < 4 * (level); i++) {
				fprintf(fp, " ");
			}
			fprintf(fp, "+");
		}
		b = print_BST_1(fp, bst->left, level);
		if (b > height)    height = b;
	}
	return height;
}

int print_BST_2(FILE* fp, BTN* bst, int level, int set[])
// print_BST_1에서 왼쪽 자식노드를 구분하기 편하도록 |를 추가해줌
// same as print_BST_1 except vertical line from center to left
// ex)
// 100/400/800/900
//    |       |   +900
//    |       +800
//    |           +500/700
//    +000
//       static variable can be used as well
{
	/* FILL */
	int height = level, a = 0, b = 0;
	if (bst != NULL) {
		// 중앙 -> 오른쪽 -> 왼쪽 순으로 outfile에 write
		level++;
		// center node
		fprintf(fp, "%s", getkey(bst));
		if (bst->right != NULL) {
			fprintf(fp, "/");
		}
		if (bst->left != NULL) set[level] = 1;		// 왼쪽 자식노드가 있는 level에 배열을 1로 둠
		else    set[level] = 0;				// 왼쪽 자식이 있음을 나타내어 후에 |를 출력하도록 함
		/* FILL: RIGHT */
		a = print_BST_2(fp, bst->right, level, set);
		if (a > height)    height = a;
		/* FILL: LEFT */
		if (bst->left != NULL) {
			// 왼쪽 자식노드가 존재할 경우 줄을 바꿔줘야함
			fprintf(fp, "\n");
			for (int i = 1; i < 4 * (level); i++) {
				if (i % 4 == 0 && set[(i / 4)] == 1)  fprintf(fp, "|");		// 키길이가 빈칸4개길이이다
				else    fprintf(fp, " ");					// set배열이 해당 level에서 1이라면
			}									// |을 출력하도록 함
			fprintf(fp, "+");
		}
		set[level] = 0;
		b = print_BST_2(fp, bst->left, level, set);
		if (b > height)    height = b;
	}
	return height;
}

BTN* del_BTN(BTN* current, BTN* before) {
	BTN* tmp;
	if (current->right != NULL) {
		if (before != NULL) {
			before->left = current->right;
			current->left = current->right = NULL;
		}
		else {//before==NULL경우
			tmp = current;
			return tmp;
		}
	}
	else {
		if(before!=NULL)
			before->left = NULL;
	}
	return current;
}

BTN* sorting_left(BTN* bst,BTN *head) {
	// bst를 오름차순 정렬
	BTN *temp, *tail, *before;
	int cnt=0;
	while (1) {
        cnt++;
		temp = bst;
		before = NULL;
		while (temp->left != NULL) {
			before = temp;
			temp = temp->left;
		}
		tail = head;
		if (head == NULL) {
			head = del_BTN(temp, before);
		}
		else {
			while (tail->left != NULL)	tail = tail->left;
			tail->left = del_BTN(temp, before);
		}

		if (before == NULL && bst->right == NULL) {
			bst = NULL;
		}
		else if (before == NULL) {
		    bst = bst->right;
            temp->right=NULL;
		}
		if (bst==NULL) break;
	}
	return head;
}

int find_type(int num,int *left,int *right){
// complete BST는 노드 갯수를 안다면 root와 root의 왼쪽노드갯수, root의 오른쪽노드갯수를 알수있다.
// 따라서 root의 좌우 노드 갯수에 따라 type을 반환하고, 좌우 갯수는 매개변수에 담아 반환한다
    int height;
    int num_leaf;
    height = (int)ceil(log(num+1)/log(2));	// 노드갯수가 num일때의 height
    num_leaf = num - (int)(pow(2,height-1)-1);	// leaf단의 노드 갯수
    if(num==1){
        *left=0;
        *right=0;
        return num;
    }
    if(num_leaf<=(int)pow(2,height-2)){		// root의 오른쪽트리가 꽉찬경우
        *right = (int)pow(2,height-2)-1;
        *left = num-1-*right;
        return 10;
    }else{					// root의 왼쪽트리가 꽉찬경우
        *left = (int)pow(2,height-1)-1;
        *right = num-1-*left;
        return 20;
    }
}

BTN* BST_to_completeBST(BTN* bst, int numNodes, BTN *head)
// 매개변수로 bst, 노드갯수와 head노드를 받아와
// 완전이진트리를 구현하는 함수
{
	/* FILL */
    BTN *lhbt,*root=NULL,*left,*right,*before;
	lhbt=NULL;
	int num_l,num_r,type;
	if(head==NULL)
        lhbt = sorting_left(bst, lhbt); // bst를 오름차순인 LHBT를  만듦
    else
        lhbt = bst;
	root = lhbt;
	type = find_type(numNodes,&num_l,&num_r);  // numNodes를 이용해 완전이진트리로 구현시 필요한 root의 왼쪽트리, 오른쪽트리 갯수를 각각 구함
	left=root;
	if(root!=NULL){
        switch(type){
            case 10 :   // left는 덜참(h-1), right는 다참(h-2)
                for(int i=0 ; i<numNodes-num_r-1 ; i++){
                    if(i==numNodes-num_r-2){
                        before = root;
                    }
                    root = root->left;
                }                       // root값
                right = root->left;
                before->left=NULL;      // left의 마지막을 NULL로 => root와 연결을 끊음 =>left(root의 왼쪽트리) 완성
                root->left=NULL;        // right를 root와의 연결을 끊음 => root, right(root의 오른쪽트리) 완성
                //left, root, right 완성
                break;
            case 20 :   // left는 다참, right는 덜참 (둘다 높이 h-1)
                // left 경우
                for(int i=0 ; i<num_l ; i++ ){
                    if(i==num_l-1){
                        before = root;
                    }
                    root = root->left;  // root값
                }
                before->left=NULL;      // left의 마지막을 NULL로 => root와 연결을 끊음 =>left 완성
                right = root->left;     //
                root->left=NULL;        // right를 root와의 연결을 끊음 => root, right 완성
                //left, root, right 완성
                break;
            case 1 :
                return root;
                break;
        }
        if(head==NULL){
            head = root;
        }
        root->left = BST_to_completeBST(left,num_l,root);
        root->right = BST_to_completeBST(right,num_r,root);
	}
	return root;
}

BTN *pivoting(BTN *head,int type[]){
    //제일 위에노드를 pivot으로 좌우로 배치(?)
    int num_l, num_r, cnt_l=0,cnt_r=0;
    BTN *pivot, *temp, *left, *right, *compare, *l_tail, *r_tail;
    pivot = head;
    head = head->left;
    pivot->left=NULL;
    left=right=compare=NULL;
    temp=head;
    while(temp!=NULL){
        compare = temp;
        temp = temp->left;
        compare->left = NULL;
        int sign = comparekey(pivot,compare);
        if(type[0]==1 || type[0]==2){
        // 같을땐 왼쪽으로
            if(sign<0){ // pivot값 < compare값
                if(right==NULL){
                    right = compare;
                    r_tail = right;
                }else{
                    r_tail->left = compare;
                    r_tail = compare;
                }
            }else{// compare값 <= pivot값
                if(left == NULL){
                    left = compare;
                    l_tail = left;
                }else{
                    l_tail->left = compare;
                    l_tail = compare;
                }
            }
        }else if(type[0]==3){
        // 같을땐 오른쪽으로
            if(sign<=0){ // pivot값 <= compare값
                if(right==NULL){
                    right = compare;
                    r_tail = right;
                }else{
                    r_tail->left = compare;
                    r_tail = compare;
                }
            }else{// pivot값 > compare값
                if(left == NULL){
                    left = compare;
                    l_tail = left;
                }else{
                    l_tail->left = compare;
                    l_tail = compare;
                }
            }
        }else if(type[0] ==0){
        // 모든 노드가 같은 값일 때 left,right 번갈아가면서 달아줌
            if(cnt_l<=cnt_r){
                if(left == NULL){
                    left = compare;
                    l_tail = left;
                    cnt_l++;
                }else{
                    l_tail->left = compare;
                    l_tail = compare;
                    cnt_l++;
                }
            }else{
                if(right==NULL){
                    right = compare;
                    r_tail = right;
                    cnt_r++;
                }else{
                    r_tail->left = compare;
                    r_tail = compare;
                    cnt_r++;
                }
            }
        }else {
            // pivot값이 왼쪽에도 오른쪽에도 들어가는 경우
	    // type[2]에 들어가 있는 숫자만큼 pivot값과 같은 수를 왼쪽트리에 채워준후 나머지 pivot값과 같은 수는 오른쪽트리에 채움
            find_type(type,&num_l,&num_r);
            if(sign<0 ){ // pivot값 < compare값
                if(right==NULL){
                    right = compare;
                    r_tail = right;
                }else{
                    r_tail->left = compare;
                    r_tail = compare;
                }
            }else if(sign==0 && cnt_r<type[2]){
                cnt_r++;
                if(right==NULL){
                    right = compare;
                    r_tail = right;
                }else{
                    r_tail->left = compare;
                    r_tail = compare;
                }
            }else{// compare값 < pivot값 or <=
                if(left == NULL){
                    left = compare;
                    l_tail = left;
                }else{
                    l_tail->left = compare;
                    l_tail = compare;
                }
            }
        }
	}
	pivot->left = left;
	pivot->right = right;
	if(type[0]==1){ // type==1 : quicksort_basic
        if(left!=NULL)
            pivoting(pivot->left,type);
        if (right!=NULL)
            pivoting(pivot->right,type);
	}
	return pivot;
}
/////////////////////////////////////////////////////////////
// FILL 4: generate binary search tree from a left-half binary tree
// using quick sort
/////////////////////////////////////////////////////////////
BTN* generate_BST_quicksort_basic(BTN* lhbt)
// gerate a BST using quick sort algorithm
// the resultant tree should be identical to generate_BST_by_insertion
{
	/* FILL */
	int type[3]={1,0,0};
	BTN *temp, *pivot;
	temp=lhbt;
    pivot = pivoting(temp,type);
	return pivot;
}

// quicktsort를 이용하여 완전이진트리 만들기
BTN* generate_BST_quicksort_advanced(BTN* lhbt,int numNodes)
// challenge: try to reduce the height using quick sort algorithm
{
	int num_l,num_r, cnt_l, cnt_r, cnt_same, stop=0;
	int type[3]={0,0,0};
	BTN *pivot=NULL, *temp, *head, *tail, *pivot_l, *pivot_r;
	head=lhbt;
	temp=lhbt;
	for(;temp!=NULL;temp=temp->left){
       tail=temp;
	}
	find_type(numNodes,&num_l,&num_r);
    while(1){
	// lhbt의 root부터 pivot으로 두고 pviot의 왼쪽트리,오른쪽트리의 노드갯수를 구한다.
	// find_type함수로 구한 정확한 왼쪽트리,오른쪽트리의 노드갯수와 동일하다면 break를 통하여 while문을 빠져나온다
	// while문을 빠져 나올 방법 num_l==cnt_l && num_r==cnt_r
	// while문을 빠져 나올 경우
	// 1. pivot값과 같은 수를 가진 노드가 없을 경우 -> 단순히 알맞은 pivot에 대하여 quicksorting을 진행
	// 2. pivot값과 같은 수가 왼쪽 혹은 오른쪽에 들어있는경우 -> pivot값과 같은 값을 가지는 노드가 있는경우 cnt_same을 1증가시켜
	//    갯수를 파악한후 cnt_l,cnt_r이 num_l,num_r에 맞도록 잘 분배해준다.
        temp=head->left;
        cnt_l=0;
        cnt_r=0;
        cnt_same=0;
        for(;temp!=NULL ; temp=temp->left){// 같으면 왼쪽
            if(comparekey(head,temp)==0){
                cnt_same++;
            }
            if(comparekey(head,temp)>=0){
                cnt_l++;
            }else{
                cnt_r++;
            }
        }
        if(cnt_same>=2){
            for(int i=0 ; i<=cnt_same ; i++){
                for(int j=cnt_same-i ; j>=0 ; j--){
                    if( (cnt_l-cnt_same+i==num_l) && (cnt_r+j==num_r) ){
                        type[0]=numNodes;
                        type[1]=i;
                        type[2]=j;
                        break;
                    }
                }
            }
        }
        // 남은 부분이 전부 같은 숫자일 경우
        if(cnt_same==(cnt_l+cnt_r) && cnt_same!=0 ){
            type[0]=0;
            pivot = pivoting(head,type);
            break;
        }
        // pivot과 같은 값은 왼쪽으로
        if(cnt_l==num_l && cnt_r==num_r){
            type[0]=2;
            pivot = pivoting(head,type);
            break;
        }
        cnt_l=0;
        cnt_r=0;
        cnt_same=0;
        temp=head->left;
        for(;temp!=NULL ; temp=temp->left){// 같으면 오른쪽
            if(comparekey(head,temp)==0){
                cnt_same++;
            }
            if(comparekey(head,temp)>0){
                cnt_l++;
            }else{
                cnt_r++;
            }
        }
        // head와 값이 같은것이 여러개있고, 좌우로 나뉜경우
        if((cnt_l+type[1]==num_l)&&(cnt_r-cnt_same+type[2]==num_r)){
            pivot=pivoting(head,type);
            break;
        }
        // pivot과 같은 값은 오른쪽
        if(cnt_l==num_l && cnt_r==num_r){
            type[0]=3;
            pivot = pivoting(head,type);
            break;
        }
        tail->left = head;
        tail = head;
        head = head->left;
        tail->left=NULL;
    }
    // while문을 빠져 나왔다면
    // pivot을 잘 정했다는 것이고, pivot에 대하여 quicksorting을 진행한다.
    if(pivot->left!=NULL){
        pivot->left=generate_BST_quicksort_advanced(pivot->left,num_l);
    }
    if(pivot->right!=NULL){
        pivot->right=generate_BST_quicksort_advanced(pivot->right,num_r);
    }
	return pivot;
}

/////////////////////////////////////////////////////////////
// main function
/////////////////////////////////////////////////////////////
#define MAXLINE	1024
int main()
{
	int numWords;	// number of words
	//int wordLen;	// word length: number of characters per word
	BTN* root, *bst1, *bst2, *head=NULL, *tail;
	int numNodes, lev;	// level of the tree
	/* for file name, max length 1023 including path */
	char line[MAXLINE];
	char infile[MAXLINE], outfile[MAXLINE];
	FILE* fp;

#ifdef MEASURE_TIME
	clock_t start, end;
	double cpu_time_used;
#endif

	/* input file name given by keyboard */
	memset(line, 0, sizeof(char) * MAXLINE);	// clear the buffer
	fprintf(stderr, "Input file name? ");
	fgets(line, MAXLINE, stdin);
	if (strlen(line) == 0 || sscanf(line, "%s", infile) != 1) {
		fprintf(stderr, "cannot read input file name from '%s'\n", line);
		exit(0);
	}

	/* output file name: enter for standard out */
	memset(line, 0, sizeof(char) * MAXLINE);	// clear the buffer
	fprintf(stderr, "Output file name? ");
	fgets(line, MAXLINE, stdin);
	if (strlen(line) == 0 || sscanf(line, "%s", outfile) != 1) {
		fprintf(stderr, "cannot read output file name from '%s'\n", line);
		fprintf(stderr, "output to stdout\n");
		fp = stdout;
		memset(outfile, 0, sizeof(char) * MAXLINE);	// clear the buffer
	}
	else {
		/* open output file pointer */
		fp = fopen(outfile, "w");
		if (fp == NULL) {
			fprintf(stderr, "cannot open file '%s' for write\n", outfile);
			fprintf(stderr, "output to stdout\n");
			fp = stdout;
		}
	}

	/* read text file of integers:
	 * number_of_intergers integer1 integer2 ...
	 * then convert it to a linked list */
	root = readkeys_textfile_LHBT(infile, &numWords);

#ifdef MEASURE_TIME
	start = clock();
#endif

	if (root != NULL) {
		// prints input
		fprintf(fp, "=====================================\n");
		numNodes = print_LHBT(fp, root);
		fprintf(fp, "total %d nodes\n", numNodes);
		int set[100 / 2];
		for (int i = 0; i < sizeof(set) / sizeof(int); i++) {
			set[i] = 0;
		}

		// BST construction by simple insertion
		// keep root unchanged
		bst1 = generate_BST_by_insertion(copy_bt_recursive(root));
		fprintf(fp, "=====================================\n");
		numNodes = print_BST_sortedorder(fp, bst1, 0);
		fprintf(fp, "total %d nodes (sorted)\n", numNodes);
		fprintf(fp, "=====================================\n");
		lev = print_BST_right_center_left(fp, bst1, 0);
		fprintf(fp, "BST height %d\n", lev);
		fprintf(fp, "=====================================\n");
		lev = print_BST_1(fp, bst1, 0);
		fprintf(fp, "\nBST height %d\n", lev);
		fprintf(fp, "=====================================\n");
		lev = print_BST_2(fp, bst1, 0, set);
		fprintf(fp, "\nBST height %d\n", lev);
		fprintf(fp, "=====================================\n");
		bst1 = BST_to_completeBST(bst1, numNodes,head);
		lev = print_BST_2(fp, bst1, 0, set);
		fprintf(fp, "\nComplete BST height %d\n", lev);
		fprintf(fp, "=====================================\n");

		//2단계 : BST using quick sort, pivot as left, basic
		bst2 = generate_BST_quicksort_basic(copy_bt_recursive(root));
		lev = print_BST_2(fp, bst2, 0, set);
		fprintf(fp, "\nBST by QUICKSORT, height %d\n", lev);
		fprintf(fp, "=====================================\n");

		// BST using quick sort, advanced, to reduce height
		bst2 = generate_BST_quicksort_advanced(copy_bt_recursive(root),numNodes);
		lev = print_BST_2(fp, bst2, 0, set);
		fprintf(fp, "\nBST by QUICKSORT (advanced), height %d\n", lev);
		fprintf(fp, "=====================================\n");

		free_bt_recursive(root);
		free_bt_recursive(bst1);
		free_bt_recursive(bst2);
	}

#ifdef MEASURE_TIME
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	fprintf(fp, "TIME %.5f seconds\n", cpu_time_used);
#endif

	if (fp != NULL && fp != stdout) fclose(fp);
	return 0;
}


/////////////////////////////////////////////////////////////
// implementation: functions for binary tree node
/////////////////////////////////////////////////////////////


const char* getkey(BTN* a)
// bulk에서 key값을 꺼내오는 함수
{
	int i;
	for (i = 0; i < BULK_SIZE - KEYLENGTH; i++) {
		if (a->bulk[i] != '\0') return a->bulk + i;
	}
	return NULL;	// not found
}

int setkey(BTN* a, const char kw[])
// key값을 setting해주는 함수
{
	int pos;
	if (a != NULL) {
		// fill with 0
		memset(a->bulk, 0, sizeof(char) * BULK_SIZE);

		// find position randomly to store KEYLENGTH+1 characters
		pos = rand() % (BULK_SIZE - KEYLENGTH);
		if (kw != NULL) memcpy(a->bulk + pos, kw, sizeof(char) * KEYLENGTH);
		a->bulk[pos + KEYLENGTH] = '\0';	// to make it a C string

		// success
		return 1;
	}
	else return 0;
}

BTN* generate_btnode(const char kw[])
// 노드를 생성해주는 함수
{
	BTN* tmp;

	tmp = (BTN*)malloc(sizeof(BTN));
	setkey(tmp, kw);

	// initial left and right children for the generated leaf node
	tmp->left = tmp->right = NULL;

	return tmp;
}

void free_bt_recursive(BTN* bt)
// 트리를 free시켜주는 함수
{
	if (bt != NULL) {
		free_bt_recursive(bt->left);
		free_bt_recursive(bt->right);
		free(bt);
	}
}

BTN* copy_bt_recursive(BTN* bt)
// 트리를 복사하는 함수
{
	BTN* dup;

	if (bt != NULL) {
		dup = (BTN*)malloc(sizeof(BTN));
		copykey(dup, bt);
		dup->left = copy_bt_recursive(bt->left);
		dup->right = copy_bt_recursive(bt->right);
	}
	else dup = NULL;
	return dup;
}

BTN* insert_left_bcnode(BTN* parent, BTN* newPtr)
{
	if (parent == NULL) return newPtr;	// no parent
	else if (newPtr == NULL) return parent;	// Nothing to add
	else if (newPtr->left != NULL) {
		fprintf(stderr, "cannot add a node with non-null left tree\n");
		return parent;
	}
	else {
		newPtr->left = parent->left;
		parent->left = newPtr;
		return newPtr;	// returning new node as a new parent
	}
}

// static: internal use only
static int _compare_n_char(const char a[], const char b[], int L)
{
	int i;
	for (i = 0; i < L; i++) {
		if (a[i] < b[i]) return -1;
		else if (a[i] > b[i]) return 1;
		else continue;	// to next character
	}
	return 0;
}

int comparekey(BTN* a, BTN* b)
{
	return _compare_n_char(getkey(a), getkey(b), KEYLENGTH);
}

/////////////////////////////////////////////////////////////
// File I/O
/////////////////////////////////////////////////////////////
BTN* readkeys_textfile_LHBT(const char infile[], int* pN)
// read key words from the given file
// and generate a binary tree which is skewed to the left
// (all right children are NULL)
{
	BTN* root, * cur, * tmp;
	char word[1024];
	FILE* fp;
	int i;

	// check for input file name
	if (infile == NULL) {
		fprintf(stderr, "NULL file name\n");
		return NULL;
	}

	// check for file existence
	fp = fopen(infile, "r");
	if (!fp) {
		fprintf(stderr, "cannot open file %s\n", infile);
		return NULL;
	}

	// check for number of keys
	if (fscanf(fp, "%d", pN) != 1 || *pN <= 0) {
		fprintf(stderr, "File %s: ", infile);
		fprintf(stderr, "number of keys cannot be read or or wrong\n");
		fclose(fp);
		return NULL;
	}

	/*
	// check for number of characters per key
	if ( fscanf(fp, "%d", pL) != 1 || *pL <= 0 ) {
	  fprintf(stderr, "File %s: ",infile);
	  fprintf(stderr, "number of characters per key cannot be read or or wrong\n");
	  fclose(fp);
	  return NULL;
	}
	*/

	// reading keys
	root = cur = tmp = NULL;
	for (i = 0; i < (*pN); i++) {
		if (fscanf(fp, "%s", word) != 1) {
			fprintf(stderr, "cannot read a word at %d/%d\n", i + 1, (*pN));
			*pN = i;	// number of read keys so far
			break;
		}
		else {
			//check_and_correct_word(word, KEYLENGTH);

			// generate a new node
			tmp = generate_btnode(word);

			if (root == NULL) root = cur = tmp;
			else cur = insert_left_bcnode(cur, tmp);
		}
	}

	return root;
}
