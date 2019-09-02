// SWAMI KARUPPASWAMI THUNNAI

#pragma once
#define DEBUG 1
#define NODEBUG 0
#define PI 3.141592653589793238462643383279502884L
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>

/*
A class to store mean and variance
*/
class mean_variance
{
private:
	unsigned long int column;
	double _mean;
	double variance;

public:
	mean_variance(unsigned long int column, double _mean, double variance) : column(column), _mean(_mean), variance(variance) {}

	unsigned long int get_column()
	{
		return column;
	}

	double get_mean()
	{
		return _mean;
	}

	double get_variance()
	{
		return variance;
	}
};

class gaussian_naive_bayes
{

private:
	// Independent variable
	std::vector<std::vector<double>> X;
	// Dependent variable
	std::vector<unsigned long int> y;
	// Verbose to print debug messages
	unsigned short verbose;

	// Independent variable probabilities <features, probability>
	std::map<unsigned long int, std::map<double, double>> X_prob;

	// Dependent variable probabilities
	std::map<unsigned long int, double> y_prob;

	// Labels of y
	std::set<unsigned long int> labels;

	// label, column, mean and variance
	std::map<unsigned long int, std::vector<mean_variance>> mean_variance_map;

	

private:
	void print(std::string message);

	void calculate_y_probabilities();
	void calculate_x_probabilities();

public:
	gaussian_naive_bayes(std::vector<std::vector<double>> X, std::vector<unsigned long int> y, unsigned short verbose): X(X), y(y), verbose(verbose){}

	void fit();

	std::map<unsigned long int, double> predict(std::vector<double> X_test);
};

