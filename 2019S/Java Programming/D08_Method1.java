// 클래스를 만들어 해당 클래스에 여러 메소드를 구현하였고
// 클래스를 객체화 시켜 메인에서 메소드들이 잘 구현되었는지 실행 시켜보았다.
import java.util.*;
// 메소드들을 가지고 있는 Method1 클래스
class Method1{
	
	double[] initArr(double[] arr){
		// 인자로 받은 배열에 난수를 저장 하여 반환하는 메소드
		for(int i=0 ; i<arr.length ; i++){
			arr[i] = Math.random()*10;
		}
		return arr;
	}
	
	void printArr(double[] arr){
		// 인자로 받은 배열의 값들을 차례대로 출력하는 메소드
		for(double x : arr){
			System.out.printf("%.2f ",x);
		}
		System.out.println();
	}
	
	double sumArr(double[] arr){
		// 인자로 받은 배열들의 값들을 모두 더하여 반환하는 메소드
		double sum = 0;
		for(double x : arr){
			sum += x;
		}
		return sum;
	}
	
	double maxArr(double[] arr){
		// 인자로 받은 배뎔들의 값 중 최댓값을 반환하는 메소드
		double max=arr[0];
		for(int i=1 ; i<arr.length ; i++){
			if(arr[i]>max){
				max = arr[i];
			}
		}
		return max;
	}
	
	int indexMaxArr(double[] arr){
		// 인자로 받은 배뎔들의 값중 최댓값의 index를 반환하는 메소드
		double max = arr[0];
		int maxIndex = 0;
		for(int i=1 ; i<arr.length ; i++){
			if(arr[i]>max){
				max = arr[i];
				maxIndex = i;
			}
		}
		return maxIndex;
	}
	
	void shuffleArr(double[] arr){
		// 인자로 받은 배뎔들의 값들의 순서를 섞어주는 메소드
		double buf;
		double temp[] = new double[arr.length];
		for(int i=0 ; i<arr.length ; i++){
			int index = (int)(Math.random()*arr.length);
			buf = arr[i];
			arr[i] = arr[index];
			arr[index] = buf;
		}
	}
	
	void rotateR1Arr(double[] arr){
		// 인자로 받은 배뎔들의 값들을 오른쪽으로 한칸씩 이동시키는 메소드
		// 가장 오른쪽 값은 0번째 index로 옮겨짐
		double temp = arr[arr.length-1];
		for(int i=arr.length-2 ; i>=0 ; i--){
			arr[i+1] = arr[i];
		}
		arr[0] = temp;
	}
	
	void rotateL1Arr(double[] arr){
		// 인자로 받은 배뎔들의 값들을 왼쪽으로 한칸씩 이동시키는 메소드
		// 가장 왼쪽의 값은 마지막 index로 옮겨짐
		double temp = arr[0];
		for(int i=1 ; i<arr.length ; i++){
			arr[i-1] = arr[i];
		}
		arr[arr.length-1] = temp;
	}
	
	void rotateRnArr(double[] arr, int n){
		// rotateR1Arr를 여러번 수행하는 메소드
		int rotate = n % arr.length;
		for(int i=1 ; i<=n ; i++){
			rotateR1Arr(arr);
		}
	}
	
	void rotateLnArr(double[] arr, int n){
		// rotateL1Arr를 여러번 수행하는 메소드
		int rotate = n % arr.length;
		for(int i=1 ; i<=n ; i++){
			rotateL1Arr(arr);
		}
	}
	
	
}

public class D08_Method1{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		Method1 m = new Method1();
		System.out.print("배열의 원소갯수 : ");
		int n = sc.nextInt();
		double[] arr = new double[n];

		m.initArr(arr);
		System.out.println("배열 성분 : ");
		m.printArr(arr);
		System.out.printf("합 : %.2f\n",m.sumArr(arr));
		System.out.printf("최댓값 : %.2f\n",m.maxArr(arr));
		System.out.printf("최댓값의 인덱스 : %d\n",m.indexMaxArr(arr));
		System.out.println("셔플후 배열성분 : ");
		m.printArr(arr);
		
		System.out.println("오른쪽으로1칸로테이션 : ");
		m.rotateR1Arr(arr);
		m.printArr(arr);
		System.out.println("왼쪽으로1칸로테이션 : ");
		m.rotateL1Arr(arr);
		m.printArr(arr);
		
		System.out.println("오른쪽 쉬프트횟수 : ");
		int right = sc.nextInt();
		System.out.printf("오른쪽으로%d칸로테이션 : ",right);
		m.rotateRnArr(arr,right);
		m.printArr(arr);
		
		System.out.println("왼쪽 쉬프트횟수 : ");
		int left = sc.nextInt();
		System.out.printf("왼쪽으로%d칸로테이션 : ",left);
		m.rotateLnArr(arr,left);
		m.printArr(arr);

		
	}
}
