#ifndef _NODE_H_
#define _NODE_H_

Template <class Type> class Node {
    Type data;
    Node* next;

  public:
    Node() {};
    void SetData(Type aData) { data = aData; };
    void SetNext(Node* aNext) { next = aNext; };
    Type Data() { return data; };
    Node* Next() { return next; };
};

#define