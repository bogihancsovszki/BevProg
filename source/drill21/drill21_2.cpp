#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>


int main() {
	std::vector<double> vd;
	
	std::ifstream bemenet;
	bemenet.open("szamok.txt");
	double x=0.0;
	for(int i=0; i<16;i++)
	{
		bemenet >> x;
		vd.push_back(x);
	}
	bemenet.close();
	for(int i=0;i<16;i++){
		std::cout << vd[i] <<std::endl;
	}
	
	std::vector<int> vi(vd.size());
	std::copy(vd.begin(),vd.end(),vi.begin());
	
	std::cout << std::endl;
	for(int i=0; i<vd.size();++i){
		std::cout << vd[i] <<'\t' << vi[i] <<std::endl;
	}
	
	double d_sum = std::accumulate(vd.begin(),vd.end(),0.0);
	std::cout << "sum of vector<doule>" <<d_sum << std::endl;
	
	double i_sum = std::accumulate(vi.begin(),vi.end(),0.0);
	std::cout << "sum of vector<int>" <<i_sum << std::endl;
	
	double diff_sum = std::inner_product(vd.begin(), vd.end(),
			vi.begin(),
			0.0,
			std::plus<double>(),
			std::minus<double>());
	std::cout << "diff:" << d_sum-i_sum << " " << diff_sum << std::endl;
	
	std::reverse(vd.begin(),vd.end());

	
	double vd_mean = d_sum / vd.size();
	std::cout << "Mean value:" <<vd_mean << std::endl;
	
	
	


}
