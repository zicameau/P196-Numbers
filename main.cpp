/****************************

Zicameau
February 6, 2016

****************************/




#include <iostream>
#include <climits>

using namespace std;

unsigned num_digits (unsigned long l);
int nth_digit(unsigned long l, unsigned n);
unsigned long rev_digits(unsigned long l);
bool is_palindrome(unsigned long l);
bool P196(unsigned long l);


int main()
{

        for (int i = 10; i < ULONG_MAX; i++) //Loop through all possible values of a ULONG_MAX
        {
            P196(i);
        }

    return 0;
}


//Finds the number of digits in the number passed to it
unsigned num_digits (unsigned long l)
{

    unsigned digits = 0;

    if (l < 10)
    {
        return 1;
    }
    //While the number is not 0
    while (l)
    {
        l /= 10; /*divide the number by 10 and reassign the number to itself
                    Integer division will eventually make the value 0.*/
        digits++;
    }
    return digits;
}


//Finds the number that the user wants and returns it's value
int nth_digit(unsigned long l, unsigned n)
{

    int retainer;
    int leftOver;

    //validation check to see if the number is greater than 4
    /*if (n > 4)
    {
        return -1;
    }*/
    //Validation check to see if the digit the user wants is less than the number of digits the number has.
   /* else */
   if (n >= num_digits(l))
    {
        return -1;
    }
    else
    {
       //divide the number by 10 until we get the digit (n) we want on the far right side of the number
       //EX: 729 we want the number 2, represented by n = 1, 729/10 = 72 then loop stops
       for (int i = 0; i < n; i++)
       {
           l /= 10;
       }

        //Subtract all numbers except for the one on the far right
        l -= 10*(l/10);

       return l;
    }
}


//Reverses the digits
unsigned long rev_digits(unsigned long l)
{
    int numDig = num_digits(l);
    unsigned long revNum = 0;
    float pows = 0.1;
    int num = 0;

    //Count down through each digit in the number
    while (numDig != 0)
    {
        num = l; //reset the num to be equal to the number passed (so we don't edit the original)
        pows = 10 * pows; //Determine where the digit needs to be in the reversed number

        for (int i = numDig; i > 1; i--) //Loop until we have the digit we want on the far right
                                            //Ex: 7309, we want the 3rd digit  so we want 73.
        {
            num = num/10;
        }
        for (int tens = pows; tens >= 10; tens /= 10) //get rid of the extra numbers we don't need Ex: 72, subtract 70.
        {
            num = num - tens*(num/tens);
        }

        num *= pows; //aAdjust the power of the digit in order to give it the right placement within the reversed number
        revNum += num; //put the new digit within the reversed number
        numDig--; //Subtract the number of digits to go to the next digit within the number passed
    }
    return revNum;
}


//Determines if the number is a palindrome or not EX: 1001 is a palindrome, 1002 is not
bool is_palindrome(unsigned long l)
{
    if (l == rev_digits(l)) //if the reverse equals it's original value return true
        return true;
    else
        return false; //if not then return false
}


//Determines if the number is a P196, if it is then it returns it's palindrome
bool P196(unsigned long l)
{
    unsigned long total;
    bool tooLargeFlag = false;

    total = l; //initialize the value we'll be using in the loop

    while (!is_palindrome(total) && tooLargeFlag == false)
    {

        if (total + rev_digits(total) < total) //If addition of the number and it's reveres rolls over, end the loop
        {
            tooLargeFlag = true;
        }
        else if (num_digits(total) == 10) //If the number is close to rolling over
        {
            if (nth_digit(total, 0) != nth_digit(rev_digits(total), 9)) //Double check that the number reversed properly
            {
                tooLargeFlag = true; //if not then it rolled over the ULONG_MAX amount of digits
            }
            else //if it can't roll over add the number with it's reversed and restart the process again
            {
                 total += rev_digits(total);
            }
        }
        else //if it can't roll over add the number with it's reversed and restart the process again!
        {
            total += rev_digits(total);
        }
    }

    if (tooLargeFlag == true) //If it overflowed, return the value as false
    {
        return false;
    }
    else
    {
        cout << total << " is a palindrome number! Therefore, " << l << " is a P196 number!" << endl; //if it didn't overflow, then display what the palindrome is and return true
        return true;
    }

}
