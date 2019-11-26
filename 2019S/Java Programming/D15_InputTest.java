
import java.util.*;
import java.io.*;

class D15_InputTest{
	public static void main(String[] args) throws FileNotFoundException{
		File f1 = new File("D15_OutputTest.txt");
		// f가 존재한다면 진행, 아니면 종료
		if(!f1.exists()){
			System.out.println(f1.getName()+"파일이 없습니다. 프로그램을 종료합니다.");
			System.exit(0);
		}
		Scanner sc = new Scanner(f1/*어디에 연결?*/);
		
		Student[] st = new Student[2];
		int age; 
		String name;
		for(int i=0 ; i<st.length ; i++){
			String temp;
			sc.next();
			temp = sc.next();
			age = Integer.parseInt(temp.substring(0,temp.length()-1));
			sc.next();
			name = sc.next();
			st[i] = new Student(age,name);
		}
		for(Student x : st){
			System.out.print(x);
		}
		
		System.out.println("while문 사용");
		while(sc.hasNext()){	// 파일의 라인수를 모르기 때문에

			System.out.println(sc.nextLine());
		}
		
		
	}
}

class Student{
	private int age;
	private String name;
	
	public Student(){
		this(1000,"둘리");
	}
	public Student(int age, String name){
		this.age = age;
		this.name = name;
	}
	public String toString(){
		return String.format("나이: %4d, 이름: %s\n",age,name);
	}
}