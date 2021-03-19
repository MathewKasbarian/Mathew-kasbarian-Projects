import java.util.ArrayList;
public class parkingLot {
	static ArrayList<vehicle>parkingLot=new ArrayList<vehicle>();
	public static void main(String[] args) {
		Bicycle b= new Bicycle(2,1,30,"Bike");
		Car c = new Car(4,2,200,"car");
		plane p= new plane(0,16,10,900,"Plane");
		//add to parking lot
		parkingLot.add(b);
		parkingLot.add(c);
		parkingLot.add(p);
	}
	public static void displayLot() {
		for (vehicle temp: parkingLot) {
			System.out.println(temp);
		}
	}
}
