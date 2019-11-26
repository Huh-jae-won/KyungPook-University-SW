import java.util.*;
class Car{
	// �ʵ�� private���� -> �ܺο��� ���� �Ұ��� �ϵ���
	// private : �ش� Ŭ���� �ȿ����� ��밡��
	private String type;
	private String color;
	private int speed;
	
	void setColor(String color){
		this.color = color;	//this. : �ش� �ʵ�
	}
	String getColor(){
		return color;
	}
	
	void setSpeed(int speed){
		this.speed = speed;
	}
	int getSpeed(){
		return speed;
	}
	
	void setType(String type){
		this.type = type;
	}
	String getType(){
		return type;
	}
	
	void speedUp(int increment){
		speed += increment;
	}
	void speedDown(int decrement){
		speed -= decrement;
		if(speed <= 0) speed = 0;
	}
}
class D10_GetSet{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		Car car1 = new Car();
		Car car2 = new Car();
		int n;
		// c.color = "���"; private�̱� ������ �ܺο��� ��� �Ұ���
		// ���� �ܺο��� ����Ҽ� �ֵ��� ������ �����ڸ� �̿�
		car1.setColor("���");
		car1.setType("SUV");
		car1.setSpeed(100);
		System.out.println("car1�� �� : "+car1.getColor());
		System.out.println("car1�� �� : "+car1.getType());
		System.out.println("car1�Ǽӵ� : "+car1.getSpeed());
		System.out.print("�ӵ������� �Է��Ͻÿ�");
		n = sc.nextInt();
		car1.speedUp(n);
		System.out.println("car1�Ǽӵ� : "+car1.getSpeed());
		
	}
}