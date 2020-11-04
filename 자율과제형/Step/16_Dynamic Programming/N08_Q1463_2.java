package Step16_DP1;

import java.util.Scanner;

public class N08_Q1463_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] dp = new int[N+1];
        for(int i=1 ; i<N+1 ; i++) {
        	dp[i] = N*4;
        }
        dp[1] = 0;
        int indx = 1;
        while(true) {
        	try {
        		int cnt = dp[indx];
        		int[] temp = {dp[indx+1],dp[indx*2]*2,dp[indx*3]};
        		//temp[i] : 다음 위치
        		for(int i=0 ; i<3 ; i++) {
        			if(cnt<dp[temp[i]]) {
        				dp[temp[i]] = cnt+1;
        			}
        		}
        		indx++;
        		if(indx==N+1) {
        			break;
        		}
        	}catch(ArrayIndexOutOfBoundsException e) {
        		continue;
        	}
        }
        System.out.println(dp[indx-1]);
    }
}

