/*
	Takes the input as "float" or "255" and converts it to the other


	Float Format: 
		input: 	float	0.1f, 0.3f, 0.34f, 1.0f
		output: 255, 255, 255, 255\n

	Byte Format: 
		input: 	byte	255, 255, 255, 255
		output: 0.1f, 0.3f, 0.34f, 1.0f

*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<string>
using namespace std;

// Initializers
short convertToByte(string strNum);
string convertToFloat(string strNum);
void output(string output);


int main(int argc, char *argv[]){
	//Variables
	int lastLet = 0;
	short currByte;			// don't need more than 255 (2^8)
	string currFloat;	
	string result = "";
	string word;
	string filename = argv[1];
	fstream file;

	// Opens text file to go through it 
	file.open(filename.c_str());
	file >> word;

	if(word == "bytes"){	
		// Breaks down format into just floats 
		for(int i = 0; i < 4; i++){
			file >> word;
			lastLet = word.length() - 1;
			if(word[lastLet] == ','){
				word.pop_back();
			}
			
			// Formatting
			currFloat = convertToFloat(word);
			result.append(currFloat);
			result.append("f, ");
		}

	} else if(word == "floats"){
		// Breaks down format into just floats 
		for(int i = 0; i < 4; i++){
			file >> word;		
			word.pop_back();
			lastLet = word.length() - 1;
			if(word[lastLet] == 'f'){
				word.pop_back();
			}
			
			// Formatting
			currByte = convertToByte(word);
			result.append(to_string(currByte));
			result.append(", ");
		}
	}

	// Removes the last ", "
	result.pop_back();
	result.pop_back();
	
	cout << result << endl;
	return 0;
}


short convertToByte(string strNum){
	float num;
	short ans;

	num = stof(strNum);
	ans = num * 255;

	return ans;
}

string convertToFloat(string strNum){
	// Variables
	float num;
	float ans;
	stringstream stream;
	string sAns;

	// Converting and solving
	num = stoi(strNum);		
	ans = num / 255; 

	// Formatting
	stream << fixed << setprecision(2) << ans;
	sAns = stream.str();

	return sAns;
}

