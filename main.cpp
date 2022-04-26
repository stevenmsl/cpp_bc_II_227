#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol227;

/*
Input: "3+2*2"
Output: 7
*/

tuple<string, int>
testFixture1()
{
  return make_tuple("3+2*2", 7);
}

/*
Input: " 3/2 "
Output: 1
*/

tuple<string, int>
testFixture2()
{
  return make_tuple(" 3/2 ", 1);
}

/*
Input: " 3+5 / 2 "
Output: 5
*/

tuple<string, int>
testFixture3()
{
  return make_tuple(" 3+5 / 2 ", 5);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << sol.calculate(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << sol.calculate(get<0>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Expect to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << sol.calculate(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}