#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    // Check if input file is provided
    if (argc < 2)
    {
        std::cout << "Error: input file not provided." << std::endl;
        return 1;
    }

    // Create an instance of BitcoinExchange class
    BitcoinExchange exchange;

    // Open input file
    std::ifstream input_file(argv[1]);
    if (!input_file)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    // Read input file line by line
    std::string line;
    while (std::getline(input_file, line))
    {
        // Parse date and value from input line
        std::string date_str, value_str;
        std::size_t pos = line.find('|');
        if (pos != std::string::npos)
        {
            date_str = line.substr(0, pos);
            value_str = line.substr(pos + 1);
        }
        else
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Convert value to float
        float value;
		try
		{
    		value = std::stof(value_str);
   			if (value > 1000)
    		{
    		    std::cout << "Error: too large a number." << std::endl;
    		    continue;
    		}
			if (value < 0)
			{
			    std::cout << "Error: not a positive number." << std::endl;
			    continue;
			}
		}
		catch (const std::exception &e)
		{
		    std::cout << "Error: bad input => " << line << std::endl;
		    continue;
		}

        // Parse date and get exchange rate
        float exchange_rate = exchange.getExchangeRate(date_str);
        if (exchange_rate < 0)
        {
            std::cout << "Error: invalid date => " << date_str << std::endl;
            continue;
        }

        // Compute and print result
        float result = value * exchange_rate;
        std::cout << date_str << " => " << value << " = " << result << std::endl;
    }

    // Close input file and exit
    input_file.close();
    return 0;
}
