/*
 * findMatches.h
 *
 *  Created on: Feb 6, 2015
 *      Author: Alex, Thurston
 */

#ifndef FINDMATCHES_H_
#define FINDMATCHES_H_
#include "Wordlist.h"
#include "Grid.h"

/**
 * findMatches searches the grid of words and prints out all the matching words
 *
 * @param Wordlist w1 -inputs the list of available words into the function to allow it
 *  to search the grid for those words
 * @param Grid g1 - into the grid of letters which is then used in conjunction with the Wordlist
 *     to search for words
 * @return void -doesn't return anything
 */
void findMatches(const Wordlist w1, const Grid g1);

#endif /* FINDMATCHES_H_ */
