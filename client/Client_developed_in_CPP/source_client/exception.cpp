#include "../include_client/exception.hpp"

const char	*MyError::what() const throw()
{
	return (_error.c_str());
}

MyError::MyError(const std::string &message) throw()
	: _error(message) {}

MyError::~MyError() throw() {}
