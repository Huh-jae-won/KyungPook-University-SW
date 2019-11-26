// 알고리즘1 수업의 과제
// 배열을 이용한 sorting
/* Directions: complete the code by filling in "FILL" parts
 *   adding functions and variables is allowed
 *   do not change print and file load/save
 *   do not use your compiler-specific libraries
 * FILL parts: merge sort on arrays
 */

/* Insertion sort and merge sort on arrays
 * COMP319 Algorithms, Fall 2019
 * School of Electronics Engineering, Kyungpook National University
 * Instructor: Gil-Jin Jang
 */

#include <stdio.h>
#include <stdlib.h>
void print( long A[], int N )
{
  int i;
  printf("[");
  for (i=0; i<N; i++) printf("%ld ",A[i]);
  printf("]\n");
}

long *readkeys_textfile( const char infile[], int *pN )
  // returns an array of long integers, with its size stored in
  // the memory indicated by integer pointer variable pN
  // the retured memory should freed by the caller
{
  long *A, tmp;
  int i;
  FILE *fp;

  // check for input file name
  if ( infile == NULL ) {
    fprintf(stderr, "NULL file name\n");
    return NULL;
  }

  // check for file existence
  fp = fopen(infile,"r");
  if ( !fp ) {
    fprintf(stderr, "cannot open file %s\n",infile);
    return NULL;
  }
  else {
    // check for number of elements
    if ( fscanf(fp, "%d", pN) != 1 || *pN <= 0 ) {
      fprintf(stderr, "cannot read number of elements %s\n",infile);
      return NULL;
    }
    else {
      A = (long*)malloc(sizeof(long)*(*pN));
      for (i=0; i<(*pN); i++) {
	if ( fscanf(fp, "%ld", &tmp) != 1 ) {
	  fprintf(stderr, "cannot read value at %d/%d\n",i+1,(*pN));
	  *pN = i;	// read data items
	  return A;
	}
	else A[i] = tmp;
      }
    }
    fclose(fp);
    return A;
  }
}

void savekeys_textfile( const char outfile[], long A[], int N )
  // save the given array of long integers, with its size N
  // to file whose name given by outfile[]
{
  int i;
  FILE *fp;

  // check for output filename
  if ( outfile == NULL ) {
    fprintf(stderr, "NULL file name\n");
    return;
  }

  // check for file existence
  fp = fopen(outfile,"w");
  if ( !fp ) {
    fprintf(stderr, "cannot open file for write %s\n",outfile);
  }
  else {
    // save number of elements
    fprintf(fp, "%d\n",N);
    for (i=0; i<N; i++) fprintf(fp, "%ld ", A[i]);
    fprintf(fp,"\n");
    fclose(fp);
  }
}

// insertion sort: GJ
void insertion_sort( long A[], int N )
{
  int i, j;
  long key;
  for (i=1; i<N; i++) {
    key = A[i];
    for (j=i-1; j >= 0 && A[j] > key ; j--) A[j+1] = A[j];
    A[j+1] = key;
  }
}

// merge sort
// A: arrays to be sorted, and to store output (fully sorted)
// Tmp: temporary space, size is at least right-left+1
void merge(long A[], long Tmp[], int left, int mid, int right){
      int l = left;     // 왼쪽 정렬 시작점
      int m = mid+1;    // 오른쪽 정렬 시작점
      int k = left;
      int t;
	// 중앙을 기준으로 두배열의 크기를 비교하여 작은것을 Tmp배열에 담는다
      while(l<=mid && m<=right){
            // 왼쪽이 큰경우
            if(A[l]>A[m]){
                  Tmp[k++]=A[m++];
            }
            // 오른쪽이 큰경우
            else{
                  Tmp[k++]=A[l++];
            }
      }
      // 한쪽 배열이 끝난 후 
      // 오른쪽이 남은경우
      if(l>mid){
            for(t=m ; t<=right ; t++){
                  Tmp[k++] = A[t];
            }
      }else {
      // 왼쪽이 남은 경우
            for(t=l ; t<=mid ; t++){
                  Tmp[k++] = A[t];
            }
      }
      //tmp값을 A로
      for(t=left ; t<=right ; t++){
            A[t] = Tmp[t];
      }
}

void merge_sort( long A[], long Tmp[], int left, int right ){
      int mid;
      if(left<right){
            mid = (left+right)/2;
            merge_sort(A, Tmp, left, mid);
            merge_sort(A, Tmp, mid+1, right);
            merge(A, Tmp, left, mid, right);
      }
}


/////////////////////////////////////////////////////////////
// main function
/////////////////////////////////////////////////////////////
/* File name by Argument input -> scanf read
 * Input file name can be typed in the terminal
 * Update on 9/24: element size is changed to long,
 * to distinguish array index easily
 * Update on 9/25: file reading is moved to a function readkeys_textfile()
 */
int main()
{
  int numElements;
  long *A;	// to store data to be sorted
  long *Tmp;	// merge sort only

  /* for file name, max length 1023 including path */
  char infile[1024], outfile[1024];
  int method;	// which sorting method

  /* file name given by keyboard */
  printf("Input file name? ");
  scanf("%s",infile);
  printf("Output file name? ");
  scanf("%s",outfile);
  // 1번 : insertion sorting, 2번 : merge sorting
  printf("Method (1: insertion, 2: merge)? ");
  scanf("%d",&method);

  /* read text file of integers:
   * number_of_intergers integer1 integer2 ... */
  A = readkeys_textfile(infile, &numElements);

  if ( A != NULL && numElements > 0 ) {
    // print all if not too many
    if ( numElements < 100 )	// GJ: comment out this line to always display
    {
      print(A, numElements);
      printf("%d Loaded\n", numElements);
    }

    switch ( method ) {
      case 1:	// insertion sort
	insertion_sort(A, numElements);
	break;
      case 2:	// merge sort
	Tmp = (long*) malloc(sizeof(long)*numElements);
	merge_sort(A, Tmp, 0, numElements-1);
	free(Tmp);
	break;
      default:
	break;
    }

    // print out results, if not too many
    if ( numElements < 100 )	// GJ: comment out this line to always display
      print(A, numElements);

    // save results
    savekeys_textfile(outfile, A, numElements);

    // once allocated, should be freed after use
    free(A);
  }

  return 0;
}
