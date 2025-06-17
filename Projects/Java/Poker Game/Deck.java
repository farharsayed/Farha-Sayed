package comp1721.cwk2;

// Implement Deck class here
import java.util.*;
import comp1721.cwk2.Card.Rank;
import comp1721.cwk2.Card.Suit;


/**
 * A class to create and manage a deck of 52 cards.
 *
 * @author Farha Rashid Sayed
 */

class Deck extends CardCollection
        {
        
        
        /**
         * Inherits cards from CardCollection, adding ones of each rank and suit to the deck.
         *
         */
public Deck() {
    //creates a deck containing the standard 52 playing cards arranged by suits and then in rank order
    super();
    for (Suit s : Suit.values()) {
        for (Rank r : Rank.values()) {
            cards.add(new Card (r, s));
        }
    }
}


        /**
         * Provides the number of cards in the deck.
         *
         * @return Number of cards
         */
public int size() {
        return cards.size();
}


/**
 * Indicates whether this collection is empty or not.
 *
 * @return true if collection is empty, false otherwise
 */
public boolean isEmpty() {
    if(cards.isEmpty())
        return true;
    else
        return false;
}


/**
 * Indicates whether a particular card is present in this collection.
 *
 * @param card Card we are looking for
 * @return true if the card is present, false otherwise
 */
public boolean contains(Card c) {
    if(cards.indexOf(c) == -1)
        return false;
    else
        return true;
}

/**
 * Discards all the cards from the deck.
 */
public void discard()
{
    cards.clear();
}

/**
 * Deals out a card from the deck.
 *
 * @return The dealt card
 */
public Card deal()
{
    if(size() <= 0)
    {
        throw new CardException("The deck is empty, cannot deal cards anymore.");
    }
    else {
        Card i = cards.get(0);
        cards.remove(0);
        return i;//String.valueOf(c);
    }
}

        /**
         * Shuffles all the cards in the deck into a random order.
         */
public void shuffle()
{
    Collections.shuffle(cards);
}
}