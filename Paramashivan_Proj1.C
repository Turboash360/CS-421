#include <iostream>
#include <string>

using namespace std;

//Purpose: To search for Uppercase
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

//Purpose: To Search for the Lowercase
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

//Purpose: To Search for the Digits
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

//Purpose: To Search for Special characters
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


//Purpose: To Check is the password is valid or not.
void isValid(string password, char x, char U[], char L[], char D[], char S[], int index, int UpperCaseCounter, int LowerCaseCounter, int DigitsCounter, int SpecialCounter, int ASCIICounter)
{
  if(index == password.length()) //Checks if the index is equal to the password length.
    {
      //While all the requirement is met then the password is valid, otherwise the password is invalid.
      while(index <= 10 && index >= 8)
	{
	  while(UpperCaseCounter >= 2 && LowerCaseCounter >=1 && DigitsCounter >= 2 && SpecialCounter >= 1)
	    {
	      cout << " ---------> (F) \n";
	      cout << "\n The password is valid. \n";
	      return;
	    }
	  cout << "-----------> (q error)";
	  cout << "\n The password is invalid. \n";
	  return;
	}
      while(index > 10)
	{
	  cout << "\n The password is too long. \n";
	  return;
	}
      while(index < 8)
	{
	  cout << "\n The password is too short. \n";
	  return;
	}
      
    }
  else
    {
      //Checks each character of the password string to make sure if the password is valid.
      //Each function is called recursively.
      if(password[index] == Capital(password, U, index))
	{
	  index += 1;
	  cout << "---------->  (U) ";
	  UpperCaseCounter += 1;
	  isValid(password, x, U, L, D, S, index, UpperCaseCounter, LowerCaseCounter, DigitsCounter, SpecialCounter, ASCIICounter);
	}
      else if(password[index] == Small(password, L, index))
	{
	  index += 1;
	  cout << "---------->  (L) ";
	  LowerCaseCounter += 1;
	  isValid(password, x, U, L, D, S, index, UpperCaseCounter, LowerCaseCounter, DigitsCounter, SpecialCounter, ASCIICounter);
	}
      else if(password[index] == Digits(password, D, index))
	{
	  index += 1;
	  cout << "---------->  (D) ";
	  DigitsCounter += 1;
	  isValid(password, x, U, L, D, S, index, UpperCaseCounter, LowerCaseCounter, DigitsCounter, SpecialCounter, ASCIICounter);
	}
      else if(password[index] == Special(password, S, index))
	{
	  index += 1;
	  cout << "---------->  (S) ";
	  SpecialCounter += 1;
	  isValid(password, x, U, L, D, S, index, UpperCaseCounter, LowerCaseCounter, DigitsCounter, SpecialCounter, ASCIICounter);
	}
      else
	{
	  index += 1;
	  cout << "---------->  (C) ";
	  ASCIICounter += 1;
	  isValid(password, x, U, L, D, S, index, UpperCaseCounter, LowerCaseCounter, DigitsCounter, SpecialCounter, ASCIICounter);
	}
    }
}

int main()
{
  char x; //Combination of ASCII Characters
  char U[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  char L[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char D[10] = {'0','1','2','3','4','5','6','7','8','9'};
  char S[4] = {'@', '%', '#', '$'}; //Special Characters

  string password;
  cout << "Use atleast 2 Uppercases, 1 Lowercases, 1 Special Characters (@, %, #, $), 2 Digits in order for the password to be valid." << endl;
  cout << "U - Uppercase" << endl;
  cout << "L - Lowercase" << endl;
  cout << "S - Special Characters"<< endl;
  cout << "D - Digits" << endl;
  cout << "C - Any Combination of ASCII Characters. U,L,S,D are all subsets of C. " << endl;


  cout << "Enter your password: ";
  cin >> password;

  //Initialize all to 0
  int index = 0; //Character counter
  int UpperCaseCounter = 0;
  int LowerCaseCounter = 0;
  int DigitsCounter = 0;
  int SpecialCounter = 0;
  int ASCIICounter = 0;

  cout << "---------->  (Start State) "; //The Starting State.
  
  isValid(password, x, U, L, D, S, index, UpperCaseCounter, LowerCaseCounter, DigitsCounter, SpecialCounter, ASCIICounter);
  return 0;
}
