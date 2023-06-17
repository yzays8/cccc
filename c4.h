typedef enum {
  TK_RESERVED,
  TK_NUM,
  TK_EOF,
} TokenKind;

typedef enum {
  ND_ADD,
  ND_SUB,
  ND_MUL,
  ND_DIV,
  ND_NUM,
  ND_EQ,
  ND_NE,  // Not Equal
  ND_LE,  // Less than or Equal
  ND_LT,  // Less than
} NodeKind;

typedef struct Token Token;
struct Token {
  TokenKind kind;
  Token *next;
  int val;  // If kind is TK_NUM, the value is stored here.
  char *str;
  int len;
};

typedef struct Node Node;
struct Node {
  NodeKind kind;
  Node *lhs;
  Node *rhs;
  int val;  // If kind is ND_NUM, the value is stored here.
};

extern Token *token;
extern char *user_input;

Token *tokenize();
Node *expr();
void gen(Node *node);
