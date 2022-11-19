#include<bits/stdc++.h>
using namespace std;

class BTreeNode{
    string MSV, hoten;
    int tuoi;
	BTreeNode *parent;
	BTreeNode *left;
	BTreeNode *right;
	public:
		BTreeNode(string _MSV, string _hoten, int _tuoi, BTreeNode *p, BTreeNode *l, BTreeNode *r){
			MSV = _MSV;
			hoten = _hoten;
			tuoi = _tuoi;
			parent = p;
			left = l;
			right = r;
		}

		string getMSV(){
			return MSV;
		}

		void setMSV(string _MSV){
			MSV = _MSV;
		}

		string getHoten(){
			return hoten;
		}

		void setHoten(string _hoten){
			hoten = _hoten;
		}

		int getTuoi(){
			return tuoi;
		}

		void setTuoi(int _tuoi){
			tuoi = _tuoi;
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


BTreeNode * themSV(BTreeNode *node, string msv, string hoten, int tuoi){
    if (node == NULL)
        return new BTreeNode(msv, hoten, tuoi, NULL, NULL, NULL);

    if (tuoi < node->getTuoi())
        node->setLeft(themSV(node->Left(), msv, hoten, tuoi));
    else
        node->setRight(themSV(node->Right(), msv, hoten, tuoi));

    return node;
}

BTreeNode* minValueNode(BTreeNode* node)
{
    BTreeNode* current = node;

    /* tim la ngoai cung ben trai */
    while (current && current->Left() != NULL)
        current = current->Left();

    return current;
}

BTreeNode* deleteNode(BTreeNode* root, int tuoi)
{
    if (root == NULL)
        return root;

    if (tuoi < root->getTuoi())
        root->setLeft(deleteNode(root->Left(), tuoi));

    else if (tuoi > root->getTuoi())
        root->setRight(deleteNode(root->Right(), tuoi));

    else {
        if (root->Left()==NULL && root->Right()==NULL)
            return NULL;

        else if (root->Left() == NULL) {
            BTreeNode* temp = root->Right();
            free(root);
            return temp;
        }
        else if (root->Right() == NULL) {
            BTreeNode* temp = root->Left();
            free(root);
            return temp;
        }

        BTreeNode* temp = minValueNode(root->Right());

        root->setTuoi(temp->getTuoi());
        root->setHoten(temp->getHoten());
        root->setMSV(temp->getMSV());

        root->setRight(deleteNode(root->Right(), temp->getTuoi()));
    }

    return root;
}

bool is_Exist(BTreeNode *v, string msv){
    if (v == NULL) return false;
    if (strcmp(v->getMSV().c_str(), msv.c_str()) == 0) return true;
    if (is_Exist(v->Left(), msv) == true) return true;
    if (is_Exist(v->Right(), msv) == true) return true;
	return false;
}

int searchTuoi(BTreeNode *v, string msv){
    if (v == NULL) return -1;
    if (strcmp(v->getMSV().c_str(), msv.c_str()) == 0) return v->getTuoi();
    if (searchTuoi(v->Left(), msv) != -1) return searchTuoi(v->Left(), msv);
    if (searchTuoi(v->Right(), msv) != -1) return searchTuoi(v->Right(), msv);
	return -1;
}

void displayNode(BTreeNode *v, string msv){
    if (v == NULL) return;
    if (strcmp(v->getMSV().c_str(), msv.c_str()) == 0){
        cout<<v->getMSV()<<" , "<<v->getHoten()<<" , "<<v->getTuoi()<<"\n";
        return;
    }
    displayNode(v->Left(), msv);
    displayNode(v->Right(), msv);
}

void updateNode(BTreeNode *v, string msv, string hoten, int tuoi){
    if (v == NULL) return;
    if (strcmp(v->getMSV().c_str(), msv.c_str()) == 0){
        v->setHoten(hoten);
        v->setTuoi(tuoi);
        return;
    }
    updateNode(v->Left(), msv, hoten, tuoi);
    updateNode(v->Right(), msv, hoten, tuoi);
}

void PreOrder(BTreeNode *v){
	if(v!=NULL){
        if (v->getTuoi() > 0)
            cout<<v->getMSV()<<" , "<<v->getHoten()<<" , "<<v->getTuoi()<<"\n";
		PreOrder(v->Left());
		PreOrder(v->Right());
	}
}

void InOrder(BTreeNode *v){
	if(v!=NULL){
        InOrder(v->Left());
        if (v->getTuoi() > 0)
            cout<<v->getMSV()<<" , "<<v->getHoten()<<" , "<<v->getTuoi()<<"\n";
		InOrder(v->Right());
	}
}

void PostOrder(BTreeNode *v){
	if(v!=NULL){
        PostOrder(v->Left());
        PostOrder(v->Right());
        if (v->getTuoi() > 0)
            cout<<v->getMSV()<<" , "<<v->getHoten()<<" , "<<v->getTuoi()<<"\n";
	}
}

void menu(){
    cout<<"1. Them sinh vien\n";
    cout<<"2. Xoa sinh vien\n";
    cout<<"3. Sua thong tin sinh vien\n";
    cout<<"4. Tim kiem sinh vien\n";
    cout<<"5. Duyet sinh vien theo thu tu truoc\n";
    cout<<"6. Duyet sinh vien theo thu tu giua\n";
    cout<<"7. Duyet sinh vien theo thu tu sau\n";
}

int main(){

    BTreeNode* root = new BTreeNode("", "", 0, NULL, NULL, NULL);
    int type, tuoi;
    string msv, hoten;
	int choice;
	
    do{
        menu();
        cout<<"Nhap: ";
        cin>>type;
        if (type == 1){
            while(getchar()!='\n');
            cout<<"MSV = ";
            getline(cin, msv);
            while (is_Exist(root, msv)){
                cout<<"MSV da ton tai!\n";
                cout<<"Nhap lai MSV = ";
                getline(cin, msv);
            }

            cout<<"Ho ten = ";
            getline(cin, hoten);
            cout<<"Tuoi = ";
            cin>>tuoi;
            root = themSV(root, msv, hoten, tuoi);
            cout << "--- DATABASE ---" << endl;
            PreOrder(root);
            cout << endl;
        } else if (type == 2){
        	cout << "--- DATABASE ---" << endl;
            PreOrder(root);
            cout << endl;
            while(getchar()!='\n');
            cout<<"MSV = ";
            getline(cin, msv);
            if (!is_Exist(root, msv)){
                cout<<"MSV khong ton tai!\n";
            } else {
                int tuoi = searchTuoi(root, msv);
                deleteNode(root, tuoi);
            }
            cout << "--- DATABASE ---" << endl;
            PreOrder(root);
            cout << endl;
        } else if (type == 3){
        	cout << "--- DATABASE ---" << endl;
            PreOrder(root);
            cout << endl;
            while(getchar()!='\n');
            cout<<"MSV = ";
            getline(cin, msv);
            if (!is_Exist(root, msv)){
                cout<<"MSV khong ton tai!\n";
            } else {
                cout<<"Thong tin dang co cua sinh vien la: ";
                displayNode(root, msv);
                cout<<"Ho ten moi = ";
                getline(cin, hoten);
                cout<<"Tuoi moi = ";
                cin>>tuoi;
                updateNode(root, msv, hoten, tuoi);
            }
            cout << "--- DATABASE ---" << endl;
            PreOrder(root);
            cout << endl;
        } else if (type == 4){
        	cout << "--- DATABASE ---" << endl;
            PreOrder(root);
            cout << endl;
            while(getchar()!='\n');
            cout<<"MSV = ";
            getline(cin, msv);
            if (!is_Exist(root, msv)){
                cout<<"MSV khong ton tai!\n";
            } else {
                cout<<"Thong tin dang co cua sinh vien la: ";
                displayNode(root, msv);
            }
        } else if (type == 5){
            PreOrder(root);
        } else if (type == 6){
            InOrder(root);
        } else if (type == 7){
            PostOrder(root);
        } else break;
    cout << "Ban muon tiep tuc? ";
    cin >> choice;
    cout << endl;
    } while(choice);
}

