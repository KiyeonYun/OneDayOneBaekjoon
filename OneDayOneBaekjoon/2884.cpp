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
//		// 60 - minute�� 0�� �Ǳ� ���� ��
//		// => 60 + minute
//		minute += 60;
//		if (hour < 0) {
//			hour += 24;
//		}
//	}
//
//	std::cout << hour << " " << minute;
//}