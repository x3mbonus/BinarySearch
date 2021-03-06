#include <iostream>
#include <vector>

void test(int i);

int lower_bound(std::vector<double> sortedVector, double searchItem);
int upper_bound(std::vector<double> sortedVector, double searchItem);

int main()
{
   for(int i = 0; i < 17; ++i)
   {
	   std::cout << "Test " << i << std::endl;
	   test(i);
   }
	system("pause");	
}

int some_bound(std::vector<double> sortedVector, double searchItem, bool isLower)
{
	int lowerBound = 0;
	int upperBound = sortedVector.size() - 1;
	if (upperBound < 0)
	{
		return -1;
	}
	bool success = false;
	int middle = 0;
	while (true)
	{
		if (lowerBound == upperBound)
		{
			double value = sortedVector[middle];
			if (value > searchItem ||
				isLower && 
				value == searchItem)
			{
				middle = lowerBound;
				success = true;
			}
			break;
		}
		middle = (lowerBound + upperBound) / 2;
		double leftValue = sortedVector[middle];
		double rightValue = sortedVector[middle + 1];		
		if ((leftValue < searchItem ||
			!isLower && 
			leftValue == searchItem) && 
			(rightValue > searchItem ||
			isLower && 
			rightValue == searchItem))
		{
			success = true;
			++middle;
			break;
		}
		else if ((leftValue < searchItem ||
				!isLower && 
				leftValue == searchItem) && 
				(rightValue < searchItem ||
				!isLower && 
				rightValue == searchItem))
		{
			if (middle == lowerBound &&
				lowerBound < upperBound)
			{
				lowerBound = upperBound;
				continue;
			}
			lowerBound = middle;
		}
		else if ((leftValue > searchItem ||
				isLower && 
				leftValue == searchItem) && 
				(rightValue > searchItem ||
				isLower && 
				rightValue == searchItem))
		{
			upperBound = middle;
		}
	}
	if (!success)
	{
		middle = -1;
	}
	return middle;
}

int lower_bound(std::vector<double> sortedVector, double searchItem)
{
	/*int lowerBound = 0;
	int upperBound = sortedVector.size() - 1;
	if (upperBound < 0)
	{
		return -1;
	}
	bool success = false;
	int middle = 0;
	while (true)
	{
		if (lowerBound == upperBound)
		{
			double value = sortedVector[middle];
			if (value >= searchItem)
			{
				middle = lowerBound;
				success = true;
			}
			break;
		}
		middle = (lowerBound + upperBound) / 2;
		double leftValue = sortedVector[middle];
		double rightValue = sortedVector[middle + 1];		
		if (leftValue < searchItem && 
			rightValue >= searchItem)
		{
			success = true;
			++middle;
			break;
		}
		else if (leftValue < searchItem && 
				rightValue < searchItem)
		{
			if (middle == lowerBound &&
				lowerBound < upperBound)
			{
				lowerBound = upperBound;
				continue;
			}
			lowerBound = middle;
		}
		else if (leftValue >= searchItem && 
				rightValue >= searchItem)
		{
			upperBound = middle;
		}
	}
	if (!success)
	{
		middle = -1;
	}
	return middle;*/
	return some_bound(sortedVector, searchItem, true);
}

int upper_bound(std::vector<double> sortedVector, double searchItem)
{
	/*int lowerBound = 0;
	int upperBound = sortedVector.size() - 1;
	if (upperBound < 0)
	{
		return -1;
	}
	bool success = false;
	int middle = 0;
	while (true)
	{
		if (lowerBound == upperBound)
		{
			double value = sortedVector[middle];
			if (value > searchItem)
			{
				middle = lowerBound;
				success = true;
			}
			break;
		}
		middle = (lowerBound + upperBound) / 2;
		double leftValue = sortedVector[middle];
		double rightValue = sortedVector[middle + 1];		
		if (leftValue <= searchItem && 
			rightValue > searchItem)
		{
			success = true;
			++middle;
			break;
		}
		else if (leftValue <= searchItem && 
				rightValue <= searchItem)
		{
			if (middle == lowerBound &&
				lowerBound < upperBound)
			{
				lowerBound = upperBound;
				continue;
			}
			lowerBound = middle;
		}
		else if (leftValue > searchItem && 
				rightValue > searchItem)
		{
			upperBound = middle;
		}
	}
	if (!success)
	{
		middle = -1;
	}
	return middle;*/
	return some_bound(sortedVector, searchItem, false);
}


void test(int i)
{
	switch(i)
	{
		case 0:
		{
			std::vector<double> sortedVector;
			double searchItem = 5;
			std::cout << "-1 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "-1 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}		
		case 1:
		{
			const double a[] = { 10 };
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));			
			double searchItem = 5;
			std::cout << "0 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "0 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}
		case 2:
		{
			const double a[] = { 10 };
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
			double searchItem = 10;
			std::cout << "0 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "-1 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}
		case 3:
		{
			const double a[] = { 10 };
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
			double searchItem = 20;
			std::cout << "-1 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "-1 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}
		case 4:
		{
			const double a[] = { 10, 20 };
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
			double searchItem = 5;
			std::cout << "0 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "0 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}		
		case 5:
		{
			const double a[] = { 10, 20 };
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
			double searchItem = 15;
			std::cout << "1 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "1 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}
		case 6:
		{
			const double a[] = { 10, 20 };
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
			double searchItem = 20;
			std::cout << "1 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "-1 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}
		case 7:
		{
			const double a[] = { 10, 20 };
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
			double searchItem = 30;
			std::cout << "-1 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "-1 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}
		case 8:
		{
			const double a[] = { 10, 20, 30, 40 };
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
			double searchItem = 5;
			std::cout << "0 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "0 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}		

		case 9:
		{
			const double a[] = { 10, 20, 30, 40 };
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
			double searchItem = 50;
			std::cout << "-1 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "-1 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}

		case 10:
		{
			const double a[] = { 10, 20, 30, 40 };
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
			double searchItem = 10;
			std::cout << "0 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "1 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}

		case 11:
		{
			const double a[] = { 10, 20, 30, 40 };
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
			double searchItem = 40;
			std::cout << "3 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "-1 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}

		case 12:
		{
			const double a[] = { 10, 20, 30, 40 };
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
			double searchItem = 20;
			std::cout << "1 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "2 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}
		

		case 13:
		{
			const double a[] = {10, 20, 30, 40, 40, 40, 50, 50, 50, 50, 60, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 80};
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
			double searchItem = 40;
			std::cout << "3 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "6 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}

		case 14:
		{
			const double a[] = {10, 20, 30, 40, 40, 40, 50, 50, 50, 50, 60, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 80};
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
			double searchItem = 50;
			std::cout << "6 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "10 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}

		case 15:
		{
			const double a[] = {10, 20, 30, 40, 40, 40, 50, 50, 50, 50, 60, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 80};
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
			double searchItem = 70;
			std::cout << "11 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "27 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}
		
		case 16:
		{
			const double a[] = { 10, 10 };
			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
			double searchItem = 10;
			std::cout << "0 = " << lower_bound(sortedVector, searchItem) << std::endl;
			std::cout << "-1 = " << upper_bound(sortedVector, searchItem) << std::endl;
			break;
		}
		
		default :
		{
			std::vector<double> sortedVector;
			double searchItem = 5;
			std::cout << "-1 = " << lower_bound(sortedVector, searchItem) << std::endl;
		}
	}	
}