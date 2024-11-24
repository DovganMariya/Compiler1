//#include "includes.h"
#include "Lexer.h"
#include <fstream>
#include "Parser.h"
using namespace std;
int main()
{
	ifstream inp("input.txt");
	Lexer programm(inp);
	programm.getHashTable().printHashTable();
	ifstream fin("input.txt");
	vector<Token> all;
	programm.getTok(all);
	Parser prog(all);
	prog.parse();
}

