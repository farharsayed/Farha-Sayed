package comp1721.cwk1;

//import statement for the guess class
import java.util.Scanner;

public class Guess {

// Use this to get player input in readFromPlayer()
private static final Scanner INPUT = new Scanner(System.in);
private String chosenWord = "";
private int guessNumber;

// TODO: Implement constructor with int parameter

//validating and assigning gamenumber
public Guess(int num) {
    if ((num >= 1) && (num <= 6)) {
        guessNumber = num;
    }
    else {
        throw new GameException("Invalid GameNumber");}
    
}

// TODO: Implement constructor with int and String parameters

//validating and assigning chosenword once accepted from user
public Guess(int num, String word) {
    //first validating and assigning guessnumber
    if ((num >= 1) && (num <= 6)) {
        guessNumber = num;
    } else {
        throw new GameException("Invalid Game Number");
    }
    //then validating and assigning chosenword
    
    chosenWord = word.trim().toUpperCase();
    //counting alphabetic chars in word to validate
    int co = 0;
    for (int a = 0; a < word.length(); a++) {
        if (Character.isLetter(word.charAt(a))) {
            co++;
        }
        else {
            throw new GameException("Invalid Word");
        }
    }
    if (chosenWord.length() != 5) {
        throw new GameException("Invalid Word");
    }
}


// TODO: Implement getGuessNumber(), returning an int
public int getGuessNumber() {
    return guessNumber;
}

// TODO: Implement readFromPlayer()
public void readFromPlayer() {
    chosenWord = INPUT.next();
    //counting alphabetic characters in input to validate
    int co = 0;
    for (int a = 0; a < chosenWord.length(); a++) {
        if (Character.isLetter(chosenWord.charAt(a))) {
            co++;
        }
        else {
            throw new GameException("Invalid Word");
        }
    }
    if (co != 5) {
        throw new GameException("Invalid Word");
    }
}

// TODO: Implement getChosenWord(), returning a String
public String getChosenWord() {
    return chosenWord;
}


// TODO: Implement compareWith(), giving it a String parameter and String return type

//declared ansi escape codes for ease in program functioning
private String green = "\033[30;102m ";
private String reset = " \033[0m";
private String yellow = "\033[30;103m ";
private String white = "\033[30;107m ";


private char chararr[] = new char[5];
//chararr[] and charcount(String) were designed for to allow for
// repeated letters and correct yellow printing

public void charcount(String mainword) {
    for (int a = 0; a < mainword.length(); a++) {
        chararr[a] = mainword.charAt(a);
    }
}

private char cw[] = new char[5];
//cw[] stores the letters of the guess, simultaneously with status[], for ease in printing
private char status[] = new char[5];

public String compareWith(String wrd)
//wrd is the target word not the chosen/guessed word
{
    charcount(wrd);
    String outputword = "";
    
    //green background
    for (int a = 0; a < wrd.length(); a++) {
        if ((Character.toUpperCase(chosenWord.charAt(a)) == wrd.charAt(a)) && (chararr[a] != ' ')) {
            chararr[a] = ' ';
            status[a] = 'g';
            cw[a] = chosenWord.charAt(a);
        }
    }
    //green background end
    
    for (int a = 0; a < wrd.length(); a++) {
        if (Character.toUpperCase(chosenWord.charAt(a)) != wrd.charAt(a)) {
            for (int b = 0; b < wrd.length(); b++) {
                //yellow background
                if ((chararr[b] != ' ') && (chosenWord.charAt(a) == wrd.charAt(b))) {
                    chararr[b] = ' ';
                    cw[a] = chosenWord.charAt(a);
                    status[a] = 'y';
                    break;
                }
                //yellow background end
                //white background
                else if ((b == 4) && ((chararr[a] != 0))) {
                    chararr[b] = ' ';
                    cw[a] = chosenWord.charAt(a);
                    status[a] = 'w';
                    break;
                }
                //white background end
                
            }
        }
    }
    
    //final formation of return value of compareWith based on status of each letter in guess
    for(int e = 0; e<5; e++) {
        if(status[e] == 'g') {
            outputword = outputword + green + cw[e] + reset;
        }
        else if(status[e] == 'y') {
            outputword = outputword + yellow + cw[e] + reset;
        }
        else {
            outputword = outputword + white + cw[e] + reset;
        }
    }
    return outputword;
}





// TODO: Implement matches(), giving it a String parameter and boolean return type
public boolean matches(String wrd)
//wrd is the target word
{
    for(int a = 0; a<wrd.length(); a++)
    {
        //just checking if values of each letter match
        if((wrd.charAt(a)-chosenWord.charAt(a))!=0)
        {
            return false;
        }
    }
    return true;
}


//accommodating for accessible feature
private String subsord[] = new String[]{"st", "nd", "rd", "th", "th"};
private String justforvalues = "";
String accessible(String aword)
//aword is target word
//parameter of accessible(String) is outputword from the compareWith function
{
    justforvalues = compareWith(aword);
    String opsentence = "";
    //final sentence to be output
    //subscript ordinals for printing output
    int print = 0;
    for (int f = 0; f < 5; f++) {
    print = f+1;
      
        //printing each letter's status as necessary
        if (status[f] == 'g') {
            opsentence = opsentence + String.valueOf(print) + subsord[f] + " is perfectly placed";
        }
        else if (status[f] == 'y') {
            opsentence = opsentence + String.valueOf(print) + subsord[f];
            opsentence = opsentence + " is in the word but in wrong position";
        }
        else if (status[f] == 'w') {
            opsentence = opsentence + String.valueOf(print) + subsord[f];
            opsentence = opsentence + " is not in the target word";
        }
        else
        {
            continue;
        }
        
        //arranging punctuation
        if (f < 4) {
            opsentence = opsentence + ", \n";
        } else if (f == 4) {
            opsentence = opsentence + ".";
        }
    }
    return opsentence;
}
}






















