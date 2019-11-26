
class OverRiding{
	//메소드 오버라이딩 : 메소드 시그니처만 다르면 중복정의가 가능하다!!
	int sum(int a, int b){
		int i = a+b;
		return i;
	}
	int sum(int a, int b, int c){
		int i = a+b+c;
		return i;
	}
/*	반환 타입만 다른것은 중복정의 불가능!!
	void sum(int a, int b){
		...
	}
*/
	double sum(double a, double b){
		double i = a+b;
		return i;
	}
}

public class D10_OverRiding{
	public static void main(String[] args){
		OverRiding or = new OverRiding();
		// 좀더 알맞은 메소드를 사용함 여기서는 int sum을 사용
		System.out.printf("1+2 = %d\n",or.sum(1,2));
		
		
	}
}