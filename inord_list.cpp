#include "inord_list.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <bits/stdc++.h>

std::string low(std::string s){
	for (int i = 0;i < s.length();i++)
		s[i] = tolower(s[i]);
	return s;
}

list::list(){
	noe = 0;
	noed = 0;
	noc = 0;
	head = NULL;
	tail = NULL;
	current = NULL;
}
bool list::insert(const listelemtype &e,int l){
	link addednode;
	addednode = new node;
	if (addednode == NULL)
		return false;
	addednode->elem = e;
	addednode->next = NULL;
	addednode->line = l;
	if (head == NULL)
		head = addednode;
	else
		tail->next = addednode;
	tail = addednode;
	noe = noe + 1;
	link k = head;
	while (k != tail){
		if (k->elem == e)
			return true;
		k = k->next;
	}
	noed = noed + 1;
	return true;
}
bool list::first(listelemtype &e){
	if (head == NULL)
		return false;
	current = head;
	e = current->elem;
	return true;
}
bool list::next(listelemtype &e){
	if (current == NULL || current->next == NULL)
		return false;
	current = current->next;
	e = current->elem;
	return true;
}
int list::NOE(){
	return noe;
}
int list::NOED(){
	return noed;
}
int list::read(std::string w,int L){
	std::istringstream iss (w);
	do {
		std::string word;
		iss >> word;
		for (int i = 0;i < word.length();i++)
			if ((word[i]<'A' || word[i]>'Z') && (word[i]>'z' || word[i]<'a') && (word[i]<'0' || word[i]>'9'))
				word.erase(i,1);
		if (word.length() > 0){
			this->insert(word,L);
			noc = noc + word.length() + 1;
		}
	} while (iss);
	return noc;
}
void list::freq(int *occ){
	for (int i=0;i<noe;i++){
		link j = head;
		link h = head;
		for (int k=0;k<i;k++){
			h = h->next;
			j = j->next;
		}
		if (h->elem == "a" || h->elem == "A" || h->elem == "an" || h->elem == "An" || h->elem == "the" || h->elem == "The" || h->elem == "in" || h->elem == "In" || h->elem == "on" || h->elem == "On" || h->elem == "of" || h->elem == "Of" || h->elem == "and" || h->elem == "And" || h->elem == "is" || h->elem == "Is" || h->elem == "are" || h->elem == "Are"){
		occ[i] = 0;
		}
		else {
			while (j != NULL){
				if (low(h->elem) == low(j->elem))
					occ[i] = occ[i] + 1;
				j = j->next;
			}
		}

	}
}
int list::count(std::string w){
	int oc = 0;
	link h = head;
	while (h != NULL){
		if (low(h->elem) == low(w))
			oc = oc + 1;
		h = h->next;
	}
	return oc;
}
std::string list::fnd(int m){
	link j = head;
	for (int i = 0;i < m;i++)
		j = j->next;
	return j->elem;
}
int list::findl(int m){
	link j = head;
	for (int i = 0;i < m;i++)
		j = j->next;
	return j->line;
}
void list::arr(int *f,int g){
	for (int r = 0;r < g;r++)
		for (int t = r + 1;t < g;t++)
			if (this->fnd(f[r]).std::string::compare(this->fnd(f[t])) > 0){
				int temp = f[r];
				f[r] = f[t];
				f[t] = temp;
			}
}
