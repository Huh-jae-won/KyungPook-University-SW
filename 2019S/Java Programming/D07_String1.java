// ���ڿ��� �ε����� �Է¹޾� �ε����� �ش��ϴ� ���� ���
// ���ڿ��� ���ڸ� �Է¹޾� ���ڰ� ��� �˻��Ǿ����� ���
// ���ڿ��� �ε��� ������ŭ �߶󳻱�
import java.util.*;
class D07_String1 {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("<<�ش� ��ġ(�ε���+1)�� ���� ���>>");
		String str;
		int x;
		System.out.print("���ڿ� : ");
		str = sc.nextLine();
		
		while(true){
			System.out.print("���� x : ");
			x = sc.nextInt();
			if((x<=str.length())&&(x>0)){
				break;
			}else{
				System.out.println("[�Է¿���] ���ڿ����� ���� ���� �Է��ϼ���.");
			}
		}
		System.out.printf("�Է��Ͻ� ���ڿ� \"%s\"���� %d��° ���ڴ� \'%s\'�Դϴ�.\n",str,x,str.charAt(x-1));
		System.out.println();
		// �ش� ���ڰ� ��������� ���
		System.out.println("<<�ش繮���� ���� ���>>");
		String c;
		int n;
		int cnt=0;
		System.out.println("���ڿ� : "+str);
		System.out.print("���� : ");
		c = sc.next();								// char c = sc.next().charAt(0);
		for(int i = 0 ; i < str.length() ; i++){
			if((str.charAt(i)+"").equals(c)){		// str.charAt(i) == c (�⺻�ڷ����̹Ƿ�)
				cnt++;
				System.out.printf("%-2d��° ",(i+1));
			}
		}
		System.out.println();
		System.out.printf("���ڿ� \"%s\"���� ���� \'%s\'�� %d�� �˻��Ǿ����ϴ�.\n",str,c,cnt);
		System.out.println();
		
		//���ڿ��� ������ŭ �߶� ���
		System.out.println("<<���ڿ��� ������ŭ �߶� ���>>");
		int first,second;
		while(true){
			System.out.print("first : ");
			first = sc.nextInt();
			if((first>=1) || (first<=str.length())){
				break;
			}else{
				System.out.println("[�Է¿���]first���� 1�̻� ���ڿ����� ������ ������ �����մϴ�.");
			}
		}
		while(true){
			System.out.print("second : ");
			second = sc.nextInt();
			if(second < first || second > str.length()){
				System.out.println("[�Է¿���]second���� first�̻� ���ڿ����� ������ ������ �����մϴ�.");
			}else{
				break;
			}
		}
		System.out.printf("�Է��� ���ڿ� \"%s\"���� %d���� %d���� ������ ���ڿ��� %s�Դϴ�\n",str,first,second,str.substring(first-1,second));
		System.out.println();
	}
}