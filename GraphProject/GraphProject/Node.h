#pragma once
#include "stdafx.h"
#define SHAPE_AREA 20
class Node :public CObject {

public:
	CPoint point;
	COLORREF borderColor;
	static int count;
	int id;
	Node(CPoint, COLORREF);
	Node()  { }
	virtual ~ Node()  {}
	virtual void Draw(CClientDC *) = 0;
	virtual void Serialize(CArchive &) = 0;
	virtual bool PtInShape(CPoint) = 0;
};

class nodeRectangle :public Node {
	DECLARE_SERIAL(nodeRectangle)
public:
	nodeRectangle(CPoint, COLORREF);
	nodeRectangle() { }
	~nodeRectangle() { }
	void Draw(CClientDC *);
	void Serialize(CArchive &);
	bool PtInShape(CPoint);

};

class nodeEllipse :public Node {
	DECLARE_SERIAL(nodeEllipse)
public:
	nodeEllipse(CPoint, COLORREF);

	nodeEllipse() { }
	~nodeEllipse() { }

	void Draw(CClientDC *);
	void Serialize(CArchive&);
	bool PtInShape(CPoint);
};


class nodeTriangle :public Node {
	DECLARE_SERIAL(nodeTriangle)
public:
	nodeTriangle(CPoint, COLORREF);

	nodeTriangle() { }

	void Draw(CClientDC *);
	void Serialize(CArchive&);
	bool PtInShape(CPoint);
};

class Edge {
public:
	Node *left, *right;
	Edge(Node *l, Node *r) {
		left = l;
		right = r;
	}

	Edge() { }
	~Edge() { }
};
