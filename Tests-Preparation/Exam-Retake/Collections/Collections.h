#pragma once

class Collection {

public:
	virtual void add(int i) = 0;
	virtual bool remove(int i) = 0;
	virtual size_t count(int i) const = 0;
	virtual bool contains(int i) const = 0;

	virtual Collection* clone() const = 0;
	virtual ~Collection() = default;
};

class DynamicCollection : public Collection {
protected:

	int* _data;
	size_t _size, _capacity;

	void resize();
public:
	DynamicCollection();
	DynamicCollection(int);

	//Big 6

};

class InfiniteCollection : public DynamicCollection { };
class FiniteCollection : public DynamicCollection {
public:
	FiniteCollection();
	FiniteCollection(int);
};

class NormalCollection : public InfiniteCollection {

public:

	NormalCollection();
	
	void add(int i) override;
	bool remove(int i) override;
	size_t count(int i) const override;
	bool contains(int i) const override;
	Collection* clone() const override;

};

class SortedCollection : public InfiniteCollection {

	int lowerBound(int) const;
	int upperBound(int) const;

public:

	SortedCollection();

	void add(int i) override;
	bool remove(int i) override;
	size_t count(int i) const override;
	bool contains(int i) const override;
	Collection* clone() const override;

};

class IntervalCollection : public FiniteCollection {

	int a, b;

public:

	IntervalCollection(int, int);

	void add(int i) override;
	bool remove(int i) override;
	size_t count(int i) const override;
	bool contains(int i) const override;
	Collection* clone() const override;

};

// Contains only unique numbers
// Could be of sorted or unsorted number 
// Although unsorted set is something completely different
class Set : public Collection{

	InfiniteCollection* _collection;

public:

	Set(int);

	void add(int i) override;
	bool remove(int i) override;
	size_t count(int i) const override;
	bool contains(int i) const override;
	Collection* clone() const override;

	~Set();

	// Big 6
};