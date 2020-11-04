package Step16_DP1;

import java.util.Scanner;

public class N09_Q10844 {
	static int N;
	static long result;
	static int mod=1000000000;
	static long[][] arr;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		result = 0;
		if(N==1) {
			System.out.println(9);
		}else {
			for(int i=1 ; i<10 ; i++) {
				int[] arr = new int[N];
				arr[0] = i;
				dfs(arr,1);
			}
			System.out.println(result%mod);
//			method2();
		}
	}
	static void method2() {
		arr = new long[N+1][10];
		int sum = 0;
		if(N==1) {
			System.out.println(9);
		}else if(N==2) {
			System.out.println(17);
		}else {
			for(int i=1 ; i<10 ; i++) {
				arr[1][i] = 1;
				arr[2][i] = 2;
			}
			arr[2][9] -= 1;
			for(int i=3 ; i<N+1 ; i++) {
				for(int j=1 ; j<10 ; j++) {
					if(j==1) {
						// 길이i,j로시작 = 길이i-2,1시작 + 길이i-1,2시작
						arr[i][j] = (arr[i-2][1]+arr[i-1][2])%mod;
					}else if(j==9) {
						arr[i][j] = arr[i-1][8]%mod;
					}else {
						arr[i][j] = (arr[i-1][j-1]+arr[i-1][j+1])%mod;
					}
				}
			}
			for(int i=1 ; i<10 ; i++) {
				sum += arr[N][i];
			}
			System.out.println(sum%mod);
		}
	}
	
	static void dfs(int[] arr,int indx) {
		if(indx==N) {
			result++;
			result = result%mod;
		}else {
			if(arr[indx-1]>0) {
				arr[indx] = arr[indx-1]-1;
				dfs(arr,indx+1);
			}
			if(arr[indx-1]<9) {
				arr[indx] = arr[indx-1]+1;
				dfs(arr,indx+1);
			}
		}
	}
}
