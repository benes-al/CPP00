#include <iostream>
#include <string>

int	main(int argc, char **argv){
	char upper;

	if (argc == 1)
		std::cout << "* LOUD AND UNEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++){
		for (int j = 0; argv[i][j]; j++){
			upper = toupper(argv[i][j]);
			std::cout << upper;
		}	
	}
	std::cout << "\n";
}