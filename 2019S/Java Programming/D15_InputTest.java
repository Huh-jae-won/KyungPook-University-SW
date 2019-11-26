
import java.util.*;
import java.io.*;

class D15_InputTest{
	public static void main(String[] args) throws FileNotFoundException{
		File f1 = new File("D15_OutputTest.txt");
		// f�� �����Ѵٸ� ����, �ƴϸ� ����
		if(!f1.exists()){
			System.out.println(f1.getName()+"������ �����ϴ�. ���α׷��� �����մϴ�.");
			System.exit(0);
		}
		Scanner sc = new Scanner(f1/*��� ����?*/);
		
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
		
		System.out.println("while�� ���");
		while(sc.hasNext()){	// ������ ���μ��� �𸣱� ������

			System.out.println(sc.nextLine());
		}
		
		
	}
}

class Student{
	private int age;
	private String name;
	
	public Student(){
		this(1000,"�Ѹ�");
	}
	public Student(int age, String name){
		this.age = age;
		this.name = name;
	}
	public String toString(){
		return String.format("����: %4d, �̸�: %s\n",age,name);
	}
}