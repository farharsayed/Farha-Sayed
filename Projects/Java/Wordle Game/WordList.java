package comp1721.cwk1;

//import statements for the wordlist class
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.util.List;
import java.util.ArrayList;

public class WordList {
private List<String> words = new ArrayList<>();
//list created as necessary
//TODO: Implement constructor with a String parameter
public WordList(String wl)throws IOException
{
    Path pth = Paths.get(wl);
    words = Files.readAllLines(pth);
}
// TODO: Implement size() method, returning an int

public int size()
{
    return this.words.size();
}
// TODO: Implement getWord() with an int parameter, returning a String

public String getWord (int gw)
//gw is the game number
{
    if((gw<0)||(gw>(words.size()-1))) {
        throw new GameException("Error");
    }
    return this.words.get(gw);
}
}