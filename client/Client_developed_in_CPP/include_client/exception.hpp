#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

#include <iostream>
#include <exception>

class MyError : public std::exception {
protected:
	std::string	_error;
public:
	MyError(const std::string &message) throw();
	virtual ~MyError() throw();
	virtual const char *what() const throw();
};

#endif /* EXCEPTION_HPP */
