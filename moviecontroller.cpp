/*
 * moviecontroller.cpp
 *
 *  Created on: 13-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */

#include "moviecontroller.h"
namespace MovieDB {
MovieController::MovieController() { m_Moviedatabase = new MovieDatabase(); }

MovieController::MovieController(IMovieDatabase* moviedatabase)
    : m_Moviedatabase(moviedatabase) {}

MovieController::MovieController(MovieController&& other) {
  this->m_Moviedatabase = other.m_Moviedatabase;
  other.m_Moviedatabase = nullptr;
}

MovieController& MovieController::operator=(MovieController&& other) {
  if (*this == other) return *this;
  delete this->m_Moviedatabase;
  this->m_Moviedatabase = other.m_Moviedatabase;
  other.m_Moviedatabase = nullptr;
  return *this;
}

const std::string MovieController::addMovie(
    std::string title, std::string leadactor, std::string leadactress,
    std::string language, int day, int month, int year, std::string villain,
    std::string producer, std::string director, std::string comedian,
    std::string supportingActor, std::string supportingActress,
    std::string genre, int hour, int min, int sec) {
  Movie movie(title, leadactor, leadactress, language,
              ReleaseDate(day, month, year), villain, producer, director,
              SupportingCast(comedian, supportingActor, supportingActress),
              genre, MovieDuration(hour, min, sec));
  return m_Moviedatabase->addMovie(std::move(movie));
}

const std::vector<Movie_Shared_Ptr> MovieController::findMoviesByTitle(
    std::string& title) {
  return m_Moviedatabase->findMoviesByTitle(title);
}

const std::vector<Movie_Shared_Ptr> MovieController::findMoviesByHeroOrHeroine(
    std::string& name) {
  return m_Moviedatabase->findMoviesByHeroOrHeroine(name);
}

const std::vector<Movie_Shared_Ptr> MovieController::findMoviesByDirector(
    std::string& director) {
  return m_Moviedatabase->findMoviesByDirector(director);
}

const std::vector<Movie_Shared_Ptr> MovieController::findMoviesByLanguage(
    std::string& language) {
  return m_Moviedatabase->findMoviesByLanguage(language);
}

const std::vector<Movie_Shared_Ptr> MovieController::findMoviesByYear(
    int startYear, int endYear) {
  return m_Moviedatabase->findMoviesByYear(startYear, endYear);
}

bool MovieController::operator==(const MovieController& other) {
  return (this->m_Moviedatabase == other.m_Moviedatabase);
}
}
