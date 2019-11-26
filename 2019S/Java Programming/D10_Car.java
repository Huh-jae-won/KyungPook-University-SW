class Car{
	private int mileage;
	private int[] last = {0,40};
	private int[] start = {50,0};
	private int[] now = {50,0};
	private int direction = 0; // 0:북, 1:동, 2:남, 3:서
	
	int[] getNow(){
		return now;
	}
	int[] getLast(){
		return last;
	}
	void position(){
		System.out.printf("현재위치는 %d, %d입니다\n",now[0],now[1]);
	}
	void goStraight(int dist/*매개변수*/){ 
	// goStraight(int dist) 메소드이름(매개변수,...) : 메소드 시그니처!!
		System.out.printf("%dm만큼 직진했습니다.\n",dist);
		this.mileage += dist;
		switch(direction){
			case 0: now[1] += dist;
				break;
			case 1: now[0] += dist;
				break;
			case 2: now[1] -= dist;
				break;
			case 3: now[0] -= dist;
				break;
		}
	}
	
	void turnLeft(){
		System.out.println("좌회전했습니다.");
		switch(direction){
			case 0: direction = 3;
				break;
			case 1: direction -= 1;
				break;
			case 2: direction -= 1;
				break;
			case 3: direction -= 1;
				break;
		}
	}
	
	void turnRight(){
		System.out.println("우회전했습니다.");
		switch(direction){
			case 0: direction += 1;
				break;
			case 1: direction += 1;
				break;
			case 2: direction += 1;
				break;
			case 3: direction = 0;
				break;
		}
	}
	
	void getMileage(){
		System.out.printf("총 주행거리는 %dm입니다.",mileage);
	}
}

public class D10_Car{
	public static void main(String[] args){
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