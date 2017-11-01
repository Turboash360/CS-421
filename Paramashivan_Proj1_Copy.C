#include <iostream>
#include <string>

using namespace std;


char Capital(string password, char U[], int index)
{
  for(int i = 0; i < 26; i++)
    {
      if(password[index] == U[i])
	{
	  return U[i];
	}
    }
}

char Small(string password, char L[], int index)
{
  for(int i = 0; i < 26; i++)
    {
      if(password[index] == L[i])
	{
	  return L[i];
	}
    }
}

char Digits(string password, char D[], int index)
{
  for(int i = 0; i < 10; i++)
    {
      if(password[index] == D[i])
	{
	  return D[i];
	}
    }
}

char Special(string password, char S[], int index)
{
  for(int i = 0; i < 4; i++)
    {
      if(password[index] == S[i])
	{
	  return S[i];
	}
    }
}



void isValid(string password, char x, char U[], char L[], char D[], char S[], int index, int UpperCaseCounter, int LowerCaseCounter, int DigitsCounter, int SpecialCounter)
{
  if(index == password.length())
    {
      cout << password << endl;
      while(index <= 10 && index >= 8)
	{
	  while(UpperCaseCounter >= 2 && LowerCaseCounter >=1 && DigitsCounter >= 2 && SpecialCounter >= 1)
	    {
	      cout << "The password is valid. \n";
	      return;
	    }
	  cout << "The password is invalid. \n";
	  return;
	}
      while(index > 10)
	{
	  cout << "The password is too long. \n";
	  return;
	}
      while(index < 8)
	{
	  cout << "The password is too short. \n";
	  return;
	}
      
    }
  else
    {
      
      if(password[index] == Capital(password, U, index))
	{
	  index += 1;
	  cout << "Moving to state " << index << endl;
	  UpperCaseCounter += 1;
	  isValid(password, x, U, L, D, S, index, UpperCaseCounter, LowerCaseCounter, DigitsCounter, SpecialCounter, ASCIICounter);
	}
      else if(password[index] == Small(password, L, index))
	{
	  index += 1;
	  cout << "Moving to state " << index << endl;
	  LowerCaseCounter += 1;
	  isValid(password, x, U, L, D, S, index, UpperCaseCounter, LowerCaseCounter, DigitsCounter, SpecialCounter, ASCIICounter);
	}
      else if(password[index] == Digits(password, D, index))
	{
	  index += 1;
	  cout << "Moving to state " << index << endl;
	  DigitsCounter += 1;
	  isValid(password, x, U, L, D, S, index, UpperCaseCounter, LowerCaseCounter, DigitsCounter, SpecialCounter, ASCIICounter);
	}
      else if(password[index] == Special(password, S, index))
	{
	  index += 1;
	  cout << "Moving to state " << index << endl;
	  SpecialCounter += 1;
	  isValid(password, x, U, L, D, S, index, UpperCaseCounter, LowerCaseCounter, DigitsCounter, SpecialCounter, ASCIICounter);
	}
      else
	{
	  index += 1;
	  cout << "Moving to state " << index << endl;
	  ASCIICounter += 1;
	  isValid(password, x, U, L, D, S, index, UpperCaseCounter, LowerCaseCounter, DigitsCounter, SpecialCounter, ASCIICounter);
	}
    }
}

int main()
{
  char x;
  char U[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  char L[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char D[10] = {'0','1','2','3','4','5','6','7','8','9'};
  char S[4] = {'@', '%', '#', '$'};

  string password;
  cout << "Enter your password: ";
  cin >> password;


  int index = 0;
  int UpperCaseCounter = 0;
  int LowerCaseCounter = 0;
  int DigitsCounter = 0;
  int SpecialCounter = 0;
  int ASCIICounter = 0;
  isValid(password, x, U, L, D, S, index, UpperCaseCounter, LowerCaseCounter, DigitsCounter, SpecialCounter, ASCIICounter);
  return 0;
}
