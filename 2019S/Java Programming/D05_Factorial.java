// n!���ϱ�, OverFlow�϶� n���ϱ�
import java.util.*;
class D05_Factorial {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n;
		int result = 1;
		int buf = 0;
		
		System.out.print("���� �Է� : ");
		n = sc.nextInt();
		for(int i = 2 ; i <= n ; i++){
			buf = result;
			result *= i;
			System.out.printf("%2d : buf : %10d, result : %10d\n",i,buf,result);
			if((result/buf)!=i){
				System.out.println("Overflow�߻�! �߻��� ��ġ�� n�� "+(i+1)+"�϶�");
				System.out.println("Overflow�߻��� ������ ��� ");
				System.out.print("n = "+i+"�϶� ");
				break;
			}
		}
		System.out.println("result = "+result);
	}
}