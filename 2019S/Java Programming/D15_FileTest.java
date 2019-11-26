
// ���� ����½� import �ʿ�
import java.io.*;
import java.util.*;
class D15_FileTest{
	public static void main(String[] args){
		// ���ϰ�ü ����(�������� ����x)
		// ���ϸ� �ۼ� : ����η� ����(������ġ ����) << ���� ����� �����
		File f1 = new File("D15_File.txt");		
		// ����� : ������ġ�� �����Ǿ�����
		File f3 = new File("D15_\\D15_File.txt");
		
		// �����η� ����(\:����� -> \\�� �������)
		File f2 = new File("D:\\D15_File.txt");
		
		// �ڹٴ� �÷����� ������ but ���������� ���� ������ /�� ����� ���� \\�� �ν��� ����
		File f4 = new File("D15_" + File.separator + "D15_File.txt");
		File f5 = new File("D15_");
		
		File[] file = {f1,f2,f3,f4,f5};
		// ���� �޼ҵ�
		for(int i=0 ; i< file.length ; i++){
			System.out.println(i+" : �� ������ �����ϴ°�? " + file[i].exists());
		}
		System.out.println();
		for(int i=0 ; i< file.length ; i++){
			System.out.println(i+" : ������ ũ�� : " + file[i].length()+"����Ʈ");
		}
		System.out.println();
		for(int i=0 ; i< file.length ; i++){
			System.out.println(i+" : ���� �̸� : "+file[i].getName());
		}
		System.out.println();
		for(int i=0 ; i< file.length ; i++){
			System.out.println(i+" : �����ΰ�  ? "+file[i].isDirectory());
			System.out.println("������ �ΰ� ? "+file[i].isAbsolute());
			System.out.println("������      : "+file[i].getAbsolutePath());
			System.out.println();
		}
		System.out.println();
		for(int i=0 ; i< file.length ; i++){
			System.out.println( i+" : ���������� : " + new Date(file[i].lastModified()) );
		}
		
		
	}
}