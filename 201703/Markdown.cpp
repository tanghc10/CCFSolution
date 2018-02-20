#include<bits/stdc++.h>
using namespace std;

enum State
{
	nullState, head, parameter, lists, stress, link
};

string handleStr(string str){
	std::size_t start, end;
	start = str.find("_");
	while(start != std::string::npos){
		//preStr存第一个'_'前面的文本，
		string preStr = str.substr(0, start);
		//msg存两个'_'之间的文本
		str = str.substr(start + 1, str.size() - 1);
		end = str.find("_");
		string msg = str.substr(0, end);
		//截取后的str是第二个'_'后面的文本
		str = str.substr(end + 1, str.size() - 1);
		msg = msg.insert(0, "<em>");
		msg = msg.insert(msg.size(), "</em>");
		str = preStr + msg + str;
		start = str.find("_");
	}
	start = str.find('[');
	while(start != std::string::npos){
		//preStr存第一个'['之前的文本
		string preStr = str.substr(0, start);
		//text存'['和']'之间的文本
		str = str.substr(start + 1, str.size() - 1);
		end = str.find("]");
		string text = str.substr(0, end);
		//截取后的str中获取Link
		str = str.substr(end + 1, str.size() - 1);
		//Link存'('和')'之间的文本
		start = str.find('(');
		str = str.substr(start + 1, str.size() - 1);
		end = str.find(')');
		string link = str.substr(0, end);
		str = str.substr(end + 1, str.size() - 1);
		str = preStr + "<a href=\"" + link + "\">" + text + "</a>" + str;
		start = str.find('[');
	}
	return str;
}

void printHead(string str, int level){
	cout<<"<h"<<level<<">"<<handleStr(str)<<"</h"<<level<<">"<<endl;
	return;
}

void printList(string str){
	cout<<"<li>"<<handleStr(str)<<"</li>"<<endl;
	return;
}

int main(){
	string tempStr;
	int currentState = nullState;
	while(getline(cin, tempStr)){
		if(tempStr.size() == 0){
			if(currentState == parameter)
				cout<<"</p>"<<endl;
			else if(currentState == lists)
				cout<<"</ul>"<<endl;
			currentState = nullState;
		}else if(tempStr[0] == '#'){
			currentState = head;
			int headCnt = 0;
			while(tempStr[0] == '#'){
				headCnt++;
				tempStr = tempStr.substr(1, tempStr.size() - 1);
			}
			while(tempStr[0] == ' ')
				tempStr = tempStr.substr(1, tempStr.size() - 1);
			printHead(tempStr, headCnt);
		}else if(tempStr[0] == '*'){
			if(currentState != lists){
				cout<<"<ul>"<<endl;
				currentState = lists;
			}
			while(tempStr[0] == '*' || tempStr[0] == ' ')
				tempStr = tempStr.substr(1, tempStr.size() - 1);
			printList(tempStr);
		}else{
			if(currentState != parameter){
				cout<<"<p>";
				currentState = parameter;
			}else
				cout<<endl;
			cout<<handleStr(tempStr);
		}
	}
	if(currentState == parameter)
		cout<<"</p>";
	else if(currentState == lists)
		cout<<"</ul>";
	return 0;
}
