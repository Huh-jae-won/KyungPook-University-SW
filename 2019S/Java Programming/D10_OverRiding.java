
class OverRiding{
	//�޼ҵ� �������̵� : �޼ҵ� �ñ״�ó�� �ٸ��� �ߺ����ǰ� �����ϴ�!!
	int sum(int a, int b){
		int i = a+b;
		return i;
	}
	int sum(int a, int b, int c){
		int i = a+b+c;
		return i;
	}
/*	��ȯ Ÿ�Ը� �ٸ����� �ߺ����� �Ұ���!!
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
		// ���� �˸��� �޼ҵ带 ����� ���⼭�� int sum�� ���
		System.out.printf("1+2 = %d\n",or.sum(1,2));
		
		
	}
}