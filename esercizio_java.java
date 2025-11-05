import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {

	Scanner scanf = new Scanner(System.in);
	
	System.out.println("inserisci il nome della prima squadra: ");
	String TeamOne = scanf.nextLine();
	
	System.out.println("inserisci il nome della seconda squadra: ");
	String TeamTwo = scanf.nextLine();
	
	System.out.println("inserisci quanti goal ha fatto la squadra " + TeamOne);
	int GoalTeamOne = scanf.nextInt();
	
	System.out.println("inserisci quanti goal ha fatto la squadra " + TeamTwo);
	int GoalTeamTwo = scanf.nextInt();
	
	if(GoalTeamOne > GoalTeamTwo){
		System.out.println("La squadra vincitrice è " + TeamOne);
	
	} else if(GoalTeamOne < GoalTeamTwo){
	   System.out.println("La squadra vincitrice è " + TeamTwo);
	}
	 else {
    System.out.println("Le squadre hanno pareggiato");
}		
		int SommaGoal = GoalTeamOne + GoalTeamTwo;
		System.out.println("la somma dei goal è " + SommaGoal);
	}
}
