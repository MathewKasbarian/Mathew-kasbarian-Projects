import java.util.Scanner;
public class winningScore 
{
	
	static Scanner input= new Scanner(System.in);
	public static void main(String[] args) 
	{
		System.out.println("Please enter in the number of free throws team apple");
		int score1=input.nextInt();
		System.out.println("please enter in the number of two pointers team apple");
		int score2=input.nextInt();
		System.out.println("please enter in the number of three pointers team apple");
		int score3=input.nextInt();
		int total= score1+ score2*2+score3*3;
		
		
		System.out.println("Please enter in the number of free throws for ream banana");
		int Score1=input.nextInt();
		System.out.println("please enter in the number of two pointers for team banana");
		int Score2=input.nextInt();
		System.out.println("please enter in the number of three pointers for team banana");
		int Score3=input.nextInt();
		int Total=Score1+Score2*2+Score3*3;
		if(total<=Total) {
			System.out.println("B");
		}
		if(Total<=total) {
			System.out.println("A");
		}
		if(total==Total) {
			System.out.println("T");
		}
	}

}
