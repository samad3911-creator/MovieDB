/*
 * main.cpp
 *
 *  Created on: 07-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */
#include <algorithm>
#include <iostream>
#include <string>

#include "../include/moviedatabasemenu.h"

int main() {
  MovieDB::MovieDBMenu movieDB;
  movieDB.performMovieDBOperations();
  return 0;
}
