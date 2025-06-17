package comp1721.cwk2;

// Implement PokerHand class here

import java.util.*;
import comp1721.cwk2.Card.Rank;
import comp1721.cwk2.Card.Suit;

/**
 * A class to manage the hands dealt during each poker game.
 *
 * @author Farha Rashid Sayed
 */

class PokerHand extends CardCollection
{

public static final int FULL_SIZE = 5;


/**
 * Inherits cards from CardCollection.
 */
public PokerHand()
{
    super();
}


/**
 * Enters initial values into cards from CardCollection.
 *
 * @param String containing cards
 *
 */
public PokerHand(String ph)
{
    super();
    String[] ph_arr = ph.split(" ", 0);
    if (ph_arr.length > FULL_SIZE){
        throw new CardException("Hand cannot have so many cards");
    }
    else {
        
        for (int a=0; a<ph_arr.length; a++){
            Card card = new Card(ph_arr[a]);
            cards.add(card);
        }
        
    }
}


/**
 * Adds the given card into the hand.
 *
 *  @param Card to be added
 *
 */
public void add(Card c)
{
    if(cards.contains(c))
    {
        throw new CardException("Card is already in the hand.");
    }
    else if(super.size() >= FULL_SIZE)
    {
        throw new CardException("The hand is already full.");
    }
    else
    {
        cards.add(c);
    }
}


/**
 * Overriden toString to allow for appropriate card representation.
 *
 * @return List of cards in hand
 */
@Override public String toString()//overrides default version
{
    String str = " ";
    for (int a = 0; a < cards.size(); a++) {
        Card c = cards.get(a);
        if (a >= cards.size() - 1) {
            str += c.toString();
        } else {
            str += c.toString() + " ";
        }
    }
    return str.trim();
}


/**
 * Provides the number of cards in this collection.
 *
 * @return Number of cards
 */
public int size()
{
    return super.size();
}


/**
 * Discards all the cards from the hand.
 */
public void discard()
{
    if(super.isEmpty())
        throw new CardException("The hand is already empty");
    else
    super.discard();
}


/**
 * Discards all the cards from the hand and puts them back in the deck.
 *
 * @param Deck to replace cards into.
 */
public void discardTo(Deck d)
{
    if(cards.isEmpty()==true)
    {
        throw new CardException("The hand is already empty!");
    }
    while(cards.isEmpty()==false) {
        d.add(cards.get(0));
        cards.remove(0);
    }
}


//predicate methods:


/**
 * Checks if the hand has a pair.
 */
boolean isPair()
{
    if(super.size()<FULL_SIZE) {
        return false;
    }
    
    int counter = 0;
    ArrayList<Rank> checks = new ArrayList<Rank>();
    for(Card c: cards)
    {
        checks.add(c.getRank());
    }
    for(Rank ranks: checks)
    {
        if(Collections.frequency(checks,ranks)==2)
        {
            counter++;
        }
    }
    if((counter == 2)&&(isFullHouse() == false)&&(isThreeOfAKind()==false)&&(isTwoPairs()==false)&&(isFourOfAKind()==false))
    {
        return true;
    }
        return false;
}

/**
 * Checks if the hand has a two pair.
 */
boolean isTwoPairs()
{
    if(super.size()<FULL_SIZE) {
        return false;
    }
    int counter = 0;
    ArrayList<Rank> checks = new ArrayList<Rank>();
    for(Card c: cards)
    {
        checks.add(c.getRank());
    }
    for(Rank ranks: checks)
    {
        if(Collections.frequency(checks,ranks)==2)
        {
            counter++;
        }
    }
    if((counter == 4)&&(isFullHouse() == false)&&(isThreeOfAKind()==false)&&(isFourOfAKind() == false))
    {
        return true;
    }
        return false;
}


/**
 * Checks if the hand has three of a kind.
 */
boolean isThreeOfAKind()
{
    if(super.size()<FULL_SIZE) {
        return false;
    }
    
    int counter = 0;
    ArrayList<Rank> checks = new ArrayList<Rank>();
    for(Card c: cards)
    {
        checks.add(c.getRank());
    }
    for(Rank ranks: checks)
    {
        if(Collections.frequency(checks,ranks)==3)
        {
            counter++;
        }
    }
    if((counter == 3)&&(isFullHouse() == false)&&(isFourOfAKind() == false))
    {
        return true;
    }
        return false;
}


/**
 * Checks if the hand has four of a kind.
 */
boolean isFourOfAKind()
{
    if(super.size()<FULL_SIZE) {
        return false;
    }
    ArrayList<Rank> checks = new ArrayList<Rank>();
    for(Card c: cards)
    {
        checks.add(c.getRank());
    }
    for(Rank ranks: checks)
    {
        if(Collections.frequency(checks,ranks)==4)
        {
           return true;
        }
    }
    return false;
    
    
}

/**
 * Checks if the hand has a full house.
 */
boolean isFullHouse()
{
    if(super.size()<FULL_SIZE) {
        return false;
    }
    
    int counter = 0;
    ArrayList<Rank> checks = new ArrayList<Rank>();
    for(Card c: cards)
    {
        checks.add(c.getRank());
    }
    for(Rank ranks: checks)
    {
        if(Collections.frequency(checks,ranks)==2||Collections.frequency(checks,ranks)==3)
        {
            counter++;
        }
    }
    if((counter == 5)&&(isFourOfAKind() == false))
    {
        return true;
    }
    return false;
    
    
}


/**
 * Checks if the hand has a flush.
 */
boolean isFlush()
{
    if(super.size()<FULL_SIZE) {
        return false;
    }
    ArrayList<Suit> checks = new ArrayList<Suit>();
    for(Card c: cards)
    {
        checks.add(c.getSuit());
    }
    for(Suit suits: checks)
    {
        if(Collections.frequency(checks,suits)==5)
        {
            return true;
        }
    }
    return false;
    
}


/**
 * Checks if the hand has a straight.
 */
boolean isStraight()
{
    if (super.size()<FULL_SIZE){
        return false;
    }
    
    ArrayList<Integer> checks = new ArrayList<Integer>();
    for (Card c: cards){
        if(c.getRank() !=Rank.KING && c.getRank() != Rank.QUEEN && c.getRank() != Rank.JACK) {
            checks.add(c.value());
        }
        if (c.getRank() == Rank.JACK) {
            checks.add(11);
        }
        if (c.getRank() == Rank.QUEEN) {
            checks.add(12);
        }
        if (c.getRank() == Rank.KING) {
            checks.add(13);
        }
    }
    for (Integer I : checks) {
        if(Collections.frequency(checks, I) > 1){
            return false;
        }
    }
    Collections.sort(checks);
    if(checks.get(4) - checks.get(0) == 4) {
        return true;
    }
    else if(checks.get(0) == 1 && checks.get(1) == 10 && checks.get(2) == 11 && checks.get(3) == 12
                    && checks.get(4) == 13) {
        return true;
    }
    return false;
}
}