package A_String_Array;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Q15_FindAllAnagrams {

	public static void main(String[] args) {
		Q15_FindAllAnagrams q15 = new Q15_FindAllAnagrams();
		List<Integer> list = new ArrayList<>();

		String s = "BACDGABCDA";
		String p = "ABCD";
		
		list = q15.findAnagrams(s, p);
//		list = q15.solution(s, p);
		System.out.println("===result===");
		System.out.println(list);
	}
	public List<Integer> solution(String txt, String pat){
		List<Integer> result = new ArrayList<>();
		// �ʱ� ���� �ν�
		if(txt==null || txt.length()==0 || pat.length()==0 || txt.length()<pat.length()) {
			return result;
		}
		
		// ���Ͽ� �ش��ϴ� �ƽ�Ű�ڵ尪 index�� 1��
		int[] patArr = new int[256]; 
		for(int i=0 ; i<pat.length() ; i++) {
			patArr[pat.charAt(i)]++;
		}
		
		for(int i=0 ; i<=txt.length()-pat.length() ; i++) {
			int[] txtArr = new int[256];
			for(int j=0 ; j<pat.length() ; j++) {
				txtArr[txt.charAt(i+j)]++;
			}
			if(check(patArr, txtArr)) {
				result.add(i);
			}
//			if(patArr.equals(txtArr)) {
//				result.add(i);
//			}
		}
		
		return result;
	}
	private boolean check(int[] patArr, int[] txtArr) {
		for(int i=0 ; i<patArr.length ; i++) {
			if(patArr[i]!=txtArr[i])
				return false;
		}
		return true;
	}
	
	
	public List<Integer> findAnagrams(String txt, String pat){
		// ��� ���� ����Ʈ
		List<Integer> list = new ArrayList<>();
		
		// pat�� ���� set
		Set<Character> patSet = new HashSet<>();
		for(int i=0 ; i<pat.length() ; i++) {
			patSet.add(pat.charAt(i));
		}
		
		for(int i=0 ; i<=txt.length()-pat.length() ; i++) {
			Set<Character> compareSet = new HashSet<>();
			System.out.print(i+" : ");
			
			// pat���� ��ŭ �����Ͽ� set���� ����
			for(int j=i ; j<i+pat.length() ; j++) {
				compareSet.add(txt.charAt(j));
			}
			System.out.print(compareSet);
			
			// patSet�� compareSet�� �����ϸ� list�� index�߰�
			if(compareSet.equals(patSet)) {
				System.out.println(" + "+i+" �߰�");
				list.add(i);
			}else {
				System.out.println();
			}
		}
		return list;
	}

}
