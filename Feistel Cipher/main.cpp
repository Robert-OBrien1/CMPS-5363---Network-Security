#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ Function Prototypes ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬
unsigned int getkey(unsigned int &k);
string getplaintext(string &plaintext);


// // ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ Main Driver ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬
int main() 
{
  // key variable
  unsigned int k;
  // plaintext variable
  string plaintext;

  // get the key from user
  k = getkey(k);
  // get the plaintext from user
  plaintext = getplaintext(plaintext);

  return 0;
}


// ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ Function Definitions ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

unsigned int getkey(unsigned int &k)
{
  // get key from keyboard
  // check if key within range
  cout << "\n\nEnter key size --→\t0 ≤ key < 2^22\n\n";
  while(true)
  {
    // enter key size 
    cin >> k;
    // if input not an integer 
    if(cin.fail())
      cout << "\n\nIntegers only!\n\n";
    // check if k is 0 ≤ k < 2^24
    else if(0 <= k && k < 16777216)
      break;
    else
      cout << "\n\n!! Key not within range !!\n\nPlease Enter a valid key\n\n";
    cin.clear();
    cin.ignore(10000, '\n');
  }
  return k;
}

string getplaintext(string &plaintext)
{
  // get plaintext 
  cout << "\n\nEnter plaintext\n\n";
  // get line input and include white spaces
  getline(cin >> ws, plaintext);
  // print input plaintext
  cout << "\n\nPlaintext input = " + plaintext + "\n\n"; 
  // remove whitespace from plaintext
  plaintext.erase(remove(plaintext.begin(), plaintext.end(), ' '), plaintext.end());
  // print plaintext without spaces
  cout << "Plaintext input without spaces = " + plaintext;
  return plaintext;
}
