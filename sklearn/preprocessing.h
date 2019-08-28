// SWAMI KARUPPASWAMI THUNNAI

#pragma once
#include <vector>
#include <set>
#include <map>

/*
Label Encoder: Encodes the label A,B,C to 0,1,2
i.e converts the categorical data into numerical values.
Written By: Visweswaran N, 2019-08-28
*/
template <typename T>
class LabelEncoder
{
private:
	std::vector<T> label_vector;
	std::vector<unsigned long int> encoded_vector;
	std::map<T, unsigned long int> headers;

	void fit();
	void transform();

public:
	LabelEncoder(std::vector<T> label_vector) : label_vector(label_vector) {}

	std::vector<unsigned long int> fit_transorm();
};