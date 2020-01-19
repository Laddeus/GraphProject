#pragma once
#include "stdafx.h"
#define SHAPE_AREA 20
class Node :public CObject {

public:
	CPoint point;
	COLORREF borderColor;
	static int count;
	int id;
	Node(const CPoint &,const COLORREF &);
	Node()  { }
	virtual ~ Node()  {}
	virtual void Draw(CDC *) = 0;
	virtual void Serialize(CArchive &) = 0;
	virtual bool PtInShape(const CPoint &) = 0;
};

class nodeRectangle :public Node {
	DECLARE_SERIAL(nodeRectangle)
public:
	nodeRectangle(const CPoint &, const COLORREF &);
	nodeRectangle() { }
	~nodeRectangle() { }
	void Draw(CDC *);
	void Serialize(CArchive &);
	bool PtInShape(const CPoint &);

};

class nodeEllipse :public Node {
	DECLARE_SERIAL(nodeEllipse)
public:
	nodeEllipse(const CPoint &, const COLORREF &);

	nodeEllipse() { }
	~nodeEllipse() { }

	void Draw(CDC *);
	void Serialize(CArchive&);
	bool PtInShape(const CPoint &);
};


class nodeTriangle :public Node {
	DECLARE_SERIAL(nodeTriangle)
public:
	nodeTriangle(const CPoint &, const COLORREF &);

	nodeTriangle() { }

	void Draw(CDC *);
	void Serialize(CArchive&);
	bool PtInShape(const CPoint &);
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
