#include<bits/stdc++.h>
using namespace std;

class BTreeNode{
	int elem;
	BTreeNode *parent;
	BTreeNode *left;
	BTreeNode *right;
	public:
		BTreeNode(int _elem, BTreeNode *p,BTreeNode *l,BTreeNode *r){
			elem = _elem;
			parent = p;
			left = l;
			right = r;
		}
		int getElem(){
			return elem;
		}
		void setEelem(int _elem){
			elem = _elem;
		}
		void setParent(BTreeNode *p){
			parent = p;
		}
		void setLeft(BTreeNode *p){
			left = p;
		}
		void setRight(BTreeNode *p){
			right = p;
		}
		BTreeNode *Left(){
			return left;
		}
		BTreeNode *Right(){
			return right;
		}
};
void PreOrder(BTreeNode *v){
	if(v!=NULL){
		cout<<v->getElem()<<"=>";
		PreOrder(v->Left());
		PreOrder(v->Right());
	}
}
int main(){
	BTreeNode A(10,NULL,NULL,NULL);
	BTreeNode B(5,&A,NULL,NULL);
	BTreeNode C(6,&A,NULL,NULL);
	BTreeNode D(8,&B,NULL,NULL);
	BTreeNode E(9,&B,NULL,NULL);
	BTreeNode F(4,&C,NULL,NULL);
	
	A.setLeft(&B);
	A.setRight(&C);
	B.setLeft(&D);B.setRight(&E);C.setLeft(&F);
	cout<<"A = "<<A.getElem()<<", Left ="<<A.Left()->getElem()<<", Right = "<<A.Right()->getElem();
PreOrder(&A);	
}

