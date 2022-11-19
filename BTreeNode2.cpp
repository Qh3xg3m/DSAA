#include<bits/stdc++.h>
using namespace std;
template <class Object>
class BTreeNode{	
private:
	Object elem;
	BTreeNode *parent;
	BTreeNode *left;
	BTreeNode *right;

public:
	BTreeNode(Object o,BTreeNode *P,BTreeNode *L,BTreeNode *R){
		elem = o; parent = P; left = L; right = R;
	}
	BTreeNode *Parent(){
		return parent;
	}
	BTreeNode *Left(){
		return left;
	}
	BTreeNode *Right(){
		return right;
	}
	void setLeft(BTreeNode *L){
		left = L;
	}
	void setRight(BTreeNode *R){
		right = R;
	}
	void setParent(BTreeNode *P){
		parent = P;
	}
	int hasLeft(){
		return (left!=NULL);
	}
	int hasRight(){
		return (right!=NULL);
	}
	Object getElem(){
		return elem;
	}
	void setElem(Object o){
		elem = o;
	}
};
void visit(BTreeNode<int>* a){
	cout<<a->getElem()<<"=> ";
}
void Double(BTreeNode<int>* a){
	a->setElem(a->getElem()*2);
}
void PreOrder(BTreeNode<int> *v,void (*visit)(BTreeNode<int>* a)){
	if(v!=NULL){
		//cout<<v->getElem()<<"=>";//
		visit(v);
		PreOrder(v->Left(),visit);
		PreOrder(v->Right(),visit);
	}
}
int main(){
	BTreeNode<int> A(10,NULL,NULL,NULL);
	BTreeNode<int> B(8,NULL,NULL,NULL);
	BTreeNode<int> C(7,NULL,NULL,NULL);
	BTreeNode<int> D(5,NULL,NULL,NULL);
	BTreeNode<int> E(3,NULL,NULL,NULL);
	BTreeNode<int> F(6,NULL,NULL,NULL);
	A.setLeft(&B); A.setRight(&C);
	B.setParent(&A);C.setParent(&A);
	B.setLeft(&D); B.setRight(&E);
	D.setParent(&B);E.setParent(&B);
	C.setRight(&F);F.setParent(&C);
	//cout<<"A= "<<A.getElem()<<", LeftA = "<<A.Left()->getElem()<<", RightA = "<<A.Right()->getElem();
	PreOrder(&A,visit);
	cout<<"\nDOuble:";
	PreOrder(&A,Double);
	PreOrder(&A,visit);
}

