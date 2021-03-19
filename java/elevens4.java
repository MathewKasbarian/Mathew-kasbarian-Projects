import java.util.Random;
import java.util.Scanner;
public class elevens4 {
	static Thread th = new Thread();
	static Random rng = new Random();	
	static int deckValue[]= {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13};
	static String deckSuit[]={" AS"," AD"," AC"," AH"," 2S"," 2D"," 2C"," 2H"," 3S"," 3D"," 3C"," 3H"," 4S"," 4D"," 4C"," 4H"," 5S"," 5D"," 5C"," 5H"," 6S"," 6D"," 6C"," 6H"," 7S"," 7D"," 7C"," 7H"," 8S"," 8D"," 8C"," 8H"," 9S"," 9D"," 9C"," 9H","10S","10D","10C","10H"," JS"," JD"," JC"," JH"," QS"," QD"," QC"," QH"," KS"," KD"," KC"," KH"," KS"};
	static String[] userBoard= new  String[9];
	static int[] logicBoard= new int[9];
	static int tracker=0;
	static String userName;
	static int[] choice= new int[3];
	static String card[]= {"First","Second","Third"};
	static int i=-1;
	static final int endOfDeck=52;
	static final int BoardLength=9;
	static boolean game=true;
	static Scanner input = new Scanner(System.in);
	static int answer;
	static int points;
	static int total;
	
	public static void main(String[] args) 
	{
		//this is my main method where i call all of my other methods
		intro();
		game();
	}
	//this method is used create the deck
private static void fillBoard() {
	//declaring a rand num
	int randNum;
	//this for loop helps create the deck
	for(int i=0;i<logicBoard.length;i++)
	{
		//declaring rand num
		randNum=rng.nextInt(endOfDeck);
		//making sure that the random number cannot equal to zero
while(deckValue[randNum]==0) {	
	randNum=rng.nextInt(endOfDeck);
}
	logicBoard[i] = deckValue[randNum];
	userBoard[i] = deckSuit[randNum];
	deckValue[randNum]=0;
	}
}
//this is the method i use to make the users board
private	static void displayGrid() {
	fillBoard();
	
	for(int i = 0; i < BoardLength; i++) {
		
if(deckValue[i]!=10) {
	//if the the number is going to be outputed on the right column then put a "|" after it
		if(i==0||i==3||i==6) {
		System.out.print(" | ");
		}
		//this outputs the other 2 columns
		System.out.print(userBoard[i]+" | ");
		if(i == 2|| i == 5||i==8) {
		System.out.println();
		
		}
	}
}
	
}
//my method that starts of the game
private static void intro() {
System.out.println("Hello and welcome to my elevens game");

	System.out.println("Please enter in your name");
userName=input.nextLine();


System.out.println("\nWelcome "+userName+" here we go");
sleep();
}
//this method runs my entire game
private static void game() 
{
	//i am calling my display grid 
	while(game) {
		displayGrid();
		//asking user how many cards they want to be taken away
		while(true) {
			try{
				//calling sleep class that allows for their to be a 2 second time delay
				sleep();
			System.out.println("Enter 2 to take away 2 cards\nEnter 3 to take away 3 cards\nAnswer: ");
			answer=Integer.parseInt(input.nextLine());
			if(2==answer||answer==3) {
				break;
			}
			}catch(Exception e) {
				System.out.println("please enter in if you would like to take away 2 or 3 cards");
			}
			}
		//if the user enter 2 then 
		if (answer==2) {
			//running my check method
			check();
			check();
			//making sure the total equals to 11
			if(logicBoard[choice[0]]+logicBoard[choice[1]]==11) {
				//outputting my point tracker
				System.out.println("good job your found a pair that equals to 11\nYou now have "+tracker+" pairs\\nyou have "+total+" left");
				//if my boolean method cardsInDeck returns as true then my getTwoCards
				if(cardsInDeck()) {
					// calls get two cards method
					getTwoCards();
				}
				//if there are no more cards this gets outputted
				else {
					System.out.println("no more cards left in the deck. please choose\nfrom the remaining cards on the board");
				}
			}
			//this gets outputted f the total is not 11
			else {
					System.out.println("the sum of the 2 numbers must be 11");
			}
		}
		//if the answer is 3 then it goes through this
		else if(answer==3) 
		{
			//going through check method
				check();
				check();
				check();
				//checking to see total is equal to 36
			if(logicBoard[choice[0]]+logicBoard[choice[1]]+logicBoard[choice[2]]==36) 
			{
				//here is my tracker
					
					System.out.println("Good job, your pair equals to 36\nYou now have "+tracker+" pairs\nyou have "+total+" left");
					
			if(cardsInDeck()) 
					{
				//makes sure that cards are in deck outputs no more cards in deck
						getThreeCards();
					}
			else 
			{
						System.out.println("no more cards left in the deck. Choose from the board. ");
					
			}
				
			}//making sure user enters in 3 face cards
			else 
			{
					System.out.println("sum needs to be 3 different face cards that equal to 36");
				
			}
		}
		
	}	
	//if it breaks out of the loop (runs out of cards) then u win
			System.out.println("u won the game congrats");
	} 
//this is my method to get three cards from my deck
private static void getTwoCards() {
	//declaring randNum and assigning it to a random interval inside of endOfDeck
	int randNum;
	randNum=rng.nextInt(endOfDeck);
	//making sure that my value is not zero
	while(deckValue[randNum]==0) {
		randNum=rng.nextInt(endOfDeck);
	}
	//
	logicBoard[choice[2]]=deckValue[randNum];
	userBoard[choice[2]]=deckSuit[randNum];
	deckValue[randNum]=0;
	randNum=rng.nextInt(endOfDeck);
	while(deckValue[randNum]==0) {
		randNum=rng.nextInt(endOfDeck);
	}
	logicBoard[choice[2]]=deckValue[randNum];
	userBoard[choice[2]]= deckSuit[randNum];
	deckValue[randNum]=0;
	}
private static boolean cardsInDeck() {
	int deckSum=0;
	for(int i=0; i<logicBoard.length;i++) {
		deckSum=deckSum+logicBoard[i];
	}
	if(deckSum>0) {
		return true;
	}
	else {
		return false;
	}
}

private static void getThreeCards() {
	int randNum;
	randNum=rng.nextInt(endOfDeck);
	while(deckValue[randNum]==0) 
	{
		randNum=rng.nextInt(endOfDeck)	;
	}
	logicBoard[choice[0]]=deckValue[randNum];
		userBoard[choice[0]]=deckSuit[	randNum];
		deckValue[randNum]=0;
	 	
		randNum=rng.nextInt(endOfDeck);
		while(deckValue[randNum]==0)
	{
		randNum=rng.nextInt(endOfDeck);
	}
	
logicBoard[choice[1]]=deckValue[randNum];
userBoard[choice[1]]=deckSuit[randNum];
deckValue[randNum]=0;

randNum=rng.nextInt(endOfDeck);
while(deckValue[randNum]==0) 
{
randNum=rng.nextInt(endOfDeck);
}

logicBoard[choice[2]]=deckValue[randNum];
userBoard[choice[2]]=deckSuit[randNum];
deckValue[randNum]=0;
}
//
private static void check() {
	i++;
	while(true) 
	{
		try{
		System.out.println("enter a number between 1-9 for your "+card[i]+" card");
		choice[i]=Integer.parseInt(input.nextLine());
		choice[i]--;
		if(1<=choice[i]&&choice[i]<=9) {
			break;
		}

		}catch(Exception e) {
			System.out.println("enter a number between 1-9");
		}
		}
	sleep();

	}
//this class is meant to delay the code by 2 seconds every time it is summoned
private static void sleep() {
	try{th.sleep(2000);
	}
	catch(Exception e){	
	}
	
}
}