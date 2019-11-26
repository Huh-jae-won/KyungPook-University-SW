// 예외처리하는 법을 알아보자!
import java.util.*;

class D16_Exception{
	public static void main(String[] args){
		try{
			printAge();
		}catch(InputMismatchException e){	//메소드가 떠넘긴 예외를 여기서 직접 처리
			e.printStackTrace();
		}catch(NegativeAgeException nae){
			nae.printStackTrace();
			System.out.println(nae.getMessage());
		}
		System.out.println("실행이될까?2");	// trycatch가있다면 예외가 발생해도 실행이 된다.
	}
	static void printAge() throws InputMismatchException, NegativeAgeException {	// 수행하던곳(여기선 main)으로 예외를 처리하도록 떠넘김
		int age;
		Scanner sc = new Scanner(System.in);
		
		try{
			System.out.print("나이: ");
			age = sc.nextInt();
			if(age<0){	//예외 발생시키기는 조건
				throw new NegativeAgeException();	// throws아님!
				// throw : JVM에게 예외가 발생되었다고 알리는 키워드
			}
		
			System.out.printf("나이(%d)",age);
		}catch(InputMismatchException ime){		// 예외도 import 해줘야함
			System.out.println("나이를 정수로 입력하시오.");
			ime.printStackTrace();					// 예외가 발생했을때 stack상황출력
			System.out.println(ime.getMessage());	// 
		}
		System.out.println("실행이될까?1");		// trycatch가있다면 예외가 발생해도 실행이 된다.
		/*
		Error : 메모리부족, 정전,... 해결할 방법이없음 -> 컴파일러가 그냥 통과시켜줌
		RuntimeExcpetion : 프로그래밍 오류(0으로나눌때,NullPointer예외(실제 객체가없을때),인덱스범위초과,...) 보통 코드를 잘못짠 경우 -> 컴파일러가 가르쳐주지않음(스스로고쳐야함)(실행했을때 발생할수있음)
		나머지 Exception : 컴파일러가 직접 검사를 해줌, 예외처리를 해줘야함
		*/
	}
}
// 사용자 정의 예외 : ex) 음수나이 예외 -> 생성자만 작성
class NegativeAgeException extends Exception{	// 예외 클래스
	NegativeAgeException(){
		super("음수 나이 예외");	// 예외 정보 작성
	}
}
