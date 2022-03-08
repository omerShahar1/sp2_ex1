/**
 *
 * AUTHORS: <Omer Shahar>
 * 
 * Date: 2022-03
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@"
													"@-------@"
													"@-@@@@@-@"
													"@-@---@-@"
													"@-@@@@@-@"
													"@-------@"
													"@@@@@@@@@"));

	CHECK(nospaces(mat(21, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@@@@@@@@@"
													 "@-------------------@"
													 "@-@@@@@@@@@@@@@@@@@-@"
													 "@-------------------@"
													 "@@@@@@@@@@@@@@@@@@@@@"));

	
	
	CHECK(nospaces(mat(5, 7, '@', '-')) == nospaces("@@@@@"
													"@---@"
													"@-@-@"
													"@-@-@"
													"@-@-@"
													"@---@"
													"@@@@@"));

	CHECK(nospaces(mat(9, 1, '@', '-')) == nospaces("@@@@@@@@@"));

	
	CHECK(nospaces(mat(15, 3, '@', '-')) == nospaces("@@@@@@@@@@@@@@@"
													 "@-------------@"
													 "@@@@@@@@@@@@@@@"));


	CHECK(nospaces(mat(9, 9, '@', '-')) == nospaces("@@@@@@@@@"
													"@-------@"
													"@-@@@@@-@"
													"@-@---@-@"
													"@-@-@-@-@"
													"@-@---@-@"
													"@-@@@@@-@"
													"@-------@"
													"@@@@@@@@@"));


	CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@"
													 "@-----------@"
													 "@-@@@@@@@@@-@"
													 "@-----------@"
													 "@@@@@@@@@@@@@"));

	CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$"
													"$+$"
													"$+$"
													"$+$"
													"$$$"));

	CHECK(nospaces(mat(1, 5, '$', '+')) == nospaces("$$$$$"));

	CHECK(nospaces(mat(5, 1, '$', '+')) == nospaces("$"
													"$"
													"$"
													"$"
													"$"));

	CHECK(nospaces(mat(3, 3, '$', '+')) == nospaces("$$$"
													"$+$"
													"$$$"));
	
	
	CHECK(nospaces(mat(5, 5, '$', '+')) == nospaces("$$$$$"
													"$+++$"
													"$+$+$"
													"$+++$"
													"$$$$$"));


	CHECK(nospaces(mat(1, 1, '$', '+')) == nospaces("$"));
	/* Add more test here */
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));

	CHECK_THROWS(mat(2, 2, '$', '%'));

	CHECK_THROWS(mat(5, 10, '$', '%'));

	CHECK_THROWS(mat(5, 0, '$', '%'));

	CHECK_THROWS(mat(0, 10, '$', '%'));

	CHECK_THROWS(mat(-6, 3, '$', '%'));

	CHECK_THROWS(mat(3, -6, '$', '%'));

	CHECK_THROWS(mat(-6, -6, '$', '%'));
    /* Add more test here */
}