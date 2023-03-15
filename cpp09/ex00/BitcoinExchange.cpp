#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// Open the bitcoin exchange rate data file, read the data, and save it to the
    // exchange_rates_ map.
    std::ifstream data_file("data.csv");
    if (!data_file)
    {
        throw std::runtime_error("Could not open data file.");
    }

    std::string line;
    while (std::getline(data_file, line))
	{
        // CSV file inject
        std::stringstream ss(line);
        std::string year, month, day , exchange_rate_str;
        std::getline(ss, year, '-');
		std::getline(ss, month, '-');
		std::getline(ss, day, ',');
        std::getline(ss, exchange_rate_str);

        std::string key = year + month + day;
        float exchange_rate;
        try
        {
            exchange_rate = std::atof(exchange_rate_str.c_str());
        }
        catch (...)
        {
            std::cerr << "Invalid argument" << std::endl;
            continue;
        }

        // exchange_rates_ 맵에 데이터를 저장합니다.
        exchange_rates_[key] = exchange_rate;
    }
}

float BitcoinExchange::getExchangeRate(const std::string &date_str)
{
    // Convert Year, Month, and Day data to strings by converting them to integers.
    std::string year_str = date_str.substr(0, 4);
    std::string month_str = date_str.substr(5, 2);
    std::string day_str = date_str.substr(8, 2);
    std::string key = year_str + month_str + day_str;

    std::map<std::string, float>::iterator it;
    it = exchange_rates_.find(key);
    if (it != exchange_rates_.end())
    {
        return it->second;
    }
    else
    {
        return 0;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    exchange_rates_ = other.exchange_rates_;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        exchange_rates_ = other.exchange_rates_;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}
