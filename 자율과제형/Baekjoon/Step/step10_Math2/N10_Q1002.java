package step10_Math2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class N10_Q1002 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int tc=1 ; tc<=T ; tc++) {
			int[] o1 = new int[2];
			int[] o2 = new int[2];
			int r1;
			int r2;
			StringTokenizer st = new StringTokenizer(br.readLine());
			o1[0] = Integer.parseInt(st.nextToken());
			o1[1] = Integer.parseInt(st.nextToken());
			r1 = Integer.parseInt(st.nextToken());
			o2[0] = Integer.parseInt(st.nextToken());
			o2[1] = Integer.parseInt(st.nextToken());
			r2 = Integer.parseInt(st.nextToken());
			
			int distX = Math.abs(o1[0]-o2[0]);
			int distY = Math.abs(o1[1]-o2[1]);
			double dist = Math.pow(distX*distX+distY*distY, 0.5);
			if(o1[0]==o2[0] && o1[1]==o2[1]) {
				// �߽��� ���� ��
				if(r1==r2) {
					// �Ÿ��� ���� -> ��� ����
					System.out.println(-1);
				}else {
					// �Ÿ��� �ٸ� -> ���� 0
					System.out.println(0);
				}
			}else {
				// �߽��� �ٸ� ��
				if(dist>r1+r2) {
					// �� ���� �ʹ� �� -> ���� 0
					System.out.println(0);
				}else if(dist+r1<r2 || dist+r2<r1){
					// �� ���� �ٸ� �� �ȿ� ���� -> ���� 0
					System.out.println(0);
				}else if (dist==(double)(r1+r2) || r1-dist==r2 || r2-dist==r1) {
					// ���� or ���� -> ���� 0
					System.out.println(1);
				}else {
					System.out.println(2);
				}
			}
			
		}
	}

}
