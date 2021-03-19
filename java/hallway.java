import java.util.Random;
import java.util.Scanner;
public class hallway 
{
	static Scanner input=new Scanner(System.in);
	static Random rng = new Random();
	public static void main(String[] args) 
	{
		int randNum=rng.nextInt(2)+1;

		hallway(randNum);

if(hallway(randNum)) {
	System.out.println("Get back to class!");	
}

else if(hallway(randNum)){
	System.out.println("caught niko vaping in the hallways");

}
	}
	private static boolean hallway(int randNum) {
		if( randNum==1) {
			return true;
		}else {
			return false;
		}
	}
}
