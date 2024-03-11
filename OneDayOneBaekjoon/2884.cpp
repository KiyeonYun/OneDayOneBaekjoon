//#include <iostream>
//
//int main()
//{
//	int hour, minute;
//	const int CORRECTION = 45;
//	std::cin >> hour >> minute;
//
//	minute -= CORRECTION;
//
//	if (minute < 0) {
//		hour -= 1;
//		// 60 - minute가 0이 되기 위한 수
//		// => 60 + minute
//		minute += 60;
//		if (hour < 0) {
//			hour += 24;
//		}
//	}
//
//	std::cout << hour << " " << minute;
//}