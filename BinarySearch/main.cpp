//#include <iostream>
//#include <vector>
//
//void test(int i);
//
//int binary_search(std::vector<double> sortedVector, double searchItem);
//
//int main()
//{
//   for(int i = 0; i < 14; ++i)
//   {
//	   std::cout << "Test " << i << std::endl;
//	   test(i);
//   }
//	system("pause");	
//}
//
//int binary_search(std::vector<double> sortedVector, double searchItem)
//{
//	int lowerBound = 0;
//	int upperBound = sortedVector.size() - 1;
//	if (upperBound < 0)
//	{
//		return -1;
//	}	
//	bool success = false;
//	int middleBound;
//	while (true)
//	{
//		middleBound = (lowerBound + upperBound) / 2;
//		double value = sortedVector[middleBound];
//		if (fabs(value - searchItem) < std::numeric_limits<double>::epsilon())
//		{
//			success = true;
//			break;
//		}
//		if (value < searchItem)
//		{
//			if (middleBound == lowerBound &&
//				middleBound < upperBound)
//			{
//				lowerBound = upperBound;
//				continue;
//			}			
//			lowerBound = middleBound;
//		}
//		else
//		{
//			upperBound = middleBound;	
//		}
//		
//		if (upperBound == lowerBound)
//		{			
//			break;
//		}
//	}
//	if (!success)
//	{
//		middleBound = -1;
//	}
//	return middleBound;
//}
//
//
//void test(int i)
//{
//	switch(i)
//	{
//		case 0:
//		{
//			std::vector<double> sortedVector;
//			double searchItem = 5;
//			std::cout << "-1 = " << binary_search(sortedVector, searchItem) << std::endl;
//			break;
//		}		
//		case 1:
//		{
//			const double a[] = { 10 };
//			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));			
//			double searchItem = 5;
//			std::cout << "-1 = " << binary_search(sortedVector, searchItem) << std::endl;
//			break;
//		}
//		case 2:
//		{
//			const double a[] = { 10 };
//			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
//			double searchItem = 10;
//			std::cout << "0 = " << binary_search(sortedVector, searchItem) << std::endl;
//			break;
//		}
//		case 3:
//		{
//			const double a[] = { 10, 20 };
//			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
//			double searchItem = 15;
//			std::cout << "-1 = " << binary_search(sortedVector, searchItem) << std::endl;
//			break;
//		}
//		case 4:
//		{
//			const double a[] = { 10, 20 };
//			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
//			double searchItem = 20;
//			std::cout << "1 = " << binary_search(sortedVector, searchItem) << std::endl;
//			break;
//		}
//		case 5:
//		{
//			const double a[] = { 10, 20, 30, 40 };
//			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
//			double searchItem = 5;
//			std::cout << "-1 = " << binary_search(sortedVector, searchItem) << std::endl;
//			break;
//		}
//		case 6:
//		{
//			const double a[] = { 10, 20, 30, 40 };
//			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
//			double searchItem = 5;
//			std::cout << "-1 = " << binary_search(sortedVector, searchItem) << std::endl;
//			break;
//		}
//
//		case 7:
//		{
//			const double a[] = { 10, 20, 30, 40 };
//			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
//			double searchItem = 50;
//			std::cout << "-1 = " << binary_search(sortedVector, searchItem) << std::endl;
//			break;
//		}
//
//		case 8:
//		{
//			const double a[] = { 10, 20, 30, 40 };
//			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
//			double searchItem = 10;
//			std::cout << "0 = " << binary_search(sortedVector, searchItem) << std::endl;
//			break;
//		}
//
//		case 9:
//		{
//			const double a[] = { 10, 20, 30, 40 };
//			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
//			double searchItem = 40;
//			std::cout << "3 = " << binary_search(sortedVector, searchItem) << std::endl;
//			break;
//		}
//
//		case 10:
//		{
//			const double a[] = { 10, 20, 30, 40 };
//			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
//			double searchItem = 20;
//			std::cout << "1 = " << binary_search(sortedVector, searchItem) << std::endl;
//			break;
//		}
//
//		case 11:
//		{
//			const double a[] = { 10, 20, 30 };
//			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
//			double searchItem = 20;
//			std::cout << "1 = " << binary_search(sortedVector, searchItem) << std::endl;
//			break;
//		}
//
//		case 12:
//		{
//			const double a[] = {10, 20, 30, 40, 50, 60, 70, 80};
//			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
//			double searchItem = 20;
//			std::cout << "1 = " << binary_search(sortedVector, searchItem) << std::endl;
//			break;
//		}
//
//		case 13:
//		{
//			const double a[] = {10, 20, 30, 40, 40, 40, 50, 50, 50, 50, 60, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 80};
//			std::vector<double> sortedVector(a,a+sizeof(a)/sizeof(double));
//			double searchItem = 40;
//			std::cout << "3-5 = " << binary_search(sortedVector, searchItem) << std::endl;
//			break;
//		}
//		
//		default :
//		{
//			std::vector<double> sortedVector;
//			double searchItem = 5;
//			std::cout << "-1 = " << binary_search(sortedVector, searchItem) << std::endl;
//		}
//	}	
//}