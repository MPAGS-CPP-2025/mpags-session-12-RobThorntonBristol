#include "PlayfairCipher.hpp"

#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>
#include <map>

/**
 * \file PlayfairCipher.cpp
 * \brief Contains the implementation of the PlayfairCipher class
 */

PlayfairCipher::PlayfairCipher(const std::string& key)
{
    this->setKey(key);
}

void PlayfairCipher::setKey(const std::string& key)
{
    // Store the original key
    key_ = key;

    // Append the alphabet to the key
    key_ += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Make sure the key is upper case
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                   ::toupper);

    // Remove non-alphabet characters
    auto inverse_alpha = [] (char letter) {
        if (std::isalpha(letter))
            return false;
        else  
            return true;
    };

    key_.erase(std::remove_if(key_.begin(), key_.end(), inverse_alpha), key_.end());

    // Change J -> I
    std::transform(key_.begin(), key_.end(), key_.begin(),
        [](char c) {
            return (c == 'J') ? 'I' : c;
        }
    );

    // Remove duplicated letters
    std::string encountered{};

    auto check_encountered = [&encountered] (char c) {
        if (encountered.find(c) != std::string::npos)
            return true;
        encountered.push_back(c);
        return false;
    };

    key_.erase(
        std::remove_if(key_.begin(), key_.end(), check_encountered)
        , key_.end()
    );

    // Store the coordinates of each letter
    using Coord = std::pair<int, int>;
    using CharToCoord = std::map<char, Coord>;
    using CoordToChar = std::map<Coord, char>;

    CharToCoord char_to_coord_;
    CoordToChar coord_to_char_;

    for (size_t i = 0; i < key_.size(); ++i) {
        int row = i / 5;
        int col = i % 5;

        Coord coord{row, col};
        char letter = key_[i];

        char_to_coord_[letter] = coord;
        coord_to_char_[coord] = letter;
    };
}

std::string PlayfairCipher::applyCipher(const std::string& inputText,
                                        const CipherMode /*cipherMode*/) const
{
    // Create the output string, initially a copy of the input text
    std::string outputText{inputText};

    // Change J -> I

    // Find repeated characters and add an X (or a Q for repeated X's)

    // If the size of the input is odd, add a trailing Z

    // Loop over the input bigrams

    // - Find the coordinates in the grid for each bigram

    // - Apply the rules to these coords to get new coords

    // - Find the letters associated with the new coords

    // - Make the replacements

    // Return the output text
    return outputText;
}
