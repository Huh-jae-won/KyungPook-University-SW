// n!구하기, OverFlow일때 n구하기
import java.util.*;
class D05_Factorial {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n;
		int result = 1;
		int buf = 0;
		
		System.out.print("정수 입력 : ");
		n = sc.nextInt();
		for(int i = 2 ; i <= n ; i++){
			buf = result;
			result *= i;
			System.out.printf("%2d : buf : %10d, result : %10d\n",i,buf,result);
			if((result/buf)!=i){
				System.out.println("Overflow발생! 발생한 위치는 n이 "+(i+1)+"일때");
				System.out.println("Overflow발생전 까지의 결과 ");
				System.out.print("n = "+i+"일때 ");
				break;
			}
		}
		System.out.println("result = "+result);
	}
}