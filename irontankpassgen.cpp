/**
 ************************************************************************************************************************
 *
 *  @file                   lolo2passgen.cpp
 *  @brief                  Iron Tank Password Generator
 *  @copyright              2019 Shawn M. Crawford
 *  @date                   March 22nd, 2019
 *
 *  @remark Author:         Shawn M. Crawford
 *
 *  @note                   For use with the N.E.S. Version
 *
 ************************************************************************************************************************
 */

/* Includes */
#include <iostream>
#include <sstream>

using namespace std;

/**
 ************************************************************************************************************************
 *
 * @brief   Runs the program
 *
 * @param   N/A
 *
 * @return  N/A
 *
 * @note    N/A
 *
 ************************************************************************************************************************
 */
int main (int argc, char *argv[])
{
    int level = 0;
    int tempArray[7];
    int r = 0;
    int i = 0;
    string input = "";

    cout << " _______                     _______               __    " << endl;
    cout << "|_     _|.----.-----.-----. |_     _|.---.-.-----.|  |--." << endl;
    cout << " _|   |_ |   _|  _  |     |   |   |  |  _  |     ||    < " << endl;
    cout << "|_______||__| |_____|__|__|   |___|  |___._|__|__||__|__|" << endl;
    cout << "Iron Tank password generator v 1.0" << endl;
    cout << "For use with the N.E.S." << endl;
    cout << "Coded by: sleepy9090" << endl;
    cout << "======================================" << endl;
    cout << endl;

    while (true) {
        cout << "Enter level number (0..511): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> level)
        {
            if (level >= 0 && level <= 511)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    r = (level & 256) >> 8 | (level & 255) << 8;
    r |= ((r & 255 ^ level & 255) << 1 | r & 255) & 255;
    level = (r & 255) + (r >> 8 & 255) + 171;
    tempArray[0] = (level & 112) >> 4;
    tempArray[6] = level & 7;
    level = 10000;
    for(int k = 0; k < 5; k++)
    {
        i = 0;
        while(r - level >= 0)
        {
            r -= level;
            i++;
        }
        level = level / 10;
        tempArray[k+1] = i;
    }

    string password;
	for(int i = 0; i < 7; i++)
    {
        password += "0123456789"[tempArray[i]];
    }

    cout << endl;
    cout << "Generated password: " << password << endl;

    return(0);
}
