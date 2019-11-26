
// 파일 입출력시 import 필요
import java.io.*;
import java.util.*;
class D15_FileTest{
	public static void main(String[] args){
		// 파일객체 생성(실제파일 생성x)
		// 파일명만 작성 : 상대경로로 접근(현재위치 기준) << 보통 상대경로 사용함
		File f1 = new File("D15_File.txt");		
		// 상대경로 : 현재위치는 생략되어있음
		File f3 = new File("D15_\\D15_File.txt");
		
		// 절대경로로 접근(\:제어문자 -> \\로 해줘야함)
		File f2 = new File("D:\\D15_File.txt");
		
		// 자바는 플랫폼에 독립적 but 리눅스에선 폴더 구분을 /로 사용함 따라서 \\는 인식을 못함
		File f4 = new File("D15_" + File.separator + "D15_File.txt");
		File f5 = new File("D15_");
		
		File[] file = {f1,f2,f3,f4,f5};
		// 파일 메소드
		for(int i=0 ; i< file.length ; i++){
			System.out.println(i+" : 이 파일이 실재하는가? " + file[i].exists());
		}
		System.out.println();
		for(int i=0 ; i< file.length ; i++){
			System.out.println(i+" : 파일의 크기 : " + file[i].length()+"바이트");
		}
		System.out.println();
		for(int i=0 ; i< file.length ; i++){
			System.out.println(i+" : 파일 이름 : "+file[i].getName());
		}
		System.out.println();
		for(int i=0 ; i< file.length ; i++){
			System.out.println(i+" : 폴더인가  ? "+file[i].isDirectory());
			System.out.println("절대경로 인가 ? "+file[i].isAbsolute());
			System.out.println("절대경로      : "+file[i].getAbsolutePath());
			System.out.println();
		}
		System.out.println();
		for(int i=0 ; i< file.length ; i++){
			System.out.println( i+" : 최종수정일 : " + new Date(file[i].lastModified()) );
		}
		
		
	}
}