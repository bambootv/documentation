#include <bits/stdc++.h>
using namespace std;

// Sort
bool soSanh(const pair<long long, int> &a, const pair<long long, int> &b){
	if(a.first == b.first){
		return a.second < b.second;
	}
	return a.first < b.first;
}

void sortDemo(){
	int a[10] = {1,4,1,1,5,7,32,4,6,4};
	sort(a,a+10);// Ascending
	sort(a,a+10,greater<int>()); //Decrease
	
	pair<long long, int> b[100];
	sort(b,b+100,soSanh);
}


// Map: Du lieu bieu dien theo key & value
void mapDemo(){
	// Auto sort, ascending
	// If want sort decrease: map<long long, int, greater<int> > m;
	map <long long, int, greater<int> > m;
	long long temp;
	for (int i=0;i<5;i++){
		//cin >> temp;
		//m[temp]++;
	}
	
	cout << "Size: " << m.size() << "\n";
	
	for(map<long long, int>::iterator it=m.begin(); it!=m.end(); it++) {
		// Google map: Ban do dan duong => ->
		// Google map => begin() & end().
		cout << it->first << " " << it->second << "\n";
	}
}


// Vector: Tuong tu nhung manh hon mang
void vectorDemo(){
	vector<int> v;
	
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	for(vector<int>::iterator it=v.begin(); it!=v.end(); it++){
		cout << *it << " ";
	}
	cout << "\n";
	
	fill(v.begin(),v.end(),0);
	
	for(vector<int>::iterator it=v.begin(); it!=v.end(); it++){
		cout << *it << " ";
	}
	cout << "\n";
	
	// Neu muon truy cap theo v[i] thi can khai bao vector<int,int> v[n];
	// Vector tuong tu mang, nhung khai bao so luong phan tu bang ()
	vector<int> ve(5);
	ve[1]=1;
	ve[2]=2;
	ve[3]=3;
	
	int l = ve.size();
	for(int i=0;i<l;i++){
		cout << ve[i] << " ";
	}
	cout << "\n";
	
}

// Pair: Du lieu bieu dien theo cap
void pairDemo(){
	int n = 100;
	pair<int,int> a[n];
	
	memset(a,0,n);
	
	for(int i=0;i<n;i++){
		cout << a[i].first << " " << a[i].second << "\n";
	}
	
	for(int i=0;i<5;i++){
		a[i].first = 1;
		a[i].second = 1;
	}
	
	for(int i=0;i<5;i++){
		cout << a[i].first << " " << a[i].second << "\n";
	}
}

//Array: Trong C++, khia bao array can khai bao kich thuoc, nhung khai bao vector thi khong, do la diem manh cua vector

void arrayDemo(){
	
}


// Long nhau

// string
void stringDemo(){
	string s1 = "3";
	string s2 = "2";
	
	int res = s1.compare(s2);
	cout << "res: " << res << "\n";
	if( res == 0){
		cout << "s1 = s2" << "\n";
	} else if(res > 0){
		cout << "s1 > s2"<<"\n";
	} else {
		cout << "s1 < s2"<<"\n";
	}
	
	// String la mot class, co cac phuong thuc duoc viet san
	s1.length();
	s1[2];
	// String manh hon char[];
	
	
	
	char c = '3';
	string s = "123";
	int i = 45;
	
	// Convert string -> int 
	cout << "Convert string -> int \n";
	int k;
	stringstream(s) >> k;
	cout << k << "\n";
	
	// Int -> string 
	cout << "Convert int -> string \n";
	stringstream str;
	str << i;
	string st = str.str();
	cout << st << "\n";
	
	// Convert char -> int
	cout << "Convert char -> int \n";
	int j = int(c) -48;
	cout << j << "\n";
	
	// String get char
	char ch = s[0];
	
	
}

//Char
void charDemo(){
	char c1 = '1';
	char c2 = '2';
	
	if(c1==c2){
		cout <<"c1 = c2" <<"\n";
	} else if(c1 > c2){
		cout << "c1 > c2" << "\n";
	} else {
		cout << "c1 < c2" << "\n";
	}
}

//Stack
void stackDemo(){
	stack<int> st;
	
	st.push(1);
	st.push(2);
	st.push(3);

	if(st.empty()){
		cout << "Stack null" << "\n";
	} else {
		cout << "Size: " << st.size() << "\n";	
	}
	
	cout << st.top() << "\n";
	st.pop();
	cout << st.top() << "\n";
	
}

//Quece
void queueDemo(){
	queue<int> q;
	
	q.push(1);
	q.push(2);
	q.push(3);
	
	cout << q.front() << "\n";
	q.pop();
	cout << q.front() << "\n";
		
}

struct soSanhQueue {
	bool operator()(const pair<int,int> &a, const pair<int,int> &b){
		if(a.first == b.first)
			return a.second > b.second;
		return a.first > b.first;
	}
};

struct soSanhQueuei{
	bool operator()(const int &a, const int &b){
		return a > b;
	}
};

// Priority_queue
void priority_queue_demo(){
	cout << "Priority_Queue \n";
	
//	priority_queue < pair<int,int>, vector< pair<int,int> >, soSanhQueue > que;
	priority_queue < int, vector< int >, soSanhQueuei > que;
//	pair<int,int> p;
//	p.first=2; p.second=2;
	que.push(2);
//	p.first=1; p.second=1;
	que.push(1);
//	p.first=3; p.second=3;
	que.push(3);
	
	while(!que.empty()){
		cout << que.top() << " ";
		que.pop();
	}
}


// Priority_queue
void priority_queue_demo_pair(){
	cout << "Priority_Queue \n";
	
	priority_queue < pair<int,int>, vector< pair<int,int> >, soSanhQueue > que;	
	
	pair<int,int> p;
	p.first=2; p.second=2;
	que.push(p);
	p.first=1; p.second=1;
	que.push(p);
	p.first=3; p.second=3;
	que.push(p);
	
	while(!que.empty()){
		cout << que.top().first << " ";
		que.pop();
	}
}


int main(){
//	vectorDemo();
//	mapDemo();
//	pairDemo();
//	stringDemo();
//	charDemo();
//	stackDemo();
//	queueDemo();
	priority_queue_demo();
	return 0;
}

