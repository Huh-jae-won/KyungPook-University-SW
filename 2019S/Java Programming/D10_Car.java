// 자동차 객체를 생성하고 최종위치 까지 이동시키는 프로그램 구현
class Car{
	private int mileage;			// 이동거리
	private int[] last = {0,40};		// 최종도착 위치
	private int[] start = {50,0};		// 시작 위치
	private int[] now = {50,0};		// 현재 위치
	private int direction = 0; // 0:북, 1:동, 2:남, 3:서
	
	int[] getNow(){
		return now;
	}
	int[] getLast(){
		return last;
	}
	void position(){			// 자동차의 현재위치를 출력하는 메소드
		System.out.printf("현재위치는 %d, %d입니다\n",now[0],now[1]);
	}
	void goStraight(int dist/*매개변수*/){ 	// 자동차를 직진시키는 메소드
	// goStraight(int dist) 메소드이름(매개변수,...) : 메소드 시그니처!!
		System.out.printf("%dm만큼 직진했습니다.\n",dist);
		this.mileage += dist;
		switch(direction){
			case 0: now[1] += dist;		// 북쪽으로 dist만큼 이동
				break;
			case 1: now[0] += dist;		// 동쪽으로 dist만큼 이동
				break;
			case 2: now[1] -= dist;		// 남쪽으로 dist만큼 이동
				break;
			case 3: now[0] -= dist;		// 서쪽으로 dist만큼 이동
				break;
		}
	}
	
	void turnLeft(){			// 자동차를 좌회전시키는 메소드
		System.out.println("좌회전했습니다.");
		switch(direction){
			case 0: direction = 3;		// 북쪽->서쪽으로 방향 회전
				break;
			case 1: direction -= 1;		// 동쪽->북쪽으로 방향 회전
				break;
			case 2: direction -= 1;		// 남쪽->동쪽으로 방향 회전
				break;
			case 3: direction -= 1;		// 서쪽->남쪽으로 방향 회전
				break;
		}
	}
	
	void turnRight(){			// 자동차를 우회전시키는 메소드
		System.out.println("우회전했습니다.");
		switch(direction){
			case 0: direction += 1;		// 북쪽->동쪽으로 방향 회전
				break;
			case 1: direction += 1;		// 동쪽->남쪽으로 방향 회전
				break;
			case 2: direction += 1;		// 남쪽->서쪽으로 방향 회전
				break;
			case 3: direction = 0;		// 서쪽->북쪽으로 방향 회전
				break;
		}
	}
	
	void getMileage(){
		System.out.printf("총 주행거리는 %dm입니다.",mileage);
	}
}

public class D10_Car{
	public static void main(String[] args){
		// 차 한대를 객체화 시키고 최종위치까지 이동시킴
		Car c = new Car();
		c.position();
		c.goStraight(25/*인자*/);
		c.position();
		c.turnLeft();
		c.goStraight(30);
		c.position();
		c.turnRight();
		c.goStraight(15);
		c.position();
		c.turnLeft();
		c.goStraight(20);
		c.position();
		int[] now = c.getNow();
		int[] last = c.getLast();
		if(now[0]==last[0] && now[1]==last[1]){
			c.getMileage();
		}
		
	}
}
