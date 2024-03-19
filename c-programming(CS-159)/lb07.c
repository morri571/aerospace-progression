/*****+---***---***---***--**-***-*-**-*****--******************************
 *
 *  Lab #: 7
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description: The purpose of this program is to generate a set of
 *  card values to determine if the user has won the game of Black Jack or not.
 *  In order to win, the user must reach a total of 21 and cannot exceed this value.
 *  In order to vary the outcomes of each game, the user of the program must
 *  input a seed value, which enables the program to randomly generate card values,
 *  which can be seen in the output.
 *
 ******+---***---***---***--**-***-*-**-*****--*****************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define UPPER 52
#define LOWER 1
#define CLUBS 1
#define DIAMONDS 2
#define HEARTS 3
#define SPADES 4
#define FACE 10
#define ACE 11
# define ACEONE 1

// Function Declarations

void get_input(int*,int*,int*,int*);
int generator();
int suit_checker(int);
int card_converter(int);
void score_calculator(int*,int*,int*,int);
void output(int,int,int,int,int);

int main (void)
{
  // Declarations

  int seed_value; //seed value that user inputs
  int score; //calculates score
  int counter; //counter for how many times score_calculator is called
  int aceCounter; //counter for how many aces are drawn
  int drawOne; //value of the first card drawn
  int drawOne_converted; //converts the value of the first card drawn to its actual card value
  int drawOne_suit; //determines the suit of the first draw
  int drawTwo; //value of the second card drawn
  int drawTwo_converted; //converts the value of the second card drawn to its actual card value
  int drawTwo_suit; //determines the suit of the second draw
  int drawThree; //value of the third card drawn
  int drawThree_converted; //converts the value of the third card drawn to its actual card value
  int drawThree_suit; //determines the suit of the third draw
  int drawFour; //value of the fourth card drawn
  int drawFour_converted; //converts the value of the fourth card drawn to its actual card value
  int drawFour_suit; //determines the suit of the fourth draw
  int drawFive; //value of the fifth card drawn
  int drawFive_converted; //converts the value of the fifth card drawn to its actual card value
  int drawFive_suit; //determines the suit of the fifth draw

  // Function Calls

  get_input(&seed_value,&score,&counter,&aceCounter); //accepts seed value inputted by user

  srand(seed_value); //seeds user inputted value

  //calculations for first draw
  drawOne = generator();
  drawOne_suit = suit_checker(drawOne);
  drawOne_converted = card_converter(drawOne);
  score_calculator(&score,&counter,&aceCounter,drawOne_converted);
  output(counter,drawOne,drawOne_converted,drawOne_suit,score);

  //calculations for second draw
  drawTwo = generator();
  drawTwo_suit = suit_checker(drawTwo);
  drawTwo_converted = card_converter(drawTwo);
  score_calculator(&score,&counter,&aceCounter,drawTwo_converted);
  output(counter,drawTwo,drawTwo_converted,drawTwo_suit,score);

  //calculations for third draw
  if(score < 16)
  {
    drawThree = generator();
    drawThree_suit = suit_checker(drawThree);
    drawThree_converted = card_converter(drawThree);
    score_calculator(&score,&counter,&aceCounter,drawThree_converted);
    output(counter,drawThree,drawThree_converted,drawThree_suit,score);
  }

  //calculations for fourth draw
  if(score < 16)
  {
    drawFour = generator();
    drawFour_suit = suit_checker(drawFour);
    drawFour_converted = card_converter(drawFour);
    score_calculator(&score,&counter,&aceCounter,drawFour_converted);
    output(counter,drawFour,drawFour_converted,drawFour_suit,score);
  }

  //calculations for fifth draw
  if(score < 16)
  {
    drawFive = generator();
    drawFive_suit = suit_checker(drawFive);
    drawFive_converted = card_converter(drawFive);
    score_calculator(&score,&counter,&aceCounter,drawFive_converted);
    output(counter,drawFive,drawFive_converted,drawFive_suit,score);
  }

  return 0;
}

/*****+---***-*--**---**--***--*-----*******--******************************
 *
 *  Function Information
 *
 *  Name of Function: get_input
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int* seed_value - the seed value as was inputted by the user
 *    2. int* score - the overall score in the game
 *    3. int* counter - counts how many times the function score_counter
 *       is called
 *    4. int* aceCounter - counts how many aces have been drawn
 *
 *  Function Description: Gathers the seed value inputted by the user so the
 *  program can generate the card values randomly. The function also sets the
 *  initial counts for score, counter, and aceCounter to 0.
 *
 ******+---***-*--**---**--***--*-----*******--*****************************/

void get_input(int* seed_value,int* score,int* counter,int* aceCounter)
{
  *score = 0;
  *counter = 0;
  *aceCounter = 0;

  printf("Enter the seed value -> ");
  scanf("%d",seed_value);
  printf("\n");

}

/*****+---***-*--**---**--***--*-----*******--******************************
 *
 *  Function Information
 *
 *  Name of Function: generator
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *  
 *  There are no parameters for this function
 *
 *  Function Description: The purpose of this function is to randomly generate
 *  a sequence of cards within a normal deck of 52 cards based upon what the
 *  user inputs as the seed value.
 *
 ******+---***-*--**---**--***--*-----*******--*****************************/

int generator()
{
  int draw; //the draw determined by the random number generator

  draw = rand() % (UPPER - LOWER + 1) + LOWER;

  return draw;
}

/*****+---***-*--**---**--***--*-----*******--******************************
 *
 *  Function Information
 *
 *  Name of Function: suit_checker
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int draw - the value of the draw received by the function (a number
 *    from 1-52)
 *
 *  Function Description: The purpose of this function is to determine the
    suit of the draw received as a parameter
 *
 ******+---***-*--**---**--***--*-----*******--*****************************/

int suit_checker(int draw)
{
  int suit; //the suit of the card

  if (draw >= 1 && draw <= 13)
  {
    suit = CLUBS;
  }
  else if (draw >= 14 && draw <= 26)
  {
    suit = DIAMONDS;
  }
  else if (draw >= 27 && draw <= 39)
  {
    suit = HEARTS;
  }
  else
  {
    suit = SPADES;
  }

  return suit;

}

/*****+-*-***-*--**---**--***--*-----*******--******************************
 *
 *  Function Information
 *
 *  Name of Function: card_converter
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int draw - the card value received based on what was randomly generated
 *    by the random number generator
 *
 *  Function Description: The purpose of this function is to convert the card
 *  value received, that value being a number from 1-52, to a number that can
 *  be more easily used by the program to determine the value of the card
 *  in Black Jack (1-13). This essentially means removing suit from the equation
 *  because suit doesn't affect the value of the cards in this game.
 *
 ******+-*-***-*--**---**--***--*-----*******--*****************************/

int card_converter(int draw)
{
  int card_number; //the converted card number

  if (draw >= 1 && draw <= 13)
  {
    card_number = draw; 
  } 
  else if (draw >= 14 && draw <= 26)
  {
    card_number = draw - 13;
  }
  else if (draw >= 27 && draw <= 39)
  {
    card_number = draw - 26;
  }
  else
  {
    card_number = draw - 39;
  }
  return card_number;
}

/*****+-*-***-*--**---**--***--*-----*******--******************************
 *
 *  Function Information
 *
 *  Name of Function: score_calculator
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int* score - the total score obtained by the user
 *    2. int* counter - how many times the function score_calculator has been
         run by the program
 *    3. int* aceCounter - how many aces have been drawn
 *    4. int draw - the number of the card drawn after it has been converted to
         a value from 1-13
 *
 *  Function Description: The purpose of this function is to calculate the score
 *  obtained by the user based upon the values for cards that have been determined
 *  by the random number generator. This takes into account how many aces have
 *  been drawn and upon drawing a second ace, the program automatically assigns
 *  a value of 1 instead of 11 to the second ace and all aces that precede it.
 *
 ******+-*-***-*--**---**--***--*-----*******--*****************************/

void score_calculator(int* score,int* counter,int* aceCounter,int draw)
{

  int tempAce; /*placeholder specifically for if there are multiple aces
                 and dealer may bust unless they are converted*/

  if (*score >= 11 && draw == 1)
  {
    draw = 0;
  }

  switch (draw)
  {
    case  13:
    case  12: 
    case  11: *score = *score + FACE;
              tempAce = FACE;
              break;
    case  1:  *score = *score + ACE;
              *aceCounter = *aceCounter + ACEONE;
              tempAce = ACE;
              break;
    case  0:  *score = *score + ACEONE;
              *aceCounter = *aceCounter + ACEONE;
              tempAce = ACEONE;
              break;
    default:  *score = *score + (draw); 
              tempAce = draw;

  }

  if (*aceCounter > 1 && *score > 21)
  {
    *score = tempAce + *aceCounter;
  }

  *counter = *counter + 1;

}

/*****+-*-***-*--**---**--***--*-----*******--******************************
 *
 *  Function Information
 *
 *  Name of Function: output
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int counter - the number of draws that have taken place
 *    2. int deck_number - the original non-converted number of the card that
 *       that was generated by the program
      3. int card_number - the converted card number
 *    4. int suit - the suit of the card as was previously determined
 *    5. int score - the total score of the game at that point in time
 *
 *  Function Description: The purpose of this function is to relay the values
 *  and results of the game to the user of the program. This requires the card
 *  values from each draw in addition to the total score as of each draw to be
 *  displayed for each draw that the program does.
 *
 ******+-*-***-*--**---**--***--*-----*******--*****************************/

void output(int counter,int deck_number,int card_number,int suit,int score)
{ 
  if (counter == 1)
  {
    printf("The first card is #: %d ",deck_number);
  }
  else if (counter == 2)
  {
    printf("The second card is #: %d ",deck_number);
  }
  else if (counter == 3)
  {
    printf("The third card is #: %d ",deck_number);
  }
  else if (counter == 4)
  {
    printf("The fourth card is #: %d ",deck_number);
  }
  else
  {
    printf("The fifth card is #: %d ",deck_number);
  }

  if (score >= 11 && card_number == 1)
  { 
    card_number = 0;
  }

  switch (card_number)
  {
    case  13: printf("(King of ");
              break;
    case  12: printf("(Queen of ");
              break;
    case  11: printf("(Jack of ");
              break;
    case  1:          
    case  0:  printf("(Ace of ");
              break;    
    default: printf("(%d of ",card_number);
  }

  switch (suit)
  {
    case 1: printf("Clubs) ");
            break;
    case 2: printf("Diamonds) ");
            break;
    case 3: printf("Hearts) ");
            break;
    case 4: printf("Spades) ");

  }

  printf("Current score: %d\n",score);

  if ((counter >= 5 && score < 21) || (score >= 16 && score < 21))
  {
    printf("\n");
    printf("Dealer holds.\n");
  }
  else if (score > 21)
  {
    printf("\n");
    printf("Dealer busts.\n");
  }
  else if (score == 21)
  {
    printf("\n");
    printf("Dealer wins!\n");
  }

}
