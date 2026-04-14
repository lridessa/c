#include "stdio.h"
#include <stack>
void tranfExp(char *exp, char *postexp);
int precedence(char op);
int calcExp(char *postexp);
using namespace std;
/********************************/
void tranfExp(char *exp, char *postexp)
{
    stack<char> opStack;
    int j = 0; // postexp的索引
    for(int i=0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if(c >= '0' && c <= '9') { // 如果是数字，直接添加到postexp
            postexp[j++] = c;
        } else if(c == '(') { // 左括号入栈
            opStack.push(c);
        } else if(c == ')') { // 右括号，弹出直到遇到左括号
            while(!opStack.empty() && opStack.top() != '(') {
                postexp[j++] = opStack.top();
                opStack.pop();
            }
            if(!opStack.empty()) {
                opStack.pop(); // 弹出左括号
            }
        } else { // 运算符
            while(!opStack.empty() && precedence(opStack.top()) >= precedence(c)) {
                postexp[j++] = opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }    
        while(!opStack.empty()) { // 最后将栈中剩余的运算符弹出
            postexp[j++] = opStack.top();
            opStack.pop();  
        }
        postexp[j] = '\0'; // 添加字符串结束符
}
int precedence(char op)  // 定义运算符优先级
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}
int calcExp(char *postexp)
{
    stack<int> numStack;
    for(int i=0; postexp[i] != '\0'; i++) {
        char c = postexp[i];
        if(c >= '0' && c <= '9') { // 如果是数字，入栈
            numStack.push(c - '0');
        } else { // 运算符，弹出两个数进行计算
            int b = numStack.top(); numStack.pop();
            int a = numStack.top(); numStack.pop();
            int result = 0;
            switch(c) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            numStack.push(result);
        }
    }
    return numStack.top();
}
/********************************/
int main()
{
    char exp[1000]="5*(4-2+1)+8/4";
    char postexp[1000];
    tranfExp(exp,postexp);
    printf("%s\n",postexp);//输出后缀表达式:542-1+*84/+
    printf("%d\n",calcExp(postexp));//输出表达式的值:17
    return 0;
}
