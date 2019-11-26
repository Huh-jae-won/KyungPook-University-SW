
import java.util.*;

class D16_Exception{
	public static void main(String[] args){
		try{
			printAge();
		}catch(InputMismatchException e){	//�޼ҵ尡 ���ѱ� ���ܸ� ���⼭ ���� ó��
			e.printStackTrace();
		}catch(NegativeAgeException nae){
			nae.printStackTrace();
			System.out.println(nae.getMessage());
		}
		System.out.println("�����̵ɱ�?2");	// trycatch���ִٸ� ���ܰ� �߻��ص� ������ �ȴ�.
	}
	static void printAge() throws InputMismatchException, NegativeAgeException {	// �����ϴ���(���⼱ main)���� ���ܸ� ó���ϵ��� ���ѱ�
		int age;
		Scanner sc = new Scanner(System.in);
		
		try{
			System.out.print("����: ");
			age = sc.nextInt();
			if(age<0){	//���� �߻���Ű��� ����
				throw new NegativeAgeException();	// throws�ƴ�!
				// throw : JVM���� ���ܰ� �߻��Ǿ��ٰ� �˸��� Ű����
			}
		
			System.out.printf("����(%d)",age);
		}catch(InputMismatchException ime){		// ���ܵ� import �������
			System.out.println("���̸� ������ �Է��Ͻÿ�.");
			ime.printStackTrace();					// ���ܰ� �߻������� stack��Ȳ���
			System.out.println(ime.getMessage());	// 
		}
		System.out.println("�����̵ɱ�?1");		// trycatch���ִٸ� ���ܰ� �߻��ص� ������ �ȴ�.
		/*
		Error : �޸𸮺���, ����,... �ذ��� ����̾��� -> �����Ϸ��� �׳� ���������
		RuntimeExcpetion : ���α׷��� ����(0���γ�����,NullPointer����(���� ��ü��������),�ε��������ʰ�,...) ���� �ڵ带 �߸�§ ��� -> �����Ϸ��� ��������������(�����ΰ��ľ���)(���������� �߻��Ҽ�����)
		������ Exception : �����Ϸ��� ���� �˻縦 ����, ����ó���� �������
		*/
	}
}
// ����� ���� ���� : ex) �������� ���� -> �����ڸ� �ۼ�
class NegativeAgeException extends Exception{	// ���� Ŭ����
	NegativeAgeException(){
		super("���� ���� ����");	// ���� ���� �ۼ�
	}
}