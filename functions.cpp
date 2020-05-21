#include "functions.h"

void importData() {
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
}

void calculator() {
	while (true)
	{
		string name;
		vector<double> m_find;
		cout << "Введите имя точки\n";
		for (size_t i = 0; ; ++i)
		{
			cin >> name;
			if (name == "1")
				break;
			for (auto obj : meas)
			{
				if (obj.name == name)
					m_find.push_back(obj.m);
			}
		}
		cout << "Введите длинну хода\n";
		double L;
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
}