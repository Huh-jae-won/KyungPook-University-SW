package step09_Math1;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class N08_Q1011 {
	static class Node{
		int loc;
		int befDist;
		int cnt;
		Node(int loc, int befDist,  int cnt){
			this.loc = loc;
			this.befDist = befDist;
			this.cnt = cnt;
		}
	}
	static int testCase;
	static int x;
	static int y;
	static int time;
	static Queue<Node> q;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		testCase = sc.nextInt();
		sc.nextLine();
		
		for(int tc=1 ; tc<=testCase ; tc++) {
			q = new LinkedList();
			x = sc.nextInt();
			y = sc.nextInt();
			sc.nextLine();
			time = Integer.MAX_VALUE;
//			System.out.println();
			q.add(new Node(x,0,0));
			bfs();
			System.out.println(time+1);
		}
	}
	static void bfs() {
		Node temp = null;
		while(!q.isEmpty()) {
			temp = q.poll();
			int loc = temp.loc;
			int befDist = temp.befDist;
			int cnt = temp.cnt;
//			System.out.printf("������ġ:%d ����ġ:%d �����̵��Ÿ�:%d Ƚ��:%d\n",temp.befLoc,loc,befDist,cnt);
			if(loc==y-1 && befDist<3) {
				if(time>cnt) {
					time = cnt;
				}else {
//					System.out.println(time+1);
					break;
				}
			}
			for(int i=-1 ; i<2 ; i++) {
				int nDist = befDist + i;	// �̹��� �̵��Ҽ� �ִ� �Ÿ�
				if(nDist>0 && loc+nDist<y)
					q.add(new Node(loc+nDist,nDist,cnt+1));
			}
		}
	}
}
