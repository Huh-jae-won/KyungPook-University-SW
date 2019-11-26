
/* ����� ����2
	�ڽĵ��� Ŭ������ ���� �ڷ������� ����� �迭�� ����� �ִ�.!!


	���ְ��� �����ֵ鿡�� ������
	Ŭ���� : ������
		conduct(�����ڵ�) : �Ű������� ������
		
	Ŭ���� : �ǾƴϽ�Ʈ
		play() : �ǾƳ븦 ����
	Ŭ���� : ÿ����Ʈ
		play() : ÿ�θ� ����
	Ŭ���� : ���̿ø�
		play() : ���̿ø��� ����
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
		
		Player[] p = {p1,p2,c1,v1,v2,v3};
		
		c.conduct(p);
	}
}

class Conductor{
	void conduct(Player[] p){
		for(Player x : p){
			System.out.printf( "%s�� %s���� �����մϴ�.\n",this.getClass().getName(),x.getClass().getName() );
			x.play(x.getClass().getName());
		}
	}
	
}

class Player{
	void play(String s){
		System.out.printf("%s��(��) �����մϴ�\n",s);
	}
}
class Pianist extends Player{
	String instrument = "�ǾƳ�";
}
class Cellist extends Player{
	String instrument = "ÿ��";
}
class Violinist extends Player{
	String instrument = "���̿ø�";
}