#include <iostream>
#include "inord_list.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc,char** argv) {
	list list;
	ifstream myfile (argv[1]);
	string L;
	int l = 0;
	int NOC = 0;
	while (getline(myfile,L)){
		l = l + 1;
		NOC = list.read(L,l);
		L.clear();
	}
	NOC = NOC - 1;
	ifstream myfile2 (argv[2]);
	string str;
	while (getline(myfile2,str)){
		istringstream iss (str);
		string cmd;
		iss >> cmd;
		if (cmd.compare("wordCount") == 0){
			string z;
			iss >> z;
			if (iss)
				cout << "Incorrect number of arguments" << endl;
			else
				cout << list.NOE() << " words" << endl;

		} else if (cmd.compare("distWords") == 0){
			string z;
			iss >> z;
			if (iss)
				cout << "Incorrect number of arguments" << endl;
			else
				cout << list.NOED() << " distinct words" << endl;

		} else if (cmd.compare("charCount") == 0){
			string z;
			iss >> z;
			if (iss)
				cout << "Incorrect number of arguments" << endl;
			else
				cout << NOC << " characters" << endl;
			
		} else if (cmd.compare("frequentWord") == 0){
			string word1;
			iss >> word1;
			if (iss){
				cout << "Incorrect number of arguments" << endl;
			}else{
			cout << endl;
			}
		} else if (cmd.compare("countWord") == 0){
			string word1,z;
			iss >> word1;
			iss >> z;
			if (iss || word1 == "")
				cout << "Incorrect number of arguments" << endl;
			else
				cout << word1 << " is repeated " << list.count(word1) << " times" << endl;

		} else if (cmd.compare("starting") == 0){
			string word2,z;
			iss >> word2;
			iss >> z;
			if (iss || word2 == "")
				cout << "Incorrect number of arguments" << endl;
			else {
				int s1 = 0;
				int q = 0;
				for (int i = 0;i < list.NOE();i++)
					if (list.fnd(i).find(word2) != string::npos && list.fnd(i).find(word2) == 0){
						for (int j = 0;j < i;j++)
							if (list.fnd(i).compare(list.fnd(j)) == 0)
								q = q + 1;
						if (q == 0)
							s1 = s1 + 1;
					}
				if (s1 == 0)
					cout << "Word not found" << endl;
				else {
				int x[s1];
				int s2 = 0;
				int q2 = 0;
				for (int v = 0;v < list.NOE();v++)
					if (list.fnd(v).find(word2) != string::npos && list.fnd(v).find(word2) == 0){
						for (int b = 0;b < v;b++)
							if (list.fnd(v).compare(list.fnd(b)) == 0)
								q2 = q2 + 1;
						if (q2 == 0){
							x[s2] = v;
							s2 = s2 + 1;
						}
					}
				list.arr(x,s2);
				for (int i = 0;i < s2;i++){
					cout << list.fnd(x[i]) << ": " << list.count(list.fnd(x[i]));
					if (i != s2-1)
						cout << "   ";
				}
				cout << endl;
			}
			}
		} else if (cmd.compare("containing") == 0){
			string word2,z;
			iss >> word2;
			iss >> z;
			if (iss || word2 == "")
				cout << "Incorrect number of arguments" << endl;
			else {
				int s1 = 0;
								int q = 0;
								for (int i = 0;i < list.NOE();i++)
									if (list.fnd(i).find(word2) != string::npos){
										for (int j = 0;j < i;j++)
											if (list.fnd(i).compare(list.fnd(j)) == 0)
												q = q + 1;
										if (q == 0)
											s1 = s1 + 1;
									}
								if (s1 == 0)
									cout << "Word not found" << endl;
								else {
								int x[s1];
								int s2 = 0;
								int q2 = 0;
								for (int v = 0;v < list.NOE();v++)
									if (list.fnd(v).find(word2) != string::npos){
										for (int b = 0;b < v;b++)
											if (list.fnd(v).compare(list.fnd(b)) == 0)
												q2 = q2 + 1;
										if (q2 == 0){
											x[s2] = v;
											s2 = s2 + 1;
										}
									}
								list.arr(x,s2);
								for (int i = 0;i < s2;i++){
									cout << list.fnd(x[i]) << ": " << list.count(list.fnd(x[i]));
									if (i != s2-1)
										cout << "   ";
								}
								cout << endl;
							}
			}
		} else if (cmd.compare("search") == 0){
			string word2,z;
			iss >> word2;
			iss >> z;
			if (iss || word2 == "")
				cout << "Incorrect number of arguments" << endl;
			else {
				int s1 = 0;
								int q = 0;
								for (int i = 0;i < list.NOE();i++)
									if (list.fnd(i).find(word2) != string::npos){
										for (int j = 0;j < i;j++)
											if (list.fnd(i).compare(list.fnd(j)) == 0)
												q = q + 1;
										if (q == 0)
											s1 = s1 + 1;
									}
								if (s1 == 0)
									cout << "Word not found" << endl;
								else {
								int x[s1];
								int s2 = 0;
								int q2 = 0;
								for (int v = 0;v < list.NOE();v++)
									if (list.fnd(v).find(word2) != string::npos){
										for (int b = 0;b < v;b++)
											if (list.fnd(v).compare(list.fnd(b)) == 0)
												q2 = q2 + 1;
										if (q2 == 0){
											x[s2] = v;
											s2 = s2 + 1;
										}
									}
								list.arr(x,s2);
								for (int i = 0;i < s2;i++){
									int L = 0;
									cout << list.fnd(x[i]) << ": lines";
									for (int j = 0;j < list.NOE();j++){
										if (low(list.fnd(x[i])).compare(low(list.fnd(j))) == 0){
											if (L != list.findl(j)){
												cout << " " << list.findl(j);
												L = list.findl(j);
											}
										}
									}
									if (i != s2-1)
										cout << endl;
								}
								cout << endl;
							}
			}
		} else {
			cout << "Undefined command" << endl;
		}
		str.clear();
	}
	return 0;
}
