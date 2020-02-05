#include <iostream>

using namespace std;

// The following code returns the cube of an input positive variable and checks if there is no integer overflow

int factorial(int num_start, int num_end)
{
    unsigned long int result = 1;
    for (int i = num_start; i <= num_end; i++)
    {
        result = result * i;
    }
    return result;
}

int main()
{
    std::cout << "Enter the total number of lottery balls: ";
    int number_of_balls_total;
    std::cin >> number_of_balls_total;
    std::cout << "Enter the number of drawn balls: ";
    int number_of_drawn_balls;
    std:: cin >> number_of_drawn_balls;
    if (number_of_balls_total >= 0 && number_of_drawn_balls >=0)
    {
        if (number_of_drawn_balls > number_of_balls_total)
        {
            std::cout << "The maximum number of drawn balls is the total amount of balls.";
        }
        else
        {
            std::cout << "The probability of guessing all " << number_of_drawn_balls << " balls correctly is 1/"<< factorial(number_of_balls_total - number_of_drawn_balls + 1,number_of_balls_total)/factorial(1, number_of_drawn_balls) <<endl;
        }
    }
    else
    {
        std::cout << "The number of balls must be a positive number.";
    }

}
