#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <stack>
#include <cstring>
using namespace sol227;
using namespace std;

/*takeaways
  - have two stacks one for operands the other for operators
    to make the code easier to write
  - pay attention to the priority among operators
    - once we encountered the situation where the incoming
      operator has a lower priority than the one sitting
      on op of the operator stack it's time to evaluate
      the expression concerning the higher priority
      operator

*/

int Solution::calculate(string s)
{
  auto operands = stack<int>();
  auto ops = stack<char>();
  for (auto i = 0; i < s.size(); i++)
  {
    auto c = s[i];
    if (isdigit(c))
    {
      auto operand = string(1, c);
      /* retrieve the operand
         - make sure the i is pointing
           at the last digit char to
           avoid skip an extra char
           as we also make advance to
           the next char in the outer
           for loop
      */
      while (i + 1 < s.size() && isdigit(s[i + 1]))
        i++, operand.push_back(s[i]);
      operands.push(stoi(operand));
    }
    else if (c == '+' || c == '-' || c == '*' || c == '/')
    {
      /* incoming operator has a lower priority
         than the one sitting on the op of the
         stack - it's time to calculate the part
         of the expression concerning the operator
         sitting on top of the stack
      */
      if (!ops.empty() && higherPripority(ops.top(), c))
      {
        /* it's a stack so operand 2 is on top of
           operand 1
         */
        auto operand2 = pop(operands);
        auto operand1 = pop(operands);
        operands.push(calc(pop(ops), operand1, operand2));
      }
      ops.push(c);
    }
  }

  while (!ops.empty())
  {
    auto operand2 = pop(operands);
    auto operand1 = pop(operands);
    operands.push(calc(pop(ops), operand1, operand2));
  }

  return operands.top();
}

int Solution::calc(char op, int operand1, int operand2)
{
  switch (op)
  {
  case '+':
    return operand1 + operand2;
  case '-':
    return operand1 - operand2;
  case '*':
    return operand1 * operand2;
  case '/':
    return operand1 / operand2;
  }

  throw;
}
int Solution::pop(stack<int> &s)
{
  auto result = s.top();
  s.pop();
  return result;
}
char Solution::pop(stack<char> &s)
{
  auto result = s.top();
  s.pop();
  return result;
}
bool Solution::higherPripority(char op1, char op2)
{
  return op1 == '*' || op1 == '/' || op2 == '+' || op2 == '-';
}
