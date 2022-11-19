#include <iostream>
#include <stdlib.h>
using namespace std;

//Class tokenType - List the valid characters that braninkfuck uses
enum tokenType    {
    LT,
    RT,
    PLUS,
    MINUS,
    DOT,
    COMMA,
    LBRACE,
    RBRACE,
    EoF, 
    ILEGAL
};


//LEXER
class Lexer {
    public:
        string input;
        Lexer(string _input){
            this->input = _input;
        };
};


string currentChar(Lexer lexer){
    return lexer.input;
}



//Class Tokem - Give us a token
class Token{
    public: 
        tokenType type;
        string lexem; 
    public:
        //Asign to a tokenType a character
        Token(tokenType _type, string _lexem);
};

Token::Token(tokenType tp, string lx){
    this->type = tp;
    cout << this->type;
    this->lexem = lx;
}

 
Token nextToken(Lexer lexer){
    string current = currentChar(lexer);
    int n;
    if (current == ">"){    return Token(RT,     ">");  }
    if (current == "<"){    return Token(LT,     "<");  }
    if (current == "+"){    return Token(PLUS,   "+");  }
    if (current == "-"){    return Token(MINUS,  "-");  }
    if (current == "."){    return Token(DOT,    ".");  }
    if (current == ","){    return Token(COMMA,  ",");  }
    if (current == "]"){    return Token(LBRACE, "]");  }
    if (current == "["){    return Token(RBRACE, "[");  }
    if (current == "0"){    return Token(EoF,    "0");  }
    else{   return  Token(ILEGAL, "ILEGAL");    }
};



int main(){
    string input;
    cout << "Bienvenido" << endl;
    cin >> input;
    Lexer *lex = new Lexer(input);
    Token tk2 = nextToken(*lex);
    cout << "El token que has creado es : " << " de typo: " << tk2.type  << " y es: " << tk2.lexem << endl;
}
