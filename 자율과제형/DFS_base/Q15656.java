package DFS_base;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q15656 {
	static int N = 0;
	static int M = 0;
	static int[] arr;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i=0 ; i<2 ; i++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			if(i==0) {
				N = Integer.parseInt(st.nextToken());
				M = Integer.parseInt(st.nextToken());	
				arr = new int[N];
			}else{
				for(int j=0 ; j<N ; j++) {
					arr[j] = Integer.parseInt(st.nextToken());
				}
			}
		}
		// sorting
		sorting();
		sol(0,"");
	}
	static void sol(int dep, String ans) {
		if(dep == M) {
			System.out.println(ans);
		}else {			
			for(int i=0 ; i<N ; i++) {
					sol(dep+1,ans+arr[i]+" ");
			}
		}
	}
	
	static void sorting() {
		int temp = 0;
		int cnt = N;
		while(cnt>1) {			
			for(int i=0 ; i<N-1 ; i++) {
				if(arr[i]>arr[i+1]) {
					temp = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = temp;
				}
			}
			cnt--;
		}
	}

}
