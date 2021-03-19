import java.util.Scanner;
public class ticTacToe {
	static Scanner input= new Scanner(System.in);
	public static void main(String[] args) 
	{
	
		char[]board= new char[] {'-','-','-','-','-','-','-','-','-','-'};
		System.out.println(board[1]+" | "+board[2]+" | "+board[3]);
		System.out.println(board[4]+" | "+board[5]+" | "+board[6]);
		System.out.println(board[7]+" | "+board[8]+" | "+board[9]);

		System.out.println("Welcome to tic tac toe");

		for(int i= 1;i <=9;i= i++){
		
		System.out.println("choose a board to play your piece on");
		int Board=input.nextInt();
		System.out.println("Please enter in an x or an o");
		board[Board] = input.next().charAt(0);
		
		
		/*if(board[Board] != 'x' || board[Board] != 'o'||board[Board] != 'X' || board[Board] != 'O')
				{
					System.out.println("please enter in an x or an o");
					board[Board] = input.next().charAt(0);
		}*/
		
		
		System.out.println(board[1]+" | "+board[2]+" | "+board[3]);
		System.out.println(board[4]+" | "+board[5]+" | "+board[6]);
		System.out.println(board[7]+" | "+board[8]+" | "+board[9]);
		if(board[1]=='x' && board[2]=='x'&& board[3]=='x'|| board[1]=='x'&&board[4]=='x'&&board[7]=='x'||board[4]=='x' && board[5]=='x'&& board[6]=='x'||board[7]=='x' && board[8]=='x'&& board[9]=='x'||board[2]=='x' && board[5]=='x'&& board[8]=='x'||board[3]=='x' && board[6]=='x'&& board[9]=='x'||board[7]=='x' && board[5]=='x'&& board[3]=='x'||board[1]=='x' && board[5]=='x'&& board[9]=='x') 
		{
			System.out.println("x wins");
			System.exit(0);
		}
		
		else if(board[1]=='o' && board[2]=='o'&& board[3]=='o'|| board[1]=='o'&&board[4]=='o'&&board[7]=='o'||board[4]=='o' && board[5]=='o'&& board[6]=='o'||board[7]=='o' && board[8]=='o'&& board[9]=='o'||board[2]=='o' && board[5]=='o'&& board[8]=='o'||board[3]=='o' && board[6]=='o'&& board[9]=='o'||board[7]=='o' && board[5]=='o'&& board[3]=='o'||board[1]=='o' && board[5]=='o'&& board[9]=='o') 
		{
			System.out.println("o wins");
			System.exit(0);
		}
		
		}
		System.out.println("cats game");
	
	}
}