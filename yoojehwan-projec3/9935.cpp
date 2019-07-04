#include <iostream>
#include <deque>
#include <stack>

using namespace std;

string str[2];
deque<char> dq;
stack<char> q;
int idx;
int last;
bool boom;

int main(void)
{
  ios::sync_with_stdio(false);

  for (int i = 0; i < 2; i++) 
    cin >> str[i];

  last = idx = str[1].length() - 1;

  for (char c : str[0]) {
    idx = last;
    dq.push_back(c);
    while(!dq.empty()) {
      if (dq.back() == str[1][idx]) {
        idx--;
        q.push(dq.back());
        dq.pop_back();
        if (idx < 0) {
          boom = true;
          break;
        }
      }
      else
        break;
    }
    if (boom) {
      while(!q.empty()) q.pop();
      boom = false;
    }
    else {
      while (!q.empty()) {
        dq.push_back(q.top());
        q.pop();
      }
    }
  }

  if (dq.empty())
    cout << "FRULA";
  else {
    while(!dq.empty()) {
      cout << dq.front();
      dq.pop_front();
    }
  }
  cout << endl;
}
