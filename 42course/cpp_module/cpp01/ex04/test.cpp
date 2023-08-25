#include <iostream>
#include <fstream>

void replaceAndWriteToFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    // Open the input file
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cerr << "Error opening input file: " << filename << std::endl;
        return;
    }

    // Create the output filename
    std::string outputFilename = filename + ".replace";

    // Open the output file
    std::ofstream output(outputFilename);
    if (!output.is_open()) {
        std::cerr << "Error opening output file: " << outputFilename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(input, line)) {
        size_t startPos = 0;
        while ((startPos = line.find(s1, startPos)) != std::string::npos) {
            // Copy characters before the match
            output << line.substr(0, startPos);
            // Copy the replacement string
            output << s2;
            // Move startPos past the matched portion
            startPos += s1.length();
        }
        // Copy the remaining characters after the last match (or the whole line if no match)
        output << line.substr(startPos);
        // Add a newline since getline discards it
        if (!input.eof()) {
            output << '\n';
        }

		// Copy the remaining characters after the last match (or the whole line if no match)
		if (startPos < line.length()) {
			output << line.substr(startPos);
		}
	}
    // Close the files
    input.close();
    output.close();

    std::cout << "Replacement complete. Result written to " << outputFilename << std::endl;
}

int main() {
    std::string filename, s1, s2;

    // Get input from the user
    std::cout << "Enter filename: ";
    std::cin >> filename;
    std::cout << "Enter string to replace (s1): ";
    std::cin >> s1;
    std::cout << "Enter replacement string (s2): ";
    std::cin >> s2;

    // Perform the replacement and write to a new file
    replaceAndWriteToFile(filename, s1, s2);

    return 0;
}
