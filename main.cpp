#include "Header.h"





int main() {
	setlocale(LC_CTYPE, "rus");
	vector<Meas> meas;
	ifstream file("data.txt");
	string name;
	double x, y;
	double m;
	while (file >> name >> x >> y >> m)
	{
		meas.push_back(Meas());
		meas.back().name = name;
		meas.back().m = m;
	}
	meas[0].name = "OPV1";

	while (true)
	{
		vector<double> m_find;
		vector<Meas>::iterator index;
		double L;
		cout << "Введите имя точки\n";
		for (size_t i = 0; ; ++i)
		{
			cin >> name;
			if (name == "1")
				break;
			for (auto a : meas) 
			{
				if (a.name == name)
					m_find.push_back(a.m);
			}
		}
		cout << "Введите длинну хода\n";
		cin >> L;
		cout << "m_max = " << *max_element(m_find.begin(), m_find.end()) << endl;
		cout << "Знаменатель дроби = " << L / (*max_element(m_find.begin(), m_find.end())) << endl;
		m_find.clear();
		cout << "Заканчиваем? 1 - нет, 2 - да\n";
		int ch;
		cin >> ch;
		if (ch == 2)
		{
			cout << "Спасибо за использование!\n";
			break;
		}
			
	}
	meas.clear();
	file.clear();
	return 0;
}