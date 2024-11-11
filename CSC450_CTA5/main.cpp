#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
// Append user input to file function
void appendToFile() {
	// prompt user to enter text to be added
    std::string userInput;
    std::cout << "Enter text to append to the file: ";
    std::getline(std::cin, userInput);

    // open the file in append mode as to not overwrite content
    std::ofstream outFile("CSC450_CT5_mod5.txt", std::ios::app);
    if (outFile.is_open()) {
    	// append user input with a newline
        outFile << userInput << std::endl;
        outFile.close(); // close file
        std::cout << "Text appended successfully!" << std::endl;
    } else {
    	// error if file cant be opened
        std::cerr << "Error: Could not open file for appending." << std::endl;
    }
}

// function to reverse the entire contents of the file and write it to a new file
void reverseFileContents() {
	// open file in read mode
	std::ifstream inFile("CSC450_CT5_mod5.txt");
	std::string content;

	if (inFile.is_open()) {
		// reading all content as a singular line using the terminator
		std::getline(inFile, content, '\0');
		inFile.close();


		// reverse the string using reverse from <algorithm>
		std::reverse(content.begin(), content.end());

		// open and write reversed in a new file
        std::ofstream outFile("CSC450-mod5-reverse.txt");
        if (outFile.is_open()) {
            outFile << content;
            outFile.close();
            std::cout << "Reversed content written to CSC450-mod5-reverse.txt!" << std::endl;
        } else {
            std::cerr << "Error: Could not open file to write reversed content." << std::endl;
        }
    } else {
        std::cerr << "Error: Could not open file to read content." << std::endl;
    }
}

int main() {
	appendToFile();  		// step 1: append user input to file
	reverseFileContents();  // step 2: reverse contents of file and save to a new file
	return 0;
}
