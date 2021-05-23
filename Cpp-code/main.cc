#include "header.h"

int listExe()
{
	list<int> l;
	l.insert(1);
	l.insert(2);
	l.insert(5);
	l.insert(7);
	l.insert(11);
	l.insert(15);
	l.insert(32);
	l.insert(55);
	l.insert(555);
	l.print();
	l.reverse();
	l.print();

	l.reverseNgroup(2);
	l.print();

	list<std::string> l1;
	l1.insert("rashmi");
	l1.insert("rrrrrrrr");

	l1.print();
	l1.reverse();
	l1.print();

	node<std::string> *tmp = l1.get("rashmi");
	std::cout << "List elem " << tmp->data  << std::endl;

	return 0;
}
int treeExe()
{
	std::vector<int> v{55, 555, 22, 222, 33, 333, 77, 777, 8,888};
	tree<int> t;
	for (int i = 0; i < v.size(); i++){
		t.insertREC(v[i]);
	}
	t.insertREC(5);
	t.insertREC(15);	
	t.print();

	treenode<int> *tmp = t.searchREC(5555);
	if(tmp) tmp->print();
	tmp = t.search(555);
	if(tmp) tmp->print();

	t.preorderTraverseREC(); 
	t.inorderTraverseREC(); 
	t.postorderTraverseREC(); 
	t.levelorderTraverseREC();

	t.preorderTraverse(); 
	t.inorderTraverse(); 
	t.postorderTraverse();
	t.levelorderTraverse();

	t.printLeftViewREC();
	t.printLeftView();

	std::cout << "height : " << t.height() << std::endl;
	std::cout << "heightREC : " << t.heightREC() << std::endl;

	std::cout << "isBst : " << t.isBst() << std::endl;
	std::cout << "isBalancedREC : " << t.isBalancedREC() << std::endl;

	t.insertREC(3);
	t.insertREC(4);
	t.print();
	std::cout << "height : " << t.height() << std::endl;
	std::cout << "isBalancedREC : " << t.isBalancedREC() << std::endl;

	tmp = t.findDeepImbalanceNodeREC();
	if(tmp) tmp->print();

	tmp = t.minElemREC();
	std::cout << "minElemREC : " << std::endl;
	if(tmp) tmp->print();
	tmp = t.maxElemREC();
	std::cout << "maxElemREC : " << std::endl;
	if(tmp) tmp->print();

	tmp = t.minElem();
	std::cout << "minElem : " << std::endl;
	if(tmp) tmp->print();
	tmp = t.maxElem();
	std::cout << "maxElem : " << std::endl;
	if(tmp) tmp->print();


	return 0;
}

int main(int argc, char const *argv[])
{
	listExe();
	treeExe();
	std::cout << "Existing " << __func__ <<std::endl;
	return 0;
}