#include <iostream>
using std::endl;


int main()
{
	std::cout << "From how many integer numbers you want to count the mean value? ";
	int num;
	std::cin >> num;
	float summation_result = 0;
	float mean_value = 0.0;

	if (num != 0) 
	{
		for (int i = 1; i < num + 1; i++)
		{
			std::cout << "Input " << i << ". number: ";
			float num_on_each_iteration;
			std::cin >> num_on_each_iteration;
			summation_result = summation_result + num_on_each_iteration;
		}

		mean_value = summation_result / num;
		std::cout << "Mean value of the given numbers is " << mean_value;
	}
	else
	{
		std::cout << "Cannot count mean value from 0 numbers";
	}
	

}