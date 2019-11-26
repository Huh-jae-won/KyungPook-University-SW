// 파일을 쓸 때 필요한 것들을 알아보자!
// 사용자로부터 나이, 이름 입력받기
import java.util.*;
import java.io.*;

class D15_OutputTest{
	public static void main(String[] args) throws FileNotFoundException{
		Scanner sc = new Scanner(System.in);
		File f1 = new File("D15_OutputTest.txt");
		System.out.println(f1.getName()+" : "+f1.exists());	// 처음만 false
		
		// 스트림 연결
		PrintWriter pw = new PrintWriter(f1/*어디에 연결?*/);	// 파일이 없다면 만들어줌
		System.out.println(f1.getName()+" : "+f1.exists());	// 따라서 true
		
		
		System.out.print("나이: ");
		int age = sc.nextInt();
		sc.nextLine();
		System.out.print("이름: ");
		String name = sc.nextLine();
		
		// 모니터에 출력
		System.out.printf("나이: %d, 이름: %s\n",age,name);
		
		// 파일에 출력
		pw.printf("나이 : %d, 이름 : %s",age,name);	// 윈도우에서의 개행 : \r\n

		// 버퍼에 있는 내용을 내보내겠다
		pw.close();	// pw를 다 쓰고 이제 그만 쓰겠다.
		System.out.println("파일을 확인해보세요 : "+f1.getAbsolutePath());
		
	}
}
