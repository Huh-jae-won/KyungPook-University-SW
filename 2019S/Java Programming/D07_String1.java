// 문자열과 인덱스를 입력받아 인덱스에 해당하는 문자 출력
// 문자열과 문자를 입력받아 문자가 몇번 검색되었는지 출력
// 문자열을 인덱스 구간만큼 잘라내기
import java.util.*;
class D07_String1 {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("<<해당 위치(인덱스+1)의 문자 출력>>");
		String str;
		int x;
		System.out.print("문자열 : ");
		str = sc.nextLine();
		
		while(true){
			// 제대로된 입력을 받을 때 까지 반복 수행
			System.out.print("숫자 x : ");
			x = sc.nextInt();
			// x값은 0보다 크고 문자열길이 보다 작은 수를 입력해야함
			if((x<=str.length())&&(x>0)){
				break;
			}else{
				System.out.println("[입력오류] 문자열보다 작은 값을 입력하세요.");
			}
		}
		System.out.printf("입력하신 문자열 \"%s\"에서 %d번째 문자는 \'%s\'입니다.\n",str,x,str.charAt(x-1));
		System.out.println();
		// 해당 문자가 몇번나오나 출력
		System.out.println("<<해당문자의 갯수 출력>>");
		String c;
		int n;
		int cnt=0;
		System.out.println("문자열 : "+str);
		System.out.print("문자 : ");
		c = sc.next();						// char c = sc.next().charAt(0)도 가능;
		for(int i = 0 ; i < str.length() ; i++){
			if((str.charAt(i)+"").equals(c)){		// str.charAt(i) == c (기본자료형이므로 '== '사용 가능)
				cnt++;
				System.out.printf("%-2d번째 ",(i+1));
			}
		}
		System.out.println();
		System.out.printf("문자열 \"%s\"에서 문자 \'%s\'는 %d번 검색되었습니다.\n",str,c,cnt);
		System.out.println();
		
		// 문자열을 입력받은 구간만큼 잘라서 출력
		System.out.println("<<문자열을 구간만큼 잘라서 출력>>");
		int first,second;		// first 부터 second까지 구간의 문자열 출력
		while(true){
			System.out.print("first : ");
			first = sc.nextInt();
			if((first>=1) || (first<=str.length())){
				break;
			}else{
				System.out.println("[입력오류]first값은 1이상 문자열길이 이하의 정수만 가능합니다.");
			}
		}
		while(true){
			System.out.print("second : ");
			second = sc.nextInt();
			if(second < first || second > str.length()){
				System.out.println("[입력오류]second값은 first이상 문자열길이 이하의 정수만 가능합니다.");
			}else{
				break;
			}
		}
		System.out.printf("입력한 문자열 \"%s\"에서 %d에서 %d까지 추출한 문자열은 %s입니다\n",str,first,second,str.substring(first-1,second));
		System.out.println();
	}
}
