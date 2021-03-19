import java.util.Scanner;
public class calculatorNoLoop
{
	static int num1;
	static int num2;
	static String multiply;
	static String divide;
	static String add;
	static String subtract;
	static int total;
	static boolean game=true;
	static String choice;
	static Scanner input=new Scanner(System.in);
	public static void main(String[] args) 
	{
		intro();
		choice();
	}
	private static void choice() {
		System.out.println("Please enter in your first number");;
		num1=input.nextInt();
		System.out.println("Please enter in your second number");
		num2=input.nextInt();
		System.out.println("Please choose your mathematical operation\n1.multiply\n2.divide\n3.subtract\n4.add");
		choice=input.next();		
		if(choice.equals("multiply")) {
			multiply(num1,num2);
		}
		if(choice.equals("divide")) {
			divide(num1,num2);
		}
		if(choice.equals("add")) {
			add(num1,num2);
		}
		if(choice.equals("subtract")) {
			subtract(num1,num2);
		}
	}
	
	private static void intro() {
		System.out.println("Welcome to my calculator\nYou will enter in 2 numbers and then you can\n1.multiply\n2.divide\n3.subtract\n4.add");
		
	}
	private static void multiply(int one, int two) {
		
	total= one*two;
	System.out.println("your answer is "+total);
	}
	private static void divide(int one, int two) {
		total= one/two;
		System.out.println("your answer is "+total);
}
	private static void subtract(int one, int two) {
		total= one-two;
		System.out.println("your answer is "+total);
}
	private static void add(int one, int two) {
		total= one+two;
		System.out.println("your answer is "+total);
	}
}