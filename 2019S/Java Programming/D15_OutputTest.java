
// ����ڷκ��� ����, �̸� �Է¹ޱ�
import java.util.*;
import java.io.*;

class D15_OutputTest{
	public static void main(String[] args) throws FileNotFoundException{
		Scanner sc = new Scanner(System.in);
		File f1 = new File("D15_OutputTest.txt");
		System.out.println(f1.getName()+" : "+f1.exists());	// ó���� false
		
		// ��Ʈ�� ����
		PrintWriter pw = new PrintWriter(f1/*��� ����?*/);	// ������ ���ٸ� �������
		System.out.println(f1.getName()+" : "+f1.exists());	// ���� true
		
		
		System.out.print("����: ");
		int age = sc.nextInt();
		sc.nextLine();
		System.out.print("�̸�: ");
		String name = sc.nextLine();
		
		// ����Ϳ� ���
		System.out.printf("����: %d, �̸�: %s\n",age,name);
		
		// ���Ͽ� ���
		pw.printf("���� : %d, �̸� : %s",age,name);	// �����쿡���� ���� : \r\n

		// ���ۿ� �ִ� ������ �������ڴ�
		pw.close();	// pw�� �� ���� ���� �׸� ���ڴ�.
		System.out.println("������ Ȯ���غ����� : "+f1.getAbsolutePath());
		
	}
}