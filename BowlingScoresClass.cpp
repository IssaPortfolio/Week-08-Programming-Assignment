/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/                                                                                                                                               /
/    For the assignment you be modifying your code from the Week 07 - Programming Assignment. Here are the requirements:                        /
/                                                                                                                                               /
/    Your program must define a class that contains the following member variables and functions:                                               /  
/                                                                                                                                               /
/        a private string that contains the name of the file.                                                                                   /
/                                                                                                                                               /
/        a private array of the same structure as defined in Week 07 - Programming Assignment                                                   /
/                                                                                                                                               /
/        a public constructor that initializes the name of the file data member.                                                                /
/        The name of the data file should be passed into the constructor as a parameter.                                                        /
/                                                                                                                                               /
/        a public Boolean returning function called GetBowlingData to read and store data into the array of the structures data member.         /
/        This function should take no parameters and return a status of either success or failure (i.e. true or false).                         /
/                                                                                                                                               /
/        a public void function called GetAverageScore that is used to calculate the average bowling score.                                     /
/        This function should take no parameters. It should fill the array of structures data member with the average score of each bowler.     /
/                                                                                                                                               /
/        a public void function called PrettyPrintResults to output the results, i.e. bowler name, scores and average.                          /
/        This function should take no parameters.                                                                                               /
/                                                                                                                                               /
/    Your program must also implement a main function that is used to create an instance of the class                                           /
/    mentioned above and call its public functions to exercise/test the classes implementation.                                                 /
/                                                                                                                                               /
/    As always:                                                                                                                                 /
/        Don't use Vectors or any other newfangled container, use only old school C arrays like in the book.                                    /
/        Use repetition structures (loops) in your functions to perform calculations and printing. Remember "dimensions = loops".               /
/        So a 2 dimensional array will require 2 loops to completely iterate over all of the elements in the array.                             /
/        Don't use magic numbers. Instead use global constants at the top of the program under the includes.                                    /
/        Include lots of meaningful comments so that I can follow you logic and know that you understand the program you wrote.                 /   
/                                                                                                                                               /
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// BY ISSA HABEEB */


#include <iostream>   // GIVES "cin" AND "cout"
#include <fstream>    // INPUTS/OUTPUTS TO A FILE
#include <iomanip>    // GIVES "setfill(char)", "setw(int)" AND "setprecision(int)"
using namespace std;

// CONSTANT VARIABLES
const int NUM_OF_BOWLERS = 10;
const int NUM_OF_SCORES = 4;

// Bowler Class
class Bowler
{
    // Private by default
    // Bowler Structure
    struct BowlerData {
        // Bowler name
        string name;

        // Bowler score array
        int score[NUM_OF_SCORES] = {};

        // Bowler average
        int average = 0;
    };

    // Txt file name
    string inputfilename;
    // Instance
    BowlerData bowler[NUM_OF_BOWLERS];

    // Everything under this is public (aka can be accessed outside of this class)
    public:
        // Constructor
        Bowler(string input_file_name)
        {
            inputfilename = input_file_name;
        }


    /* Read and store data into the array of the structures data member. 
       This function should take no parameters and return a status of either success or failure (i.e. true or false).  */
    bool GetBowlingData()
    {
        // Opens file
        ifstream InputStream;
        InputStream.open(inputfilename);
        // Checks if file opened correctly
        if (!InputStream)
        {
            cout << "'" << inputfilename << "' file could not be found\n" << endl;
            system("pause");
            return false;
        }
        else
            cout << "Loading file: '" << inputfilename << "'...\n\n" << endl;

        // Variables to store into
        string get_name;
        int get_score;

        // One dimension array
        for (int row = 0; row < NUM_OF_BOWLERS; row++)
        {
            // Gets data
            InputStream >> get_name;
            bowler[row].name += get_name;
            // Two dimension array
            for (int column = 0; column < NUM_OF_SCORES; column++)
            {
                InputStream >> get_score;
                bowler[row].score[column] = get_score;
            }

        }
        // Closes file and returns true
        InputStream.close();
        return true;
    }

    // It should fill the array of structures data member with the average score of each bowler.
    void GetAverageScore()
    {
        // One dimension array
        for (int row = 0; row < NUM_OF_BOWLERS; row++)
        {
            // Initially set everything in the array to 0
            bowler[row].average = 0;
            // Two dimension array
            for (int column = 0; column < NUM_OF_SCORES; column++)
            {
                // Technically gets the total and not the average
                bowler[row].average += bowler[row].score[column];
            }
            // Divdes the total by number of scores to get average
            bowler[row].average = bowler[row].average / NUM_OF_SCORES;
        }
    }

    // Output the results, i.e. bowler name, scores and average. This function should take no parameters.
    void PrettyPrintResults()
    {
        cout << setfill(' ');
        // One dimension array
        for (int row = 0; row < NUM_OF_BOWLERS; row++)
        {
            // Outputs name
            cout << "Name: " << bowler[row].name << setw(20 - bowler[row].name.length()) << "Scores: ";
            // Two dimension array
            for (int column = 0; column < NUM_OF_SCORES; column++)
            {
                // Outputs scores
                cout << "|" << bowler[row].score[column] << "| ";
            }
            // Outputs average
            cout << "\n" << setw(27) << "Average: " << bowler[row].average << "\n" << endl;
        }
        cout << endl;
    }
};


int main()
{
    // Instance
    Bowler bowler("BowlingScores.txt");

    // Bowler class methods (functions)
    bowler.GetBowlingData();
    bowler.GetAverageScore();
    bowler.PrettyPrintResults();
    // Pauses console and "int main()" return 0 after function completion. 
    system("pause");
    return 0;
}


/*

    Professor, I have taken your feedback on extracting data using a loop (as seen at line 102).

    This allows me to not have hard-coded/fixed values and only thing that would need to change if txt file was modified (such as adding a 5th score)
    would be the const variables at the top of the program.

    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    Some things I am confused on:

    "a private string that contains the name of the file." and "a public constructor that initializes the name of the file data member. 
    The name of the data file should be passed into the constructor as a parameter."

    The first quote, to me it implies that this string variable has a value I am supposed to set. Then, the second quote implies that the string variable
    gets it value from the passed value from main (which is what I believe I have done). So I am assuming that is what I am supposed to do.

    One thing I was unsure about is a de-constructor. I don't think it's useful in this program, and if so, it would be used to close the txt file? But I
    have opted out of using it. 

*/