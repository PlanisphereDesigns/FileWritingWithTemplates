/*Guards*/
#ifndef FILEWRITER_H
#define FILEWRITER_H

/*Set the namespace.*/
using namespace std;

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

/*The template class is both defined and impelented in the header file.*/
template<typename Generic>
class Writer {
	public:
	
		inline Writer() {
			/*Nothing in the constructor.*/
		}

		inline ~Writer() {
			cout << "I've been destructed!" << endl;
		}

		inline void addItem(Generic myItem) {
			myStoredGenericItems.push_back(myItem);
		}

		inline void writeItemToFile() {
			
			ofstream out(fileName);
			out << "The file is called " << fileName << endl;
			for (int i = 0; i < int(myStoredGenericItems.size()); i++) {
				out << myStoredGenericItems.at(i) << " | ";
			}
			out.close();
			cout << "File successfully written.  Look for the text file." << endl;
		}

		inline void printVectorItems() {
			cout << "File name is " << fileName << endl;
			for (int j = 1; j < int(myStoredGenericItems.size()); j++) {
				cout << "File item number  " << j << " is " << myStoredGenericItems.at(j)<< "! " << endl;
			}
		}

		inline int getVectorSize() {
			return int(myStoredGenericItems.size());
		}

		inline void setFileName(string myFileName) {
			fileName = myFileName + ".txt";
		}

	private:
		/*Variables here.  Have to store all the variables inside of one data structure in order to
		get them all into the file.*/
		vector<Generic> myStoredGenericItems;
		string fileName = "genericfile.txt";
		
};



#endif