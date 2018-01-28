#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

typedef struct _Type
{
	bool has_Level;
	string category;
	int level;
}Type;

typedef struct _role
{
	int typeNum;
	string roleName;
	Type *typeArray;
}Role;

typedef struct _user
{
	int roleNum;
	string userName;
	Role *roleArray;
}User;

int main(){
	int typeNum = 0, roleNum = 0, userNum = 0, searchNum = 0;
	int cnt = 0;
	std::size_t found;
	string tempStr;
	//ifstream in("in.dat");
	cin>>typeNum;
	Type *typeList = new Type[typeNum];
	for(;cnt < typeNum; cnt++){
		cin>>tempStr;
		found = tempStr.find(":");
		if(found != std::string::npos){
			typeList[cnt].has_Level = true;
			typeList[cnt].category = tempStr.substr(0, found);
			typeList[cnt].level = atoi(tempStr.substr(found + 1, tempStr.size() - 1).c_str());
		}else{
			typeList[cnt].has_Level = false;
			typeList[cnt].category = tempStr;
			typeList[cnt].level = -1;
		}
	}
	cin>>roleNum;
	Role *roleList = new Role[roleNum];
	for(cnt = 0; cnt < roleNum; cnt++){
		cin>>tempStr;
		roleList[cnt].roleName = tempStr;
		int typeCnt = 0, number = 0;
		cin>>number;
		roleList[cnt].typeNum = number;
		roleList[cnt].typeArray = new Type[number];
		for(; typeCnt < number; typeCnt++){
			cin>>tempStr;
			found = tempStr.find(":");
			if(found != std::string::npos){
				roleList[cnt].typeArray[typeCnt].has_Level = true;
				roleList[cnt].typeArray[typeCnt].category = tempStr.substr(0, found);
				roleList[cnt].typeArray[typeCnt].level = atoi(tempStr.substr(found + 1, tempStr.size() - 1).c_str());
			}else{
				roleList[cnt].typeArray[typeCnt].has_Level = false;
				roleList[cnt].typeArray[typeCnt].category = tempStr;
				roleList[cnt].typeArray[typeCnt].level = -1;
			}
		}
	}
	cin>>userNum;
	User *userList = new User[userNum];
	for(cnt = 0; cnt < userNum; cnt++){
		cin>>tempStr;
		userList[cnt].userName = tempStr;
		int roleCnt = 0, number = 0;
		cin>>number;
		userList[cnt].roleNum = number;
		userList[cnt].roleArray = new Role[number];
		for(; roleCnt < number; roleCnt++){
			cin>>tempStr;
			userList[cnt].roleArray[roleCnt].roleName = tempStr;
			int traverseCnt = 0;
			for(; traverseCnt < roleNum; traverseCnt++){
				if (tempStr.compare(roleList[traverseCnt].roleName) == 0){
					userList[cnt].roleArray[roleCnt].typeNum = roleList[traverseCnt].typeNum;
					userList[cnt].roleArray[roleCnt].typeArray = new Type[userList[cnt].roleArray[roleCnt].typeNum];
					int typeCopyCnt = 0;
					for(; typeCopyCnt < userList[cnt].roleArray[roleCnt].typeNum; typeCopyCnt++){
						userList[cnt].roleArray[roleCnt].typeArray[typeCopyCnt].has_Level = roleList[traverseCnt].typeArray[typeCopyCnt].has_Level;
						userList[cnt].roleArray[roleCnt].typeArray[typeCopyCnt].category = roleList[traverseCnt].typeArray[typeCopyCnt].category;
						userList[cnt].roleArray[roleCnt].typeArray[typeCopyCnt].level = roleList[traverseCnt].typeArray[typeCopyCnt].level;
					}
					break;
				}
			}
		}
	}
	cin>>searchNum;
	string searchUser;
	string searchAuthorization;
	int searchLevel;
	bool search_has_Level;
	bool has_authorization;
	bool keep_search;
	int max_level;
	while(searchNum--){
		has_authorization = false;
		keep_search = true;
		max_level = -1;
		cin>>searchUser;
		cin>>tempStr;
		found = tempStr.find(":");
		if(found != std::string::npos){
			searchAuthorization = tempStr.substr(0, found);
			searchLevel = atoi(tempStr.substr(found + 1, tempStr.size() - 1).c_str());
			search_has_Level = true;
		}else{
			searchAuthorization = tempStr;
			search_has_Level = false;
		}
		int userCnt = 0;
		for(; keep_search && userCnt < userNum; userCnt++){
			if(searchUser.compare(userList[userCnt].userName) == 0){
				int roleCnt = 0;
				for(; keep_search && roleCnt < userList[userCnt].roleNum; roleCnt++){
					int typeCnt = 0;
					for(; keep_search && typeCnt < userList[userCnt].roleArray[roleCnt].typeNum; typeCnt++){
						if(searchAuthorization.compare(userList[userCnt].roleArray[roleCnt].typeArray[typeCnt].category) == 0){
							if(userList[userCnt].roleArray[roleCnt].typeArray[typeCnt].has_Level == false){
								cout<<"true"<<endl;
								keep_search = false;
							}else{
								if(search_has_Level == false){
									if (max_level < userList[userCnt].roleArray[roleCnt].typeArray[typeCnt].level)
										max_level = userList[userCnt].roleArray[roleCnt].typeArray[typeCnt].level;
								}else{
									if(userList[userCnt].roleArray[roleCnt].typeArray[typeCnt].level >= searchLevel){
										cout<<"true"<<endl;
										keep_search = false;
									}
								}
							}
						}
					}
				}
				break;
			}
		}
		if(search_has_Level == false && max_level != -1)
			cout<<max_level<<endl;
		else if (keep_search == true)
			cout<<"false"<<endl;
	}
	return 0;
}
