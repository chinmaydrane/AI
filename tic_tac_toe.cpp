#include <iostream>
#include <vector>
using namespace std;

int turn = 0;
vector<int> board(9, 2);

void display()
{
  cout << "\nBoard:\n";
  for (int i = 0; i < 9; i++)
  {
    if (board[i] == 3)
      cout << "X ";
    else if (board[i] == 5)
      cout << "O ";
    else
      cout << "B ";

    if ((i + 1) % 3 == 0)
      cout << endl;
  }
  cout << endl;
}

void go(int x)
{
  if (turn % 2 == 0)
    board[x] = 3;
  else
    board[x] = 5;
  turn++;
}

int make2()
{
  if (board[4] == 2)
    return 4;
  for (int i = 1; i <= 7; i += 2)
  {
    if (board[i] == 2)
      return i;
  }
  return -1;
}

int poswin(int n)
{
  vector<vector<int>> w = {{0, 1, 2}, {0, 3, 6}, {0, 4, 8}, {1, 4, 7}, {2, 5, 8}, {2, 4, 6}, {3, 4, 5}, {6, 7, 8}};
  if (n == 3)
  {
    for (int i = 0; i < 8; i++)
    {
      int prod = 1;
      for (int j = 0; j < 3; j++)
        prod *= board[w[i][j]];
      if (prod == 18)
      {
        for (int j = 0; j < 3; j++)
        {
          if (board[w[i][j]] == 2)
            return w[i][j];
        }
      }
    }
  }
  else
  {
    for (int i = 0; i < 8; i++)
    {
      int prod = 1;
      for (int j = 0; j < 3; j++)
        prod *= board[w[i][j]];
      if (prod == 50)
      {
        for (int j = 0; j < 3; j++)
        {
          if (board[w[i][j]] == 2)
            return w[i][j];
        }
      }
    }
  }
  return -1;
}

bool iswin(int n)
{
  vector<vector<int>> w = {{0, 1, 2}, {0, 3, 6}, {0, 4, 8}, {1, 4, 7}, {2, 5, 8}, {2, 4, 6}, {3, 4, 5}, {6, 7, 8}};
  if (n == 3)
  {
    for (int i = 0; i < 8; i++)
    {
      int prod = 1;
      for (int j = 0; j < 3; j++)
        prod *= board[w[i][j]];
      if (prod == 27)
        return true;
    }
  }
  else
  {
    for (int i = 0; i < 8; i++)
    {
      int prod = 1;
      for (int j = 0; j < 3; j++)
        prod *= board[w[i][j]];
      if (prod == 125)
        return true;
    }
  }
  return false;
}

int main()
{
  int x, p, m;

  cout << "Enter position for x: ";
  cin >> x;
  go(x);
  display();

  m = make2();
  go(m);
  display();

  cout << "Enter position for x: ";
  cin >> x;
  go(x);
  display();

  p = poswin(3);
  if (p != -1)
    go(p);
  else
  {
    m = make2();
    go(m);
  }
  display();

  cout << "Enter position for x: ";
  cin >> x;
  go(x);
  display();

  if (iswin(3))
  {
    cout << "You WIN!!!";
    return 0;
  }

  p = poswin(5);
  if (p != -1)
  {
    go(p);
  }
  else if (poswin(3) != -1)
  {
    go(poswin(3));
  }
  else
  {
    go(make2());
  }
  display();

  if (iswin(5))
  {
    cout << "I WIN!!!";
    return 0;
  }

  cout << "Enter position for x: ";
  cin >> x;
  go(x);
  display();

  if (iswin(3))
  {
    cout << "You WIN!!!";
    return 0;
  }

  p = poswin(5);
  if (p != -1)
  {
    go(p);
  }
  else if (poswin(3) != -1)
  {
    go(poswin(3));
  }
  else
  {
    go(make2());
  }
  display();

  if (iswin(5))
  {
    cout << "I WIN!!!";
    return 0;
  }

  cout << "Enter position for x: ";
  cin >> x;
  go(x);
  display();

  if (iswin(3))
  {
    cout << "You WIN!!!";
    return 0;
  }

  cout << "DRAW!!!";
  return 0;
}
// HI I am chinmay