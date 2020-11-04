package Step16_DP1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class N10_Q2156 {
	// ½ÍÆÐ
	static int N;
	static int result;
	static int[] step;
	static Queue<Node> q;
	static class Node{
		int loc;
		int score;
		int conti;
//		String str;
		Node(int loc,int score, int conti/*,String str*/){
			this.loc = loc;
			this.score = score;
			this.conti = conti;
//			this.str = str;
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine().trim());
		result = Integer.MIN_VALUE;
		step = new int[N+1];
		q = new LinkedList();
		for(int i=1 ; i<N+1 ; i++) {
			step[i] = Integer.parseInt(br.readLine().trim());
		}
		q.add(new Node(N-2,step[N-1]+step[N-2],2));
		q.add(new Node(N-1,step[N]+step[N-1],2));
		bfs();
		System.out.println(result);
	}
	static void bfs() {
		while(!q.isEmpty()) {
			Node temp = null;
			temp = q.poll();
			int loc = temp.loc;
			int score = temp.score;
			if(canNotMove(temp)) {
				if(result<score) {
					result = score;
				}
			}else {
				if(temp.conti<2 && loc-1>=1)
					q.add(new Node(loc-1,score+step[loc-1],temp.conti+1/*,temp.str+" "+(loc+1)*/));
				if(loc-2>=1)
					q.add(new Node(loc-2,score+step[loc-2],1/*,temp.str+" "+(loc+2)*/));
			}
		}
	}
	static boolean canNotMove(Node temp) {
		int loc = temp.loc;
		int score = temp.score;
		int conti = temp.conti;
		if(loc==1) {
			return true;
		}
		if(loc==2 && conti==2) {
			return true;
		}
		return false;
	}
}
