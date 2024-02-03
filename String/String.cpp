#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
class String
{
public:
	String() : text(nullptr) {}
	String(const char* line) : size{ int(strlen(line) + 1) }, text{ new char[size] }
	{
		for (int i = 0; i < size; i++)
		{
			this->text[i] = line[i];
		}
	}
	String(const String& copy)
	{
		if (copy.text)
		{
			size = copy.size;
			text = new char[size];
			for (int i = 0; i < size; i++)
			{
				this->text[i] = copy.text[i];
			}
		}
		else
		{
			text = nullptr;
			size = 0;
		}
	}

	~String()
	{
		delete[]text;
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
	void Changeline(const char* line)
	{
		
		if (line)
		{
			size = int(strlen(line) + 1);
			text = new char[size];
			for (int i = 0; i < size; i++)
			{
				text[i] = line[i];
			}
		}
		else
		{
			text = nullptr;
			size = 0;
		}
	}
	String returnline(int start, int end) 
	{
		if (text&&start>=0&&end<strlen(text)&&start<=end)
		{
			char* ret = new char[end - start + 2];
			strncpy(ret, text + start, end - start + 1);
			ret[end - start + 1] = '\0';
			String result(ret);
			delete[]ret;
			return result;
		}
		else
		{
			return String();
		}
	}
	void ShowString()
	const
	{
		if (text)
		{
			std::cout << text;
		}
	}
	int countWords(const char* word)
		const
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
			token = strtok(nullptr, "");
		}
		return count;
	}
	
private:
	char* text;
	int size;
};
int main()
{
	String emptyString;
	String stringParam("Hello world!");
	String copiedString = stringParam;
	emptyString.ShowString();
	std::cout << std::endl;
	stringParam.ShowString();
	std::cout << std::endl;
	copiedString.ShowString();
	std::cout << std::endl;
	copiedString.Changeline("New string");
	copiedString.ShowString();
	std::cout << std::endl;
	String returnLineResult = copiedString.returnline(1, 7);
	returnLineResult.ShowString();
	std::cout << std::endl;
	int wordCount = copiedString.countWords("New");
	std::cout << "Word count: " << wordCount << std::endl;
}