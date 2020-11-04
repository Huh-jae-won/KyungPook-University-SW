package Step16_DP1;

import java.util.Scanner;

public class N02_Q1003 {
	static int testCase;
	static int[] zero;
	static int[] one;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		testCase = Integer.parseInt(sc.nextLine().trim());
		for(int tc=1 ; tc<=testCase ; tc++) {
			zero = new int[42];
			one = new int[42];
			int n = Integer.parseInt(sc.nextLine().trim());
			zeroCnt(n);
			oneCnt(n);
			System.out.println(zero[n]+" "+one[n]);
		}
	}
	static int zeroCnt(int n) {
		if(n==0) {
			zero[0] = 1;
		}else if(n==1) {
			zero[1] = 0;
		}else if(zero[n]==0){
			zero[n] = zeroCnt(n-1)+zeroCnt(n-2);
		}else {
//			zero[n] = zero[n-1]+zero[n-2];
		}
		return zero[n];
	}
	
	static int oneCnt(int n) {
		if(n==0) {
			one[0] = 0;
		}else if(n==1) {
			one[1] = 1;
		}else if(one[n]==0){
			one[n] = oneCnt(n-1) + oneCnt(n-2);
		}else {
//			one[n] = one[n-1] + one[n-2];
		}
		return one[n];
	}

}
