class Car{
	private int mileage;
	private int[] last = {0,40};
	private int[] start = {50,0};
	private int[] now = {50,0};
	private int direction = 0; // 0:��, 1:��, 2:��, 3:��
	
	int[] getNow(){
		return now;
	}
	int[] getLast(){
		return last;
	}
	void position(){
		System.out.printf("������ġ�� %d, %d�Դϴ�\n",now[0],now[1]);
	}
	void goStraight(int dist/*�Ű�����*/){ 
	// goStraight(int dist) �޼ҵ��̸�(�Ű�����,...) : �޼ҵ� �ñ״�ó!!
		System.out.printf("%dm��ŭ �����߽��ϴ�.\n",dist);
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
		System.out.println("��ȸ���߽��ϴ�.");
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
		System.out.println("��ȸ���߽��ϴ�.");
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
		System.out.printf("�� ����Ÿ��� %dm�Դϴ�.",mileage);
	}
}

public class D10_Car{
	public static void main(String[] args){
		Car c = new Car();
		c.position();
		c.goStraight(25/*����*/);
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