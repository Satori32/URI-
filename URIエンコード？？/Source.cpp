#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdint>
#include <algorithm>

//this is not URI_Encode.
//this is like a URI_encode.not same.

//Yaki is Burn.焼。no mean postfix.
std::string ItoAYaki(std::int64_t N, const std::string& Ch) {
	std::string R;
	bool F = N >= 0 ? true : false;
	while (N != 0) {
		R += Ch[N % Ch.size()];
		N /= Ch.size();//radix divide
	}
	if (!F) R += '-';

	std::reverse(R.begin(), R.end());

	return R;


}
std::intmax_t AtoIYaki(const std::string& S, const std::string& Ch) {//this is not reference to gryph.
	std::uintmax_t R=0;
	bool F = S[0] != '-'? true : false;
	for(auto &o:S){
		if (o == '-')continue;
		auto it = std::find(Ch.begin(), Ch.end(),o);
		R *= Ch.size();//radix multiple.
		R += std::distance(Ch.begin(), it);
	}
	if (!F)R *= -1;

	return R;


}

std::string ReversibleHash_Encode(const std::string& S,std::string C) {
	std::string R;
	for (auto& o : S) {
		R += '%';
		R += ItoAYaki(static_cast<std::uint8_t>(o), C);
	}
	return R;
}
std::string ReversibleHash_Decode(const std::string& S,std::string C) {
	std::string R;
	std::string V;
	bool F = true;
	for (auto& o : S) {
		std::intmax_t N = o;
		if (o != '%') {
			F = false;
			V += o;
		}
		else {
			if (F)continue;
			R += AtoIYaki(V.data(),C);
			V.clear();
		}
	}
	if (V.size())R += AtoIYaki(V.data(), C);
	return R;
}
int main() {
	{
		std::string R;
		std::string S;

		S = "ウィキペディア";

		R = ReversibleHash_Encode(S, "0123456789");

		std::cout << R << std::endl;

		R = ReversibleHash_Decode(R, "0123456789");

		std::cout << R << std::endl;
	}
	{
		//dictionary Crypt.
		std::string R;
		std::string S;
		std::string Ch = "abcdefghijklnmopqrstuvwxyz0123456789";
		S = "ウィキペディア";

		R = ReversibleHash_Encode(S, Ch);

		std::cout << R << std::endl;

		R = ReversibleHash_Decode(R, Ch);

		std::cout << R << std::endl;
	}
	return 0;
}