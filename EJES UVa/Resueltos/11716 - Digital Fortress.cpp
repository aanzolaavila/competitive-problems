#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

void decypher(char * line);

int main()
{
	int n;
	string line;
	char text[10050];
	scanf("%d", &n);
	cin.ignore();
	for(int i = 0; i < n; i++)
	{
		getline(cin, line);
		strcpy(text, line.c_str());
		decypher(text);
		cout << text << endl;
	}
	
	return 0;
}

void decypher(char * line)
{
	int len = strlen(line);
	int n = (int)sqrt(len);
	if( (int)pow(n,2) != len )
	{	
		strcpy(line, "INVALID");
		return;
	}
	
	int pos = 0;
	char grid[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			grid[i][j] = line[pos++];
	
	pos = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			line[pos++] = grid[j][i];
	line[pos] = '\0';
}