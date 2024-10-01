/**
 * test.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277t
 *
 * <Khadeja>
 * <Rizvi>
 *
 * EECS 183: Project 2
 * Fall 2024
 *
 * Testing functions for your rps.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <iostream>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in rps.cpp
//************************************************************************
string getName(int playerNumber);
int getMenuChoice();
bool isMoveGood(char move);
char getMove(string playerName);
bool isRoundWinner(char move, char opponentMove);
void announceRoundWinner(string winnerName);
int doRound(string p1Name, string p2Name);
void announceWinner(string winnerName);
string doGame(string p1Name, string p2Name, int gameType);

//************************************************************************
// The following functions were already implemented for you in rps.cpp
//************************************************************************
void printInitialHeader();
void printMenu();
void printErrorMessage(int errorNumber);
void printCloser();

//************************************************************************
// Testing function declarations. Function definition is below main.
//************************************************************************
void test_isMoveGood();
void test_isRoundWinner();
void test_announceRoundWinner();
void test_announceWinner();

void test_getName();
void test_getMenuChoice();


void startTests() {
    cout << "\nExecuting your test cases\n";

    test_isMoveGood();
    test_getName();
    test_getMenuChoice();
    test_announceRoundWinner();
    test_isRoundWinner();
    test_isMoveGood();
    test_announceWinner();


    return;
}

//************************************************************************
// Put all your test function implementations below here.
// We have stubbed all required functions for you
// to recieve full points when submitting test.cpp
// NOTE: We will only grade your tests for the following functions
//       * isMoveGood
//       * isRoundWinner
//       * announceRoundWinner()
//       * announceWinner()
//************************************************************************

void test_getName() {
    cout << "Now testing function getName()\n";
    
    // a valid input would be Rana or David
    cout << "testing good input" << endl;
    cout << "'Rana': Expected: \"Rana\",";
    cout << " Actual: " << getName(1) << endl;

    cout << "'David': Expected: \"David\",";
    cout << " Actual: " << getName(2) << endl;

    // an invalid input would be just pressing enter
    cout << "testing invalid input" << endl;
    cout << "\"\": Expected: \"ERROR: Illegal name given, using default\",";
    cout << "Actual: " << getName(1) << endl;
}

void test_getMenuChoice() {
    cout << "Now testing function getMenuChoice()\n";

    // good inputs would be 1, 2, or 3
    cout << "testing good input" << endl;

    cout << "'1': Expected: 1, Actual: ";
    cout << getMenuChoice() << endl;

    cout << "'2': Expected: 2, Actual: ";
    cout << getMenuChoice() << endl;

    cout << "'3': Expected: 3, Actual: ";
    cout << getMenuChoice() << endl;


    // invalid input would be other numbers, like 5 or -1
    cout << "testing invalid input" << endl;

    cout << "'5': Expected: \"Invalid menu choice\", Actual: ";
    cout << getMenuChoice() << endl;
 
    cout << "'-1': Expected: \"Invalid menu choice\", Actual: ";
    cout << getMenuChoice() << endl;

    cout << "'0': Expected: \"Invalid menu choice\", Actual: ";
    cout << getMenuChoice() << endl;
}


void test_isMoveGood() {
    cout << "Now testing function isMoveGood()\n";

    //testing valid inputs (move must be either r, p, or s regardless of case)
    cout << "'r': Expected: 1, Actual: " << isMoveGood('r') << endl;
    cout << "'R': Expected: 1, Actual: " << isMoveGood('R') << endl;
    cout << "'p': Expected: 1, Actual: " << isMoveGood('p') << endl;
    cout << "'P': Expected: 1, Actual: " << isMoveGood('P') << endl;
    cout << "'s': Expected: 1, Actual: " << isMoveGood('s') << endl;
    cout << "'S': Expected: 1, Actual: " << isMoveGood('S') << endl;

    //testing invalid inputs (another letter besides the three)
    cout << "'q': Expected: 0, Actual: " << isMoveGood('q') << endl;
    cout << "'Q': Expected: 0, Actual: " << isMoveGood('Q') << endl;
    cout << "' ': Expected: 0, Actual: " << isMoveGood(' ') << endl;
    cout << "'!': Expected: 0, Actual: " << isMoveGood('!') << endl;
}

void test_isRoundWinner() {

    //testing for valid moves 'r' or 's' or 'p'
    cout << "Now testing function isRoundWinner()\n";

    cout << "'r' and 's' Expected: 1, Actual: ";
    cout << isRoundWinner('r', 's') << endl;

    cout << "'s' and 'r' Expected: 0, Actual: ";
    cout << isRoundWinner('s', 'r') << endl;

    cout << "'r' and 'p' Expected: 0, Actual: ";
    cout << isRoundWinner('r', 'p') << endl;

    cout << "'p' and 'r' Expected: 1, Actual: ";
    cout << isRoundWinner('p', 'r') << endl;

    cout << "'s' and 'p' Expected: 1, Actual: ";
    cout << isRoundWinner('s', 'p') << endl;

    cout << "'p' and 's' Expected: 0, Actual: ";
    cout << isRoundWinner('p', 's') << endl;

    //testing for valid moves for a tie
    cout << "'r' and 'R' Expected: 0, Actual: ";
    cout << isRoundWinner('r', 'R') << endl;

}

void test_announceRoundWinner() {
    //testing for valid winnerNames
    cout << "Now testing function announceRoundWinner()\n";
    cout << "\"\": Expected: \"This round is a draw!\", Actual: ";
    announceRoundWinner("");

    cout << "\"Rana\": Expected: \"Rana wins the round!\", Actual: ";
    announceRoundWinner("Rana");

    cout << "\"Rana1\": Expected: \"Rana1\", Actual: ";
    announceRoundWinner("Rana1");

    cout << "\"13\": Expected: \"13 wins the round!\", Actual: ";
    announceRoundWinner("13");

    cout << "\"13 13 R\": Expected: \"13 13 R wins the round!\", Actual: ";
    announceRoundWinner("13 13 R");

    
    return;
}

void test_announceWinner() {
    cout << "Now testing function announceWinner()\n";
    cout << "\"\": Expected: \"No winner!\", Actual: ";
    announceWinner("");

    cout << "\"Rana\": Expected: \"Congratulations Rana!\" \n";
    cout << " \"You won EECS 183 Rock-Paper-Scissors!\", Actual: ";
    announceWinner("Rana");

    cout << "\"Rana Rana\": Expected: \"Congratulations Rana Rana!\" \n"; 
    cout << " \"You won EECS 183 Rock-Paper-Scissors!\", Actual: ";
    announceWinner("Rana Rana");

    cout << "\"Rana5\": Expected: \"Congratulations Rana5!\" \n";
    cout << " \"You won EECS 183 Rock-Paper-Scissors!\", Actual: ";
    announceWinner("Rana5");

    cout << "\"10 10\": Expected: \"Congratulations 10 10!\" \n";
    cout << " \"You won EECS 183 Rock-Paper-Scissors!\", Actual: ";
    announceWinner("10 10");

    return;
}
