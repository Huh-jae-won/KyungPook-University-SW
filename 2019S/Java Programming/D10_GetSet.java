import java.util.*;
class Car{
	// 필드는 private으로 -> 외부에서 변경 불가능 하도록
	// private : 해당 클래스 안에서만 사용가능
	private String type;
	private String color;
	private int speed;
	
	void setColor(String color){
		this.color = color;	//this. : 해당 필드
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
		// c.color = "노랑"; private이기 때문에 외부에서 사용 불가능
		// 따라서 외부에서 사용할수 있도록 설정자 접근자를 이용
		car1.setColor("노랑");
		car1.setType("SUV");
		car1.setSpeed(100);
		System.out.println("car1의 색 : "+car1.getColor());
		System.out.println("car1의 종 : "+car1.getType());
		System.out.println("car1의속도 : "+car1.getSpeed());
		System.out.print("속도증감을 입력하시오");
		n = sc.nextInt();
		car1.speedUp(n);
		System.out.println("car1의속도 : "+car1.getSpeed());
		
	}
}