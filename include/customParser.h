#ifndef CUSTOMPARSER_H
#define CUSTOMPARSER_H

#include <string>
#include <sstream>

/**
 * @brief The customParser class is responsible for parsing HTML content
 *        to extract specific information such as battleground name, faction which won,
 *        date, and time.
 */
class customParser {
public:
    /**
     * @brief Constructs a customParser object with the given HTML content.
     * @param htmlContent The HTML content to be parsed.
     */
    customParser(const std::string& htmlContent);

    /**
     * @brief Destructor to clean up resources.
     */
    ~customParser();

    /**
     * @brief Finds and extracts battleground information from the HTML content.
     */
    void findHeaders();

    std::string battlegroundName; /**< Extracted battleground name. */
    std::string faction; /**< Extracted faction, that won. */
    std::string date; /**< Extracted date. */
    std::string time; /**< Extracted time. */

private:
    /**
     * @brief Finds and extracts battleground name from the HTML content.
     */
    void findBG();

    /**
     * @brief Finds and extracts faction information from the HTML content.
     */
    void findFaction();

    /**
     * @brief Finds and extracts time and date from the HTML content.
     */
    void findTimeAndDate();

    std::stringstream htmlStream; /**< Input HTML content stream. */
    std::string reader; /**< String for reading HTML content. */
};

#endif // CUSTOMPARSER_H
