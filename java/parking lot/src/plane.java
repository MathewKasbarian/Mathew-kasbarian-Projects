
public class plane extends vehicle{
plane(int altitude,int numWheels, int size, int maxSpeed, String type) {
		super(numWheels, size, maxSpeed, type);
		//another way to make altitude is this.altitude = 200;
		this.altitude=altitude;
	}
private int altitude;

public String fly() {
	return "the plan has taken off and is flying";
	
}
}
