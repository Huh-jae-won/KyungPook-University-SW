package Step16_DP1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class N07_Q2579 {
	static int N;
//	static String strRslt;
	static int[] step;
	static int[] arr;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine().trim());
//		N=10;
		arr = new int[N+1];
		step = new int[N+1];
		for(int i=1 ; i<N+1 ; i++) {
			step[i] = Integer.parseInt(br.readLine().trim());
		}
		// 마실수 있는 경우
		// 1,2
		// 1,3
		// 2,3
		// 4번부터는
		// 1,2 4 -> arr[2]+step[4];
		// 2,3,x -> arr[3];
		// 1,3,4 -> arr[1]+step[3]+step[4];
		arr[1] = step[1];
		if(N==2) {
			System.out.println(step[1]+step[2]);
		}else if(N>=3){
			arr[2] = step[1]+step[2];
			arr[3] = (int) Math.max(Math.max(step[1]+step[2], step[1]+step[3]),step[2]+step[3]);
			for(int i=4 ; i<=N ; i++) {
				//					2,3				1,2					1,3
				arr[i] = Math.max(arr[i-1], Math.max(arr[i-2]+step[i], arr[i-3]+step[i-1]+step[i]));
			}
			System.out.println(arr[N]);
		}
	}
}
