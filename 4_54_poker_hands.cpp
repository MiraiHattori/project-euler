#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/*
High Card: Highest value card.
One Pair: Two cards of the same value.
Two Pairs: Two different pairs.
Three of a Kind: Three cards of the same value.
Straight: All cards are consecutive values.
Flush: All cards of the same suit.
Full House: Three of a kind and a pair.
Four of a Kind: Four cards of the same value.
Straight Flush: All cards are consecutive values of same suit.
Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
*/

enum class Hand : int {
    HighCard = 0,
    OnePair,
    TwoPairs,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    RoyalFlush,
};

// {{{ Suit & Card Declaration & Utils
int charToValue(const char& c)
{
    switch (c) {
    case 'T':
        return 10;
    case 'J':
        return 11;
    case 'Q':
        return 12;
    case 'K':
        return 13;
    case 'A':
        return 14;
    default:
        return c - '0';
    }
}
enum class Suit : char {
    Diamond = 'D',
    Clover = 'C',
    Heart = 'H',
    Spade = 'S',
};
struct Card {
public:
    explicit Card() = default;
    explicit Card(const int& value, const Suit& suit)
        : value(value), suit(suit) {}
    explicit Card(const int& value, const char& suit_char)
        : value(value), suit(static_cast<Suit>(suit_char)) {}
    int value;
    Suit suit;
};

std::ostream& operator<<(std::ostream& os, const Suit& suit)
{
    os << static_cast<char>(suit);
    return os;
}
std::ostream& operator<<(std::ostream& os, const Card& card)
{
    os << card.suit << card.value << " ";
    return os;
}
std::ostream& operator<<(std::ostream& os, const std::array<Card, 5>& player_hand)
{
    for (const auto& card : player_hand) {
        os << card << " ";
    }
    return os;
}

// }}}


std::pair<Hand, std::vector<int>> hand(const std::array<Card, 5>& player_hand)
{
    // {{{ conditions
    bool royal = false;                  // if a hand has 10, 11, 12, 13 and 14(Ace)
    bool straight = false;               // if a hand has consecutive numbers
    bool flush = false;                  // if a hand is in same suit
    std::vector<int> four_of_a_kind{};   // if a hand has 4 cards of the same value and its numbers
    std::vector<int> three_of_a_kind{};  // if a hand has 3 cards of the same value a hand has and its numbers
    std::vector<int> two_pairs{};        // if a hand has 2 pairs of 2 cards of the same value and its numbers
    std::vector<int> one_pair{};         // if a hand has 2 cards of the same value a hand has and its numbers
    std::vector<int> high_card{};        // if a hand has no pairs of the same value a hand has and its numbers

    // }}}
    std::vector<int> values{};
    for (int i = 0; i < 5; i++) {
        values.emplace_back(player_hand.at(i).value);
    }
    std::sort(values.rbegin(), values.rend());
    std::vector<Suit> suits{};
    for (int i = 0; i < 5; i++) {
        suits.emplace_back(player_hand.at(i).suit);
    }

    // {{{ condition requirement check
    royal = (values == std::vector<int>({14, 13, 12, 11, 10}));
    straight = (values.at(0) - 1 == values.at(1))
               and (values.at(1) - 1 == values.at(2))
               and (values.at(2) - 1 == values.at(3))
               and (values.at(3) - 1 == values.at(4));
    flush = (suits.at(0) == suits.at(1))
            and (suits.at(1) == suits.at(2))
            and (suits.at(2) == suits.at(3))
            and (suits.at(3) == suits.at(4));
    std::array<int, 15> number_of_cards{};
    for (const auto& value : values) {
        number_of_cards.at(value)++;
    }
    for (int i = 14; i >= 0; i--) {
        if (number_of_cards.at(i) == 4) {
            four_of_a_kind.emplace_back(i);
            for (int j = 14; j >= 0; j--) {
                if (number_of_cards.at(j) == 1) {
                    four_of_a_kind.emplace_back(j);
                    break;
                }
            }
            std::cerr << "Here at line " << __LINE__ << " occurs an error" << std::endl;
            break;
        }
        if (number_of_cards.at(i) == 3) {
            three_of_a_kind.emplace_back(i);
            for (int j = 14; j >= 0; j--) {
                if (number_of_cards.at(j) == 2) {
                    one_pair.emplace_back(j);
                    break;
                }
                if (number_of_cards.at(j) == 1) {
                    three_of_a_kind.emplace_back(j);
                }
            }
            break;
        }
        if (number_of_cards.at(i) == 2) {
            one_pair.emplace_back(i);
        }
    }
    if (one_pair.size() == 2) {
        two_pairs = one_pair;
        one_pair.clear();
    }
    // }}}

    // {{{ condition management
    if (royal and straight and flush) {
        return std::make_pair<Hand, std::vector<int>>(Hand::RoyalFlush, std::vector<int>({14}));
    }
    if (straight and flush) {
        return std::make_pair<Hand, std::vector<int>>(Hand::StraightFlush, std::vector<int>(*std::max_element(values.begin(), values.end())));
    }
    if (not four_of_a_kind.empty()) {
        return std::make_pair<Hand, std::vector<int>>(Hand::FourOfAKind, std::move(four_of_a_kind));
    }
    if (not three_of_a_kind.empty() and not two_pairs.empty()) {
        return std::make_pair<Hand, std::vector<int>>(Hand::FullHouse, std::move(three_of_a_kind));
    }
    if (flush) {
        return std::make_pair<Hand, std::vector<int>>(Hand::Flush, std::move(values));
    }
    if (straight) {
        return std::make_pair<Hand, std::vector<int>>(Hand::Straight, std::vector<int>(*std::max_element(values.begin(), values.end())));
    }
    if (not three_of_a_kind.empty()) {
        return std::make_pair<Hand, std::vector<int>>(Hand::ThreeOfAKind, std::move(three_of_a_kind));
    }
    if (not two_pairs.empty()) {
        return std::make_pair<Hand, std::vector<int>>(Hand::TwoPairs, std::move(two_pairs));
    }
    if (not one_pair.empty()) {
        return std::make_pair<Hand, std::vector<int>>(Hand::OnePair, std::move(one_pair));
    }
    return std::make_pair<Hand, std::vector<int>>(Hand::HighCard, std::move(values));
    // }}}
}

bool player1Win(std::string str)
{
    // {{{ parse string
    std::array<Card, 5> player1, player2;
    int value_pos = 0;
    int suit_pos = 1;
    for (int i = 0; i < 5; i++) {
        player1.at(i) = Card(charToValue(str.at(value_pos)), str.at(suit_pos));
        value_pos += 3;
        suit_pos += 3;
    }
    for (int i = 0; i < 5; i++) {
        player2.at(i) = Card(charToValue(str.at(value_pos)), str.at(suit_pos));
        value_pos += 3;
        suit_pos += 3;
    }
    // }}}
    if (hand(player1).first != hand(player2).first) {
        return static_cast<int>(hand(player1).first)
               > static_cast<int>(hand(player2).first);
    } else {
        // dictionary comparison
        return hand(player1).second > hand(player2).second;
    }
}


int main()
{
    std::ifstream ifs("p054_poker.txt");
    std::string str;
    int result = 0;
    while (std::getline(ifs, str)) {
        if (player1Win(str)) {
            result++;
        }
    }
    std::cout << result << std::endl;
    return 0;
}
