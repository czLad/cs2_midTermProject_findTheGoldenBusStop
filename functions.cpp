//
// Created by myatz on 2/25/2023.
//

#include "functions.h"
void playFindTheGoldenBusStop() //A game in which the player tries to complete their mission without getting trapped.
{
    do
    {
        gameObjectives();
        startMenu();
    }while(goAgain());
}
void gameObjectives() //Display the game's rules and objectives.
{
    menu("Greetings! Player One.\n", "Your mission is to find the golden bus stop on Del Mar Boulevard.\n", "");
    menu("If you walked into the tiger's den, you have 3 tries to escape and", " return to your mission.\n", "");
    menu("If you can't escape, You Lose.\n", "If you choose the wrong bus stop, You Lose.\n", "Now, let us begin.\n");
    menu("It's a pleasure to guide you on your journey.\n", "You are at the corner of Harkness Avenue & Colorado Boulevard\n", "");
    output("Where would you like to go?\n");
}
void startMenu() //Gives the player their first choice.
{
    menu("Turn (l)eft and walk straight\n", "(C)ross the road in front\n", "(E)xit\n");
    switch(choice())
    {
        case 'l':
            leftNStraight();
            break;
        case 'c':
            harkness2ColoradoCrossRoad();
            break;
        default:
            break;
    }
}
void leftNStraight() //Display the places the player can go after turning left and going straight.
{                                                   //Allows player to choose their next step.
    menu("Go To\n", "(N)orthern Cafe\n", "(B)ubble Puff\n");
    menu("(S)ubway\n","(C)ross the road\n", "(R)eturn to starting point\n");
    switch(choice())
    {
        case 'n':
            northernCafe();
            break;
        case 'b':
            bubblePuff();
            break;
        case 's':
            subway();
            break;
        case 'c':
            harkness2ColoradoCrossRoad();
            break;
        case 'r':
            startMenu();
            break;
    }
}
void harkness2ColoradoCrossRoad() //Takes player to the other side of the road and display options to go to.
{                                                                  //Allows player to choose their next step.
    menu("Go To\n", "(P)asadena City College\n", "Turn (l)eft and walk to Bonnie Avenue\n");
    menu("(R)eturn to the other side of the road\n", "", "");
    switch(choice())
    {
        case 'l':
            left2Bonnie();
            break;
        case 'p':
            pasadenaCityCollege();
            break;
        case 'r':
            leftNStraight();
            break;
    }
}
void northernCafe() //Display the places the player can go after going and exiting Northern Cafe.
{                                                   //Allows player to choose their next step.
    menu("Go To\n", "(B)ubble Puff\n", "(C)ross the road\n");
    menu("(R)eturn to starting point\n", "", "");
    switch(choice())
    {
        case 'b':
            bubblePuff();
            break;
        case 'c':
            harkness2ColoradoCrossRoad();
            break;
        case 'r':
            startMenu();
            break;
    }
}
void bubblePuff() //Display the places the player can go after going and exiting Bubble Puff.
{                                                    //Allows player to choose their next step.
    menu("Go To\n", "(S)ubway\n", "(C)ross the road\n");
    menu("(R)eturn to Northern Cafe\n", "", "");
    switch(choice())
    {
        case 's':
            subway();
            break;
        case 'c':
            harkness2ColoradoCrossRoad();
            break;
        case 'r':
            northernCafe();
            break;
    }
}
void subway() //Display the places the player can go after going and exiting Bubble Puff.
{                                                          //Allows player to choose their next step.
    menu("The map ends here so going forward, you only have one option right now\n", "(C)ross the road\n", "(R)eturn to Bubble Puff\n");
    switch(choice())
    {
        case 'c':
            colorado2BonnieCrossRoad();
            break;
        case 'r':
            bubblePuff();
            break;
    }
}
void left2Bonnie() //Display the places the player can go after turning left and walking to Bonnie Avenue.
{                                                   //Allows player to choose their next step.
    menu("Walk Straight (D)own Bonnie Avenue\n", "(P)asadena City College\n", "(R)eturn to Colorado - Harkness cross road\n");
    switch(choice())
    {
        case 'd':
            straightDownBonnie2DelMar();
            break;
        case 'p':
            pasadenaCityCollege();
            break;
        case 'r':
            harkness2ColoradoCrossRoad();
            break;
    }
}
void colorado2BonnieCrossRoad() //Display the places the player can go after crossing the road from North to
{                                               //South Bonnie Avenue.//Allows player to choose their next step.
    menu("Walk Straight (D)own Bonnie Avenue\n", "(P)asadena City College\n", "(R)eturn to Subway\n");
    switch(choice())
    {
        case 'd':
            straightDownBonnie2DelMar();
            break;
        case 'p':
            pasadenaCityCollege();
            break;
        case 'r':
            subway();
            break;
    }
}
void straightDownBonnie2DelMar() //Display the places the player can go after walking straight down
{                                   //south Bonnie Avenue.//Allows player to choose their next step.
    menu("Go To\n", "Del Mar - (H)ill bus stop\n", "Del Mar - (B)onnie bus stop\n");
    menu("(P)asadena City College\n", "(R)eturn to Colorado - Bonnie Corner\n", "");
    switch(choice())
    {
        case 'h':
            delMarHillBusStop();
            break;
        case 'b':
            delMarBonnieBusStop();
            break;
        case 'p':
            pasadenaCityCollege();
            break;
        case 'r':
            colorado2BonnieCrossRoad();
            break;
    }
}
void pasadenaCityCollege() //Generates a random number between 0 and 2. Locks the player in if the
{                           //generated number is not 0
    if(isNotSchoolDay())                 //Make the player lose after 3 tries.
    {                                    //If the player doesn't get locked, connects to next step.
        noClassToday();
    }
    else
    {
        int tries = 0;
        char answer;
        do
        {
            int trappedOrNot;
            tries++;
            trappedOrNot = rand() % 3;
            if(trappedOrNot == 0)
            {
                output("Yayy!! Your class was canceled!!\n");
                classCancelled();
                break;
            }
            else
            {
                output("Oops! You walked straight into the Tiger's Den!\n");
            }
            if(tries == 4) // Player has three tries to escape PCC.
            {
                output("This is your 4th class. You are dead.\n");
                output("Mission failed. You Lose!\n");
                break;
            }
            output("Would you like to try escaping? (y/n)\n");
            answer = charInput();
        }while(answer == 'y');
    }
}
bool isNotSchoolDay()   //Generates a random number between 0 and 4.
{                               //Gives the player a 1 out of 5 chance to avoid the Tiger's Den.
    int friday = rand() % 5;
    return (friday == 4);
}
void noClassToday() //If the player avoided the Tiger's Den, displays their next steps.
{
    menu("You don't have class today\n", "If you choose to go to school despite this, ", "");
    menu("you are attending a waiting class\n", "A class where you wait for your important someone to finish his/her/their class ;)\n","");
    classCancelled();
}
void classCancelled() //If the player doesn't get locked in the tiger's den, display their next steps
{                       //Allows player to choose their next step.
    menu("Go to (D)el Mar Boulevard\n", "Go to (C)olorado Boulevard\n", "");
    switch(choice())
    {
        case 'd':
            go2DelMar();
            break;
        case 'c':
            go2Colorado();
            break;
    }
}
void go2DelMar() //Display the places the player can go after exiting pcc from Del Mar gate.
{                   //Allows player to choose their next step.
    menu("Go To\n", "Del Mar - (H)ill bus stop\n", "Del Mar - (B)onnie bus stop\n");
    menu("(P)asadena City College\n", "(C)olorado - Bonnie Corner\n", "");
    switch(choice())
    {
        case 'h':
            delMarHillBusStop();
            break;
        case 'b':
            delMarBonnieBusStop();
            break;
        case 'p':
            pasadenaCityCollege();
            break;
        case 'c':
            colorado2BonnieCrossRoad();
            break;
    }
}
void go2Colorado() //Display the places the player can go after exiting pcc from Colorado gate.
{                       //Allows player to choose their next step.
    menu("Turn (r)ight and walk to Bonnie Avenue\n", "Turn (l)eft to Colorado - Harkness cross road\n", "(P)asadena City College\n");
    menu("(C)ross the road in front\n", "", "");
    switch(choice())
    {
        case 'r':
            right2Bonnie();
            break;
        case 'l':
            harkness2ColoradoCrossRoad();
            break;
        case 'p':
            pasadenaCityCollege();
            break;
        case 'c':
            leftNStraight();
            break;
    }
}
void right2Bonnie() //Display the places the player can go after turning right from pcc Colorado gate and
{                   //walking to Bonnie Ave. Allows player to choose their next step.
    colorado2BonnieCrossRoad();
}
void delMarHillBusStop() //Tells the player they lost the game.
{
    menu("Silly you! This is the silver bus stop.\n", "Mission failed. You Lose!\n", "");
}
void delMarBonnieBusStop() //Tells the player they won the game.
{
    menu("Congratulations!!!!\n", "You found the golden bus stop.\n", "Rewards include freedom and travelling ;)\n");
    menu("Recommended destinations include:\n", "Factory Tea Bar\n", "Allen Gold Line Station\n");
    menu("Everywhere else except school\n", "My dearest gratitude for playing. Peace out V\n", "");
}

char choice()
{
    char choice;
    choice = charInput();
    return tolower(choice);
}
void menu(std::string s1, std::string s2, std::string s3)
{
    if (s1 != "")
    {
        output(s1);
    }
    if (s2 != "")
    {
        output(s2);
    }
    if (s3 != "")
    {
        output(s3);
    }
}
char charInput() //inputs the character the player entered
{
    char input;
    std::cin >> input;
    return input;
}
void output(std::string message) //outputs a string
{
    std::cout << message;
}
bool goAgain() //asks the user if they would like to play again.
{
    char answer;
    output("Would you like to play again (y/n)?\n");
    std::cin >> answer;
    return (tolower(answer) == 'y');
}
