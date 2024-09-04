#pragma once

class File {
protected:
	char _name[32 + 1];
public:

	File(const char* name);
	virtual void printContent() const = 0;
	virtual void printDir(int depth) const;
	virtual ~File() = default;
	virtual File* clone() const = 0;
	const char* getName() const;
};

class TextFile : public File {
private:
	char* _data;

	TextFile();
public:
	TextFile(const char* name, const char* data);
	void printContent() const override;
	File* clone() const override;

	// Big 6
	~TextFile();
};

class Dir : public File {
private:
	File** _files;
	size_t _size;
	size_t _capacity;
public:
	// Big 6
	Dir(const char* name);

	void add(File* f);
	void add(const File& f);
	File* clone() const override;
	void printContent() const override;
	void printDir(int depth) const override;

	File* findByName(const char* str) const;

	~Dir();
};