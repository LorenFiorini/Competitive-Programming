#include<bits/stdc++.h>
using namespace std;

int get_number(char ch) {
	int row;
	switch (ch) {
		case 'A':
			row = 12;
			break;
		case 'K':
			row = 11;
			break;
		case 'Q':
			row = 10;
			break;
		case 'J':
			row = 9;
			break;
		case 'T':
			row = 8;
			break;
		default:
		row = ch - '2';
	}
	return row;
}

int get_suit(char ch) {
	int col;
	switch (ch) {
		case 'H':
			col = 0;
			break;
		case 'C':
			col = 1;
			break;
		case 'S':
			col = 2;
			break;
		case 'D':
			col = 3;
			break;
	}
	return col;
}



bool solve(vector<string> &a, vector<string> &b) {
	vector<vector<int>> cards(13, vector<int> (4, 0));
	for (string card : a) 
	{
		int row = get_number(card[0]);
		int col = get_suit(card[1]);
		cards[row][col] = 1;
	}
	for (string card : b) 
	{
		int row = get_number(card[0]);
		int col = get_suit(card[1]);
		cards[row][col] = -1;
	}
	//for (int i =0; i<13;i++) {for (int j=0; j<4; j++) {cout << cards[i][j] << " "; }cout << "\n";}
	
	
	
	
	return 1;
}





int main() 
{
	ifstream file("054_poker.txt");
	int answer = 0;
	string s;
	while (getline(file, s)) 
	{
		int n = s.size();
		vector<string> a;
		vector<string> b;
		for (int i = 0; i < n; i += 3) 
		{
			if (i < n / 2) {
				a.push_back(s.substr(i, 2));
			} else {
				b.push_back(s.substr(i, 2));
			}
		}
		if (solve(a, b)) answer++;
		if (answer) break;
	}
	cout << answer << endl;
	return 0;
}



/*
bool solve(vector<string> &a, vector<string> &b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < (int) a.size(); i++) cout << a[i] << " ";
	cout << "\n";
	for (int i = 0; i < (int) b.size(); i++) cout << b[i] << " ";
	return 1;
}
int main() 
{
	ifstream file("054_poker.txt");
	int answer = 0;
	string s;
	while (getline(file, s)) 
	{
		int n = s.size();
		vector<string> a;
		vector<string> b;
		for (int i = 0; i < n; i += 3) {
			if (i < n / 2) a.push_back(s.substr(i, 2));
			else b.push_back(s.substr(i, 2));
		}
		if (solve(a, b)) answer++;
		if (answer) break;
	}
	cout << answer << endl;
	return 0;
}
*/
