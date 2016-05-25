#include<vector>
#include<set>
#include<fstream>
#include<iostream>
#include<math.h>
using namespace std;
int record=10000;
ofstream out("output.txt");
vector<vector<vector<int>>> result;
void print(vector<vector<int>> v )
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
			out << v[i][j];
		out << endl;
	}
}
void print(set<pair<int, int>> s)
{
	for (auto q = s.begin(); q != s.end(); q++)
		cout << (*q).first << (*q).second << " ";
}
/*void perebor(vector<vector<int>> doska, set<pair<int, int>> free, int h,pair<int,int> key)
{
	if (h > record) return;
	doska[key.first][key.second] = 1;
	int x = key.first;
	int y = key.second;
	set<pair<int, int>> removed;
	removed.insert(make_pair(x, y));
	set<pair<int, int>> potential;
	//potential.insert(make_pair(x - 1, y + 2));
	potential.insert(make_pair(x + 1, y + 2));
	potential.insert(make_pair(x + 2, y + 1));
	potential.insert(make_pair(x + 2, y - 1));
	potential.insert(make_pair(x + 1, y - 2));
	potential.insert(make_pair(x - 1, y - 2));
	potential.insert(make_pair(x - 2, y - 1));
	potential.insert(make_pair(x - 1, y + 1));
	free.erase(make_pair(x, y));
	free.erase(make_pair(x - 1, y + 2));
	free.erase(make_pair(x + 1, y + 2));
	free.erase(make_pair(x + 2, y + 1));
	free.erase(make_pair(x + 2, y - 1));
	free.erase(make_pair(x + 1, y - 2));
	free.erase(make_pair(x - 1, y - 2));
	free.erase(make_pair(x - 2, y - 1));
	free.erase(make_pair(x - 2, y + 1));
	if (free.size() == 0)
	{
		if (h + 1 < record)
		{
			record = h + 1;
			result.clear();
			result.push_back(doska);
			print(doska,doska.size());
			cout << endl;
		}
		else 
		if (h + 1 == record)
		{
			result.push_back(doska);
		}
		
	}
	else
	{
		for (auto q = free.begin(); q != free.end(); q++)
		{
			perebor(doska, free, h + 1, (*q));
		}
	}
	//if (h = 25) cout << "full";
	return;
}
void main()
{
	set<pair<int, int>> free;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	in >> n;
	int m;
	in >> m;
	vector<vector<int>> doska(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			free.insert(make_pair(i, j));
	//cout << free.size() << endl;
	//print(free);
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		in >> x >> y;
		doska[x-1][y-1] = 2;
		free.erase(make_pair(x-1, y-1));
		/*free.erase(make_pair(x, y));
		free.erase(make_pair(x-1, y+2));
		free.erase(make_pair(x+1, y+2));
		free.erase(make_pair(x+2, y+1));
		free.erase(make_pair(x+2, y-1));
		free.erase(make_pair(x+1, y-2));
		free.erase(make_pair(x-1, y-2));
		free.erase(make_pair(x-2, y-1));
		free.erase(make_pair(x-2, y+1));*/
		
/*	}
	print(doska, n);
	for (auto q = free.begin(); q != free.end(); q++)
	{
		perebor(doska, free, 0, (*q));
	}
	//print(free);
	//print(result[0], n);
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
	{
		print(result[i], n);
		cout << endl;
	}
	//cout << free.size();
	//main();
	system("pause");
}*/
int min_versh(set < pair<int, int>> free)
{
	vector<pair<int, int>>a;
	
	int n = free.size();
	vector<bool> s(n, false); 
	while (!free.empty())
	{
		a.push_back(*free.begin());
		free.erase(free.begin());
	}
	int r = 0;
	vector<vector<int>> g(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int x1 = a[i].first;
			int y1 = a[i].second;
			int x2 = a[j].first;
			int y2 = a[j].second;
			if (((abs(x1 - x2) == 1) && (abs(y1 - y2) == 2)) || ((abs(x1 - x2) == 2) && (abs(y1 - y2) == 1)))
			{
				g[i][j] = 1;
				r++;
				s[i] = true;
				s[j] = true;
			}
		}
	r /= 2;
	int i_ = 0, j_ = 0;
	set<int> res;
	while (true)
	{
		bool flag = true;
		for (int i = i_; i < n; i++)
			for (int j = j_; j < n; j++)
			{
				if (g[i][j] != 0)
				{
					res.insert(i);
					res.insert(j);
					for (int k = 0; k < n; k++)
					{
						g[i][k] = 0;
						g[j][k] = 0;
						g[k][i] = 0;
						g[k][j] = 0;
					}
					i_ = i;
					j_ = j;
					flag = false;
					break;
				}
			}
		if (flag) break;
	}
	for (int i = 0; i < n; i++)
		if (s[i] == false) res.insert(i);
	return res.size();
}
void perebor(vector<vector<int>> doskaa, set<pair<int, int>> freee, set<pair<int, int>> potentiall,pair<int,int> current,int h)
{
	doskaa[current.first][current.second] = 1;
	int x = current.first;
	int y = current.second;
	freee.erase(make_pair(x, y));
	freee.erase(make_pair(x - 1, y + 2));
	freee.erase(make_pair(x + 1, y + 2));
	freee.erase(make_pair(x + 2, y + 1));
	freee.erase(make_pair(x + 2, y - 1));
	freee.erase(make_pair(x + 1, y - 2));
	freee.erase(make_pair(x - 1, y - 2));
	freee.erase(make_pair(x - 2, y - 1));
	freee.erase(make_pair(x - 2, y + 1));

	potentiall.erase(make_pair(x, y));
	//int pr = 2*min_versh(freee);
	//int pr = 2 * min_versh(potentiall);
	if (freee.size() == 0)
	{
		if (h + 1 < record)
		{
			result.clear();
			result.push_back(doskaa);
			record = h + 1;
			cout << record << endl;
			
		}
		else
			if (h + 1 == record)
			{
				result.push_back(doskaa);
			}
			
			
		return;
	}
	if (h + 1 == record) return;
	
	/*if (freee.size() == 1)
	{
		auto k = *freee.begin();
		doskaa[k.first][k.second] = 1;
		if (h + 2 < record)
		{
			result.clear();
			result.push_back(doskaa);
			record = h + 2;
			//cout << record << endl;

		}
		else
			if (h + 2 == record)
			{
				result.push_back(doskaa);
			}


		return;
	}*/
	/*if (record < h + 1 + pr)
	{
		//int x;
		//print(doskaa);
		//cout << h << " " << record <<" "<< pr<<endl;

		return;
	}*/
	while (!potentiall.empty())
	{
		pair<int, int> key = (*potentiall.begin());
		//potentiall.emplace(potentiall.begin());
		potentiall.erase(key);
		perebor(doskaa, freee, potentiall, key, h + 1);
	}
	
}

void main()
{
	set<pair<int, int>> free;
	ifstream in("input.txt");
	
	int m, n, k;
	in >> m >> n >> k;
	vector<vector<int>> doska(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			free.insert(make_pair(i, j));
	for (int i = 0; i < k; i++)
	{
		int x, y;
		in >> x >> y;
		doska[x - 1][y - 1] = 2;
		free.erase(make_pair(x - 1, y - 1));
	}
	set<pair<int, int>> potential = free;
	record = 2*min_versh(free) ;
	//cout << record << endl;
	while (!potential.empty())
	{
		pair<int, int>key = *potential.begin();
		potential.erase(potential.begin());
		perebor(doska, free, potential, key, 0);
	}
	out << result.size()<<endl;
	out << endl;
	for (int i = 0; i < result.size(); i++)
	{
		print(result[i]);
		out << endl;
	}
	//print(doska);
	//print(free);
	//cout << min_versh(free);
	//system("pause");
}
