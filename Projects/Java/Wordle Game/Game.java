package comp1721.cwk1;

//import statements for the game class
import java.time.LocalDate;
import java.io.PrintWriter;
import java.io.IOException;
import static java.time.temporal.ChronoUnit.DAYS;

public class Game
{

private static String target;
//target word, referenced as wrd later

private final int gamenmbr;
//gamenumber

private WordList wrdlst;
//obj for ref to wordlist.java

// TODO: Implement constructor with String parameter
Game(String filename)throws IOException
//parameter is the name of file
{
    wrdlst = new WordList(filename);
    gamenmbr = (int)DAYS.between(LocalDate.parse ("2021-06-19"), LocalDate.now());
    target = wrdlst.getWord(gamenmbr);
    //the gamenmbr is the number of days its been since first game on 19/6/2021
}

// TODO: Implement constructor with int and String parameters
Game(int num, String filename)throws IOException {
    wrdlst = new WordList(filename);
    target = wrdlst.getWord(num);
    gamenmbr = num;
}





//accessible feature
private boolean accessible = false;
//new game constructor designed to easily distinguish runFixed from runAccessible
Game (String filename, int num)throws IOException
{
    accessible = true;
    wrdlst = new WordList(filename);
    target = wrdlst.getWord(num);
    gamenmbr = num;
}

// TODO: Implement play() method

private int gn = 1;
//gn is the guess number

private Guess ges = new Guess(gn);
//validating and assigning

private String guess= "";
//this will hold the user's guess

private String savedguesses[] = new String[5];

void play()
{
    gn = 1;
    for(int a = 1; a<=6; a++,gn++)
    {
        System.out.print("Enter guess (" + a + "/6): ");
        ges.readFromPlayer();
        guess = ges.getChosenWord();
        
        savedguesses[a-1] = ges.compareWith(target);
        //saving guesses for storing in lastgame.txt through save()
        
        ges = new Guess(gn, guess);
        // validating and assigning
        
        if(accessible)
        {
            //for an accessible game, comparewith is called inside ges.accessible(target)
            System.out.println("\n" + ges.accessible(target) + "\n");
        }
        else {
            //for regular game
            System.out.println(ges.compareWith(target));
        }
        
        //following is for printing apt comments after guesses
        if((gn == 1) && (ges.matches(target))) {
            System.out.print("\nSuperb - Got it in one!");
            break;
        }
        else if ((gn >=2) && (gn<6) && (ges.matches(target))) {
            System.out.print("\nWell done!");
            break;
        }
        else if((gn == 6) && (ges.matches(target))) {
            System.out.print("\nThat was a close call!");
            break;
        }
        else {
            continue;
        }
    }
}
// TODO: Implement save() method, with a String parameter

void save (String filename)throws IOException
{
    PrintWriter pw = new PrintWriter(filename);
    for(int a = 0; a< ges.getGuessNumber(); a++) {
        pw.write(savedguesses[a]+ "\n");
    }
    pw.flush();
    pw.close();
}






}
