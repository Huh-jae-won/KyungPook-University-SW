package F_BackTracking;

import java.util.ArrayList;
import java.util.List;

public class Q02_Permutation {
	public static void main(String[] args) {
		Q02_Permutation a = new Q02_Permutation();
		int[] nums = {1,2,3};
		List<List<Integer>> ret;
//		ret = a.permute_dfs(nums);
		ret = a.solution(nums);
		System.out.println(ret);
	}
	public List<List<Integer>> solution(int[] nums) {
		List<List<Integer>> ret = new ArrayList<>();
		List<Integer> list = new ArrayList<>();
		if(nums==null || nums.length==0)
			return ret;
		sol_dfs(nums,ret,list);
		
		return ret;
	}
	private void sol_dfs(int[] nums, List<List<Integer>> ret, List<Integer>cur) {
		// ���
		if(cur.size()==nums.length) {
			// ���� ����� ��ƾ���
			List<Integer> temp = new ArrayList<Integer>(cur);
			ret.add(temp);
		}
		
		
		// ����, Ż��
		for(int i=0 ; i<nums.length ; i++) {
			// 3���Ǹ� skip�ǵ���
			if(cur.size()==nums.length) {
				break;
			}
			// �ߺ� ����
			if(cur.contains(nums[i]))
				continue;
			cur.add(nums[i]);
			sol_dfs(nums,ret,cur);
			cur.remove(cur.size()-1);
		}
	}
	
	/////////////////////////////////////////////////////////
	 public List<List<Integer>> permute_dfs(int[] nums) {
		 List<List<Integer>> ret = new ArrayList<>();
		 boolean[] visited = new boolean[nums.length];
		 dfs(ret,nums,visited,0,"");
		return ret;
	 }
	 private void dfs(List<List<Integer>>ret, int[] nums, boolean[] visited,int dep,String str) {
		 if(dep==nums.length) {
			 List<Integer> list = new ArrayList<Integer>();
			 for(char ch : str.toCharArray()) {
				 list.add(Integer.parseInt(String.valueOf(ch)));
			 }
//			 System.out.println(str);
			 ret.add(list);
			 return ;
		 }
		 for(int i=0 ; i<nums.length ; i++) {
			 if(!visited[i]) {
				 // if�� �����ϸ� �ߺ� ���� ���� ����
				 visited[i] = true;
				 dfs(ret,nums,visited,dep+1,str+nums[i]);
				 visited[i] = false;
			 }
		 }
	 }
}
