#include <iostream> //cout
#include <string> //string, stol
#include <string.h> 
#include <stdlib.h> //strtoull
#include <cstring> //c_str()

using namespace std;

//Forward Declarations
void byteToBinaryStr(unsigned char, char*);
char binaryOut[9];
//The Base 64 Output
static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'};

void byteToBinaryStr(unsigned char num, char* rstr)
{
	 // declare some temporary variables to work with
	char resultStr[8];
	char tempStr[8];
	unsigned char tnum = num;
	unsigned char remainder;
	int cnt = 8;
	
	strncpy(resultStr, "", 8);
	while(cnt != 0){
		remainder = tnum % 2;
		tnum = tnum / 2;
		switch (remainder){
			case 0:
				strncpy(tempStr, "0", 8);
				break;
			case 1:
				strncpy(tempStr, "1", 8);
				break;
		}
		strncat(tempStr, resultStr, 8);
		strncpy(resultStr, tempStr, 8);
		cnt--;
		
	}
	
	
	strncpy(rstr, resultStr, 8);
}

void encode(){
	//Declaring variables
	string myString;
  string bigString;
  int myNum;
  unsigned char tempByte;
  char * pEnd;
  unsigned long long int num1;
  
	//Getting user input
  cout << "Enter text to convert to ASCII: ";
  cin >> myString;
  cout << endl << "Original Data: " << myString << endl;
  
  //Arrays to store my values for later
  int myArray[myString.length()];
	unsigned long long int myArray2[myString.length()*2];
  string myArrayBinary8[myString.length()];
  string myArrayBinary6[(myString.length())*2];
  
  //Getting ASCII codes in decimal
  for(int i = 0; i < myString.length(); i++){
    char temp = myString.at(i);
    myNum = int(temp);
    myArray[i] = myNum;
  }
  cout << "ASCII Codes:   ";
  //Displaying the results for ASCII
  for(int i = 0; i< myString.length(); i++){
    cout << myString.at(i) << " = " << myArray[i] << "   ";
  }
  
  cout << endl << "In Binary:     ";
  //Converting the decimals from earlier into binary
  for(int i = 0; i < myString.length(); i++){
    tempByte = myArray[i];
    byteToBinaryStr(tempByte, (char*)&binaryOut);
    myArrayBinary8[i] = binaryOut;
  }
  //Displaying Binary results
  for(int i=0; i<myString.length(); i++){
    cout << myArrayBinary8[i] << " ";
  }
  cout << endl << endl << "Groups of 6" << "        " << "Base 10" << "        " << "Base 64" << endl << "___________        _______        _______" << endl;
  
  //Putting the binary into one long string to break up into groups of 6 bits
  for(int i=0; i<myString.length(); i++){
    bigString += myArrayBinary8[i];
  }
  
	//Displaying all the final outputs
  for(int i=0; i<bigString.length(); i+=6){
		int j=0;
    string temp = "";
		temp = bigString.substr(i,6);
		while(temp.length() < 6){
			temp += "0";
		}
   
		string x = temp;
		char const* y = x.c_str();
		
		num1 = strtoll(y, &pEnd, 2);
		myArray2[j] = num1;
		
		cout << "   " << temp << "            " << num1 << "             " <<  encoding_table[num1] << endl;
		j++;
  }
}

int main(int argc, char* argv[]){
	string answer;
	encode();
}