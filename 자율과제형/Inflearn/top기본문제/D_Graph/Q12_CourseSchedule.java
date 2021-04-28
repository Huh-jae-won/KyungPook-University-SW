package D_Graph;

import java.util.LinkedList;
import java.util.Queue;

public class Q12_CourseSchedule {

	public static void main(String[] args) {
		int course = 4;
		int[][] nums = {
//				course ���� : 0,1,2,3, ������� ����
				{1,0},	// 1�� ������� : 0
				{2,1},	// 2�� ������� : 1
				{3,2}	// 3�� ������� : 2
 
			};
		int[][] nums2 = {
				{1,0},
				{0,1} };
		Q12_CourseSchedule q12 = new Q12_CourseSchedule();
		System.out.println(q12.solution(course, nums));
	}
	public boolean solution(int courseNumber, int[][] nums) {
		if(courseNumber <=0)
			return false;
		
//		1. inDegree �迭, Queue ����
		Queue<Integer> q = new LinkedList<>();
		int[] indegree = new int[courseNumber];
		
		int length = nums.length;
		for(int i=0 ; i<length ; i++) {
			// ��������̸� +1
			indegree[nums[i][1]]++;
		}
		
		for(int i=0 ; i<indegree.length ; i++) {
			if(indegree[i]==0) {
				q.offer(i);
			}
		}
		
		while(!q.isEmpty()) {
			int val = q.poll();
			for(int i=0 ; i<nums.length ; i++) {
				if(val==nums[i][0]) {
					int valPre = nums[i][1];	// val�� �������
					indegree[valPre]--;
					if(indegree[valPre]==0) {
						q.offer(valPre);
					}
				}
			}
		}
		
		for(int i=0 ; i<indegree.length ; i++) {
			if(indegree[i]!=0)
				return false;
		}
		return true;
	}
}
