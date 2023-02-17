#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	system("color 2A");
	cout << "Please drag and drop .wbfs file onto this console window and press <Enter>" << endl;
	std::string innyz = "";
	while (1){
		cout << "\nMaster, gimme absolute file path or 'q' to quit" << endl;
		getline(cin, innyz);
		if (innyz == "") continue;
		if (innyz == "q") break;

		// should be file
		int len = innyz.length();
		if (innyz[0] == '"' && len > 2 && innyz[len - 1] == '"'){
			innyz = innyz.substr(1, len - 2); // strip quotes
		}

		// Fun fact: using ios::ate when opening a file >= 4 GB will fail. Open without ::ate then seekg to end to get size.
		ifstream ifs(innyz, ios::in | ios::binary);
		if (!ifs.is_open()){
			cout << "Error: path to WBFS invalid or file not openable" << endl;
			ifs.close();
			continue;
		}

		ifs.seekg(0, ifs.end);
		unsigned long long flen = ifs.tellg();
		if (flen < 800){
			cout << "File size: " << flen << " bytes" << endl;
			cout << "Error: file too small to contain valid WBFS header info; expecting 800 Bytes to properly read the ID/title." << endl;
			ifs.close();
			continue;
		}

		ifs.seekg(0, ios::beg); // read start to end of ID
		char buffer[800];
		ifs.read(buffer, 800);

		if (buffer[0] != 'W' || buffer[1] != 'B' || buffer[2] != 'F' || buffer[3] != 'S'){
			cout << "Warning: file header does not start with \"WBFS\" and the following ID may not be accurate." << endl;
		}

		// read buffer into string until reaches a \0
		std::string ID = "";
		for (int xint = 512; xint < 535; xint++){
			if (buffer[xint] == '\0') break;
			ID += buffer[xint];
		}
		// longest game title supposedly is 103 chars in Japanese (206 bytes if UTF-16), we'll allow room for 256 to be safe :)
		std::string title = "";
		for (int xint = 544; xint < 800; xint++){
			if (buffer[xint] == '\0') break;
			title += buffer[xint];
		}


		// success!
		cout << "Game title: " << title << endl;
		cout << "Game ID:    " << ID << endl;


		ifs.close();
	}
}