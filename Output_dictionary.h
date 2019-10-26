//
// Created by ELIAS on 11/05/2019.
//

#ifndef ASSIGHMENT2DSA_OUTPUT_DICTIONARY_H
#define ASSIGHMENT2DSA_OUTPUT_DICTIONARY_H
#include <iostream>
#include <csignal>
#include "AVL_ADT.h"
#include "map"
#include <set>
#include <string>
#include <fstream>
using namespace std;
struct DATA
{
    string key;
    int age;
    static int counter;
    set <string> myset;
    set <pair <int, string> > SET;
    int NODECOUNT;

};
int DATA::counter = 0;
class dictionary: public AvlTree<DATA, string> {
    string word;
public:
    priority_queue<string> DELETEKEY;
    struct letter_only: std::ctype<char>
    {
        letter_only(): std::ctype<char>(get_table()) {}

        static std::ctype_base::mask const* get_table()
        {
            static std::vector<std::ctype_base::mask>
                    rc(std::ctype<char>::table_size,std::ctype_base::space);

            std::fill(&rc['A'], &rc['z'+1], std::ctype_base::alpha);
            return &rc[0];
        }
    };

    int counter= 0;
    static int c;
    void readTextFile( DATA &ss);
    void wordsearch(DATA &ss);
    void  phrases( DATA &ss);
    void  clear( priority_queue <pair <int,string>> &queue1);
    void  Address(DATA &ss);
    void DELETE();
    void read(ifstream &ifstream1, DATA &ss);
    void total();

};

bool stop = true;
int counter1 = 0;
double  value1= 0;
string words;




/*READ FILES */
void dictionary ::  readTextFile( DATA &ss) {
    for (int i = 1; i <= 5; i++) {
        ifstream file;
        file.open( "G:\\\\Elias Ennebt 18391679 DSA 2\\\\Elias Ennebt 18391679 DSA 2 copy 2\\\\file"+ to_string(i) + ".txt");

        if (file.is_open()) {
            file.imbue(std::locale(std::locale(), new letter_only()));
            while (file >> word) {
                if (!AVL_Retrieve(word, ss)) {
                    ss.NODECOUNT++;
                    ss.key = word;
                    ss.age = 1;
                    AVL_Insert(ss);
                    ss.counter++;
                    ss.myset.insert("file" + to_string(i) + ".txt");
                    ss.SET.insert(make_pair(ss.NODECOUNT, ss.key));
                } else {
                    ss.key = word;

                    AVL_UPDATE(ss);
                }
            }
        }


        file.close();
    }

}



/*WORDSEARCH */

void dictionary :: wordsearch(DATA &ss ){
    cout << "please enter a word "<< endl;

    cin >> words;
    priority_queue <pair <int,string>> queue1;

    if(SEARCH(words, ss,queue1)){
        while(!queue1.empty() && stop ) {
            pair<int, string> pair1 = queue1.top();
            cout << pair1.first << " = "<< pair1.second << "   ";
            if(AVL_Retrieve(pair1.second, ss)){
                for(auto it = ss.myset.begin();it != ss.myset.end(); ++it ) {
                    cout << *it << "  ";
                }
            }
            cout << endl;
            counter1++;
            if(counter1 == 5){
                stop = false;
            }

            queue1.pop();
        }
    }
    clear(queue1);
}
/*EMPTY DICTIONARY */
void dictionary :: clear(std::  priority_queue <pair <int,string>> &queue1){
    priority_queue <pair <int,string>> empty;
    std::swap( queue1, empty );
}


/*PHRASE INSERTION */

void dictionary :: phrases( DATA &ss) {
    string phrase1 = " ";
    int counter = 0;
    vector <string> phrase;
    for (int i = 1; i <= 5; i++) {
        ifstream file;
//        file.open("F:\\Assighment2DSA\\file" + to_string(i) + ".txt");
        file.open( "G:\\\\Elias Ennebt 18391679 DSA 2\\\\Elias Ennebt 18391679 DSA 2 copy 2\\\\file"+ to_string(i) + ".txt");
        if (file.is_open()) {
            file.imbue(std::locale(std::locale(), new letter_only()));
            while (file >> word) {
                phrase1 += " " + word;
                ss.key = phrase1;
                counter++;
                if (!AVL_Retrieve(phrase1, ss)) {
                    if (counter <= 3) {
                        phrase.push_back(ss.key);
                        ss.key = phrase1;
                        ss.age = 1;
                        ss.counter++;
                        ss.myset.insert("File" + to_string(i) + ".txt");
                        AVL_Insert(ss);
                    } else {
                        counter = 0;
                        phrase1 = " ";
                    }

                } else {
                    ss.key = phrase1;

                    AVL_UPDATE(ss);
                }
            }
            file.close();
        }
    }
}


int inputstr;



/*READ DICTIONARY FILE */

void dictionary::read(ifstream &ifstream1, DATA &ss){
        if(ifstream1.is_open()) {
            while (ifstream1 >> word) {
                ifstream1.imbue(std::locale(std::locale(), new letter_only()));
                if (!AVL_Retrieve(word, ss)) {
                    ss.key = word;
                    ss.age = 1;
                    AVL_Insert(ss);
                    ss.counter++;

                } else {
                    ss.key = word;
                    ss.myset.insert("G:\\Elias Ennebt 18391679 DSA 2\\Elias Ennebt 18391679 DSA 2 copy 2\\Dictionary.txt");
                    AVL_UPDATE(ss);
                }
            }

        }

}

/*SAVE ADDRESSES */
void dictionary :: Address(DATA &ss){
    cout << "please enter a Number "<< endl;
    cin >> inputstr;


    for(auto it = ss.SET.begin();it != ss.SET.end(); ++it ) {
        if(inputstr == it->first) {
            cout << it->first << "  " << it->second << endl;
        }
    }

}
/*WOR TOTAL AFTER DELETION */
void dictionary :: total() {
    cout <<" The Total number of words/phrases in the dictionary is " <<  c << endl;
}


int dictionary :: c = 0;

/*DELET PRHASES LESS THEN FRESHHOLD*/
void dictionary :: DELETE (){

    while(!DELETEKEY.empty()){
        AVL_Delete(DELETEKEY.top());
        DELETEKEY.pop();
    }


}






/* AVL TREE FUCNTIONS */

template <class TYPE, class KTYPE>

void AvlTree<TYPE, KTYPE> :: AVL_UPDATE (TYPE dataIn)
{
    NODE<TYPE> *node;

    node = _retrieve(dataIn.key, tree);

    if(node){

        node->data.age+=1;

    }

}
template <class TYPE, class KTYPE>
//            q.push(root->data.age,word);
void AvlTree<TYPE,KTYPE> :: _search(KTYPE key, NODE<TYPE> *root, priority_queue <pair <int,string>> &q){

    if(root){

        string word = root->data.key;
        string str1 = key;

        if (str1 == word.substr(0,str1.length())){
            int frequency = root->data.age;
            q.push(make_pair(frequency,word));


            _search(key, root->left, q);
            _search (key, root->right, q);
        }
        else if (key < root->data.key)
            _search (key, root->left, q);
        else {
            _search (key, root->right, q);
        }


    } else
        return;




};
bool search1;
template <class TYPE, class KTYPE>
bool AvlTree<TYPE, KTYPE> ::  SEARCH (KTYPE key, TYPE& dataOut,priority_queue <pair <int,std::string>>&q  ){

//	Statements
    if (!tree)
        return true;
    search1 = true;
    if (search1)
    {
        _search (key, tree, q);

        return true;
    } // if found
    else{
        search1 = false;
        return false;



    }



};






#endif //ASSIGHMENT2DSA_OUTPUT_DICTIONARY_H
