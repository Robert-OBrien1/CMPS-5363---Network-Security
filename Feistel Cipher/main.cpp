// Robert O'Brien, Taylor Mendez, Aquella Warner
// CMPS 4663/5363
// 04/26/2022

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdint> 
using namespace std;

// ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ Function Prototypes ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬
unsigned int getkey(unsigned int &k);
string getplaintext(string &plaintext);
int string_to_int(string value);
string feistel(string plaintext, int key, int index);


union left
{
    unsigned int decimal;
    char letter[2];
};
union right
{
    unsigned int decimal;
    char letter[2];
};
union full
{
    unsigned int decimal;
    char letter[4];
};

// // ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ Main Driver ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬
int main() 
{

  
  // key variable
  unsigned int k;
  // plaintext variable
  string plaintext;
  
  // get the key from user
   k = getkey(k);
  cout << "Your Key = " << k << '\n';
  cout << hex << k << '\n';
  int keys[4];
  keys[0] = k;
  for (int i = 1; i < 4; i++){
    int x = k >> 12;
    int y = k << 4;
    k = x ^ y;
    k = (k & 0x0000FFFF);
    keys[i] = k;
    cout << keys[i] << endl;
  }
  // get the plaintext from user
  plaintext = getplaintext(plaintext);
  // int keys[4] = {32773, 88, 1408, 22528};
  cout << "\n" << "Encrypted text: ";
  for (int i = 0; i < plaintext.length(); i+=4)
  {
    string tempPlaintext = "";
    for (int j = 0; j < 4; j++)
    {
      tempPlaintext.push_back(plaintext[i+j]);
    }
    //cout << "\n" << tempPlaintext;
    for (int k = 0; k < 4; k++)
    {
        tempPlaintext = feistel(tempPlaintext, keys[k], k);
    }
  }
  cout << "\n";
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
  return k + 32768;
}

string getplaintext(string &plaintext)
{
  // index for while loop
  int i = 0;
  // temp string variable for while loop
  string temp;
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

  // while plaintext % 4, add plaintext[i] to the end until plaintext is multiple of 4
  while(true)
  {
    temp = plaintext;
    if(plaintext.length() % 4 > 0)
    { 
      plaintext = temp + plaintext[i];
      i++;
    }
    else
      break;
  }

  cout << "\nFinal plaintext = " << plaintext;
  return plaintext;
}

int string_to_int(string value)
{
  string finalstring ="";
  for(int i = 0; i < value.length(); i++)
    {
      finalstring += to_string(value[i]);
    }
  return stoi(finalstring);
}

// takes 4 characters of a time of plaintext
string feistel(string plaintext, int key, int index){
  // put full word in union
  union full word;
  word.letter[0] = plaintext[0];
  word.letter[1] = plaintext[1];
  word.letter[2] = plaintext[2];
  word.letter[3] = plaintext[3];
  //cout << "\nword before flip: " << word.decimal;

  word.letter[0] = plaintext[0];
  word.letter[1] = plaintext[1];
  word.letter[2] = plaintext[3];   // flip last 2 letters
  word.letter[3] = plaintext[2];   // flip last 2 letters
  //cout << "\nword after flip: " << word.decimal;

  // put left half
  union left left;
  left.letter[0] = plaintext[1];
  left.letter[1] = plaintext[0];
  //cout << "\nleft word: " << left.decimal;


  // put right half
  union left right;
  right.letter[0] = plaintext[2];
  right.letter[1] = plaintext[3];
  //cout << "\nright word: " << right.decimal;

  // xor right half with key1
  right.decimal = right.decimal ^ key;
  //cout << "\nfirst xor with key: " << right.decimal;
  // xor right half with left original
  right.decimal = right.decimal ^ left.decimal;
  //cout << "\nsecond xor with key: " << right.decimal;

  // for printing 
  // word.letter[0] = right.letter[0];
  // word.letter[1] = right.letter[1];
  // word.letter[2] = plaintext[3];
  // word.letter[3] = plaintext[2];
  
  word.letter[0] = plaintext[2];
  word.letter[1] = plaintext[3];
  word.letter[2] = right.letter[1];
  word.letter[3] = right.letter[0];
  // cout << "\nend round: "<< word.decimal << "\n";
  if (index == 3)
    cout << word.decimal;

  string temp = "";
  char chararray[4];
  for(int i = 0; i < 4; i++){
    chararray[i] = word.letter[i];
    temp.push_back(chararray[i]);
  }
  return temp;
}
