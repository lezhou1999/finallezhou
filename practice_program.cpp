 
#include <vector>
#include <iostream>

using namespace std; 



string vec_to_string(vector<double> v){
	if(v.size() == 0){
		return "[]";
	}

	string s = "[";
	for(size_t i = 0; i < v.size()-1; i++){
		s = s + to_string(v.at(i)) + ", ";
	}
	
	s = s + to_string(v.at(v.size()-1)) + "]";
	return s;
}
 
vector<double> double_them(vector<double> &v){
	vector<double> toStore;
	for(size_t i = 0; i < v.size(); i++){
		v.at(i) = v.at(i)*2;
		
	}
	return v;
	
}


int main(){
	
	vector<double> v = {3.4, 5.2, 6.1, 7.9, 4.2};
	cout << "Before: " << vec_to_string(v) << endl;
	double_them(v);
	cout << "After: " << vec_to_string(v) << endl;
	
	return 0;
}
