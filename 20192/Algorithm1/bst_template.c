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
	char bulk[BULK_SIZE];	// null character to be added
	BTN* left, * right;	// binary tree: left and right children
};


/////////////////////////////////////////////////////////////
// GIVEN: functions for binary tree node
// name and parameters only
// implementations are moved after "main" function
/////////////////////////////////////////////////////////////

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

BTN* insert_left_bcnode(
	BTN* parent, BTN* newPtr);
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
	/* FILL */
	BTN* head, * temp;
	int cnt = 0;
	head = temp = NULL;
	temp = lhbt;
	lhbt = lhbt->left;
	temp->left = NULL;
	temp->right = NULL;
	if (head == NULL) {
		head = temp;
		temp = lhbt;
		lhbt = lhbt->left;
		temp->left = NULL;
		temp->right = NULL;
		cnt++;
	}
	while (1) {
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
// prints left-half binary treechar
// ___-___-___
// INPUT
//   fp: file pointer for the output file, stdout for monitor output
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
// bst를 오름차순 정렬
// prints a binary search tree nodes by a single line
// in a SORTED ORDER
// (hint: inorder traversal)
// INPUT
//   fp: file pointer for the output file, stdout for monitor output
//   bst: root node of the BST, should satisfy the property of
//      binary search tree, left <= center < right
//   level: level of the root node, starting from 0 (empty)
//      if it is unnecessary, do not have to use it
// RETURNs number of NODES in the list
{
	/* GJ: you may fill out the *FILL* lines, or completely rewrite */
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
// prints a binary search tree, rotated by 270 degrees
// Note: key's length is fixed to KEYLENGTH, so there are
// (KEYLENGTH+1)*level spaces. For examples,
//         999
//     777
//         555
// 333
//     222
//         111
// INPUT
//   (same as print_BST_sortedorder)
// RETURNs HEIGHT-1 of the printed tree (2 in the above example)
//   (hint: printing order is right -> center -> left
//    carefully count the number of spaces)
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
			fprintf(fp, "    ");    // 빈칸 4칸
		}
		fprintf(fp, "%s\n", getkey(bst));
		/* FILL: LEFT */
		b = print_BST_right_center_left(fp, bst->left, level);
		if (b > height)    height = b;
	}
	return height;
}

int print_BST_1(FILE* fp, BTN* bst, int level)
// prints a binary search tree, rotated by 270 degrees, with less lines
//  1) center and right are in the same line
//  2) left subtree is below the center
//  3) right is connected by '/' and left by '+'
// Note: key's length is fixed to KEYLENGTH,
// so left and right begins at (KEYLENGTH+1)*level+1
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
// INPUT and OUPUT
//   (same as print_BST_right_center_left)
//   (hint: printing order is center -> right -> left)
{
	/* FILL */
	int height = level, a = 0, b = 0;
	if (bst != NULL) {
		level++;
		// center node
		fprintf(fp, "%s", getkey(bst));
		if (bst->right != NULL) {
			fprintf(fp, "/");
		}
		/* FILL: RIGHT */
		a = print_BST_1(fp, bst->right, level);
		if (a > height)    height = a;
		/* FILL: LEFT */
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
// same as print_BST_1 except vertical line from center to left
// 100/400/800/900
//    |       |   +900
//    |       +800
//    |           +500/700
//    +000
// Hint: stack or some extra variables may help.
//       static variable can be used as well
//       You may add additional parameter to the function if necessary
{
	/* FILL */
	int height = level, a = 0, b = 0;
	if (bst != NULL) {
		level++;
		// center node
		fprintf(fp, "%s", getkey(bst));
		if (bst->right != NULL) {
			fprintf(fp, "/");
		}
		if (bst->left != NULL) set[level] = 1;
		else    set[level] = 0;
		/* FILL: RIGHT */
		a = print_BST_2(fp, bst->right, level, set);
		if (a > height)    height = a;
		/* FILL: LEFT */
		if (bst->left != NULL) {
			fprintf(fp, "\n");
			for (int i = 1; i < 4 * (level); i++) {
				if (i % 4 == 0 && set[(i / 4)] == 1)  fprintf(fp, "|");
				else    fprintf(fp, " ");
			}
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
    int height;
    int num_leaf;
    height = (int)ceil(log(num+1)/log(2));
    num_leaf = num - (int)(pow(2,height-1)-1);
    if(num==1){
        *left=0;
        *right=0;
        return num;
    }
    if(num_leaf<=(int)pow(2,height-2)){
        *right = (int)pow(2,height-2)-1;
        *left = num-1-*right;
        return 10;
    }else{
        *left = (int)pow(2,height-1)-1;
        *right = num-1-*left;
        return 20;
    }
}

/////////////////////////////////////////////////////////////
// FILL 3: Conversionsorting_lhbt of an BST to a complete BST
/////////////////////////////////////////////////////////////

BTN* BST_to_completeBST(BTN* bst, int numNodes, BTN *head)
{
	/* FILL */
    BTN *lhbt,*root=NULL,*left,*right,*before;
	lhbt=NULL;
	int num_l,num_r,type;
	if(head==NULL)
        lhbt = sorting_left(bst, lhbt); //LHBT오름차순 만듬
    else
        lhbt = bst;
	root = lhbt;
	type = find_type(numNodes,&num_l,&num_r);  // numNodes
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
                before->left=NULL;      // left의 마지막을 NULL로 => root와 연결을 끊음 =>left 완성
                root->left=NULL;        // right를 root와의 연결을 끊음 => root, right 완성
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
{
	int i;
	for (i = 0; i < BULK_SIZE - KEYLENGTH; i++) {
		if (a->bulk[i] != '\0') return a->bulk + i;
	}
	return NULL;	// not found
}

int setkey(BTN* a, const char kw[])
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
{
	BTN* tmp;

	tmp = (BTN*)malloc(sizeof(BTN));
	setkey(tmp, kw);

	// initial left and right children for the generated leaf node
	tmp->left = tmp->right = NULL;

	return tmp;
}

void free_bt_recursive(BTN* bt)
{
	if (bt != NULL) {
		free_bt_recursive(bt->left);
		free_bt_recursive(bt->right);
		free(bt);
	}
}

BTN* copy_bt_recursive(BTN* bt)
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
