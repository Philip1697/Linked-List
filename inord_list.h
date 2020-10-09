#ifndef INORD_LIST_H_
#define INORD_LIST_H_
#include <string>
#include <fstream>
typedef std::string listelemtype;
std::string low(std::string s);
class list {
public:
	list();
	bool insert(const listelemtype &e,int l);
	bool first(listelemtype &e);
	bool next(listelemtype &e);
	int read(std::string w,int L);
	void freq(int occ[]);
	int count(std::string w);
	std::string fnd(int m);
	int findl(int m);
	void arr(int f[], int g);
	int NOE();
	int NOED();
private:
	struct node;
	typedef node *link;
	struct node{
		listelemtype elem;
		int line;
		link next;
	};
	link head;
	link tail;
	link current;
	int noe;
	int noed;
	int noc;
};
#endif
