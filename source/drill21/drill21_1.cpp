#include <stdexcept>
#include <map>
#include <numeric>
#include <string>
#include <iostream>

template<typename K, typename V> 
void print(const std::map<K,V>&m){
	//for(const auto& a : m){
	for(const std::pair<K,V>&a : m){
		std::cout<< a.first <<"\t" <<a.second << std::endl;
	}
	
}

void read_map(std::map<std::string,int>& m){
	std::string s;
	int i=0;
	
	while(m.size()<10){
		std::cin >> s >> i;
		//m[s] = i;
		m.insert(std::make_pair(s,i));
	}
}
//8
template<typename K, typename V> 
void sum(const std::map<K,V>&m){

	int sum=0;
	for(const std::pair<K,V>&a : m){
		sum=a.second+sum;
	}
	std::cout <<"eredmeny:" << sum << std::endl;
}


int main()
try{
	std::map<std::string, int> msi;
	
	msi["a"] =   42;
	msi["e"] =   21;
	msi["fgds"] = 2;
	msi["key"] =  3;
	msi["ab"] =  17;
	msi["cd"] =  93;
	msi["po"] =  62;
	msi["tt"] =  37;
	msi["x"] =   11;
	msi["k"] =   17;
	
	print(msi);
	
	std::cout <<std::endl<< "törlés után" << std::endl;
	msi.erase("a");
	print(msi);
	
	msi.erase(msi.begin(),msi.end());
	std::cout <<std::endl<< "teljes törlés után" << std::endl;
	print(msi);
	
	
	std::cout <<std::endl<< "Adj meg 10 kulcs érték párt!" << std::endl;
	read_map(msi);
	std::cout <<std::endl<< "A megadott map: " << std::endl;
	print(msi);
	
	sum(msi);
	//9
	std::map<int, std::string> mis;
	for(const auto& a : msi){
		mis[a.second] = a.first;
	}
	std::cout <<std::endl<< "mis map: " << std::endl;
	print(mis);

	

}catch(std::exception& e){
	std::cerr << "exeption:" <<e.what()<<'\n';
	return 1;
}catch(...){
	std::cerr << "exeption" <<"\n";
	return 2;
}
