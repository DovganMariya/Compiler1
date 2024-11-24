#include <fstream>
#include <vector>
#include "Token.h"
//#include "Lexer.h"
using namespace std;
struct Node {
	string data;
	vector<Node> children;
};
class Parser {
private:
	vector<Token> text;
	string input;
	Token lexeme;
	int stroka=1;
	int i;
	void getLexeme();
	void printparse(vector<Token> tok);
	void Begin();
	void Descr();
	void Op();
	void End();
public:

	Parser(vector<Token> tok);
	void parse();
};
