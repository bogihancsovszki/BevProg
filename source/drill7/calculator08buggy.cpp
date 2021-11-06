
#include "../std_lib_facilities.h"

struct Token {
	char kind;
	double value;
	string name;
	Token() {}		
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string n) :kind(ch), name (n) { }
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer=t; full=true; }

	void ignore(char);
};

const char let = 'L';
const string declkey = "let";
const char quit = 'q';
const char print = '=';
const char number = '8';
const char name = 'a';
const char square_root = 'S';


Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
		double val;
		cin >> val;
		return Token(number,val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s=ch;
			cin.unget();
			if (s == "let") return Token(let);	
			if (s == "q") return Token(name);
			if (s == "sqrt") return Token(square_root); 	
			return Token(name,s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;	

double get_value(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ",s);
}

void set_value(string s, double d)
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

bool is_declared(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

void define_name(string name, double val)
{   
    names.push_back(Variable(name,val));
}
Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		 return d; //
	}
	case '-':
		return - primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
		
    	case square_root:
  	    { ts.unget(t);
  	          return NULL; }  
	default:
		error("primary expected");
	}
}

double secondary()                             //SQRT OVERHAULD CODE HERE!!!
{
    double left = primary(); //is null if sqrt called
    Token t = ts.get();        // get the next token from token stream
    Token t2;
    double d;

        while(true) {

        switch (t.kind) {
            case square_root:

                t2 = ts.get(); //make sure '(' is next token
                if (t2.kind != '(') 
                            error("'(' missing in declaration sqrt ");

                d = expression(); 
                left = sqrt(d);

                cout << endl << "new output works: " << left << endl;

                t = ts.get();

                if (t.kind != ')') //make sure ')' is last token in call to sqrt
                        error("')' expected");

                t = ts.get();
                break;

           default: 
                ts.unget(t);    // put t back into the token stream
                return left;
        }
    }
}
double term()
{
    double left = secondary();
    while(true) {
        Token t = ts.get();
        switch(t.kind) {
        case '*':
            left *= primary();
            break;
        case '/':
        {   double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            break;
        }
        default:
            ts.unget(t);
            return left;
        }
    }
}
//------------------------------------------------------------------------------
double expression()
{
    double left = term();
    while(true) {
        Token t = ts.get();
        switch(t.kind) {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        default:
            ts.unget(t);
            return left;
        }
    }
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error ("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	double d = expression();
	names.push_back(Variable(name,d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "  --  ";
const string result = "= ";

void calculate()
{
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
{
 cout << "Welcome to our simple calculator. Please enter expressions using floating-point numbers." << endl;
  cout << "Available operators: +, -, *, /, (), %." << endl;
        cout << "Use '=' to print result. Use 'q' to exit." << endl << endl;
		define_name("k", 1000);
	try {
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}
}
