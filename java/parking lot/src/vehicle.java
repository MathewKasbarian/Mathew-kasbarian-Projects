
public class vehicle {
	//super class
	protected int numWheels;
	protected int size;
	protected int maxSpeed;
	protected String type;
	
	vehicle(int numWheels,int size,int maxSpeed,String type){
		this.numWheels=numWheels;
		this.size=size;
		this.type=type;
		this.maxSpeed=maxSpeed;
	}
public String toString() {
	return "vehicle: "+ this.type+"\nNumber of wheels: "+this.numWheels+ "\nMax Speed: "+this.maxSpeed+"km/h.\n";
}
public String move(){
	return "I am a vehicle and i move!";
}
}
