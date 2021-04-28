package A_String_Array;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Interval05{
	int start;
	int end;
	
	Interval05(){
		start = 0;
		end = 0;
	}
	Interval05(int s, int e){
		this.start = s;
		this.end = e;
	}
}

public class Q05_MergeInterval {
	public static void main(String[] args) {
		Q05_MergeInterval q05 = new Q05_MergeInterval();
		List<Interval05> in = new ArrayList<Interval05>();
		in.add(new Interval05(1,3));
		in.add(new Interval05(2,6));
		in.add(new Interval05(8,10));
		in.add(new Interval05(15,18));
		in.add(new Interval05(4,11));
//		q05.solution(in);
		q05.merge(in);
		

	}
	
	// �͸� Ŭ���� : ���ǿ� ��üȭ �ѹ��� �ۼ�
	Comparator comp = new Comparator<Interval05>() {
		@Override
		public int compare(Interval05 a, Interval05 b) {
			// TODO Auto-generated method stub
			return a.start - b.start; // ��������
		}
	};
	
	public List<Interval05> solution(List<Interval05> intervals){
		if(intervals.isEmpty())
			return null;
//		1. 
		List<Interval05> ret = new ArrayList<>();
		
		print(intervals);
		System.out.println();
		Collections.sort(intervals,comp); // �͸�Ŭ���� ���
		Collections.sort(intervals,(a,b)->a.start-b.start); // ����ǥ���� ���
		print(intervals);
		
		for(int i=0 ; i<intervals.size()-1 ; i++) {
			for(int j=i+1 ; j<intervals.size() ; j++) {
//				~~~~~~
			}
		}
		
		return null;
	}
	public List<Interval05> merge(List<Interval05> intervals){
		for(int i=0 ; i<intervals.size()-1 ; i++) {
			int j=i+1;
			while(j<intervals.size()) {
				if(intervals.get(i).end>intervals.get(j).start) {
					intervals.get(i).end = intervals.get(j).end;
					intervals.remove(j);
				}
				j++;
			}
		}
		return null;
	}
	public void print(List<Interval05> intervals) {
		for(int i=0 ; i<intervals.size() ; i++) {
			System.out.println(intervals.get(i).start+" ~ "+intervals.get(i).end);
		}
	}

}
