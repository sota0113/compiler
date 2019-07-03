#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// トークンの型を表す値
enum {
	TK_NUM = 256, //整数トークン
	TK_EOF,
};

// トークンの型

typedef struct {
	int ty;		//トークンの型
	int val;	//tyがTK_NUMの場合、その数値
	char *input;	//トークン文字列(エラーメッセージ用)
} Token;

// トークナイズした結果のトークン列の保存先配列
// 0-100の101個の分の保存領域
Token tokens[100];

// エラーを報告するための関数
void error(char *fmt, ...) { //可変長引数。"..."が相当。char型のfmtポインタを定義。ポインタ変数のサイズはmax32bitの４byteまで
	va_list ap;	// "va_list"は、任意個の引数を1つの変数に変換。char*型。４バイトの倍数で区切る
	va_start(ap, fmt);	//可変個引数リストapを初期化する。可変引数のデータ型としてfmtを指定
	vfprintf(stderr, fmt, ap); //可変長引数のfprintf
	fprintf(stderr, "\n");
	exit(1);
}

// pが指している文字列をトークンに分割してtokensに保存
void tokenize(char *p){
	int i = 0;
	while (*p) {
		//空白文字スキップ
		if (isspace(*p)) {
			p++;		//次の文字へ
			continue;
		}

		if (*p == '+' || *p == '-' ) {
			tokens[i].ty = *p;	//トークン型の変数にメモリアドレスを入れている？？？
			tokens[i].input = p;	//トークンの文字列を代入
			i++;	//次の配列番地へ
			p++;	//次の文字へ
			continue;
		}

		if (isdigit(*p)) {
			tokens[i].ty = TK_NUM;	//TK_NUMを代入。enumの定義から256になる？？
			tokens[i].input = p;	//トークンの文字列を代入
			tokens[i].val = strtol(p,&p, 10);	//基数10でpつまり(strの？)数値をintに変換
			i++;	//次の配列番地へ
			//p++は不要
			continue;	
		}

		error("トークナイズできません1: %s", p);
		exit(1);

	}

	tokens[i].ty = TK_EOF;
	tokens[i].input = p;
}


//main関数

int main (int argc, char **argv) {
	if (argc != 2) {
		printf("引数の数が正しくありません。");
		return 1;
	}

	// トークナイズを実行
	tokenize(argv[1]);


	// アセンブリの前半部分を出力
	printf(".intel_syntax noprefix\n");
	printf(".global main\n");
	printf("main:\n");

	// 式の最初は数で無ければならないので、チェックして最初のmov命令を出力。

	if (tokens[0].ty != TK_NUM) {
		error("最初の項が整数ではありません");
	}

	printf("	mov rax, %d\n",tokens[0].val);
	
	// `+ <整数>`あるいは`- <整数>`というトークンの並びを消費しつつ、アセンブリを出力
	
	int i = 1;
	while (tokens[i].ty != TK_EOF) {
		if (tokens[i].ty == '+' ) {
			i++;
			if(tokens[i].ty != TK_NUM ) {
				error("予期しないトークンです：%s",tokens[i].input);
			}
			printf("	add rax, %d\n", tokens[i].val);
			i++;
			continue;
		}
		if (tokens[i].ty == '-' ) {
			i++;
			if(tokens[i].ty != TK_NUM ) {
				error("予期しないトークンです：%s",tokens[i].input);
			}
			printf("	sub rax, %d\n",tokens[i].val);
			i++;
			continue;
		}
		error("予期しないトークンです:%s",tokens[i].input);
	}
	printf("	ret\n");
	return 0;
}

