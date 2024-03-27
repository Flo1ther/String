#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

template <class T>
class String
{
public:
	String() : text(nullptr), size(0), capacity(0), pointer(nullptr) {}

	String(const char* line) : size(static_cast<int>(strlen(line) + 1)), text(new char[size]), capacity(size), pointer(new T[size])
	{
		for (int i = 0; i < size; i++)
		{
			this->text[i] = line[i];
		}
	}

	String(const String& copy) : size(copy.size), capacity(copy.capacity), text(new char[copy.size]), pointer(new T[copy.size])
	{
		if (copy.text)
		{
			for (int i = 0; i < size; i++)
			{
				this->text[i] = copy.text[i];
			}
		}
	}

	~String()
	{
		delete[] text;
		delete[] pointer;
	}

	int getSize()
	{
		return size;
	}

	char* getText()
	{
		return text;
	}

	void setText(const char* text_)
	{
		for (int i = 0; i < size; i++)
		{
			this->text[i] = text_[i];
		}
	}

	void setSize(const int size_)
	{
		this->size = size_;
	}

	void ChangeLine(const char* line)
	{
		if (line)
		{
			size = static_cast<int>(strlen(line) + 1);
			delete[] text;
			text = new char[size];
			for (int i = 0; i < size; i++)
			{
				text[i] = line[i];
			}
		}
		else
		{
			delete[] text;
			text = nullptr;
			size = 0;
		}
	}

	String returnLine(int start, int end)
	{
		if (text && start >= 0 && end < size && start <= end)
		{
			char* ret = new char[end - start + 2];
			strncpy(ret, text + start, end - start + 1);
			ret[end - start + 1] = '\0';
			String result(ret);
			delete[] ret;
			return result;
		}
		else
		{
			return String();
		}
	}

	void ShowString() const
	{
		if (text)
		{
			std::cout << text;
		}
	}

	void pop_back()
	{
		if (size > 0)
		{
			size--;
			if (size < capacity - 4)
			{
				T* tmp = new T[capacity - 4];
				for (int i = 0; i < size; i++)
				{
					tmp[i] = pointer[i];
				}
				delete[] pointer;
				pointer = tmp;
				capacity -= 4;
			}
		}
	}

	int countWords(const char* word) const
	{
		if (!text || !word)
		{
			return 0;
		}
		int count = 0;
		char* token = strtok(text, " ");

		while (token)
		{
			if (strcmp(token, word) == 0)
			{
				count++;
			}
			token = strtok(nullptr, " ");
		}
		return count;
	}

private:
	char* text;
	int size;
	int capacity;
	T* pointer;
};

int main()
{
	String<int> emptyString;
	String<int> stringParam("Hello world!");
	String<int> copiedString = stringParam;
	emptyString.ShowString();
	std::cout << std::endl;
	stringParam.ShowString();
	std::cout << std::endl;
	copiedString.ShowString();
	std::cout << std::endl;
	copiedString.ChangeLine("New string");
	copiedString.ShowString();
	std::cout << std::endl;
	String<int> returnLineResult = copiedString.returnLine(1, 7);
	returnLineResult.ShowString();
	std::cout << std::endl;
	int wordCount = copiedString.countWords("New");
	std::cout << "Word count: " << wordCount << std::endl;

	return 0;
}
