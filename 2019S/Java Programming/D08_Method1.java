
import java.util.*;
class Method1{
	double[] initArr(double[] arr){
		for(int i=0 ; i<arr.length ; i++){
			arr[i] = Math.random()*10;
		}
		return arr;
	}
	
	void printArr(double[] arr){
		for(double x : arr){
			System.out.printf("%.2f ",x);
		}
		System.out.println();
	}
	
	double sumArr(double[] arr){
		double sum = 0;
		for(double x : arr){
			sum += x;
		}
		return sum;
	}
	
	double maxArr(double[] arr){
		double max=arr[0];
		for(int i=1 ; i<arr.length ; i++){
			if(arr[i]>max){
				max = arr[i];
			}
		}
		return max;
	}
	
	int indexMaxArr(double[] arr){
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
		double temp = arr[arr.length-1];
		for(int i=arr.length-2 ; i>=0 ; i--){
			arr[i+1] = arr[i];
		}
		arr[0] = temp;
	}
	
	void rotateL1Arr(double[] arr){
		double temp = arr[0];
		for(int i=1 ; i<arr.length ; i++){
			arr[i-1] = arr[i];
		}
		arr[arr.length-1] = temp;
	}
	
	void rotateRnArr(double[] arr, int n){
		int rotate = n % arr.length;
		for(int i=1 ; i<=n ; i++){
			rotateR1Arr(arr);
		}
	}
	
	void rotateLnArr(double[] arr, int n){
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