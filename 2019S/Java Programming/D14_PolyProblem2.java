// 상속의 장점을 
/* 상속의 장점
	자식들의 클래스를 같은 자료형으로 만들어 배열로 만들수 있다!!

	지휘가가 연자주들에게 지휘함
	클래스 : 지휘자
		conduct(연주자들) : 매개변수를 지휘함
	클래스 : 피아니스트
		play() : 피아노를 연주
	클래스 : 첼리스트
		play() : 첼로를 연주
	클래스 : 바이올린
		play() : 바이올린을 연주
*/
class D14_PolyProblem2{
	public static void main(String[] args){
		Conductor c = new Conductor();
		Player p1 = new Pianist();
		Player p2 = new Pianist();
		Player c1 = new Cellist();
		Player v1 = new Violinist();
		Player v2 = new Violinist();
		Player v3 = new Violinist();
		// 지휘자 1명과 여러명의 연주자를 생성
		
		// Player이기 때문에 한 배열에 모든 연주자를 담을 수 있다.
		Player[] p = {p1,p2,c1,v1,v2,v3};
		
		c.conduct(p);
	}
}

class Conductor{
	void conduct(Player[] p){
		for(Player x : p){
			System.out.printf( "%s가 %s들을 지휘합니다.\n",this.getClass().getName(),x.getClass().getName() );
			x.play(x.getClass().getName());
		}
	}
	
}

class Player{
	void play(String s){
		System.out.printf("%s을(를) 연주합니다\n",s);
	}
}
class Pianist extends Player{		// Player를 상속함
	String instrument = "피아노";
}
class Cellist extends Player{		// Player를 상속함
	String instrument = "첼로";
}
class Violinist extends Player{		// Player를 상속함
	String instrument = "바이올린";
}
